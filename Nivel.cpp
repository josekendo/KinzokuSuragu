/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nivel.cpp
 * Author: fv
 * 
 * Created on April 5, 2018, 10:18 AM
 */

#include "Nivel.hpp"

Nivel* Nivel::unica_instancia = 0;

Nivel::Nivel() 
{
    
}

void Nivel::cargarNivel(int niv)
{
    switch(niv)
    {
        case 1:
            fabrica.construirNivel("resources/niveles/1.xml");
        break;
        case 2:
            fabrica.construirNivel("resources/niveles/2.xml");
        break;
        case 3:
            fabrica.construirNivel("resources/niveles/3.xml");
        break;
        case 4:
            fabrica.construirNivel("resources/niveles/4.xml");
        break;
    }
}
//carga de un jugador
void Nivel::juegoIndividual(int tipo)
{
    modo = 1;
    if(tipo == 0)//masculino jugador 1
    {
      jugadores[0].initJugador(0,1);  
    }
    if(tipo == 1)//femenino jugador 1
    {
      jugadores[0].initJugador(1,1);  
    }    
}
//carga de dos jugadores
void Nivel::juegoMultijugador(int tipo1, int tipo2)
{
    modo = 2;
    if(tipo1 == 0)//masculino jugador 1
    {
        jugadores[0].initJugador(0,1);  
    }
    if(tipo1 == 1)//femenino jugador 1
    {
        jugadores[0].initJugador(1,1);  
    }
    if(tipo2 == 0)//maculino jugador 2
    {
        jugadores[1].initJugador(0,2);  
    }
    if(tipo2 == 1)//femenino jugador 2
    {
        jugadores[1].initJugador(1,2);  
    }
}

void Nivel::draw()
{
     Motor2D *motor2D = Motor2D::getInstance();//clase global
     motor2D->drawCap1();
     motor2D->drawCap2();
     //pintamos a enemigos y jugadores
     if(modo == 1)
     {
         //std::cout << "draw de nivel m 1" << std::endl;
         jugadores[0].draw();
     }
     else
     {
         //std::cout << "draw de nivel m 2"  << std::endl;
         jugadores[0].draw();
         jugadores[1].draw();
     } 
     motor2D->drawCap3();
}

void Nivel::moverJugador(int jugador)
{
    //std::cout << "entro en nivel " << jugador << std::endl;
    jugadores[jugador].mover();//el mira su estado actual y se movera en consecuencia (aqui deberia ir el stop cuando no se pueda mover a causa de una colision)
}

void Nivel::moverJugadorAtras(int jugador)
{
    //std::cout << "entro en nivel " << jugador << std::endl;
    jugadores[jugador].moverAtras();//el mira su estado actual y se movera en consecuencia (aqui deberia ir el stop cuando no se pueda mover a causa de una colision)
}

int Nivel::getModo()
{
    return modo;
}

int Nivel::separacion()
{
    if(modo == 2)
    {
        int newS = jugadores[0].getX() - jugadores[1].getX();
        return abs(newS);
    }       
    return 0;
}