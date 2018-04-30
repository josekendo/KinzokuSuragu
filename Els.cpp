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
    elemento = type;
    motor->initEls(type);
    if (type == 0)
        coordenadas = Coordenadas(100,48);
    else if (type == 1)
        coordenadas = Coordenadas(150,48);
    else if (type == 2)
        coordenadas = Coordenadas(200,48);
    else if (type == 3)
        coordenadas = Coordenadas(250,48);
    else if (type == 4)
        coordenadas = Coordenadas(300,48);
    else if (type == 5)
        coordenadas = Coordenadas(350,48);
    else if (type == 6)
        coordenadas = Coordenadas(400,48);
    else if (type == 7)
        coordenadas = Coordenadas(450,48);
    else if (type == 8)
        coordenadas = Coordenadas(500,48);
    else if (type == 9)
        coordenadas = Coordenadas(550,48);
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
