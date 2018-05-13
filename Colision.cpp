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
            
            if(capa==1){
            }
            else if(capa==3){
                std::cout<< capa3[i][j] <<", ";
            }
            //std::cout<<"matriz: "<< matriz[(i*col)+j] <<std::endl;
            
            }
        }
    
    
}
bool Colision::ColisionSuelo(int x, int y, sf::Vector2f dim, int dir){
    bool tocasuelo=false;
    
    int xaux=x/32+1;
    int yaux=(y/32)+17; // el +17 es para ajustarlo a la matriz
    int ctop=y-31,cizq=x-12,cder=x+20;//parametros cabeza
    int ttop=y-1,tizq=x-12,tder=x+11,tbot=y+15;//parametros torso // dir para cambiar la orientacion -1 o 1
    /*int anchura=dim.x/4;
    int altura=dim.y/4;
    int left=x-anchura,rigth=x+anchura;
    int top=y-altura,bot=y+altura;*/
    
    //std::cout<<"x: "<<x<<", y: "<<y<<", anchura: "<<anchura<<", altura: "<<altura<<std::endl;
   // std::cout<<"left: "<<left/32<<", rigth: "<<rigth/32<<", top: "<<top/32<<", bot: "<<bot/32<<std::endl;
   
    /*std::cout<<"arriba pos iz: "<<capa3[(bot/32)+16][left/32]<<". arriba pos der: "<<capa3[(bot/32)+16][rigth/32]<<std::endl;
    std::cout<<"en mi pos iz: "<<capa3[(bot/32)+17][(left/32)+1]<<". en mi pos der: "<<capa3[(bot/32)+17][rigth/32]<<std::endl;
    std::cout<<"pos en pantalla: "<<std::endl;
    std::cout<<"abajo iz: "<<capa3[(bot/32)+18][left/32]<<". abajo pos der: "<<capa3[(bot/32)+18][rigth/32]<<std::endl;
    
    if(capa3[(bot/32)+17][(left/32)+1]>0 || capa3[(bot/32)+17][(rigth/32)+1]>0){
        tocasuelo=true;
    }*/
    if(dir==-1){
        tizq=x-12;tder=x+10;
    }
    
    if(xaux<col-1 && yaux<filas-1){//estan dentro de los limites del mapa
        
       std::cout<<"y: "<<y<<std::endl;
       std::cout<<"y/32: "<<y/32<<std::endl;
        std::cout<<"tbot: "<<tbot<<std::endl;
       std::cout<<"tbot/32 : "<<(tbot/32)+17<<std::endl;
       std::cout<<"capa2 arriba : "<<capa3[(tbot/32)+16][(tizq/32)+1]<<std::endl;
       std::cout<<"capa2 donde toca : "<<capa3[(tbot/32)+17][(tizq/32)+1]<<std::endl;
       std::cout<<"capa2 abajo : "<<capa3[(tbot/32)+18][(tizq/32)+1]<<std::endl;
       
       if(y<0){ // al tener y negativas y realizar la division para comparar el numero en la matriz, acabamos con dos posicioens 0, con este if se evita
             if(capa3[(tbot/32)+16][(tizq/32)+1]>=0 || capa3[(tbot/32)+16][(tder/32)+1]>=0){ // colision por abajo
                tocasuelo=true;
                
            }  
       }
       else{
           
         if(capa3[(tbot/32)+17][(tizq/32)+1]>=0 || capa3[(tbot/32)+17][(tder/32)+1]>=0){ // colision por abajo
            tocasuelo=true;
        }  
       }
    }
    else{
        tocasuelo=false;
    }
    
    
    return tocasuelo;
}
bool Colision::ColisionTecho(int x, int y,sf::Vector2f dim, int dir){
    bool tocasuelo=false;
    int xaux=x/32+1; //el +1 es para ajustarlo a la matriz
    int yaux=(y/32)+15; // el +17 es para ajustarlo a la matriz
    int ctop=y-31,cizq=x-12,cder=x+15,cbot=y-2;
    
    if(dir==-1){
        cizq=x-12;cder=x+10;
    }
    
    if(xaux<col-1 && yaux<filas-1){//estan dentro de los limites del mapa
        
       if(y<0){ // al tener y negativas y realizar la division para comparar el numero en la matriz, acabamos con dos posicioens 0, con este if se evita
             if(capa3[(ctop/32)+16][(cizq/32)+1]>=0 || capa3[(ctop/32)+16][(cder/32)+1]>=0){ // colision por abajo
                tocasuelo=true;
                std::cout<<"cabeza por arriba-----1"<<std::endl;
            }  
       }
       else{
         if(capa3[(ctop/32)+17][(cizq/32)+1]>=0 || capa3[(ctop/32)+17][(cder/32)+1]>=0){ // colision por abajo
            tocasuelo=true;
            std::cout<<"cabeza por arriba ++++1"<<std::endl;
        }  
       }
    }
    else{
        tocasuelo=false;
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
                    std::cout<<"-cabeza"<<std::endl;
                }
                else if(capa3[(ptop/32)+16][(pder/32)]>=0 || capa3[(pbot/32)+16][(pder/32)]>=0){ // colision piernas
                    techocas=true;
                    //std::cout<<"-piernas "<<std::endl;
                }
            }
            else{
            
                if(capa3[(ctop/32)+17][(cder/32)]>=0 || capa3[(cbot/32)+17][(cder/32)]>=0){ // colision cabeza
                    techocas=true;
                    std::cout<<"cabeza"<<std::endl;
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
    
    
    


