/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nivel.cpp
 * Author: fv
 * 
 * Created on April 5, 2018, 10:18 AM
 */

#include "Nivel.hpp"
#include <iostream>

Nivel* Nivel::unica_instancia = 0;

Nivel::Nivel() 
{
    
}

void Nivel::cargarNivel(int niv)
{
    switch(niv)
    {
        case 1:
            fabrica.construirNivel("resources/niveles/1.xml");
        break;
        case 2:
            fabrica.construirNivel("resources/niveles/2.xml");
        break;
        case 3:
            fabrica.construirNivel("resources/niveles/3.xml");
        break;
        case 4:
            fabrica.construirNivel("resources/niveles/4.xml");
        break;
    }
}

