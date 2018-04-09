/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Controles.cpp
 * Author: fv
 * 
 * Created on March 24, 2018, 2:22 PM
 */

#include <SFML/Window/Keyboard.hpp>

#include "Controles.h"

Controles* Controles::unica_instancia = 0;

Controles::Controles()
{
    control=2;//uno es por defecto asdw
    twoPlayer=false;
    //2 son las flechas de control
}

Controles::~Controles(void)
{
    
}

void Controles::cambiarControl(int a)
{
    if(a >= 2)
    control=2;
    if(a < 2)
    control=1;
}

int Controles::getControlInvidual()
{
   return control; 
}

int Controles::whatPlayer(sf::Keyboard::Key key)
{
    if(twoPlayer)
    {
        if(key == sf::Keyboard::W || key == sf::Keyboard::A || key == sf::Keyboard::D || key == sf::Keyboard::S || key == sf::Keyboard::LShift || key == sf::Keyboard::LControl || key == sf::Keyboard::Q ||key == sf::Keyboard::Escape)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    return -1;
}

sf::Keyboard::Key Controles::moveUP()
{
    if(control == 1)
        return sf::Keyboard::W;
    else
        return sf::Keyboard::Up;
}

sf::Keyboard::Key Controles::moveDOWN()
{
    if(control == 1)
        return sf::Keyboard::S;
    else
        return sf::Keyboard::Down;
}

sf::Keyboard::Key Controles::moveLEFT()
{
    if(control == 1)
        return sf::Keyboard::A;
    else
        return sf::Keyboard::Left;
}

sf::Keyboard::Key Controles::moveRIGHT()
{
    if(control == 1)
        return sf::Keyboard::D;
    else
        return sf::Keyboard::Right;
}
//estos en teclado seran fijos pero se cambiaran para gamepad
sf::Keyboard::Key Controles::moveAtaque()
{
    if(control == 1)
    return sf::Keyboard::LShift;
    else
    return sf::Keyboard::RShift;
}

sf::Keyboard::Key Controles::moveDefensa()
{
    if(control == 1)
    return sf::Keyboard::LControl;
    else
    return sf::Keyboard::RControl;
}

sf::Keyboard::Key Controles::moveAtras()
{
    return sf::Keyboard::Escape;
}        

sf::Keyboard::Key Controles::moveSalir()
{
    return sf::Keyboard::Q;
}
//activa dos jugadores
void Controles::onTwo()
{
    twoPlayer = true;
}
//desactiva dos jugadores
void Controles::offTwo()
{
    twoPlayer = false;
}

//---------------------Parte gamepad
//aqui ira el hilo que se encargue de revisar los puertos a ver si se conecta un mando
//segun se vayan conectando se hara una series de comprobaciones para configurar el mando

