/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menus.h
 * Author: fv
 *
 * Created on March 19, 2018, 10:12 AM
 */


#ifndef MENUS_H
#define MENUS_H

#include <SFML/Graphics.hpp>

class Menus {
public:
    Menus(float x,float y, int tipo);
    Menus(const Menus& orig);
    virtual ~Menus();
    void draw(sf::RenderWindow &ventana);
    void MoverArriba();
    void MoverAbajo();
    void MoverIzquierda();
    void MoverDerecha();
    void Intro();
    void Intro(int x,int y);
    void volverMenus();
    void cierrePunteros();
    void cambioEstado(int nuevo);
private:
    int seleccion;//la opcion seleccionada[General]
    int estado; //en que parte del menu nos encontramos[General]
    sf::Font fuente;//fuente global[General]
    sf::Font tit;//fuente para titulo
    sf::Clock espera;//reloj para eventos generales
    sf::Texture background;//bg menu [Menus]
    sf::Texture bgNiveles;//bg niveles[Niveles]
    sf::Texture button;//textura de boton[Menus]
    sf::Texture nivel;//textura de nivel[Niveles]
    sf::Texture titulo;//textura de estilo titulo [General]
    sf::Texture exi;//boton salida[Menus]
    sf::Texture scroll;//textura scroll[General]
    sf::Texture c1;
    sf::Texture c2;//228 145
    sf::Texture nave;//593 434
    sf::Texture log;//2621 2062
    sf::Sprite backsp;//bg menu [Menus]
    sf::Sprite bgNivels;//bg niveles[Niveles]
    sf::Sprite titul;//sprite del titulo donde estamos[General]
    sf::Sprite sc;//sprite de la barra scroll[General]
    sf::Sprite conf[2];
    sf::Sprite ovni;
    sf::Sprite logo;
    sf::Text textconf[3];
    bool intro;//se comprueba que se hace intro o que se pulsa con el raton[General]
    int animacion;//para hacer la animacion de que has pulsado es un estado[General]
    sf::Sprite buttons[6];//botones [Menus]
    sf::Sprite niveles[12];//niveles [Niveles]
    sf::Text opciones[6];//Textos de los botones [Menus]
    sf::Text textoNiveles[12];//Texto del numero de nivel[Niveles]
    sf::Text tituloNiveles[12];//Texto del titulo de nivel[Niveles]
    sf::Text tituloVentana;
    sf::Text *Estadisticas;
    sf::Text creditos;
    int nivel_estamos;
    bool salir = false;
    void drawMenus(sf::RenderWindow &ventana);
    void drawNiveles(sf::RenderWindow &ventana,int players);
    void drawEstadisticas(sf::RenderWindow &ventana);
    void drawCreditos(sf::RenderWindow &ventana);
    void drawConfiguracion(sf::RenderWindow &ventana);
};

#endif	// MENUS_H

