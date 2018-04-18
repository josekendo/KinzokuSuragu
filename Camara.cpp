/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Camara.cpp
 * Author: fv
 * 
 * Created on April 18, 2018, 9:32 AM
 */

#include "Camara.hpp"

Camara* Camara::unica_instancia = 0;

Camara::Camara() 
{
    
}

Camara::~Camara() 
{
    
}

void Camara::bloquear()
{
    block = true;
}

void Camara::desbloquear()
{
    block = false;
}

bool Camara::meMuevo()
{
    return false;
}

bool Camara::mePuedoMover(int xn, int yn)
{
    if(!block)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Camara::coordenadaX()
{
    return x;
}

int Camara::coordenadaY()
{
    return y;
}

void Camara::setCoordenadas(int xn, int yn)
{
    x = xn;
    y = yn;
}