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
#include "Motor2D.hpp"
#include <iostream>

Camara* Camara::unica_instancia = 0;

Camara::Camara() 
{
    x = 400;
    y = 0;
    minLimite = 400;
    maxLimite = 4000;
    Motor2D *motor = Motor2D::getInstance();
    motor->initCamera();
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

void Camara::meMuevo(int xn, int yn)
{
    //std::cout << "Memuevo 0 " << (x+400) << " - " << xn << std::endl;
    if(!block && xn < maxLimite)
    {
        std::cout << "Memuevo 1 " << xn << std::endl;
        if(xn > x+370)
        {
            std::cout << "Memuevo 2 " << xn << std::endl;
            x = x+(xn-(x+370));
        }
    }
}

bool Camara::mePuedoMover(int xn, int yn)
{
    if(!block)
    {
        if(xn < maxLimite)
            return true;
        else
            return false;
    }
    else
    {
        //tenemos que comprobar que no se salga del rango en el que estamos
        if(xn < x)
            return true;
        else
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

void Camara::draw()
{   
    Motor2D *motor = Motor2D::getInstance();
    motor->cambiarPosicionCamera(x,y);
    motor->drawCamera();
}