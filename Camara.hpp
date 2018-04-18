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
    int coordenadaX();//devuelve la coordenada x
    int coordenadaY();//devuelve la coordenada y
    bool mePuedoMover(int xn,int yn);//devuelve true si se puede mover a esa posicion el jugador
    bool meMuevo();//siempre que se vaya a mover el jugador se le pasa esta funcion para indicarle a la camara que se esta moviendo
    
private:
    //clase singleton 
    Camara();
    static Camara* unica_instancia;
    //fin clase singleto private
    int x,y=0;
    int block = false;
};

#endif /* CAMARA_HPP */

