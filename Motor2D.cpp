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
#define kVel 1
Motor2D* Motor2D::unica_instancia = 0;

Motor2D::Motor2D() 
{
    window.create(sf::VideoMode(800, 600), "Kinzoku Suragu");
    window.setFramerateLimit(60);
    texturas[0].loadFromFile("resources/SpriteSheet_Character1.png");
    //texturas[1].loadFromFile("resources/SpriteSheet_Character2.png"); FALTA SPRITESHEET JUGADOR 2
    initCamera();
    controles = Controles::getInstance();
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

void Motor2D::drawPersonaje(int player,int esta, int fram, int ori, float x,float y, int st)
{
    //std::cout << "draw de motor2dpersonaje player " << player << " estado " << esta << " frame " << fram <<  "\n x " << x << " y " << y << std::endl;
    //ori = -1;
    if (ori == 1) //SI VA HACIA LA DERECHA
    {
        jugadores[player].setTextureRect(sf::IntRect(fram*48, esta*48,48*ori,48));
        
        if (st == 1)  //SI ESTÁ EN MOVIMIENTO
        {
            jugadores[player].move(kVel, 0);
            x = jugadores[player].getPosition().x;
            jugadores[player].setPosition(x,y);
            
        }
        else if (st == 0)//SI ESTÁ ESTÁTICO
        {
            jugadores[player].setPosition(x,y);
        }
    }
    
    else if (ori == -1) //SI VA HACIA LA IZQUIERDA
    {
        fram = fram + 1;
        jugadores[player].setTextureRect(sf::IntRect(fram*48, esta*48,48*ori,48));
        
        if (st == 1) // SI ESTÁ EN MOVIMIENTO
        {
         jugadores[player].move(-kVel, 0);
         x = jugadores[player].getPosition().x;
         jugadores[player].setPosition(x,y);
        }
        else if (st == 0) // SI ESTÁ ESTÁTICO
        {
            jugadores[player].setPosition(x,y);
        }
    
    }
    
    window.draw(jugadores[player]);
    
    
}
/*void Motor2D::ResetDirPersonaje(int player, int ori)
{
    
    if(player == 1)
    {
        jugadores[player-1].setTextureRect(sf::IntRect(0*48, 0*48, 48*ori,48));
        
    }
    
    if(player == 2)
    {
        jugadores[player-1].setTextureRect(sf::IntRect(0*48, 0*48, 48,48));
        
    }
}*/
void Motor2D::initPersonaje(int player, int tipo)
{
    
    if(player == 1)
    {
        //std::cout << player-1 << " tipo textura 1" << tipo  << " t "<< std::endl;
        jugadores[player-1].setTexture(texturas[tipo]);
        jugadores[player-1].setOrigin(48/2,48/2);
        jugadores[player-1].setTextureRect(sf::IntRect(0*48, 0*48, 48,48));
        jugadores[player-1].scale(sf::Vector2f(2, 2));
    }
    
    if(player == 2)
    {
        //std::cout << player-1 << " tipo textura 2" << tipo  << " t "<< std::endl;
        jugadores[player-1].setTexture(texturas[tipo]);
        jugadores[player-1].setOrigin(48/2,48/2);
        jugadores[player-1].setTextureRect(sf::IntRect(0*48, 0*48, 48,48));
        jugadores[player-1].scale(sf::Vector2f(2, 2));
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


void Motor2D::reiniciarUPDATE()
{
    update.restart();
}

void Motor2D::Inputs()
{
    sf::Event eventos;
    while (window.pollEvent(eventos))
    {
              
            switch(eventos.type){
                //Si se recibe el evento de cerrar la ventana la cierro
                //comprobacion de mandos
                case sf::Event::JoystickButtonPressed:
                    std::cout << "boton:" << eventos.joystickButton.button << std::endl; 
                    break;
                case sf::Event::JoystickMoved:
                    std::cout << "joystick:" << eventos.joystickMove.axis << std::endl;
                    std::cout << "joystick:" << eventos.joystickMove.position << std::endl; 
                    break;
                    //fin mandos
                case sf::Event::Closed:
                    window.close();
                    break;
                //Se pulsó una tecla, imprimo su codigo
                case sf::Event::KeyPressed:
                    
                    if(eventos.key.code == sf::Keyboard::Num1)//un jugador a
                        controles->cambiarControl(1);
                    if(eventos.key.code == sf::Keyboard::Num2)//un jugador b
                        controles->cambiarControl(2);
                    if(eventos.key.code == sf::Keyboard::Num3)//dos jugadores
                        controles->onTwo();
                    if(eventos.key.code == sf::Keyboard::Num4)//dos jugadores
                        controles->offTwo();
                    //Verifico si se pulsa alguna tecla de movimiento
                        //Mapeo del cursor
                        if(controles->whatPlayer(eventos.key.code) == 1)
                        {
                            controles->cambiarControl(1);
                        }
                        else if(controles->whatPlayer(eventos.key.code) == 2)
                        {
                            controles->cambiarControl(2);
                        }
                    
                        if(eventos.key.code == controles->moveRIGHT())
                        std::cout << "derecha" << std::endl;
                        else if(eventos.key.code == controles->moveLEFT())
                        std::cout << "izquierda" << std::endl;   
                        else if(eventos.key.code == controles->moveUP())
                        std::cout << "salto" << std::endl;   
                        else if(eventos.key.code == controles->moveDOWN())
                        std::cout << "caida rapida o agacharse" << std::endl;   
                        else if(eventos.key.code == controles->moveAtaque())
                        std::cout << "ataque" << std::endl;   
                        else if(eventos.key.code == controles->moveDefensa())
                        std::cout << "defensa" << std::endl;   
                        else if(eventos.key.code == controles->moveSalir())
                        window.close();
                              
                    

        }
            
    }
}
int Motor2D::darAnimacion()
{
    return animaciones.getElapsedTime().asMilliseconds();
}

int Motor2D::darUPDATE()
{
    return update.getElapsedTime().asMilliseconds();
}