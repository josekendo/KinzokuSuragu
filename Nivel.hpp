/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nivel.hpp
 * Author: fv
 *
 * Created on April 5, 2018, 10:18 AM
 */

#ifndef NIVEL_HPP
#define NIVEL_HPP


#include "Jugadores.hpp"
#include "Enemigos.hpp"
#include "FabricarNivel.h"

class Nivel {
public:
    //clase singleton
    ~Nivel(void);
    static Nivel *getInstance()
    {
        if(unica_instancia == 0)
        unica_instancia = new Nivel();
        return unica_instancia;  
    }
    //fin singleton public
    void cargarNivel(int niv);//carga el nivel pasado empezando por 1
private:
    //clase singleton 
    Nivel();
    static Nivel* unica_instancia;
    //fin clase singleto private
    FabricarNivel fabrica;
    Jugadores *jugadores;//array de jugadores
    Enemigos *enemigos;//array de enemigos
};

#endif /* NIVEL_HPP */