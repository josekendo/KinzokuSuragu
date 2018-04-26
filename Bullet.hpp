/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bullet.hpp
 * Author: fv
 *
 * Created on April 9, 2018, 10:09 AM
 */

#ifndef BULLET_HPP
#define BULLET_HPP
#include "Coordenadas.hpp"
#include <iostream>

class Bullet {
public:
    Bullet(int tipo, int elemento, int x, int y, int jugador, int dano, int ori);
    virtual ~Bullet();
    void draw(int point);//se le llama a pintar esa bala en el motor
    bool sigoViva();//si sigue viva devuelve true si no false
    bool matarBala(int point);//mata a su sprite en el motor 
    int getOri();
    void realimentar(int ori);//realimentamos su velocidad
    
private:
    
    Coordenadas coordenadas = Coordenadas(400,30);
    int orientacion;
    int tipob;
    int elementob;
    int jugadorb;
    int danob;
    int velocidad;//velocidad que tendra las 15 veces que se ejecute por reloj
    bool ini = false;
};

#endif /* BULLET_HPP */

