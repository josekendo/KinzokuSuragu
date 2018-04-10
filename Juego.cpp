/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Juego.cpp
 * Author: fv
 * 
 * Created on April 5, 2018, 10:06 AM
 */

#include "Juego.hpp"

Juego* Juego::unica_instancia = 0;

Juego::Juego() 
{
    estado = &menu;
    motor = Motor2D::getInstance();
}

void Juego::cambiarEstado(int est)
{
    switch(est)
    {
        case 1:
            estado = &menu;
            break;
        case 2:
           estado = &jugando;
           break;
        case 3:
            estado = &estadisticas;
    }
}

Juego::~Juego() {
    
}

bool Juego::execVentana()
{
    return motor->execVentana();
}

void Juego::Inputs()
{
    motor->Inputs();
}

void Juego::Draw()
{
    estado->Pintar();
}

void Juego::izquierda(int play)
{
    //jugando
    if(estado->QueEstado() == 2)
    {
    
    }
    //estadistica
    if(estado->QueEstado() == 3)
    {
    
    }
}

void Juego::derecha(int play)
{
    //jugando
    if(estado->QueEstado() == 2)
    {
        Nivel *nivel = Nivel::getInstance();//clase global
        if(play == -1)
        {
            nivel->moverJugador(0);
        }
        else
        {
            nivel->moverJugador(play-1);
        }
    }
    //estadistica
    if(estado->QueEstado() == 3)
    {
    
    }
}

void Juego::salto(int play)
{
    //menu
    if(estado->QueEstado() == 1)
    {
        motor->menuUP();
    }
    //jugando
    if(estado->QueEstado() == 2)
    {
    
    }
    //estadistica
    if(estado->QueEstado() == 3)
    {
    
    }
}

void Juego::agacharse(int play)
{
    //menu
    if(estado->QueEstado() == 1)
    {
        motor->menuDOWN();
    }
    //jugando
    if(estado->QueEstado() == 2)
    {
        
    }
    //estadistica
    if(estado->QueEstado() == 3)
    {
        
    }
}

void Juego::ataque(int play)
{
    //menu
    if(estado->QueEstado() == 1)
    {
        motor->menuSPACE();
    }
    //jugando
    if(estado->QueEstado() == 2)
    {
        
    }
    //estadistica
    if(estado->QueEstado() == 3)
    {
    
    }
}

void Juego::defensa(int play)
{
    //menu
    if(estado->QueEstado() == 1)
    {
        motor->menuATRAS();
    }
    //jugando
    if(estado->QueEstado() == 2)
    {
    
    }
    //estadistica
    if(estado->QueEstado() == 3)
    {
    
    }
}

void Juego::mouse(int boton, int x, int y)
{
    //menu
    if(estado->QueEstado() == 1)
    {
        if(boton == 0)
        {
            motor->menuSPACE(x,y);
        }
        else
        {
            motor->menuATRAS();
        }
    }
    //jugando
    if(estado->QueEstado() == 2)
    {
    
    }
    //estadistica
    if(estado->QueEstado() == 3)
    {
    
    }
}

//Nivel
void Juego::cargarNivel(int niv)
{
    Nivel *nivel = Nivel::getInstance();//clase global
    nivel->cargarNivel(niv);//llamamos a cargar nivel de nivel
}

void Juego::cargaCompleta()
{
    //cambiaremos el estado ya que termino el loading
    cambiarEstado(2);
}

void Juego::Ejecucion()
{
        if(motor->darUPDATE() > 1000/15)
        {
            //en este momento realizamos logica 
            //si hay un boton presionado hacemos la logica que sea
            motor->reiniciarUPDATE();
        }
}

//Menu

//Estadistica
