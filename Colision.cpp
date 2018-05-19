/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Colision.cpp
 * Author: fv
 * 
 * Created on April 25, 2018, 8:45 AM
 */

#include "Colision.hpp"
#include <iostream>
#include <stdlib.h>
#include <SFML/System/Vector2.hpp>


Colision* Colision::unica_instancia = 0;

Colision::Colision() {

}

Colision::~Colision() {
}

void Colision::generarMatriz(int* matriz,int capa,int anchura, int altura){ //genera 1 matriz para cada una de las 3 capas
    filas=altura; //y
    col=anchura; //x
    
    
    int** capaux;
    
    
    if(capa==1){
        capa1 = new int*[filas];
        for(int i=0;i<filas;i++){
            capa1[i]=new int[col];
        }
        capaux=capa1;
    }
    else if(capa==2){
        capa2 = new int*[filas];
        for(int i=0;i<filas;i++){
            capa2[i]=new int[col];
        }
        capaux=capa2;
    }
    else if(capa==3){
        capa3 = new int*[filas];
        for(int i=0;i<filas;i++){
            capa3[i]=new int[col];
        }
        capaux=capa3;
    }
    else if(capa==4){
        capa4 = new int*[filas];
        for(int i=0;i<filas;i++){
            capa4[i]=new int[col];
        }
        capaux=capa4;
    }
    else if(capa==5){
        capa5 = new int*[filas];
        for(int i=0;i<filas;i++){
            capa5[i]=new int[col];
        }
        capaux=capa5;
    }
    
    for(int i=0;i<filas;i++){ // transformo el array en matriz para tener una mejor vision
        for(int j=0;j<col;j++){
            capaux[i][j]=matriz[(i*col)+j];
            //std::cout<<"matriz: "<< matriz[(i*col)+j] <<std::endl;
            
            }
        }
    
    
}
bool Colision::ColisionSuelo(int x, int y, sf::Vector2f dim, int dir){
 bool tocasuelo=false;
 
 y=y+16;
 int xaux=x;
 xaux=xaux-8;
 int izq=(xaux/32)+1;
 xaux=xaux+8+16;
 int der=(xaux/32)+1;
 int yaux=(y/32)+17;
 
 if(dir==-1){
    xaux=x;
    xaux=xaux-16;
    izq=(xaux/32)+1;
    xaux=xaux+16+8;
    der=(xaux/32)+1;
 }
 
 if(izq<col && der<col && yaux<filas){ // para segurarse que no se sale del array
     if(y<=-5){
        if(capa3[yaux-1][izq]>0 || capa3[yaux-1][der]>0){
        tocasuelo=true;
        } 
     }
     else{
       if(capa3[yaux][izq]>0 || capa3[yaux][der]>0){
        tocasuelo=true;
        }   
     }
 }

 
 
 return tocasuelo;
}

bool Colision::ColisionTecho(int x, int y,sf::Vector2f dim, int dir){
    bool tocasuelo=false;
    y=y-16;
    int xaux=x;
    xaux=xaux-8;
    int izq=(xaux/32)+1;
    xaux=xaux+8+16;
    int der=(xaux/32)+1;
    int yaux=(y/32)+17;
    
    if(dir==-1){
        xaux=x;
        xaux=xaux-16;
        izq=(xaux/32)+1;
        xaux=xaux+16+8;
        der=(xaux/32)+1;
    }
    
    
    if(der<col && izq<col && yaux<filas){//estan dentro de los limites del mapa
        if(y<6){
            if(capa3[yaux-1][izq]>0 || capa3[yaux-1][der]>0){
                tocasuelo=true;
            }
        }
        else{
            if(capa3[yaux][izq]>0 || capa3[yaux][der]>0){
                tocasuelo=true;
            }
        }
       
    }
    
    return tocasuelo;
}
bool Colision::ColisionLateral(int x, int y,sf::Vector2f dim, int dir){
    bool techocas=false;
    int xaux=x/32+1; //el +1 es para ajustarlo a la matriz
    int yaux=(y/32)+17; // el +17 es para ajustarlo a la matriz
    int ctop=y-31,cizq=x-12,cder=x+15,cbot=y-2;//parametros cabeza
    //int atop=y-1,aizq=x-12,ader=x+30,abot=y+10;//colision arma
    int ptop=y-1,pizq=x-12,pder=x+15,pbot=y+15;//parametros piernas
    
    if(xaux<col-1 && yaux<filas-1){
        if(dir==-1){
        cizq=x;cder=x+10;
        pizq=x;pder=x+10;
        if(y<0){ // al tener y negativas y realizar la division para comparar el numero en la matriz, acabamos con dos posicioens 0, con este if se evita
                if(capa3[(ctop/32)+16][(cder/32)+1]>=0 || capa3[(cbot/32)+16][(cder/32)+1]>=0){ // colision cabeza
                    techocas=true;
                    //std::cout<<"-cabeza"<<std::endl;
                }
                else if(capa3[(ptop/32)+16][(pder/32)]>=0 || capa3[(pbot/32)+16][(pder/32)]>=0){ // colision piernas
                    techocas=true;
                    //std::cout<<"-piernas "<<std::endl;
                }
            }
            else{
            
                if(capa3[(ctop/32)+17][(cder/32)]>=0){ // colision cabeza
                    techocas=true;
                    //std::cout<<"cabeza"<<std::endl;
                }

                else if(capa3[(ptop/32)+17][(pder/32)]>=0 || capa3[(pbot/32)+17][(pder/32)]>=0){
                     techocas=true;
                     //std::cout<<"piernas"<<std::endl;
                } 
            }
        }
        else {
            if(y<0){ // al tener y negativas y realizar la division para comparar el numero en la matriz, acabamos con dos posicioens 0, con este if se evita
                if(capa3[(ctop/32)+16][(cder/32)+1]>=0 || capa3[(cbot/32)+16][(cder/32)+1]>=0){ // colision cabeza
                    techocas=true;
                    //std::cout<<"-cabeza"<<std::endl;
                }
                else if(capa3[(ptop/32)+16][(pder/32)+1]>=0 || capa3[(pbot/32)+16][(pder/32)+1]>=0){ // colision piernas
                    techocas=true;
                    //std::cout<<"-piernas "<<std::endl;
                }
            }
            else{
                if(capa3[(ctop/32)+17][(cder/32)+1]>=0 || capa3[(cbot/32)+17][(cder/32)+1]>=0){ // colision cabeza
                    techocas=true;
                    //std::cout<<"cabeza"<<std::endl;
                }

                else if(capa3[(ptop/32)+17][(pder/32)+1]>=0 || capa3[(pbot/32)+17][(pder/32)+1]>=0){
                     techocas=true;
                     //std::cout<<"piernas"<<std::endl;
                } 
            }
        }
    }
    else{
        techocas=false;
    }
    
    return techocas;
}
    
    
    


