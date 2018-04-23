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
#include "TileMap.cpp"
#include "Controles.h"
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
    //fin singleton public
    
    bool cargarCapa(int *matriz, int capa, int longitud, int anchura, int altura, char tileset[]);//carga las capas en las capas locales
    void drawCap1();//pinta la capa 1
    void drawCap2();//pinta la capa 2
    void drawCap3();//pinta la capa 3
    void Inputs();//gestiona los inputs y los envia a controles (despues es gestionado por juego)
    bool execVentana();//nos dice si esta abierta la ventana
    void mostrar();//nos muestra el frame
    sf::RenderWindow &getVentana();//Esto se borrara es provisional
    void drawPersonaje(int player,int esta, int fram, int ori, float x,float y, int st);//pinta el personaje
    void ResetDirPersonaje(int player,int tipo);//le asigna la orientación (izquierda o derecha) del sprite
    void initPersonaje(int player,int tipo);//le asigna el conjunto de sprites al personaje
    void initCamera();//inicializamos la camara
    void drawCamera();//seleccionamos la camara para pintar en ella
    //relojes
    int darUPDATE();
    void reiniciarUPDATE();
    int darAnimacion();
    //fin relojes
private:
    //clase singleton 
    Motor2D();
    static Motor2D* unica_instancia;
    //fin clase singleto private
    sf::RenderWindow window;//ventana
    TileMap ca1,ca2,ca3;//capas
    sf::Sprite jugadores[2];//jugadores
    sf::Sprite *enemigos;//enemigos vector
    sf::Texture texturas[10];//tilesets
    sf::View camera;//camara del juego
    sf::Clock update;//nos sirve para saber cuando tenemos que ejecutar la parte logica 1000/15 por defecto
    sf::Clock animaciones;//nos sirve para saber cuando tenemos que cambiar de animacion
    Controles *controles;
};

#endif /* MOTOR2D_HPP */

