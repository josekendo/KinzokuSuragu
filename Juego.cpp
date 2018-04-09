/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Juego.cpp
 * Author: fv
 * 
 * Created on April 5, 2018, 10:06 AM
 */

#include "Juego.hpp"

Juego* Juego::unica_instancia = 0;

Juego::Juego() 
{
    estado = &menu;
    motor = Motor2D::getInstance();
}

void Juego::cambiarEstado(int est)
{
    switch(est)
    {
        case 1:
            estado = &menu;
            break;
        case 2:
           estado = &jugando;
           break;
        case 3:
            estado = &estadisticas;
    }
}

Juego::~Juego() {
    
}

void Juego::Draw()
{
    estado->Pintar();
}

//Nivel
void Juego::cargarNivel(int niv)
{
    Nivel *nivel = Nivel::getInstance();//clase global
    nivel->cargarNivel(niv);//llamamos a cargar nivel de nivel
}

void Juego::cargaCompleta()
{
    //cambiaremos el estado ya que termino el loading
    cambiarEstado(2);
}

void Juego::Ejecucion()
{
        if(motor->darUPDATE() > 1000/15)
        {
            //en este momento realizamos logica 
            //si hay un boton presionado hacemos la logica que sea
            motor->reiniciarUPDATE();
        }
}

//Menu

//Estadistica
