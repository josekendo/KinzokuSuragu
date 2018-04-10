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
#include "Bullet.hpp"
#include <vector> 
#include <iostream>

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
    void juegoIndividual(int tipo);//prepara el personaje con el tipo 0-masculino, 1-femenino
    void juegoMultijugador(int tipo1,int tipo2);//prepara los personajes con los tipos(0 masculino, 1 femenino)
    void moverJugador(int jugador);
    void draw();
private:
    //clase singleton 
    Nivel();
    static Nivel* unica_instancia;
    //fin clase singleto private
    FabricarNivel fabrica;
    Jugadores jugadores[2];//array de jugadores
    std::vector<Enemigos> enemigos;//array autodimensionable de enemigos
    std::vector<Bullet> bullet;//array autodimensionable de proyectiles
    int modo;//modo un jugador(0), dos jugadores(1)
};  

#endif /* NIVEL_HPP */