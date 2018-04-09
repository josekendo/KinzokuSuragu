/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Motor2D.cpp
 * Author: fv
 * 
 * Created on April 5, 2018, 10:08 AM
 */

#include "Motor2D.hpp"
#include <iostream>

Motor2D* Motor2D::unica_instancia = 0;

Motor2D::Motor2D() 
{
    window.create(sf::VideoMode(800, 600), "Kinzoku Suragu");
    window.setFramerateLimit(60);
    texturas[0].loadFromFile("resources/pp.png");
    initCamera();
}

bool Motor2D::cargarCapa(int* matriz, int capa, int longitud, int anchura, int altura, char tileset[])
{
    switch(capa)
    {
        case 1:
            if (ca1.load(tileset, sf::Vector2u(longitud, longitud), matriz, anchura, altura))
                ca1.setPosition(0,43);
        break;
        case 2:
            if (ca2.load(tileset, sf::Vector2u(longitud, longitud), matriz, anchura, altura))
                ca2.setPosition(0,43);
        break;
        case 3:
            if (ca3.load(tileset, sf::Vector2u(longitud, longitud), matriz, anchura, altura))
                ca3.setPosition(0,43);
        break;
    }
}

bool Motor2D::execVentana()
{
    return window.isOpen();
}

sf::RenderWindow& Motor2D::getVentana()
{
    return window;
}

void Motor2D::drawCap1()
{
    window.clear(sf::Color::Black);
    window.draw(ca1);
}

void Motor2D::drawCap2()
{
    window.draw(ca2);
}

void Motor2D::drawCap3()
{
    window.draw(ca3);
}

void Motor2D::mostrar()
{
    window.display();
}

void Motor2D::drawPersonaje(int player,int esta, int fram, float x,float y)
{
    //std::cout << "draw de motor2dpersonaje player " << player << " estado " << esta << " frame " << fram <<  "\n x " << x << " y " << y << std::endl;
    jugadores[player].setTextureRect(sf::IntRect(fram*228, esta*300, 228,300));
    jugadores[player].setPosition(x,y);
    window.draw(jugadores[player]);
}

void Motor2D::initPersonaje(int player, int tipo)
{
    
    if(player == 1)
    {
        //std::cout << player-1 << " tipo textura 1" << tipo  << " t "<< std::endl;
        jugadores[player-1].setTexture(texturas[tipo]);
        jugadores[player-1].setOrigin(228/2,300/2);
        jugadores[player-1].setTextureRect(sf::IntRect(0*228, 0*300, 228,300));
        jugadores[player-1].scale(sf::Vector2f(0.3f, 0.3f));
    }
    
    if(player == 2)
    {
        //std::cout << player-1 << " tipo textura 2" << tipo  << " t "<< std::endl;
        jugadores[player-1].setTexture(texturas[tipo]);
        jugadores[player-1].setOrigin(228/2,300/2);
        jugadores[player-1].setTextureRect(sf::IntRect(0*228, 0*300, 228,300));
        jugadores[player-1].scale(sf::Vector2f(0.3f, 0.3f));
    }
}

void Motor2D::initCamera()
{
    camera = sf::View(sf::FloatRect(0, 0, 800, 600));
    camera.setCenter(400,0);
}

void Motor2D::drawCamera()
{
    window.setView(camera);
}

int Motor2D::darUPDATE()
{
    return update.getElapsedTime().asMilliseconds();
}

void Motor2D::reiniciarUPDATE()
{
    update.restart();
}

int Motor2D::darAnimacion()
{
    return animaciones.getElapsedTime().asMilliseconds();
}