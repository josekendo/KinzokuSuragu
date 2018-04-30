/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Els.cpp
 * Author: fv
 * 
 * Created on April 29, 2018, 5:03 PM
 */

#include "Els.hpp"
#include "Camara.hpp"
#include "Nivel.hpp"
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

Els::Els() {
    
    elemento = 0;
    motor = Motor2D::getInstance();
    
}

Els::Els(const Els& orig) {
}

Els::~Els() {
}

void Els::initEl(int type)
{
    for (int i = 0; i < 10; i++ )
    {
        
        posicionesX[i] = rand() % 11100 + 0;
        std::cout<<"PosicionX generada: "<<i<<"  "<<posicionesX[i]<<endl;
        
    }
    srand (time(NULL));
    
    for (int j = 0; j < 10; j++ )
    {
        
        posicionesY[j] = rand() % 300 + 0;
        std::cout<<"PosicionY generada: "<<j<<"  "<<posicionesY[j]<<endl;
        
    }
    srand (1);
    
    
        
    elemento = type;
    motor->initEls(type);
    if (type == 0)
        coordenadas = Coordenadas(0+posicionesX[0],48-posicionesY[0]);
    else if (type == 1)
        coordenadas = Coordenadas(0+posicionesX[1],48-posicionesY[1]);
    else if (type == 2)
        coordenadas = Coordenadas(0+posicionesX[2],48-posicionesY[2]);
    else if (type == 3)
        coordenadas = Coordenadas(0+posicionesX[3],48-posicionesY[3]);
    else if (type == 4)
        coordenadas = Coordenadas(0+posicionesX[4],48-posicionesY[4]);
    else if (type == 5)
        coordenadas = Coordenadas(0+posicionesX[5],48-posicionesY[5]);
    else if (type == 6)
        coordenadas = Coordenadas(0+posicionesX[6],48-posicionesY[6]);
    else if (type == 7)
        coordenadas = Coordenadas(0+posicionesX[7],48-posicionesY[7]);
    else if (type == 8)
        coordenadas = Coordenadas(0+posicionesX[8],48-posicionesY[8]);
    else if (type == 9)
        coordenadas = Coordenadas(0+posicionesX[9],48-posicionesY[9]);
}

void Els::drawEl()
{
    motor->DrawEls(elemento, coordenadas.getCoordenadaX(), coordenadas.getCoordenadaY());
}

int Els::getX()
{
    return coordenadas.getCoordenadaX();
}

int Els::getY()
{
    return coordenadas.getCoordenadaY();
}

void Els::ChangeCoords(int x, int y)
{
    coordenadas.ResetCoordenadas(x, y);

}
