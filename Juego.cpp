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

void Juego::Draw()
{
    estado->Pintar();
}