/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Motor2D.hpp
 * Author: fv
 *
 * Created on April 5, 2018, 10:08 AM
 */

#ifndef MOTOR2D_HPP
#define MOTOR2D_HPP
#define TIEMPOUPDATE 1000/15
//clases basicas
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include "TileMap.cpp"
#include "Controles.h"
#include "Menus.h"
#include "Hud.hpp"
#include "Colision.hpp"
//fin clases basicas

class Motor2D {
public:
    //clase singleton
    ~Motor2D(void);
    static Motor2D *getInstance()
    {
        if(unica_instancia == 0)
        unica_instancia = new Motor2D();
        return unica_instancia;  
    }
    
    static void ResetInstance()
    {
        delete unica_instancia;
        unica_instancia = 0;
    }
    //fin singleton public
    
    bool cargarCapa(int *matriz, int capa, int longitud, int anchura, int altura, char tileset[]);//carga las capas en las capas locales
    void drawCap1();//pinta la capa 1
    void drawCap2();//pinta la capa 2
    void drawCap3();//pinta la capa 3
    void initMenu();//inicializa la variable de menu
    void drawMenu();//pinta el menu (en cualquier de sus subestados)
    void menuDOWN();//redireccion a menu control abajo
    void menuUP();//redireccion a menu control arriba
    void menuIZQ();//redireccion a menu control izquierda
    void menuDER();//redireccion a menu control derecha
    void menuSPACE();//redirecciona a menu control intro
    void menuSPACE(int x, int y);//redireccionar a menu control intro de mouse
    void menuSALIR();//redirecciona a menu salir
    void menuATRAS();//redirecciona a menu atras
    void Inputs();//gestiona los inputs y los envia a controles (despues es gestionado por juego)
    bool execVentana();//nos dice si esta abierta la ventana
    void mostrar();//nos muestra el frame
    sf::RenderWindow &getVentana();//Esto se borrara es provisional
    void drawPersonaje(int player,int esta, int fram, int ori, float x,float y);//pinta el personaje
    void ResetDirPersonaje(int player,int tipo);//le asigna la orientación (izquierda o derecha) del sprite
    void initPersonaje(int player,int tipo);//le asigna el conjunto de sprites al personaje
    void initCamera();//inicializamos la camara
    void drawCamera();//seleccionamos la camara para pintar en ella
    void cambiarPosicionCamera(int x,int y);//cambia la posicion de la view
    
    void initEnemigo(int tipo, int elemento);//crea un sprite de un enemigo
    void drawEnemigo(int enemigo,int esta, int fram, int ori, float x,float y);//pinta el enemigo en esa posicion
    void matarEnemigo(int point);//elimina el sprite del enemigo 
    void desactivarSonidos();
    //relojes
    int darUPDATE();
    void reiniciarUPDATE();
    int darAnimacion();
    //fin relojes
    
    void initBala(int px, int py, int tipo, int elemento);
    //bala
    void crearBala(int tipo, int elemento, int ori);//crea un sprite de una bala
    void drawBala(int point, int x, int y);//pinta la bala en esa posicion
    void matarBala(int point);//elimina el sprite de la bala 
    //fin bala
    //hud
    void initHud(int player);
    void drawHud(int player);
    //fin hud
    void finalNivel();//cambia el estado de menu
    
    //ELEMENTOS
    void initEls(int elemento);
    void DrawEls(int elemento, int x, int y);
    
    //COLISION DE ELEMENTO
    bool ElementCol(int player, int el);
    

private:
    //clase singleton 
    Motor2D();
    static Motor2D* unica_instancia;
    //fin clase singleto private
    Colision *colision= Colision::getInstance();
    sf::RenderWindow window;//ventana
    TileMap ca1,ca2,ca3;//capas
    sf::Sprite jugadores[2];//jugadores
    sf::Sprite elementos[10];//elementos
    std::vector<sf::Sprite*> bullets;//proyectiles
    sf::Sprite enemigos[6];//enemigos vector
    sf::Texture texturas[14];//tilesets
    sf::SoundBuffer sb[6];
    sf::Sound sound[6];
    sf::View camera;//camara del juego
    sf::Clock update;//nos sirve para saber cuando tenemos que ejecutar la parte logica 1000/15 por defecto
    sf::Clock animaciones;//nos sirve para saber cuando tenemos que cambiar de animacion
    Controles *controles;
    Menus *menus;
    sf::Text textos[6];//aqui iran los valores de los marcadores
    sf::Sprite marcadores[6];//aqui iran los marcadores
    sf::View hud1,hud2;
    sf::Font fuent;
    int tip;
    
};

#endif /* MOTOR2D_HPP */

