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
#include "Colision.hpp"
#include "SFML/Audio.hpp"


#define kVel 1

Motor2D* Motor2D::unica_instancia = 0;

Motor2D::Motor2D() 
{
    window.create(sf::VideoMode(800, 600), "Kinzoku Suragu");
    initMenu();
    window.setFramerateLimit(60);
    fuent.loadFromFile("resources/Menu/fuente.ttf");
    texturas[0].loadFromFile("resources/SpriteSheet_Character1.png");
    texturas[1].loadFromFile("resources/SpriteSheet_Character2.png");
    texturas[2].loadFromFile("resources/Bullet_Sprites_New.png");
    //texturas[1].loadFromFile("resources/SpriteSheet_Character2.png"); FALTA SPRITESHEET JUGADOR 2
    texturas[3].loadFromFile("resources/Hud/life.png");
    texturas[4].loadFromFile("resources/Hud/defense.png");
    texturas[5].loadFromFile("resources/Hud/loa.png");
    texturas[6].loadFromFile("resources/blob.png");
    texturas[7].loadFromFile("resources/miniblob.png");
    texturas[8].loadFromFile("resources/wizard3.png");
    texturas[9].loadFromFile("resources/aliendog2.png");
    texturas[10].loadFromFile("resources/zombiewalk2.png");
    texturas[11].loadFromFile("resources/saiyan2.png");
    texturas[12].loadFromFile("resources/Element_SpriteS.png");
    texturas[13].loadFromFile("resources/bala1.png");
    texturas[14].loadFromFile("resources/bala2.png");
    texturas[15].loadFromFile("resources/bala3.png");
    sb[0].loadFromFile("resources/giro2.ogg");
    sb[1].loadFromFile("resources/deslizar.ogg");
    sb[2].loadFromFile("resources/shot1.ogg");
    sb[3].loadFromFile("resources/dog1.ogg");
    sb[4].loadFromFile("resources/zombiesound4.ogg");
    sb[5].loadFromFile("resources/shot3.ogg");
    sound[0].setBuffer(sb[0]);
    sound[0].setLoop(true);
    sound[0].setVolume(75);
    sound[1].setBuffer(sb[1]);
    sound[1].setLoop(true);
    sound[1].setVolume(50);
    sound[2].setBuffer(sb[2]);
    sound[2].setLoop(true);
    sound[2].setVolume(50);
    sound[3].setBuffer(sb[3]);
    sound[3].setLoop(true);
    sound[3].setVolume(50);
    sound[4].setBuffer(sb[4]);
    sound[4].setLoop(true);
    sound[5].setBuffer(sb[5]);
    sound[5].setLoop(true);
    sound[5].setVolume(25);
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
                ca1.setPosition(-32,-532);
            colision->generarMatriz(matriz,capa,anchura,altura);
        break;
        case 2:
            if (ca2.load(tileset, sf::Vector2u(longitud, longitud), matriz, anchura, altura))
                ca2.setPosition(-32,-532);
            colision->generarMatriz(matriz,capa,anchura,altura);
        break;
        case 3:
            if (ca3.load(tileset, sf::Vector2u(longitud, longitud), matriz, anchura, altura))
                ca3.setPosition(-32,-532);
            colision->generarMatriz(matriz,capa,anchura,altura);
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

void Motor2D::drawPersonaje(int player,int esta, int fram, int ori, float x,float y)
{
    //std::cout << "draw de motor2dpersonaje player " << player << " estado " << esta << " frame " << fram <<  "\n x " << x << " y " << y << std::endl;
    if (ori == -1)
    {
        fram = fram + 1;
    }
    
    
    jugadores[player].setTextureRect(sf::IntRect(fram*48, (esta*48)+8, 48*ori, 32));
    jugadores[player].setPosition(x,y);
    Camara *camara = Camara::getInstance();
    camara->meMuevo(x,y);
    
    

    window.draw(jugadores[player]);
}


void Motor2D::initPersonaje(int player, int tipo)
{
    
    if(player == 1)
    {
        //std::cout << player-1 << " tipo textura 1" << tipo  << " t "<< std::endl;
        jugadores[player-1] = sf::Sprite();
        jugadores[player-1].setTexture(texturas[tipo]);
        jugadores[player-1].setOrigin(48/2,32/2);
        jugadores[player-1].setTextureRect(sf::IntRect(0*48, 0*48 + 8, 48, 32));
        jugadores[player-1].scale(sf::Vector2f(2, 2));
    }
    
    if(player == 2)
    {
        //std::cout << player-1 << " tipo textura 2" << tipo  << " t "<< std::endl;
        jugadores[player-1] = sf::Sprite();
        jugadores[player-1].setTexture(texturas[tipo]);
        jugadores[player-1].setOrigin(48/2,32/2);
        jugadores[player-1].setTextureRect(sf::IntRect(0*48, 0*48 + 8, 48, 32));
        jugadores[player-1].scale(sf::Vector2f(2, 2));
    }
}

void Motor2D::drawEnemigo(int enemigo,int esta, int fram, int ori, float x,float y)
{
    enemigos[enemigo].setPosition(x,y);
    if (ori == -1)
    {
        fram = fram + 1;
    }
    if(enemigo==0){
    enemigos[enemigo].setTextureRect(sf::IntRect(fram*80, esta*300, ori*80,80));
    if(sound[0].getStatus()!=sf::Sound::Playing){
        sound[0].play();
    }
    }
    else if(enemigo==1){
    enemigos[enemigo].setTextureRect(sf::IntRect(fram*80, esta*300, ori*80,80));
    if(sound[1].getStatus()!=sf::Sound::Playing){
        sound[1].play();
    }
    }
    else if(enemigo==2){
    enemigos[enemigo].setTextureRect(sf::IntRect(fram*640, esta*750, ori*640, 750));
    if(sound[2].getStatus()!=sf::Sound::Playing){
        sound[2].play();
    }
    }
    else if(enemigo==3){
    enemigos[enemigo].setTextureRect(sf::IntRect(fram*65, esta*300, ori*65, 32));
    if(sound[3].getStatus()!=sf::Sound::Playing){
        sound[3].play();
    }
    }
    else if(enemigo==4){
    enemigos[enemigo].setTextureRect(sf::IntRect(fram*392, esta*550, ori*392, 550));
    if(sound[4].getStatus()!=sf::Sound::Playing){
        sound[4].play();
    }
    }
    else if(enemigo==5){
    enemigos[enemigo].setTextureRect(sf::IntRect(fram*95, esta*95, ori*95, 95));
    if(sound[5].getStatus()!=sf::Sound::Playing){
        sound[5].play();
    }
    }
    window.draw(enemigos[enemigo]);
}


void Motor2D::initEnemigo(int enemigo, int tipo)
{
    if(tipo == 0)//jugadores
    {
        sf::Sprite *enemy = new sf::Sprite;
        enemy->setTexture(texturas[6]);
        enemy->setTextureRect(sf::IntRect(0, 0, 15,14));
        tip = enemigo;
        enemigos[enemigo] = sf::Sprite();
        if(enemigo == 0){
        enemigos[enemigo].setTexture(texturas[6]);
        enemigos[enemigo].setOrigin(228/2,350/2);
        enemigos[enemigo].setTextureRect(sf::IntRect(0*80, 0*300, 80,80));
        enemigos[enemigo].scale(sf::Vector2f(1.5f, 1.5f));
        }
        else if(enemigo == 1){
        enemigos[enemigo].setTexture(texturas[7]);
        enemigos[enemigo].setOrigin(228/2,400/2);
        enemigos[enemigo].setTextureRect(sf::IntRect(0*80, 0*300, 80,80));
        enemigos[enemigo].scale(sf::Vector2f(1.0f, 1.0f));
        }
        else if(enemigo == 2){
        enemigos[enemigo].setTexture(texturas[8]);
        enemigos[enemigo].setOrigin(600/2,2600/2);
        enemigos[enemigo].setTextureRect(sf::IntRect(0*640, 0*750, 640, 750));
        enemigos[enemigo].scale(sf::Vector2f(0.2f, 0.2f));
        }
        else if(enemigo == 3){
        enemigos[enemigo].setTexture(texturas[9]);
        enemigos[enemigo].setOrigin(228/2,300/2);
        enemigos[enemigo].setTextureRect(sf::IntRect(0*65, 0*300, 65, 32));
        enemigos[enemigo].scale(sf::Vector2f(1.5f, 1.5f));
        }
        else if(enemigo == 4){
        enemigos[enemigo].setTexture(texturas[10]);
        enemigos[enemigo].setOrigin(228/2,2800/2);
        enemigos[enemigo].setTextureRect(sf::IntRect(0*392, 0*550, 392, 550));
        enemigos[enemigo].scale(sf::Vector2f(0.2f, 0.2f));
        }
        else if(enemigo == 5){
        enemigos[enemigo].setTexture(texturas[11]);
        enemigos[enemigo].setOrigin(228/2,240/2);
        enemigos[enemigo].setTextureRect(sf::IntRect(0*95, 0*95, 95, 95));
        enemigos[enemigo].scale(sf::Vector2f(3.0f, 3.0f));
        }
            
    }
    
}

void Motor2D::matarEnemigo(int point)
{
    Juego *juego = Juego::getInstance();
    if(juego->queEstado()==2){
    if(point==2||point==5){
    juego->finalNivel();
    }
    }
    if(sound[point].getStatus()==sf::Sound::Playing){
    sound[point].stop();
    }
    
}

void Motor2D::desactivarSonidos()
{
    
    for(int i=0;i<6;i++){
    if(sound[i].getStatus()==sf::Sound::Playing){
    sound[i].stop();
    }
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
    int contro;
    contro = 0; 
    sf::Vector2f movimiento;
            
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
                      
                    if(eventos.joystickButton.joystickId == 0)
                    {
                        //control 1
                        contro = 1;
                    }
                    else
                    {
                        //control 2
                        contro = 2;
                    }
                    
                    if(eventos.joystickButton.button == 13)
                    {
                        //ARRIBA
                        controles->pu(contro);
                    }
                    if(eventos.joystickButton.button == 15)
                    {
                        //IZQUIERDA
                        controles->pl(contro);
                    }
                    if(eventos.joystickButton.button == 16)
                    {
                        //DERECHA
                        controles->pr(contro);
                    }
                    if(eventos.joystickButton.button == 14)
                    {
                        //ABAJO
                        controles->pd(contro);
                    }
                    if(eventos.joystickButton.button == 2)
                    {
                        //cuerpo a cuerpo
                        controles->pd(contro);
                    }
                    if(eventos.joystickButton.button == 1)
                    {
                        //DEFENSA
                        controles->pf(contro);
                    }
                    if(eventos.joystickButton.button == 0)
                    {
                        //ATAQUE
                        controles->pa(contro);
                    }
                    if(eventos.joystickButton.button == 8)
                    {
                        //SALIR
                        if(contro == 1)
                        {  
                            if(juego->queEstado() == 1)
                            {
                                std::cout << "salir"<<"\n";
                                window.close();
                            }
                            else
                            {
                                juego->finalNivel();
                            }
                        }
                    }
                    break;
                case sf::Event::JoystickButtonReleased:
                    if(eventos.joystickButton.joystickId == 0)
                    {
                        //control 1
                        contro = 1;
                    }
                    else
                    {
                        //control 2
                        contro = 2;
                    }
                    if(eventos.joystickButton.button == 13)
                    {
                        //ARRIBA
                        controles->du(contro);
                    }
                    if(eventos.joystickButton.button == 15)
                    {
                        //IZQUIERDA
                        controles->dl(contro);
                    }
                    if(eventos.joystickButton.button == 16)
                    {
                        //DERECHA
                        controles->dr(contro);
                    }
                    if(eventos.joystickButton.button == 14)
                    {
                        //ABAJO
                        controles->dd(contro);
                    }
                    if(eventos.joystickButton.button == 2)
                    {
                        //ataque cuerpo a cuerpo
                        controles->dd(contro);
                    }
                    if(eventos.joystickButton.button == 1)
                    {
                        //DEFENSA
                        controles->df(contro);
                    }
                    if(eventos.joystickButton.button == 0)
                    {
                        
                        //ATAQUE
                        controles->da(contro);
                    }
                    break;
                case sf::Event::JoystickMoved:
                    if(eventos.joystickMove.joystickId == 0)
                    {
                        //control 1
                        contro = 1;
                    }
                    else
                    {
                        //control 2
                        contro = 2;
                    }
                    
                    movimiento = sf::Vector2f(sf::Joystick::getAxisPosition(eventos.joystickMove.joystickId,sf::Joystick::X),sf::Joystick::getAxisPosition(eventos.joystickMove.joystickId,sf::Joystick::Y));
                    
                    if(movimiento.x > 0)
                    {
                        //derecha
                        controles->pr(contro);
                    }
                    else
                    {
                        controles->dr(contro);
                    }
                    
                    if(movimiento.x < 0)
                    {
                        //izquierda
                        controles->pl(contro);
                    }
                    else
                    {
                        controles->dl(contro);
                    }
                    
                    if(movimiento.y > 0)
                    {
                        //abajo
                        controles->pd(contro);
                    }
                    else
                    {
                        controles->dd(contro);
                    }
                    
                    if(movimiento.y < 0)
                    {
                        //arriba
                        controles->pu(contro);
                    }
                    else
                    {
                        controles->du(contro);
                    }
                    break;
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
                        if(eventos.key.code == controles->moveLEFT())
                            controles->pl(controles->whatPlayer(eventos.key.code));
                        if(eventos.key.code == controles->moveUP())
                            controles->pu(controles->whatPlayer(eventos.key.code));
                        if(eventos.key.code == controles->moveDOWN())
                            controles->pd(controles->whatPlayer(eventos.key.code));
                        if(eventos.key.code == controles->moveAtaque())
                            controles->pa(controles->whatPlayer(eventos.key.code));
                        if(eventos.key.code == controles->moveDefensa())
                            controles->pf(controles->whatPlayer(eventos.key.code));
                        if(eventos.key.code == controles->moveSalir())
                        {
                            if(juego->queEstado() == 1)
                            {
                                std::cout << "salir"<<"\n";
                                window.close();
                            }
                            else
                            {
                                juego->finalNivel();
                            }
                        }
                        break;
                case sf::Event::KeyReleased:
                        
                    if(controles->whatPlayer(eventos.key.code) == 1)
                        {
                            controles->cambiarControl(1);
                        }
                        else if(controles->whatPlayer(eventos.key.code) == 2)
                        {
                            controles->cambiarControl(2);
                        }
                    
                        //std::cout << "tecla" << eventos.key.code << " jug:" << controles->whatPlayer(eventos.key.code) <<"\n";
                    
                        if(eventos.key.code == controles->moveRIGHT())
                            controles->dr(controles->whatPlayer(eventos.key.code));
                        if(eventos.key.code == controles->moveLEFT())
                            controles->dl(controles->whatPlayer(eventos.key.code));
                        if(eventos.key.code == controles->moveUP())
                            controles->du(controles->whatPlayer(eventos.key.code));
                        if(eventos.key.code == controles->moveDOWN())
                            controles->dd(controles->whatPlayer(eventos.key.code));
                        if(eventos.key.code == controles->moveAtaque())
                            controles->da(controles->whatPlayer(eventos.key.code));
                        if(eventos.key.code == controles->moveDefensa())
                            controles->df(controles->whatPlayer(eventos.key.code));
                    break;
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
    menus->MoverIzquierda();
}

void Motor2D::menuDER()
{
    menus->MoverDerecha();
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

void Motor2D::initBala(int px, int py, int tipo, int elemento)
{
    
}
void Motor2D::crearBala(int tipo, int elemento, int ori)
{
    if(tipo == 0 || tipo == 1)//jugadores
    {
        sf::Sprite *bala = new sf::Sprite;
        bala->setTexture(texturas[2]);
        bala->setOrigin(4/2, 2/2);
        bala->setScale(sf::Vector2f(2, 2));
        bala->setTextureRect(sf::IntRect(0, 0, 4, 2));
        int fram;
        
        if (ori == -1)
        {
            fram = 1;
        }
        else if (ori == 1)
        {
            fram = 0;
        }
        
        //color elemento
        if(elemento == 0)
            bala->setTextureRect(sf::IntRect(4*fram, 2*elemento, 4*ori,2));
            //bala->setColor(sf::Color::White);
        else if(elemento == 1)
            bala->setTextureRect(sf::IntRect(4*fram, 2*elemento, 4*ori,2));
            //bala->setColor(sf::Color::Blue);
        else if(elemento == 2)
            bala->setTextureRect(sf::IntRect(4*fram, 2*elemento, 4*ori,2));
            //bala->setColor(sf::Color::Cyan);
        else if(elemento == 3)
            bala->setTextureRect(sf::IntRect(4*fram, 2*elemento, 4*ori,2));
            //bala->setColor(sf::Color::Green);
        else if(elemento == 4)
            bala->setTextureRect(sf::IntRect(4*fram, 2*elemento, 4*ori,2));
            //bala->setColor(sf::Color::Magenta);
            //bala->setColor(sf::Color::Red);
            
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
        //std::cout << "se pinta draw hud1" << "\n";
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
        //std::cout << "se pinta draw hud2" << "\n";
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

void Motor2D::finalNivel()
{
    menus->cambioEstado(8);
}


void Motor2D::initEls(int el)
{  
    elementos[el] = sf::Sprite();
    elementos[el].setTexture(texturas[12]);
    
    int ele;
    if (el == 0 || el == 5)
        ele = 0;
    else if (el == 1 || el == 6)
        ele = 1;
    else if (el == 2 || el == 7)
        ele = 2;
    else if (el == 3 || el == 8)
        ele = 3;
    else if (el == 4 || el == 9)
        ele = 4;
    
    elementos[el].setTextureRect(sf::IntRect((ele*48)+17, 22, 16,17));
    elementos[el].setOrigin(48/2,48/2);
    elementos[el].scale(sf::Vector2f(2, 2));
        
}


void Motor2D::DrawEls(int tipo, int x, int y)
{  
    elementos[tipo].setPosition(x, y);
    window.draw(elementos[tipo]);
}

bool Motor2D::ElementCol(int player, int el)
{
    if (jugadores[player].getGlobalBounds().intersects(elementos[el].getGlobalBounds()))
    {
        //std::cout<<"HA COLISIONADO CON EL ELEMENTO"<<endl;
        return true;       
    }           
}


Motor2D::~Motor2D()
{

}