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
    coordenadas = Coordenadas(200,20);
}

void Els::drawEl()
{
    int x = coordenadas.getCoordenadaX();
    int y = coordenadas.getCoordenadaY();
    std::cout<<"Coordenada X: "<<x<<endl;
    std::cout<<"Coordenada Y: "<<y<<endl;
    motor->DrawEls(elemento, coordenadas.getCoordenadaX(), coordenadas.getCoordenadaY());
}