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
//clases basicas
#include <SFML/Graphics.hpp>
#include "TileMap.cpp"
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
    bool cargarCapa(int *matriz, int capa, int longitud, int anchura, int altura, char tileset[]);//carga las capas en las capas locales
    void drawCap1();//pinta la capa 1
    void drawCap2();//pinta la capa 2
    void drawCap3();//pinta la capa 3
    bool execVentana();//nos dice si esta abierta la ventana
    void mostrar();//nos muestra el frame
    sf::RenderWindow &getVentana();
    //fin singleton public
    
private:
    //clase singleton 
    Motor2D();
    static Motor2D* unica_instancia;
    //fin clase singleto private
    sf::RenderWindow window;//ventana
    TileMap ca1,ca2,ca3;//capas
    sf::Sprite *jugadores;
    sf::Sprite *enemigos;    
};

#endif /* MOTOR2D_HPP */

