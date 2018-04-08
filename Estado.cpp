/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estado.cpp
 * Author: fv
 * 
 * Created on April 5, 2018, 10:14 AM
 */

#include "Estado.hpp"
#include "Motor2D.hpp"

void Menu::Draw()
{
     std::cout << "Pintar Menu" << std::endl;
}

void Estadisticas::Draw()
{
     std::cout << "Pintar Estadisticas" << std::endl;
}

void Jugando::Draw()
{
     Motor2D *motor2D = Motor2D::getInstance();//clase global
     
     motor2D->drawCap1();
     motor2D->drawCap2();
     //pintamos a enemigos y jugadores
     motor2D->drawCap3();
     motor2D->mostrar();
     
     std::cout << "Pintar Jugando(Nivel)" << std::endl;
}


