/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Coordenadas.cpp
 * Author: fv
 * 
 * Created on April 5, 2018, 11:42 AM
 */

#include "Coordenadas.hpp"
#include <iostream>

Coordenadas::Coordenadas() 
{
    x = 0;
    y = 0;
    ay = 0;
    ax = 0;
}

Coordenadas::Coordenadas(int xi, int yi) 
{
    x = xi;
    y = yi;
    ay = yi;
    ax = xi;
}

Coordenadas::Coordenadas(const Coordenadas& orig) {
}

Coordenadas::~Coordenadas() {
}
//cambia la posicion de x e y, copiandolos en ax y ay(Diferentes estados)
void Coordenadas::cambiarPosicion(int xi, int yi)
{
    ax = x;
    ay = y;
    x = xi;
    y = yi;
}
//devuelve las coordenadas x
int Coordenadas::getCoordenadaX()
{
    return x;
}
//devuelve las coordenadas y
int Coordenadas::getCoordenadaY()
{
    return y;
}
//devuelve coordenada interpolada x
int Coordenadas::getCoordenadaXI(float tiempo)
{
    if(x == ax)
    {
        return x;
    }
    else
    {
        float tick;
        tick = (tiempo/(1000/15));

        if(tick > 1)
            tick = 1;
        
        //std::cout << "tick " << tick << std::endl;
        int paso= ax*(1-tick)+x*tick;
        if(paso >= x)
        {
            ax = x;
        }
        return paso;
    }
}
//devuelve coordenada interpolada y
int Coordenadas::getCoordenadaYI(float tiempo)
{
    if(y == ay)
    {
        return y;
    }
    else
    {
        float tick = (tiempo/(1000/15));
        
        if(tick > 1)
            tick = 1;
        
        //std::cout << "tick " << tick << std::endl;
        int paso= ay*(1-tick)+y*tick;
        if(paso >= y)
        {
            ay = y;
        }
        return paso;
    }
}
//cambia las coordenadas pasadas
void Coordenadas::setCoordenadasA(int iax, int iay)
{
    ax = iax;
    ay = iay;
}

//resetea las coordenadas
void Coordenadas::ResetCoordenadas(int xn, int yn)
{
    x = xn;
    y = yn;
    ax = xn;
    ay= yn;
}