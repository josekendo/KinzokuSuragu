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
#include "Juego.hpp"

#define kVel 1
Motor2D* Motor2D::unica_instancia = 0;

Motor2D::Motor2D() 
{
    window.create(sf::VideoMode(800, 600), "Kinzoku Suragu");
    initMenu();
    window.setFramerateLimit(60);
    fuent.loadFromFile("resources/Menu/fuente.ttf");
    texturas[0].loadFromFile("resources/SpriteSheet_Character1.png");
    //texturas[1].loadFromFile("resources/SpriteSheet_Character2.png"); FALTA SPRITESHEET JUGADOR 2
    texturas[3].loadFromFile("resources/Hud/life.png");
    texturas[4].loadFromFile("resources/Hud/defense.png");
    texturas[5].loadFromFile("resources/Hud/loa.png");
    initCamera();
    controles = Controles::getInstance();
    initMenu();
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

void Motor2D::initMenu()
{
    menus = new Menus(window.getSize().x,window.getSize().y,0);
}

void Motor2D::drawMenu()
{
    menus->draw(window);
}

void Motor2D::drawCap1()
{
    window.draw(ca1);
}

void Motor2D::drawCap2()
{
    window.draw(ca2);
}

void Motor2D::drawCap3()
{
    window.clear(sf::Color::Black);
    window.draw(ca3);
}

void Motor2D::mostrar()
{
    window.display();
}

void Motor2D::drawPersonaje(int player,int esta, int fram, int ori, float x,float y, int st)
{
    //std::cout << "draw de motor2dpersonaje player " << player << " estado " << esta << " frame " << fram <<  "\n x " << x << " y " << y << std::endl;
    if (ori == -1)
    {
        fram = fram + 1;
    }
    jugadores[player].setTextureRect(sf::IntRect(fram*48, esta*48, 48*ori,48));
    jugadores[player].setPosition(x,y);
    Camara *camara = Camara::getInstance();
    camara->meMuevo(x,y);
    
    /*if (ori == 1) //SI VA HACIA LA DERECHA
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
    
    }*/
    

    window.draw(jugadores[player]);
}
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

void Motor2D::cambiarPosicionCamera(int x, int y)
{
    camera.setCenter(x,y);
}

void Motor2D::reiniciarUPDATE()
{
    update.restart();
}

void Motor2D::Inputs()
{
    sf::Event eventos;
    Juego *juego = Juego::getInstance();
    
    while (window.pollEvent(eventos))
    {
              
            switch(eventos.type){
                //Si se recibe el evento de cerrar la ventana la cierro
                //comprobacion de mandos
                case sf::Event::MouseButtonPressed:
                    // std::cout << "mouse:" << eventos.mouseButton.button << eventos.mouseButton.y << std::endl;
                     juego->mouse(eventos.mouseButton.button,eventos.mouseButton.x,eventos.mouseButton.y);
  
                break;
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
                            controles->pr(controles->whatPlayer(eventos.key.code));
                        else if(eventos.key.code == controles->moveLEFT())
                            controles->pl(controles->whatPlayer(eventos.key.code));
                        else if(eventos.key.code == controles->moveUP())
                            controles->pu(controles->whatPlayer(eventos.key.code));
                        else if(eventos.key.code == controles->moveDOWN())
                            controles->pd(controles->whatPlayer(eventos.key.code));
                        else if(eventos.key.code == controles->moveAtaque())
                            controles->pa(controles->whatPlayer(eventos.key.code));
                        else if(eventos.key.code == controles->moveDefensa())
                            controles->pf(controles->whatPlayer(eventos.key.code));
                        else if(eventos.key.code == controles->moveSalir())
                            window.close();
                        
                        break;
                case sf::Event::KeyReleased:
                        if(eventos.key.code == controles->moveRIGHT())
                            controles->dr(controles->whatPlayer(eventos.key.code));
                        else if(eventos.key.code == controles->moveLEFT())
                            controles->dl(controles->whatPlayer(eventos.key.code));
                        else if(eventos.key.code == controles->moveUP())
                            controles->du(controles->whatPlayer(eventos.key.code));
                        else if(eventos.key.code == controles->moveDOWN())
                            controles->dd(controles->whatPlayer(eventos.key.code));
                        else if(eventos.key.code == controles->moveAtaque())
                            controles->da(controles->whatPlayer(eventos.key.code));
                        else if(eventos.key.code == controles->moveDefensa())
                            controles->df(controles->whatPlayer(eventos.key.code));
        }
            
    }
}

void Motor2D::menuUP()
{
    menus->MoverArriba();
}

void Motor2D::menuDOWN()
{
    menus->MoverAbajo();
}

void Motor2D::menuIZQ()
{
    
}

void Motor2D::menuDER()
{
    
}

void Motor2D::menuSPACE()
{
    menus->Intro();
}

void Motor2D::menuSPACE(int x, int y)
{
    menus->Intro(x,y);
}

void Motor2D::menuSALIR()
{
    menus->Intro();
}

void Motor2D::menuATRAS()
{
    menus->volverMenus();
}
int Motor2D::darAnimacion()
{
    return animaciones.getElapsedTime().asMilliseconds();
}

int Motor2D::darUPDATE()
{
    return update.getElapsedTime().asMilliseconds();
}

void Motor2D::crearBala(int tipo, int elemento)
{
    if(tipo == 0)//jugadores
    {
        sf::Sprite *bala = new sf::Sprite;
        bala->setTexture(texturas[3]);
        bala->setTextureRect(sf::IntRect(0, 0, 15,14));
        
        //color elemento
        if(elemento == 0)
            bala->setColor(sf::Color::White);
        else if(elemento == 1)
            bala->setColor(sf::Color::Blue);
        else if(elemento == 2)
            bala->setColor(sf::Color::Cyan);
        else if(elemento == 3)
            bala->setColor(sf::Color::Green);
        else if(elemento == 4)
            bala->setColor(sf::Color::Magenta);
        else if(elemento == 5)
            bala->setColor(sf::Color::Red);
            
        bullets.push_back(bala);
        //std::cout << "bullets guarda " << int(bullets.size()) << " numero de balas.\n";
    }
}

void Motor2D::drawBala(int point,int x, int y)
{
    bullets[point]->setPosition(x,y);
    window.draw(*bullets[point]);
    //std::cout << "bullets guarda " << bullets[point]->getPosition().x << " numero de balas. "<< bullets[point]->getPosition().y << "\n";
    //std::cout << "bullets guarda " << x << " numero de balas. "<< y << "\n";
}

void Motor2D::matarBala(int point)
{
    delete bullets[point];
    bullets[point] = NULL;
    bullets.erase(bullets.begin()+point);
    //std::cout << "se borra bala-sprite " << point << "\n";
}

void Motor2D::initHud(int player)
{   
    if(player <= 1)
    {
        hud1 = sf::View(sf::FloatRect(0, 0, 100, 100));
        marcadores[0].setTexture(texturas[3]);
        marcadores[1].setTexture(texturas[4]);
        marcadores[2].setTexture(texturas[5]);
        marcadores[0].setTextureRect(sf::IntRect(0,0,15,14));
        marcadores[1].setTextureRect(sf::IntRect(0,0,15,16));
        marcadores[2].setTextureRect(sf::IntRect(0,0,11,8));
        marcadores[0].setOrigin(15/2,14/2);
        marcadores[1].setOrigin(15/2,16/2);
        marcadores[2].setOrigin(11/2,8/2);
        marcadores[0].setPosition(265,-26);
        marcadores[1].setPosition(265,-1);
        marcadores[2].setPosition(265,24);
        textos[0].setFont(fuent);
        textos[0].setColor(sf::Color::Red);
        textos[0].setString("0");        
        textos[0].setPosition(280,-50);
        textos[1].setFont(fuent);
        textos[1].setColor(sf::Color::Green);
        textos[1].setString("0");        
        textos[1].setPosition(280,-25);
        textos[2].setFont(fuent);
        textos[2].setColor(sf::Color::Blue);
        textos[2].setString("0");        
        textos[2].setPosition(280,0);
        hud1.setCenter(300,0);
        hud1.setViewport(sf::FloatRect(0.0f, 0, 0.25f, 0.25f));
    }
    
    if(player == 2)
    {
        hud2 = sf::View(sf::FloatRect(0, 0, 100, 100));
        marcadores[3].setTexture(texturas[3]);
        marcadores[4].setTexture(texturas[4]);
        marcadores[5].setTexture(texturas[5]);
        marcadores[3].setTextureRect(sf::IntRect(0,0,15,14));
        marcadores[4].setTextureRect(sf::IntRect(0,0,15,16));
        marcadores[5].setTextureRect(sf::IntRect(0,0,11,8));
        marcadores[3].setOrigin(15/2,14/2);
        marcadores[4].setOrigin(15/2,16/2);
        marcadores[5].setOrigin(11/2,8/2);
        marcadores[3].setPosition(265,-26);
        marcadores[4].setPosition(265,-1);
        marcadores[5].setPosition(265,24);
        textos[3].setFont(fuent);
        textos[3].setColor(sf::Color::Red);
        textos[3].setString("0");        
        textos[3].setPosition(280,-50);
        textos[4].setFont(fuent);
        textos[4].setColor(sf::Color::Green);
        textos[4].setString("0");        
        textos[4].setPosition(280,-25);
        textos[5].setFont(fuent);
        textos[5].setColor(sf::Color::Blue);
        textos[5].setString("0");        
        textos[5].setPosition(280,0);
        hud2.setCenter(300,0);
        hud2.setViewport(sf::FloatRect(0.85f, 0, 0.25f, 0.25f));
    }
}

void Motor2D::drawHud(int player)
{
    Hud *hud = Hud::getInstance();
    if(player <= 1)
    {       
        std::cout << "se pinta draw hud1" << "\n";
        window.setView(hud1);
        textos[0].setString(to_string(hud->getVida(1)));
        window.draw(textos[0]);
        textos[1].setString(to_string(hud->getDefensa(1)));
        window.draw(textos[1]);
        textos[2].setString(to_string(hud->getMunicion(1)));
        window.draw(textos[2]);
        window.draw(marcadores[0]);
        window.draw(marcadores[1]);
        window.draw(marcadores[2]);
    }
    
    if(player == 2)
    {
        std::cout << "se pinta draw hud2" << "\n";
        window.setView(hud2);
        textos[3].setString(to_string(hud->getVida(2)));
        window.draw(textos[3]);
        textos[4].setString(to_string(hud->getDefensa(2)));
        window.draw(textos[4]);
        textos[5].setString(to_string(hud->getMunicion(2)));
        window.draw(textos[5]);
        window.draw(marcadores[3]);
        window.draw(marcadores[4]);
        window.draw(marcadores[5]);
    }
}