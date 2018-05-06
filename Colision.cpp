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
    
    for(int i=0;i<filas;i++){ // transformo el array en matriz para tener una mejor vision
        for(int j=0;j<col;j++){
            capaux[i][j]=matriz[(i*col)+j];
            
            /*if(capa==1){
            }
            else if(capa==2){
               // std::cout<<"capa2: "<< capa2[i][j] <<", ";
            }
            else if(capa==3){
                //std::cout<<"capa3: "<< capa3[i][j] <<std::endl;
            }
            //std::cout<<"matriz: "<< matriz[(i*col)+j] <<std::endl;
             * */
             
            }
        }
    
    
}
bool Colision::ColisionSuelo(int x, int y,int dir){
    bool tocasuelo=false;
    
    int xaux=x/32+1;
    int yaux=(y/32)+17; // el +17 es para ajustarlo a la matriz
    int ctop=y-31,cizq=x-12,cder=x+20;//parametros cabeza
    int ttop=y-1,tizq=x-12,tder=x+11,tbot=y+15;//parametros torso // dir para cambiar la orientacion -1 o 1
    if(dir==-1){
        tizq=x-12;tder=x+10;
    }
    
    if(xaux<col-1 && yaux<filas-1){//estan dentro de los limites del mapa
        
       /*std::cout<<"y: "<<y<<std::endl;
       std::cout<<"y/32: "<<y/32<<std::endl;
        std::cout<<"tbot: "<<tbot<<std::endl;
       std::cout<<"tbot/32 : "<<(tbot/32)+17<<std::endl;
       std::cout<<"capa2 arriba : "<<capa2[(tbot/32)+16][(tizq/32)+1]<<std::endl;
       std::cout<<"capa2 donde toca : "<<capa2[(tbot/32)+17][(tizq/32)+1]<<std::endl;
       std::cout<<"capa2 abajo : "<<capa2[(tbot/32)+18][(tizq/32)+1]<<std::endl;
        */
        
        /*for(int i=0;i<filas;i++){
            for(int j=0;j<col;j++){
                std::cout<<"fila: "<<i<<". Col: "<<col<<". capa2: "<<capa2[i][j]<<std::endl;
            }
        }*/
       if(y<0){ // al tener y negativas y realizar la division para comparar el numero en la matriz, acabamos con dos posicioens 0, con este if se evita
             if(capa2[(tbot/32)+16][(tizq/32)+1]==27 || capa2[(tbot/32)+16][(tder/32)+1]==27 || capa2[(tbot/32)+16][(tizq/32)+1]==79 || capa2[(tbot/32)+16][(tder/32)+1]==79){ // colision por abajo
                tocasuelo=true;
                
            }  
       }
       else{
           
         if(capa2[(tbot/32)+17][(tizq/32)+1]==27 || capa2[(tbot/32)+17][(tder/32)+1]==27 || capa2[(tbot/32)+17][(tder/32)+1]==158 || capa2[(tbot/32)+17][(tizq/32)+1]==158 || capa2[(tbot/32)+16][(tizq/32)+1]==79 || capa2[(tbot/32)+16][(tder/32)+1]==79 ){ // colision por abajo
            tocasuelo=true;
        }  
       }
    }
    else{
        tocasuelo=false;
    }
    
    return tocasuelo;
}
bool Colision::ColisionTecho(int x, int y, int dir){
    bool tocasuelo=false;
    int xaux=x/32+1; //el +1 es para ajustarlo a la matriz
    int yaux=(y/32)+15; // el +17 es para ajustarlo a la matriz
    int ctop=y-31,cizq=x-12,cder=x+15,cbot=y-2;
    
    if(dir==-1){
        cizq=x-12;cder=x+10;
    }
    
    if(xaux<col-1 && yaux<filas-1){//estan dentro de los limites del mapa
        
       if(y<0){ // al tener y negativas y realizar la division para comparar el numero en la matriz, acabamos con dos posicioens 0, con este if se evita
             if(capa2[(ctop/32)+16][(cizq/32)+1]==27 || capa2[(ctop/32)+16][(cder/32)+1]==27 || capa2[(ctop/32)+16][(cizq/32)+1]==79 || capa2[(ctop/32)+16][(cder/32)+1]==79){ // colision por abajo
                tocasuelo=true;
                std::cout<<"cabeza por arriba-----1"<<std::endl;
            }  
       }
       else{
         if(capa2[(ctop/32)+17][(cizq/32)+1]==79 || capa2[(ctop/32)+17][(cder/32)+1]==79 || capa2[(ctop/32)+17][(cder/32)+1]==158 || capa2[(ctop/32)+17][(cizq/32)+1]==158 ){ // colision por abajo
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
bool Colision::ColisionLateral(int x, int y, int dir){
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
                if(capa2[(ctop/32)+16][(cder/32)+1]>0 || capa2[(cbot/32)+16][(cder/32)+1]>0){ // colision cabeza
                    techocas=true;
                    std::cout<<"-cabeza"<<std::endl;
                }
                else if(capa2[(ptop/32)+16][(pder/32)]>0 || capa2[(pbot/32)+16][(pder/32)]>0){ // colision piernas
                    techocas=true;
                    //std::cout<<"-piernas "<<std::endl;
                }
            }
            else{
            
                if(capa2[(ctop/32)+17][(cder/32)]>0 || capa2[(cbot/32)+17][(cder/32)]>0){ // colision cabeza
                    techocas=true;
                    std::cout<<"cabeza"<<std::endl;
                }

                else if(capa2[(ptop/32)+17][(pder/32)]>0 || capa2[(pbot/32)+17][(pder/32)]>0){
                     techocas=true;
                     //std::cout<<"piernas"<<std::endl;
                } 
            }
        }
        else {
            if(y<0){ // al tener y negativas y realizar la division para comparar el numero en la matriz, acabamos con dos posicioens 0, con este if se evita
                if(capa2[(ctop/32)+16][(cder/32)+1]>0 || capa2[(cbot/32)+16][(cder/32)+1]>0){ // colision cabeza
                    techocas=true;
                    //std::cout<<"-cabeza"<<std::endl;
                }
                else if(capa2[(ptop/32)+16][(pder/32)+1]>0 || capa2[(pbot/32)+16][(pder/32)+1]>0){ // colision piernas
                    techocas=true;
                    //std::cout<<"-piernas "<<std::endl;
                }
            }
            else{
                if(capa2[(ctop/32)+17][(cder/32)+1]>0 || capa2[(cbot/32)+17][(cder/32)+1]>0){ // colision cabeza
                    techocas=true;
                    //std::cout<<"cabeza"<<std::endl;
                }

                else if(capa2[(ptop/32)+17][(pder/32)+1]>0 || capa2[(pbot/32)+17][(pder/32)+1]>0){
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
/*bool Colision::ColisionDerecha(int x, int y){
    bool techocas=false;
    int xaux=x/32;
    int yaux=y/32;
    
    //x/32 max 16-col ; y/32 max 8-filas
    //alturagato 11;
    //anchuragato 35;
    if(x>32*(col-1)){ // detecta el final del mapa por la derecha
        techocas=true;
    }
    else if(y/32 == filas){//si se sale por abajo, se cae por un agujero
        if(capa1[filas-1][xaux+1]>-1 || capa2[filas-1][xaux+1]>-1 ){
            if(capa1[filas-1][xaux+1]>-1 || capa2[filas-1][xaux+1]>-1 ){//cuerpo del gato
                if(x+25>(xaux+1)*32){
               techocas=true; 
                }
            }
        }
    }
    else if((x/32)<col && y/32<filas && y/32>1){
        if(capa1[yaux-1][xaux+1]==1 || capa2[yaux-1][xaux+1]==1 || capa1[yaux-1][xaux+1]==53 || capa2[yaux-1][xaux+1]==53 ){
            techocas=false;
        }
        else{
          if(capa1[yaux-1][xaux+1]>-1 || capa2[yaux-1][xaux+1]>-1 ){//cuerpo del gato
            if(x+25>(xaux+1)*32){
               techocas=true; 
            }
        }
        
        if( capa1[yaux][xaux+1]>-1 || capa2[yaux][xaux+1]>-1 ){//pies del gato
            if(x+25>(xaux+1)*32 && y-17>(yaux)*32){
                std::cout<<"y del gato:"<<y<<std::endl;
                std::cout<<"y calculada: "<<yaux*32<<std::endl; 
                techocas=true;
                }
            } 
        
        if(capa1[yaux-2][xaux+1]>-1 || capa2[yaux-2][xaux+1]>-1){//cabeza del gato
                if(x+25>(xaux+1)*32 ){
                techocas=true;
                }
            }  
        }
        
    }
    
    return techocas;
}*/
bool Colision::ColisionIzquierda(int x, int y){
   bool techocas=false;
    int xaux=x/32;
    int yaux=y/32;
   
    if(y/32 == filas){//si se sale por abajo, se cae por un agujero
        if(capa1[filas-1][xaux-1]>-1 || capa2[filas-1][xaux-1]>-1 ){
            if(capa1[filas-1][xaux-1]>-1 || capa2[filas-1][xaux-1]>-1 ){//cuerpo del gato
                if(x+25>(xaux-1)*32){
               techocas=true; 
                }
            }
        }
    }
    //la colision con la izuierda la detecta la camara
    else if(x/32>0 && y/32<filas && y/32>1){//condicion para no salirse del array
        
        if(capa1[yaux-1][xaux-11]==1 || capa2[yaux-1][xaux-1]==1 || capa1[yaux-1][xaux-1]==53 || capa2[yaux-1][xaux-1]==53 ){
            techocas=false;
        }
        else{
           if(capa1[yaux-1][xaux-1]>-1 || capa2[yaux-1][xaux-1]>-1 ){
                if(x-25>(xaux-1)*32){
                    techocas=true; 
                }
        }
        
        if( capa1[yaux][xaux-1]>-1 || capa2[yaux][xaux-1]>-1 ){//pies del gato
                if(x-25>(xaux-1)*32 && y-17>(yaux)*32){
                    techocas=true;
                }
            }
        
        
        
        if(capa1[yaux-2][xaux-1]>-1 || capa2[yaux-2][xaux-1]>-1){//cabeza del gato
                if(x-25>(xaux-1)*32 ){
                    techocas=true;
                }
            } 
        }
        
        
    }
    return techocas;
}
    
    
    

