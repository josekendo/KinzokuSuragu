/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Elementos.cpp
 * Author: fv
 * 
 * Created on April 29, 2018, 12:11 PM
 */

#include "Elementos.hpp"
#include "Camara.hpp"
#include "Nivel.hpp"
//using namespace std;

Elementos::Elementos() 
{
    
    Motor2D *motor = Motor2D::getInstance();
    
}

Elementos::Elementos(const Elementos& orig) {
}

Elementos::~Elementos() {
}


void Elementos::initElemento(int tip, int cant)
{
    //std::cout << play << " tipo textura - " << tip  << " t "<< std::endl;
    motor->initEls(tip);
    
    tipo = tip;
    if (cant = 1)
    {
        if (tip == 0)
        coordenadas = Coordenadas(20,220);
        else if(tip == 1)
            coordenadas = Coordenadas(40,220);
        else if(tip == 2)
            coordenadas = Coordenadas(60,220);
        else if(tip == 3)
            coordenadas = Coordenadas(80,220);
        else if(tip == 4)
            coordenadas = Coordenadas(100,220);
    }
    
    
    // IMPLEMENTAR DOS ELEMENTOS DE CADA UNO
    
    else if (cant = 2)
    {
        if (tip == 0)
        coordenadas = Coordenadas(20,268);
        else if(tip == 1)
            coordenadas = Coordenadas(40,268);
        else if(tip == 2)
            coordenadas = Coordenadas(60,268);
        else if(tip == 3)
            coordenadas = Coordenadas(80,268);
        else if(tip == 4)
            coordenadas = Coordenadas(100,268);
        
        else if(tip == 5)
            coordenadas = Coordenadas(120,268);
        else if(tip == 6)
            coordenadas = Coordenadas(140,268);
        else if(tip == 7)
            coordenadas = Coordenadas(160,268);
        else if(tip == 8)
            coordenadas = Coordenadas(180,268);
        else if(tip == 9)
            coordenadas = Coordenadas(200,268);
    }
    
    
}

void Elementos::drawElemento()
{
    motor->DrawEls(tipo, coordenadas.getCoordenadaX(),coordenadas.getCoordenadaY());
    
}

int Elementos::getX()
{
    return coordenadas.getCoordenadaX();
}

int Elementos::getY()
{
    return coordenadas.getCoordenadaY();
}


bool Elementos::eraseEl(int elemento)
{
    Motor2D *motor = Motor2D::getInstance();
    motor->deleteEl(elemento);
    return true;
}
