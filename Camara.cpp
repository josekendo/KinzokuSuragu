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
#include "Nivel.hpp"
#include <iostream>

Camara* Camara::unica_instancia = 0;

Camara::Camara() 
{
    x = 400;
    y = 0;
    minLimite = 400;
    maxLimite = 11150;
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
        //std::cout << "Memuevo 1 " << xn << std::endl;
        if(xn > x+370)
        {
            //std::cout << "Memuevo 2 " << xn << std::endl;
            x = x+(xn-(x+370));
        }
    }
}

bool Camara::mePuedoMover(int xn, int yn)
{
    Nivel *nivel = Nivel::getInstance();
    if(!block)
    {
        //segun modo de juego se debe hacer una deteccion u otra
        if(nivel->getModo() == 1)
        {
            //en este modo solo tenemos que comprobar que este dentro del rango 
            if(xn < maxLimite && xn > x-380)
                return true;
            else
                return false;
        }
        
        if(nivel->getModo() == 2)
        {
            //en este modo tenemos que comprobar que entre uno y otro no haya mas de 790 puesto que las medidas de la camara son de 800 
            if(xn < maxLimite && xn > x-380)
            {
                //std::cout << nivel->separacion() << "no " << (x+400)-xn<< std::endl;
                if(nivel->separacion() < 750 && (x+400)-xn >= 25)
                {        
                    return true;
                }
                else if(((x+400)-xn) >= 775 && nivel->separacion() >= 750)
                {
                    return true;
                }
                else if(((x+400)-xn) >= 35 && nivel->separacion() >= 750)
                {
                    return true;
                }
            }
            else
                return false;        
        }
    }
    else
    {
        //tenemos que comprobar que no se salga del rango en el que estamos
        if(xn-380 < x  && xn+380 > x)
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