/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Jugadores.cpp
 * Author: fv
 * 
 * Created on April 5, 2018, 10:07 AM
 */

#include "Jugadores.hpp"
#include "Camara.hpp"
#include <iostream>
#define kVel 2
using namespace std;

Jugadores::Jugadores() 
{
    vida = 100;
    defensa = 0;
    ataque = 4;
    ataquefisico = 7;
    muertes = 0;
    danototal = 0;
    elemento = 0;
    //Fin stats
    motor = Motor2D::getInstance();
    //animacion
    estado = 7;//estados
    frame = 7;//numero de frames
    estado_actual= 0;
    frame_actual=-1;
    frame_refresh=80;//milisegundos
    proximo = 0;
    weapon = 0; //arma con la que inicia
    orientacion = 0;
    stat = 0; //dice si el personaje está en movimiento o no
    
}

Jugadores::Jugadores(const Jugadores& orig) {
}

Jugadores::~Jugadores() {
}


int Jugadores::getVida()
{
    return vida;
}

void Jugadores::addMuerte()
{
    muertes= muertes+1;
}

void Jugadores::Idle(int dir)
{
    estado = 0;
    estado_actual = estado;
    orientacion = dir;
    stat = 0;
    draw();
    
}

void Jugadores::Walk(int dir)
{
    estado = 1;
    estado_actual = estado;
    //SI DIR = 1 VA A LA DERECHA
    //SI DIR = -1 VA A LA IZQUIERDA
    
    orientacion = dir;
    stat = 1;
    if (dir == 1)
    {   
        coordenadas.cambiarPosicion(coordenadas.getCoordenadaXI(motor->darUPDATE())+kVel,coordenadas.getCoordenadaYI(motor->darUPDATE()));
    }
    
    else if (dir == -1)
    {
        coordenadas.cambiarPosicion(coordenadas.getCoordenadaXI(motor->darUPDATE())-kVel,coordenadas.getCoordenadaYI(motor->darUPDATE()));
    }
    
    
    draw();
    std::cout<< "Mover está en estado: " << mover() << std::endl;
}



void Jugadores::Shoot(int dir)
{
    estado = 2;
    estado_actual = estado;
    orientacion = dir;
    stat = 0;
    draw();
    
    
}

void Jugadores::Kick(int dir)
{
    estado = 3;
    estado_actual = estado;
    orientacion = dir;
    stat = 0;
    draw();
    
    
}

void Jugadores::Block(int dir)
{
    estado = 4;
    estado_actual = estado;
    orientacion = dir;
    if (tieneDefensa() == true)
    {
        if(proximo <= motor->darAnimacion()) // ANIMACIÓN DE DEFENSA 
        {
            proximo = motor->darAnimacion()+frame_refresh;

            if(frame > frame_actual)
            {
                frame_actual = frame_actual+1;
            }
            else
            {

            }
        }
        motor->drawPersonaje(player-1,estado_actual,frame_actual, orientacion, coordenadas.getCoordenadaXI(motor->darUPDATE()),coordenadas.getCoordenadaYI(motor->darUPDATE()), stat);
        //CHECK COLISION == FALSE;
    
    }
    
}

void Jugadores::Jump(int dir)
{
    estado = 5;
    estado_actual = estado;
    orientacion = dir;
    frame = 9;
    stat = 0;
    draw();
    
    
}
void Jugadores::Die(int dir)
{
    estado = 6;
    estado_actual = estado;
    //SI DIR = 1 VA A LA DERECHA
    //SI DIR = -1 VA A LA IZQUIERDA
    orientacion = dir;
    
        if(proximo <= motor->darAnimacion()) // ANIMACIÓN DE DEFENSA 
        {
            proximo = motor->darAnimacion()+frame_refresh;

            if(frame > frame_actual)
            {
                frame_actual = frame_actual+1;
            }
            else
            {

            }
        }
        motor->drawPersonaje(player-1,estado_actual,frame_actual, orientacion, coordenadas.getCoordenadaXI(motor->darUPDATE()),coordenadas.getCoordenadaYI(motor->darUPDATE()), stat);
        //CHECK COLISION == FALSE;
}


void Jugadores::addDano(int dano)
{
    danototal = danototal+dano;
}

void Jugadores::cambiarElemento(int element)
{
    if(element >= 0 && element <= 5)
    elemento = element;
}

void Jugadores::setDefensa(int defen)
{
    if(defen >= 0 && defen <= 100)
        defensa = defen;
}

void Jugadores::initJugador(int tip, int play)
{
    //std::cout << play << " tipo textura - " << tip  << " t "<< std::endl;
    motor->initPersonaje(play,tip);
    tipo = tip;
    player = play;
    if(play <= 1)
    {
        coordenadas = Coordenadas(20,220);
    }
    else
    {
        coordenadas = Coordenadas(80,220);
    }
}

void Jugadores::draw()
{
    //std::cout << " x " << coordenadas.getCoordenadaX() << " y " << coordenadas.getCoordenadaY() << std::endl;
    /*comprobamos que animacion sea mayor que el frame que le hayamos dado de refresco*/
    
    if(proximo <= motor->darAnimacion())
    {
        proximo = motor->darAnimacion()+frame_refresh;
        
        if(frame > frame_actual)
        {
            frame_actual = frame_actual+1;
        }
        else
        {
            frame_actual = 0;
        }
    }
    std::cout<< "Se está dibujando el personaje " << std::endl;
    
    if (stat == 1)
    {
        motor->drawPersonaje(player-1,estado_actual,frame_actual,orientacion, coordenadas.getCoordenadaX(),coordenadas.getCoordenadaY(), stat);
    }
    else if (stat == 0)
    {
        motor->drawPersonaje(player-1,estado_actual,frame_actual, orientacion, coordenadas.getCoordenadaXI(motor->darUPDATE()),coordenadas.getCoordenadaYI(motor->darUPDATE()), stat);
    
    }
    
}

bool Jugadores::mover()
{
    //segun estado ponemos una velocidad o otra
    //comprobar colisiones
    //obtenemos la posicion en la que estamos segun su tiempo de interpolacion
    //std::cout << "entro en jugador" << std::endl;
    //int mov = 5;
    int mov = kVel;
    Camara *camara = Camara::getInstance();
    
    if(camara->mePuedoMover(coordenadas.getCoordenadaXI(motor->darUPDATE())+mov,coordenadas.getCoordenadaYI(motor->darUPDATE())))
    {
        //std::cout << "true moviendo" << std::endl;  
        //coordenadas.cambiarPosicion(coordenadas.getCoordenadaXI(motor->darUPDATE())+mov,coordenadas.getCoordenadaYI(motor->darUPDATE()));
       
        return 1;
    }
    else //obtenemos el movimiento maximo
    {
        //std::cout << "false moviendo" << std::endl;
        
        return 0;
    }
        
}

bool Jugadores::moverAtras()
{
    //segun estado ponemos una velocidad o otra
    //comprobar colisiones
    //obtenemos la posicion en la que estamos segun su tiempo de interpolacion
    //std::cout << "entro en jugador" << std::endl;
    //int mov = -5;
    int mov = -kVel;
    Camara *camara = Camara::getInstance();
    
    if(camara->mePuedoMover(coordenadas.getCoordenadaXI(motor->darUPDATE())+mov,coordenadas.getCoordenadaYI(motor->darUPDATE())))
    {
        //std::cout << "true moviendo" << std::endl;  
        //coordenadas.cambiarPosicion(coordenadas.getCoordenadaXI(motor->darUPDATE())+mov,coordenadas.getCoordenadaYI(motor->darUPDATE()));
        
        return  1;
    }
    else //obtenemos el movimiento maximo
    {
        //std::cout << "false moviendo" << std::endl;
       
        return 0;
    }
}

bool Jugadores::tieneDefensa()
{
    if(defensa > 0)
        return true;
    else
        return false;
}

bool Jugadores::setDanoVida(int dano)
{
    if(defensa < dano)
    {
        vida = vida-dano;
    }
    
    if(vida > 0)
        return true;
    else
        return false;
}

bool Jugadores::setVida(int vid)
{
    if(vid < 100)
    {
        if((vid+vida) >= 100)
        {
            vida = 100;
            return true;
        }
        else
        {
            vida = (vid+vida);
            return true;
        }
    }
    
    return false;
}

int Jugadores::getDano(int element,int tipo)
{
    if(element == 0)
    {
        if(tipo == 0)//largos
        return ataque;
        else
        return ataquefisico;
    }
    
    if(element < elemento)
    {
        if(tipo == 0)//largos
        return (ataque*2);
        else
        return (ataquefisico*2);
    }
    
    if(element > elemento)
    {
        if(tipo == 0)//largos
        return (ataque/2);
        else
        return (ataquefisico/2);
    }
    
    return ataque;
}

int Jugadores::getX()
{
    return coordenadas.getCoordenadaX();
}