/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Enemigos.cpp
 * Author: fv
 * 
 * Created on April 5, 2018, 10:07 AM
 */

#include "Enemigos.hpp"

Enemigos::Enemigos() 
{
    vida = 100;
    defensa = 0;
    ataque = 4;
    ataquefisico = 7;
    danototal = 0;
    elemento = 0;
}

Enemigos::Enemigos(int vid, int ataq, int ataqfisico,int element,int defen) 
{
    vida = vid;
    defensa = defen;
    ataque = ataq;
    ataquefisico = ataqfisico;
    danototal = 0;
    elemento = 0;
}

Enemigos::Enemigos(const Enemigos& orig) {
}

Enemigos::~Enemigos() {
}

int Enemigos::getVida()
{
    return vida;
}

void Enemigos::addDano(int dano)
{
    danototal = danototal+dano;
}

void Enemigos::cambiarElemento(int element)
{
    if(element >= 0 && element <= 5)
    elemento = element;
}

void Enemigos::setDefensa(int defen)
{
    if(defen >= 0 && defen <= 100)
        defensa = defen;
}

bool Enemigos::tieneDefensa()
{
    if(defensa > 0)
        return true;
    else
        return false;
}

bool Enemigos::setDanoVida(int dano)
{
    if(defensa < dano)
    {
        vida = vida-dano;
    }
    
    if(vida > 0)
        return true;
    else
        return false;
}

int Enemigos::getDano(int element,int tipo)
{
    if(element == 0)
    {
        if(tipo == 0)//largos
        return ataque;
        else
        return ataquefisico;
    }
    
    if(element < elemento)
    {
        if(tipo == 0)//largos
        return (ataque*2);
        else
        return (ataquefisico*2);
    }
    
    if(element > elemento)
    {
        if(tipo == 0)//largos
        return (ataque/2);
        else
        return (ataquefisico/2);
    }
    
    return ataque;
}