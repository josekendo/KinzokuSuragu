/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Camara.hpp
 * Author: fv
 *
 * Created on April 18, 2018, 9:32 AM
 */

#ifndef CAMARA_HPP
#define CAMARA_HPP

class Camara {
public:
      //clase singleton
    ~Camara(void);
    static Camara *getInstance()
    {
        if(unica_instancia == 0)
        unica_instancia = new Camara();
        return unica_instancia;  
    }
    //fin singleton public
    
    void bloquear();//bloquea la camara
    void desbloquear();//desbloque la camara
    void setCoordenadas(int xn, int yn);//cambia la camara de posicion
    void draw();//llama a pintar de la clase motor2d
    void meMuevo(int xn, int yn);//siempre que se vaya a mover el jugador se le pasa esta funcion para indicarle a la camara que se esta moviendo
    int coordenadaX();//devuelve la coordenada x
    int coordenadaY();//devuelve la coordenada y
    bool mePuedoMover(int xn,int yn);//devuelve true si se puede mover a esa posicion el jugador
    
private:
    //clase singleton 
    Camara();
    static Camara* unica_instancia;
    //fin clase singleto private
    int x,y=0;//nos servira para saber las posiciones de la camara
    int block = false;//nos servira para saber si esta bloqueada o no
    int minLimite,maxLimite = 0;//los limites de la camara
    int altura = 600, anchura = 800;//medidas de la vision de la camara
};

#endif /* CAMARA_HPP */

