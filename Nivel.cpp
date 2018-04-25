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
#include "Hud.hpp"

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
    Controles *con = Controles::getInstance();
    con->offTwo();
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
    Controles *con = Controles::getInstance();
    con->onTwo();
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
     motor2D->drawCap3();
     motor2D->drawCap1();
     //pintamos a enemigos y jugadores
     if(modo == 1)
     {
         //std::cout << "draw de nivel m 1" << std::endl;
         jugadores[0].draw();
         //jugadores[0].Idle(1);
     }
     else
     {
         //std::cout << "draw de nivel m 2"  << std::endl;
         jugadores[0].draw();
         
         
        //jugadores[0].Idle(1); //Estado default
         jugadores[1].draw();
         //jugadores[1].Idle(1); //Estado default
   
     } 
     //pintamos balas
     
     int contador = 0;
     for(int a = 0; a < bullet.size();a++)
     {
         if(bullet[a]->sigoViva())
            bullet[a]->draw(a);
         else
         {
             
             bool ver = bullet[a]->matarBala(a);
             delete bullet[a];
             bullet[a] = NULL;
             bullet.erase(bullet.begin()+a);
             //std::cout << "se borra bala " << a << "\n";
         }
     }
     
     motor2D->drawCap2();
}

void Nivel::moverJugador(int jugador)
{
    jugadores[jugador].mover();//el mira su estado actual y se movera en consecuencia (aqui deberia ir el stop cuando no se pueda mover a causa de una colision)
        
    //std::cout << "entro en nivel " << jugador << std::endl;
    if (jugadores[jugador].mover() == 1)
    {
        jugadores[jugador].Walk(1);//Función para desplazar a personaje hacia adelante
    
    }
    else if (jugadores[jugador].mover() == 0)
    {
        jugadores[jugador].Idle();//Función de estado default
    }
    
}

void Nivel::moverJugadorAtras(int jugador)
{
    //std::cout << "entro en nivel " << jugador << std::endl;
    jugadores[jugador].moverAtras();//el mira su estado actual y se movera en consecuencia (aqui deberia ir el stop cuando no se pueda mover a causa de una colision)
    
      //std::cout << "entro en nivel " << jugador << std::endl;
    if (jugadores[jugador].moverAtras() == 1)
    {
       
        jugadores[jugador].Walk(-1);//función para desplazar a personaje hacia atrás
    
    }
    else if (jugadores[jugador].moverAtras() == 0)
    {
        jugadores[jugador].Idle();//Función de estado default
    }
}

void Nivel::brincarJugador(int jugador)
{
    jugadores[jugador].mover();//el mira su estado actual y se movera en consecuencia (aqui deberia ir el stop cuando no se pueda mover a causa de una colision)
        
    //std::cout << "entro en nivel " << jugador << std::endl;
    if (jugadores[jugador].mover() == 1)
    {
        jugadores[jugador].Jump();//Función para desplazar que brinque el personaje
    
    }
    else if (jugadores[jugador].mover() == 0)
    {
        jugadores[jugador].Idle();//Función de estado default
    }
    
}

void Nivel::AtaqueCercano(int jugador)
{
    if (jugadores[jugador].isMoving() != 1)
    {
        jugadores[jugador].Kick(); //Función para que el personaje Patee (ataquecercano) 
    }
}

void Nivel::AtaqueLejano(int jugador)
{
    jugadores[jugador].Shoot();//Función para que el personaje Dispare (ataquelejano)
}

void Nivel::IdleJugador(int jugador)
{
    jugadores[jugador].Idle();//Función de estado default
}

void Nivel::BlockJugador(int jugador)
{
    if (jugadores[jugador].isMoving() != 1 )
    {
        jugadores[jugador].Block(); //Función para que el personaje Patee (ataquecercano) 
    }
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

void Nivel::crearBala(int tipo, int elemento, int x, int y, int jugador, int dano)
{
    bullet.push_back(new Bullet(tipo,elemento,x,y,jugador,dano));
}

void Nivel::realimentarBalas()
{
     for(int o = 0; o < bullet.size();o++)
     {
         bullet[o]->realimentar();
     }  
}