/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FabricarNivel.h
 * Author: fv
 *
 * Created on March 11, 2018, 4:31 AM
 */

#include "Motor2D.hpp"
#include "Juego.hpp"
#include <iostream>
#include <cstring>
#include <string>
#include "tinyxml.h" //para leer el archivo resources/niveles/"nivel".xml

using namespace std;
#ifndef FABRICARNIVEL_H
#define FABRICARNIVEL_H


class FabricarNivel {
public:
    FabricarNivel();
    FabricarNivel(const FabricarNivel& orig);
    virtual ~FabricarNivel();
    void construirNivel(char nivel[]);
    int numeroNiveles();//devuelve el numero de niveles
private:
    int longitud;//longitud de sprites
    int niveles;
    int* Split(string &cadena,char delimitador);
};

#endif /* FABRICARNIVEL_H */

