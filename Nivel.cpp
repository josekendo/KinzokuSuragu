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
#include <iostream>

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
         //jugadores[0].draw();
         jugadores[0].Idle(1); //Estado default
         //jugadores[1].draw();
         jugadores[1].Idle(1); //Estado default
         
         
         //jugadores[0].Walk(1); //COMPROBAR QUE WALK FUNCIONA
         //jugadores[0].Shoot(1); //COMPROBAR QUE SHOOT FUNCIONA
         //jugadores[0].Kick(1); //COMPROBAR QUE SHOOT FUNCIONA
         //jugadores[0].setDefensa(1);//COMPROBAR QUE SETDEFENSA FUNCIONA
         //jugadores[0].Block(1); //COMPROBAR QUE BLOCK FUNCIONA
         //jugadores[0].Die(-1); //COMPROBAR QUE DIE FUNCIONA
         //jugadores[0].Jump(1); //COMPROBAR QUE ANIMACIÓN JUMP FUNCIONA 
     } 
     motor2D->drawCap3();
}
