/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Motor2D.hpp
 * Author: fv
 *
 * Created on April 5, 2018, 10:08 AM
 */

#ifndef MOTOR2D_HPP
#define MOTOR2D_HPP
//clases basicas
#include <SFML/Graphics.hpp>
//fin clases basicas

class Motor2D {
public:
    //clase singleton
    ~Motor2D(void);
    static Motor2D *getInstance()
    {
        if(unica_instancia == 0)
        unica_instancia = new Motor2D();
        return unica_instancia;  
    }
    //fin singleton public
private:
    //clase singleton 
    Motor2D();
    static Motor2D* unica_instancia;
    //fin clase singleto private
};

#endif /* MOTOR2D_HPP */

