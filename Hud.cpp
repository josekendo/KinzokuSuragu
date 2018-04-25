/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hud.cpp
 * Author: fv
 * 
 * Created on April 25, 2018, 7:38 AM
 */

#include "Hud.hpp"

Hud* Hud::unica_instancia = 0;

Hud::Hud() 
{
    vidas[0]=100;
    vidas[1]=100;
    defensas[0]=0;
    defensas[0]=0;
    municiones[0]=0;//infinita
    municiones[0]=0;//infinita
}

Hud::~Hud(void) 

{
    
}

void Hud::cambiarDefensa(int player, int defensa)
{
    if(player <= 1)
    {
        defensas[0] = defensa;
    }
    
    if(player == 2)
    {
        defensas[1] = defensa;
    }  
}

void Hud::cambiarVida(int player, int vida)
{
    if(player <= 1)
    {
        vidas[0] = vida;
    }
    
    if(player == 2)
    {
        vidas[1] = vida;
    }    
}

void Hud::cambiarMunicion(int player, int municion)
{
    if(player <= 1)
    {
        municiones[0] = municion;
    }
    
    if(player == 2)
    {
        municiones[1] = municion;
    }
}

void Hud::draw(int modo)
{
    if(modo == 1)
    {
        //pinto hud1
        
    }
    else
    {
        //pinto hud1 
        
        //pinto hud2
        
    }
}
