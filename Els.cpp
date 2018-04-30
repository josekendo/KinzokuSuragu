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

Els::Els() {
}

Els::Els(const Els& orig) {
}

Els::~Els() {
}

void Els::initEl(int type)
{
    elemento = type;
    motor->initEls(type);
    coordenadas = Coordenadas(100,220);
}

void Els::drawEl()
{
    motor->DrawEls(elemento, coordenadas.getCoordenadaX(), coordenadas.getCoordenadaY());
}