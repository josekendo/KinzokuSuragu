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
    frame = 9;//numero de frames
    estado_actual= 0;
    frame_actual=-1;
    frame_refresh=200;//milisegundos
    proximo = 0;
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
    
    
    motor->drawPersonaje(player-1,estado_actual,frame_actual,coordenadas.getCoordenadaXI(motor->darUPDATE()),coordenadas.getCoordenadaYI(motor->darUPDATE()));
}

void Jugadores::mover()
{
    //segun estado ponemos una velocidad o otra
    //comprobar colisiones
    //obtenemos la posicion en la que estamos segun su tiempo de interpolacion
    //std::cout << "entro en jugador" << std::endl;
    int mov = 5;
    Camara *camara = Camara::getInstance();
    
    if(camara->mePuedoMover(coordenadas.getCoordenadaXI(motor->darUPDATE())+mov,coordenadas.getCoordenadaYI(motor->darUPDATE())))
    {
        //std::cout << "true moviendo" << std::endl;  
        coordenadas.cambiarPosicion(coordenadas.getCoordenadaXI(motor->darUPDATE())+mov,coordenadas.getCoordenadaYI(motor->darUPDATE()));
    }
    else //obtenemos el movimiento maximo
    {
        //std::cout << "false moviendo" << std::endl;
    }
        
}

void Jugadores::moverAtras()
{
    //segun estado ponemos una velocidad o otra
    //comprobar colisiones
    //obtenemos la posicion en la que estamos segun su tiempo de interpolacion
    //std::cout << "entro en jugador" << std::endl;
    int mov = -5;
    Camara *camara = Camara::getInstance();
    
    if(camara->mePuedoMover(coordenadas.getCoordenadaXI(motor->darUPDATE())+mov,coordenadas.getCoordenadaYI(motor->darUPDATE())))
    {
        //std::cout << "true moviendo" << std::endl;  
        coordenadas.cambiarPosicion(coordenadas.getCoordenadaXI(motor->darUPDATE())+mov,coordenadas.getCoordenadaYI(motor->darUPDATE()));
    }
    else //obtenemos el movimiento maximo
    {
        //std::cout << "false moviendo" << std::endl;
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