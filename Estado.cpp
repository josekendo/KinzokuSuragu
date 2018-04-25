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
#include "Nivel.hpp"
#include "Hud.hpp"

void Menu::Draw()
{
     Motor2D *motor2D = Motor2D::getInstance();//clase global
     Camara *camara = Camara::getInstance();
     camara->draw();
     motor2D->drawMenu();
     motor2D->mostrar();    
}

int Menu::Esta()
{
    return 1;
}

void Estadisticas::Draw()
{
     std::cout << "Pintar Estadisticas" << std::endl;
}

int Estadisticas::Esta()
{
    return 3;
}

void Jugando::Draw()
{
     Motor2D *motor2D = Motor2D::getInstance();//clase global
     Nivel *nivel = Nivel::getInstance();//clase global
     Hud *hud = Hud::getInstance();
     Camara *camara = Camara::getInstance();
     camara->draw();
     nivel->draw();
     hud->draw(nivel->getModo());
     motor2D->mostrar();
     //std::cout << "Pintar Jugando(Nivel)" << std::endl;
}

int Jugando::Esta()
{
    return 2;
}