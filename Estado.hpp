/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estado.hpp
 * Author: fv
 *
 * Created on April 5, 2018, 10:14 AM
 */

#ifndef ESTADO_HPP
#define ESTADO_HPP
#include <iostream>

//aqui definimos la clase interfaz de los estados
class Estado {
private:
    //funciones que tiene la interfaz como virtual (porque no existen pero deberian)
    virtual void Draw() = 0;
    virtual int Esta() = 0;    
public:
    void Pintar(){ Draw(); };
    int QueEstado(){ return Esta(); };
};

//diferentes clases de estado
class Menu: public Estado{
    private:
        void Draw();
        int Esta();
};

class Jugando: public Estado{
    private:
        void Draw();
        int Esta();
};

class Estadisticas: public Estado{
    private:
        void Draw();
        int Esta();
};
#endif /* ESTADO_HPP */

