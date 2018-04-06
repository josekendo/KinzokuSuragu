/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nivel.hpp
 * Author: fv
 *
 * Created on April 5, 2018, 10:18 AM
 */

#ifndef NIVEL_HPP
#define NIVEL_HPP
#include "FabricarNivel.hpp"

class Nivel {
public:
    //clase singleton
    ~Nivel(void);
    static Nivel *getInstance()
    {
        if(unica_instancia == 0)
        unica_instancia = new Nivel();
        return unica_instancia;  
    }
    //fin singleton public
private:
    //clase singleton 
    Nivel();
    static Nivel* unica_instancia;
    //fin clase singleto private
};

#endif /* NIVEL_HPP */

