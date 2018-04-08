/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Enemigos.hpp
 * Author: fv
 *
 * Created on April 5, 2018, 10:07 AM
 */

#ifndef ENEMIGOS_HPP
#define ENEMIGOS_HPP
#include "Coordenadas.hpp"

class Enemigos {
public:
    Enemigos();
    Enemigos(int vid, int ataq, int ataqfisico,int element,int defen);
    Enemigos(const Enemigos& orig);
    virtual ~Enemigos();
    int getVida();//devuelve la vida del personaje restante(100 maximo)
    bool setDanoVida(int dano);//incrementa el dano a la vida restante devuelve true si el personaje se debilita(muerte)
    bool tieneDefensa();//nos sirve para saber si tiene defensa o no
    void setDefensa(int defen);//damos la defensa maximo (100), si el dano individual que le hacen es menor que la defensa no se le hace dano.
    int getDano(int element, int tipo);//si el elemento es neutro se le hara el dano base si es un elemento mas fuerte se le hara el doble, si es mas flojo la mitad
    void cambiarElemento(int element);//cambia al elemento pasado por parametro: 0(neutral),1(aire),2(tierra),3(agua),4(fuego),5(metal) - El mejor
    //estadisticas
    void addDano(int dano);//se agrega el dano realizado al marcador
private:
    int vida,defensa,ataque,ataquefisico,danototal,elemento;    
    Coordenadas coordenadas;
};

#endif /* ENEMIGOS_HPP */

