/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Elementos.hpp
 * Author: fv
 *
 * Created on April 29, 2018, 12:11 PM
 */

#ifndef ELEMENTOS_HPP
#define ELEMENTOS_HPP
#include "Coordenadas.hpp"
#include "Motor2D.hpp"
#include <iostream>

class Elementos {
public:
    Elementos();
    Elementos(const Elementos& orig);
    virtual ~Elementos();
    void initElemento(int tip, int cant);
    void drawElemento();
    int getX();
    int getY();
    bool eraseEl(int elemento);
    
private:
     
    Coordenadas coordenadas;//coordenadas del sprite
    Motor2D *motor;
    int tipo;
};

#endif /* ELEMENTOS_HPP */

