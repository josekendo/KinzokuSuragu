/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Els.hpp
 * Author: fv
 *
 * Created on April 29, 2018, 5:03 PM
 */

#ifndef ELS_HPP
#define ELS_HPP
#include "Coordenadas.hpp"
#include "Motor2D.hpp"

class Els {
public:
    Els();
    Els(const Els& orig);
    virtual ~Els();
    
    void initEl(int type);
    void drawEl();
    int getX();
    int getY();
    void ChangeCoords(int x, int y);
private:
    
    Coordenadas coordenadas;//coordenadas del sprite
    int elemento;//
    Motor2D *motor;

};

#endif /* ELS_HPP */

