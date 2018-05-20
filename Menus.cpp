/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menus.cpp
 * Author: fv
 * 
 * Created on March 19, 2018, 10:12 AM
 */

#include "Menus.h"
#include "Juego.hpp"
#include "GestionArchivos.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

Menus::Menus(float x,float y,int tipo) {
    
    if (!(tit.loadFromFile("resources/Menu/fuente4.ttf") && nave.loadFromFile("resources/Menu/ovni2.png") && fuente.loadFromFile("resources/Menu/fuente3.ttf") && background.loadFromFile("resources/Menu/b.png") && button.loadFromFile("resources/Menu/bg.png") && exi.loadFromFile("resources/Menu/ex.png") && bgNiveles.loadFromFile("resources/Menu/niveles.jpg") && nivel.loadFromFile("resources/Menu/nivel.jpg") && titulo.loadFromFile("resources/Menu/titulo2.png") && scroll.loadFromFile("resources/Menu/scroll.png") && c1.loadFromFile("resources/Menu/flechas.png") && c2.loadFromFile("resources/Menu/teclas.png")))
    {
        std::cout << "error: cargando el menu" << std::endl;
    }
    Estadisticas = NULL;
    
    if(tipo == 8)
    Menus::cambioEstado(8);
    else
    Menus::cambioEstado(0);    
    
}

Menus::Menus(const Menus& orig) {

}

Menus::~Menus() {

}

void Menus::Intro()
{
    //cambiamos de menu
    if(seleccion == 6)
    {
        salir = true;
    }
    
    if(estado == 1 || estado == 2)
    {
        if(estado == 1)
        {
            Juego *juego = Juego::getInstance();
            Nivel *nivel = Nivel::getInstance();
            juego ->cargarNivel(nivel_estamos);
            nivel ->juegoIndividual(0);
        }
        else
        {
            Juego *juego = Juego::getInstance();
            Nivel *nivel = Nivel::getInstance();
            juego ->cargarNivel(nivel_estamos);
            nivel ->juegoMultijugador(0,1);     
        }    
    }
    else
    {
        intro = true;
    }
}

void Menus::Intro(int x, int y)
{
    switch(estado)
    {
    //entramos segun el pick del raton
    case 0:
        if(x > 330 && x < 605 && y > 50 && y < 100)
        {
            buttons[1].setColor(sf::Color(255, 255, 255, 255));
            buttons[2].setColor(sf::Color(255, 255, 255, 255));
            buttons[3].setColor(sf::Color(255, 255, 255, 255));
            buttons[4].setColor(sf::Color(255, 255, 255, 255));
            buttons[5].setColor(sf::Color(255, 255, 255, 255));
            seleccion = 1;
            intro = true;
        }

        if(x > 330 && x < 605 && y > 150 && y < 200)
        {
            buttons[2].setColor(sf::Color(255, 255, 255, 255));
            buttons[3].setColor(sf::Color(255, 255, 255, 255));
            buttons[4].setColor(sf::Color(255, 255, 255, 255));
            buttons[5].setColor(sf::Color(255, 255, 255, 255));
            buttons[0].setColor(sf::Color(255, 255, 255, 255));
            seleccion = 2;
            intro = true;
        }

        if(x > 330 && x < 605 && y > 250 && y < 300)
        {
            buttons[3].setColor(sf::Color(255, 255, 255, 255));
            buttons[4].setColor(sf::Color(255, 255, 255, 255));
            buttons[5].setColor(sf::Color(255, 255, 255, 255));
            buttons[0].setColor(sf::Color(255, 255, 255, 255));
            buttons[1].setColor(sf::Color(255, 255, 255, 255));
            seleccion = 3;
            intro = true;
        }

        if(x > 330 && x < 605 && y > 350 && y < 400)
        {
            buttons[4].setColor(sf::Color(255, 255, 255, 255));
            buttons[5].setColor(sf::Color(255, 255, 255, 255));
            buttons[0].setColor(sf::Color(255, 255, 255, 255));
            buttons[1].setColor(sf::Color(255, 255, 255, 255));
            buttons[2].setColor(sf::Color(255, 255, 255, 255));
            seleccion = 4;
            intro = true;
        }

        if(x > 330 && x < 605 && y > 450 && y < 500)
        {
            buttons[5].setColor(sf::Color(255, 255, 255, 255));
            buttons[0].setColor(sf::Color(255, 255, 255, 255));
            buttons[1].setColor(sf::Color(255, 255, 255, 255));
            buttons[2].setColor(sf::Color(255, 255, 255, 255));
            buttons[3].setColor(sf::Color(255, 255, 255, 255));
            seleccion = 5;
            intro = true;
        }

        if(x > 760 && x < 790 && y > 20 && y < 50)
        {
            buttons[0].setColor(sf::Color(255, 255, 255, 255));
            buttons[1].setColor(sf::Color(255, 255, 255, 255));
            buttons[2].setColor(sf::Color(255, 255, 255, 255));
            buttons[3].setColor(sf::Color(255, 255, 255, 255));
            buttons[4].setColor(sf::Color(255, 255, 255, 255));
            seleccion = 6;
            intro = true;
            salir = true;
        }
    break;
    case 1:
        if(x >= 760 && x <= 780 && y >= 30 && y <= 570)
        {
            int numMax = 4;
            int numTotal = 12;//esto se obtiene de la clase FabricarNivel
            int min = -270;
            int numPages = numTotal/numMax;//numero de paginas
            int anchuraScroll = 78/numPages;
            int anchuraPaso = 546/numPages;
            int anscroll = anchuraScroll*7;
            int anterior = 0;
            for(int a = 0;a < numPages;a++)
            {
                if(a == 0)
                {
                    if(y >= 33 && y < anchuraPaso)
                    {
                                sc.setPosition(sc.getPosition().x,-270);
                    }
                    anterior = anchuraPaso;
                }
                else
                {
                    if(y >= anterior && y < anchuraPaso*(1+a))
                    {
                        sc.setPosition(sc.getPosition().x,(-270+(anscroll*(a+1))-anchuraPaso));
                    }
                    anterior = anterior+anchuraPaso;
                }
            }
        }
                    
            if(x >=  100 && x <= 350 & y >= 150 && y <= 300)
            {
                if(sc.getPosition().y == -270)
                {
                    //nivel 1
                    Juego *juego = Juego::getInstance();
                    Nivel *nivel = Nivel::getInstance();
                    juego ->cargarNivel(1);
                    nivel ->juegoIndividual(0);
                }
            }

            if(x >=  450 && x <= 700 & y >= 150 && y <= 300)
            {
                if(sc.getPosition().y == -270)
                {
                    //nivel 2
                    Juego *juego = Juego::getInstance();
                    Nivel *nivel = Nivel::getInstance();
                    juego ->cargarNivel(2);
                    nivel ->juegoIndividual(0);
                }
            }

            /*if(x >=  100 && x <= 350 & y >= 400 && y <= 530)
            {
                if(yn == -270)
                {
                    //nivel 3
                }
            }

            if(x >=  450 && x <= 700 & y >= 400 && y <= 530)
            {
                if(yn == -270)
                {
                    //nivel 4
                    
                }
            }*/
    break;
    case 2:
        if(x >= 760 && x <= 780 && y >= 30 && y <= 570)
        {
            int numMax = 4;
            int numTotal = 12;//esto se obtiene de la clase FabricarNivel
            int min = -270;
            int numPages = numTotal/numMax;//numero de paginas
            int anchuraScroll = 78/numPages;
            int anchuraPaso = 546/numPages;
            int anscroll = anchuraScroll*7;
            int anterior = 0;
            for(int a = 0;a < numPages;a++)
            {
                if(a == 0)
                {
                    if(y >= 33 && y < anchuraPaso)
                    {
                                sc.setPosition(sc.getPosition().x,-270);
                    }
                    anterior = anchuraPaso;
                }
                else
                {
                    if(y >= anterior && y < anchuraPaso*(1+a))
                    {
                        sc.setPosition(sc.getPosition().x,(-270+(anscroll*(a+1))-anchuraPaso));
                    }
                    anterior = anterior+anchuraPaso;
                }
            }            
        }
        
            if(x >=  100 && x <= 350 & y >= 150 && y <= 300)
            {
                if(sc.getPosition().y == -270)
                {
                    //nivel 1
                    Juego *juego = Juego::getInstance();
                    Nivel *nivel = Nivel::getInstance();
                    juego ->cargarNivel(1);
                    nivel ->juegoMultijugador(0,1);
                }
            }

            if(x >=  450 && x <= 700 & y >= 150 && y <= 300)
            {
                if(sc.getPosition().y == -270)
                {
                    //nivel 2
                    Juego *juego = Juego::getInstance();
                    Nivel *nivel = Nivel::getInstance();
                    juego ->cargarNivel(2);
                    nivel ->juegoMultijugador(0,1);
                }
            }

            /*if(x >=  100 && x <= 350 & y >= 400 && y <= 530)
            {
                if(yn == -270)
                {
                    //nivel 3
                }
            }

            if(x >=  450 && x <= 700 & y >= 400 && y <= 530)
            {
                if(yn == -270)
                {
                    //nivel 4
                    
                }
            }*/
    break;
    }
}

void Menus::MoverAbajo()
{
    int numMax = 4;
    int numTotal = 12;//esto se obtiene de la clase FabricarNivel
    int numPages = numTotal/numMax;
    int anchuraScroll = 78/numPages;
    int anchuraPaso = 546/numPages;
    int anscroll = anchuraScroll*7;
    //cambiamos la opcion de color
    switch(estado)
    {
        case 0:
    if(!intro)
    {
    if(seleccion < 6)
    {
        seleccion =(seleccion+1);    
    }
    
    switch(seleccion)
    {
        case 1:
            buttons[5].setColor(sf::Color(255, 255, 255, 255));
            buttons[0].setColor(sf::Color(0, 255, 0, 255));
            buttons[1].setColor(sf::Color(255, 255, 255, 255));
        break;
            
        case 2:
            buttons[0].setColor(sf::Color(255, 255, 255, 255));
            buttons[1].setColor(sf::Color(0, 255, 255, 255));
            buttons[2].setColor(sf::Color(255, 255, 255, 255));
        break;
            
        case 3:
            buttons[1].setColor(sf::Color(255, 255, 255, 255));
            buttons[2].setColor(sf::Color(0, 255, 255, 255));
            buttons[3].setColor(sf::Color(255, 255, 255, 255));
        break;
            
        case 4:
            buttons[2].setColor(sf::Color(255, 255, 255, 255));
            buttons[3].setColor(sf::Color(0, 255, 255, 255));
            buttons[4].setColor(sf::Color(255, 255, 255, 255));
        break;
            
        case 5:
            buttons[3].setColor(sf::Color(255, 255, 255, 255));
            buttons[4].setColor(sf::Color(0, 255, 255, 255));
            buttons[5].setColor(sf::Color(255, 255, 255, 255));
        break;
        
        case 6:
            buttons[4].setColor(sf::Color(255, 255, 255, 255));
            buttons[5].setColor(sf::Color(255, 0, 0, 255));
            buttons[1].setColor(sf::Color(255, 255, 255, 255));
        break;
    }
    }
    break;
        case 1:
            if((276-anscroll) >= (sc.getPosition().y+anchuraPaso))
            sc.setPosition(sc.getPosition().x,sc.getPosition().y+anchuraPaso);
        break;
        case 2:
            if((276-anscroll) >= (sc.getPosition().y+anchuraPaso))
            sc.setPosition(sc.getPosition().x,sc.getPosition().y+anchuraPaso);            
        break;
    }
}

void Menus::MoverArriba()
{
    int numMax = 4;
    int numTotal = 12;
    int numPages = numTotal/numMax;
    int anchuraPaso = 546/numPages;    
    //cambiamos la opcion de color
    switch(estado)
    {
        case 0:
    if(!intro)
    {
    if(seleccion > 1)
    {
        seleccion = (seleccion-1);
    }
    
    switch(seleccion)
    {
        case 1:
            buttons[5].setColor(sf::Color(255, 255, 255, 255));
            buttons[0].setColor(sf::Color(0, 255, 255, 255));
            buttons[1].setColor(sf::Color(255, 255, 255, 255));
        break;
            
        case 2:
            buttons[0].setColor(sf::Color(255, 255, 255, 255));
            buttons[1].setColor(sf::Color(0, 255, 255, 255));
            buttons[2].setColor(sf::Color(255, 255, 255, 255));
        break;
            
        case 3:
            buttons[1].setColor(sf::Color(255, 255, 255, 255));
            buttons[2].setColor(sf::Color(0, 255, 255, 255));
            buttons[3].setColor(sf::Color(255, 255, 255, 255));
        break;
            
        case 4:
            buttons[2].setColor(sf::Color(255, 255, 255, 255));
            buttons[3].setColor(sf::Color(0, 255, 255, 255));
            buttons[4].setColor(sf::Color(255, 255, 255, 255));
        break;
            
        case 5:
            buttons[3].setColor(sf::Color(255, 255, 255, 255));
            buttons[4].setColor(sf::Color(0, 255, 255, 255));
            buttons[5].setColor(sf::Color(255, 255, 255, 255));
        break;
        
        case 6:
            buttons[4].setColor(sf::Color(255, 255, 255, 255));
            buttons[5].setColor(sf::Color(255, 0, 0, 255));
            buttons[1].setColor(sf::Color(255, 255, 255, 255));
        break;
    }
  }
  break;  
        case 1:

            if((-270) <= (sc.getPosition().y-anchuraPaso))
            sc.setPosition(sc.getPosition().x,sc.getPosition().y-anchuraPaso);
            break;
        case 2:
            if((-270) <= (sc.getPosition().y-anchuraPaso))
            sc.setPosition(sc.getPosition().x,sc.getPosition().y-anchuraPaso);       
        break;
        case 3:
            break;
        case 4:
            break;
  }
}

void Menus::draw(sf::RenderWindow &ventana)
{
    //aqui van los diferentes menus y como se pintan
    //vamos a poner las opciones
    //2 Un jugador
    //3 Dos jugadores
    //4 Estadisticas
    //5 Creditos
    //6 Configuracion
    if(salir)
    {
        ventana.close();
    }
    
    switch(estado)
    {
        case 0://menu
            Menus::drawMenus(ventana);
            break;
        case 1://un jugador
            Menus::drawNiveles(ventana,1);
            break;
        case 2://dos jugadores
            Menus::drawNiveles(ventana,2);
            break;
        case 3:
            Menus::drawEstadisticas(ventana);
            break;
        case 4:
            Menus::drawCreditos(ventana);
            break;
        case 5:
            Menus::drawConfiguracion(ventana);
            break;
        case 8:
            Menus::drawEstadisticas(ventana);
            break;
    }
}

void Menus::drawMenus(sf::RenderWindow &ventana)
{
    if(intro && espera.getElapsedTime().asMilliseconds() > 380)
    {    
        switch(animacion)
        {
            case 0:
                buttons[seleccion-1].setColor(sf::Color(255,0,0,255));
                animacion = (animacion+1);
                espera.restart();
            break;
            case 1:
                buttons[seleccion-1].setColor(sf::Color(0,255,0,255));
                animacion = (animacion+1);
                espera.restart();
            break;
            case 2:
                buttons[seleccion-1].setColor(sf::Color(255,0,0,255));
                animacion = 0;
                intro =false;
                espera.restart();
                Menus::cambioEstado(seleccion);
            break;
        }
    }            
    ventana.draw(backsp);
    ventana.draw(ovni);
    ventana.draw(buttons[0]);
    ventana.draw(buttons[1]);
    ventana.draw(buttons[2]);
    ventana.draw(buttons[3]);
    ventana.draw(buttons[4]);
    ventana.draw(buttons[5]);
    ventana.draw(opciones[0]);
    ventana.draw(opciones[1]);
    ventana.draw(opciones[2]);
    ventana.draw(opciones[3]);
    ventana.draw(opciones[4]);
    ventana.draw(opciones[5]);
}

void Menus::drawNiveles(sf::RenderWindow &ventana,int players)
{
    //necesitaremos una variable que diga si es para un jugador o para dos
    //int numjugadores = 1 o 2
    //necesitaremos el numero de niveles y su informacion
    //tendran nivel, nombre del nivel y dificultad
    //vamos a cargar primero el fondo,luego el nivel 

    //logica de scroll
    //obtenemos donde esta scroll
    //pondre el calculo en la proxima version
    ventana.draw(bgNivels);
    ventana.draw(titul);
    ventana.draw(sc);
    ventana.draw(tituloVentana);
    switch((int)sc.getPosition().y)
    {
        case -270:
            ventana.draw(niveles[0]);
            ventana.draw(textoNiveles[0]);
            ventana.draw(tituloNiveles[0]);
            ventana.draw(niveles[1]);
            ventana.draw(textoNiveles[1]);
            ventana.draw(tituloNiveles[1]);
            ventana.draw(niveles[2]);
            ventana.draw(textoNiveles[2]);
            ventana.draw(tituloNiveles[2]);
            ventana.draw(niveles[3]);            
            ventana.draw(textoNiveles[3]);
            ventana.draw(tituloNiveles[3]);
            break;
        case -88:
            ventana.draw(niveles[4]);
            ventana.draw(textoNiveles[4]);
            ventana.draw(tituloNiveles[4]);            
            ventana.draw(niveles[5]);
            ventana.draw(textoNiveles[5]);
            ventana.draw(tituloNiveles[5]);
            ventana.draw(niveles[6]);
            ventana.draw(textoNiveles[6]);
            ventana.draw(tituloNiveles[6]);
            ventana.draw(niveles[7]);
            ventana.draw(textoNiveles[7]);
            ventana.draw(tituloNiveles[7]);
            break;
        case 94:
            ventana.draw(niveles[8]);
            ventana.draw(textoNiveles[8]);
            ventana.draw(tituloNiveles[8]);
            ventana.draw(niveles[9]);
            ventana.draw(textoNiveles[9]);
            ventana.draw(tituloNiveles[9]);            
            ventana.draw(niveles[10]);
            ventana.draw(textoNiveles[10]);
            ventana.draw(tituloNiveles[10]);
            ventana.draw(niveles[11]);            
            ventana.draw(textoNiveles[11]);
            ventana.draw(tituloNiveles[11]);
            break;
    }
}
void Menus::drawEstadisticas(sf::RenderWindow &ventana)
{
    ventana.draw(bgNivels);
    ventana.draw(titul);
    ventana.draw(tituloVentana);
    for(int a = 0; a < 7;a++)
    {
        ventana.draw(Estadisticas[a]);
    }
}

void Menus::drawCreditos(sf::RenderWindow &ventana)
{
    //desplazamiento automatico dependiendo del reloj
    //salida al menu por terminar o por escape
    ventana.draw(bgNivels);
    ventana.draw(titul);
    ventana.draw(tituloVentana);
    ventana.draw(creditos);    
}

void Menus::drawConfiguracion(sf::RenderWindow &ventana)
{
    ventana.draw(bgNivels);
    ventana.draw(titul);
    ventana.draw(tituloVentana);
    ventana.draw(textconf[0]);
    ventana.draw(textconf[1]);
    ventana.draw(textconf[2]);
    ventana.draw(conf[0]);
    ventana.draw(conf[1]);
    //solo se configurar los movimientos (asdw o <^v>)y los botones de ataque a(ataque) b(bloqueo)
}

void Menus::cambioEstado(int nuevo)
{
    //esto reinicializa todas las variables y carga la nueva ventana
    if(nuevo >= 0 && nuevo <= 8)
    {
        int Max = 4;
        int NumeroNiveles = 12;//esto se obtiene de FabricarNivel
        int Pages = NumeroNiveles/Max;
        int contador = 0;
        std::ostringstream os;
        estado =nuevo;
        GestionArchivos *gestion = GestionArchivos::getInstance();
        int *info = gestion->devolverInformacion();
        int *info2;
        
        if(estado == 8)
        {
            Nivel *jugando = Nivel::getInstance();
            info2 = jugando->devolverEstadisticas();
        }
        
        switch(estado)
        {
            case 0:
                seleccion = 1;
                intro = false;
                animacion = 0;
                buttons[0].setColor(sf::Color(0, 255, 0, 255));
                backsp.setTexture(background);
                backsp.setTextureRect(sf::IntRect(0, 0, 640, 360));
                backsp.setPosition(0,-300); 
                backsp.setColor(sf::Color(255, 255, 255, 200));//transparencia
                backsp.setScale(4.0f,2.0f);
                ovni.setTexture(nave);
                ovni.setTextureRect(sf::IntRect(0, 0, 2500, 1335));
                ovni.setOrigin(2500/2,1335/2);
                ovni.setScale(0.10f,0.10f);
                ovni.setPosition(175,40);
                ovni.setRotation(-30);
                opciones[0].setString("Un Jugador");
                opciones[0].setStyle(sf::Text::Bold);
                opciones[0].setCharacterSize(20);
                opciones[0].setFont(fuente);
                opciones[0].setPosition(350,-240);
                buttons[0].setTexture(button);
                buttons[0].setTextureRect(sf::IntRect(0, 0, 197, 44));
                buttons[0].setOrigin(15,0);
                buttons[0].setScale(1.4f,1.1f);
                buttons[0].setPosition(350,-250);
                opciones[1].setString("Dos Jugadores");
                opciones[1].setStyle(sf::Text::Bold);
                opciones[1].setCharacterSize(20);
                opciones[1].setFont(fuente);
                opciones[1].setPosition(350,-140);    
                buttons[1].setTexture(button);
                buttons[1].setTextureRect(sf::IntRect(0, 0, 197, 44));
                buttons[1].setOrigin(15,0);
                buttons[1].setScale(1.4f,1.1f);
                buttons[1].setPosition(350,-150);
                opciones[2].setString("Estadisticas");
                opciones[2].setStyle(sf::Text::Bold);
                opciones[2].setCharacterSize(20);
                opciones[2].setFont(fuente);
                opciones[2].setPosition(350,-40);
                buttons[2].setTexture(button);
                buttons[2].setTextureRect(sf::IntRect(0, 0, 197, 44));
                buttons[2].setOrigin(15,0);
                buttons[2].setScale(1.4f,1.1f);
                buttons[2].setPosition(350,-50);
                opciones[3].setString("Creditos");
                opciones[3].setStyle(sf::Text::Bold);
                opciones[3].setCharacterSize(20);
                opciones[3].setFont(fuente);
                opciones[3].setPosition(350,60);
                buttons[3].setTexture(button);
                buttons[3].setTextureRect(sf::IntRect(0, 0, 197, 44));
                buttons[3].setOrigin(15,0);
                buttons[3].setScale(1.4f,1.1f);
                buttons[3].setPosition(350,50);
                opciones[4].setString("Configuracion");
                opciones[4].setStyle(sf::Text::Bold);
                opciones[4].setCharacterSize(20);
                opciones[4].setFont(fuente);
                opciones[4].setPosition(350,160);
                buttons[4].setTexture(button);
                buttons[4].setTextureRect(sf::IntRect(0, 0, 197, 44));
                buttons[4].setOrigin(15,0);
                buttons[4].setScale(1.4f,1.1f);
                buttons[4].setPosition(350,150);
                opciones[5].setString("Kinzoku \nSuragu\n     X");
                opciones[5].setStyle(sf::Text::Bold);
                opciones[5].setCharacterSize(50);
                opciones[5].setFont(tit);
                opciones[5].setPosition(50,-280);
                buttons[5].setTexture(exi);
                buttons[5].setPosition(760,-280);
                buttons[5].setTextureRect(sf::IntRect(0, 0, 28,27));
                buttons[1].setColor(sf::Color(255, 255, 255, 255));
                buttons[2].setColor(sf::Color(255, 255, 255, 255));
                buttons[3].setColor(sf::Color(255, 255, 255, 255));
                buttons[4].setColor(sf::Color(255, 255, 255, 255));
                buttons[5].setColor(sf::Color(255, 255, 255, 255));
                break;
            case 1:
                bgNivels.setTexture(bgNiveles);
                bgNivels.setScale(1.0f,1.0f);
                bgNivels.setPosition(0,-300);
                scroll.setSmooth(true);
                sc.setTexture(scroll);
                sc.setPosition(760,-270);
                sc.setScale(0.6,78.0f/(float)Pages);
                tituloVentana.setPosition(70,-260);
                tituloVentana.setString("Un jugador");
                tituloVentana.setCharacterSize(20);
                tituloVentana.setFont(fuente);
                titulo.setSmooth(true);
                titul.setTexture(titulo);
                titul.setPosition(20,-270);
                titul.setScale(1.8f,1.8f);
                titul.setColor(sf::Color(255,255,255,180));
                //pintamos los niveles en el viewport
                for(int a=0;a < NumeroNiveles;a++)
                {
                    if(contador == 4)
                    {
                        contador =0;
                    }    
                    
                    if(contador == 0)
                    {
                        niveles[a].setPosition(100,-150);
                    }
                    else if(contador == 1)
                    {
                        niveles[a].setPosition(450,-150);   
                    }
                    else if(contador == 2)
                    {
                        niveles[a].setPosition(100,100);
                    }
                    else if(contador == 3)
                    {
                        niveles[a].setPosition(450,100);          
                    }
                        niveles[a].setTexture(nivel);
                        textoNiveles[a].setFont(fuente);
                        textoNiveles[a].setString(std::to_string(a+1));
                        textoNiveles[a].setPosition(niveles[a].getPosition().x+20,niveles[a].getPosition().y);
                        tituloNiveles[a].setFont(fuente);
                        tituloNiveles[a].setCharacterSize(16);
                        if(a == 0)
                        {    
                            tituloNiveles[a].setString("Selva \nAlienigena"); 
                            niveles[a].setColor(sf::Color::Green);
                        }
                        else if(a == 1)
                        {
                            tituloNiveles[a].setString("Ciudad \nVerde");
                        }
                        else
                        {
                            tituloNiveles[a].setString("\nProximamente");//esto lo obtendremos de gestionarchivos
                            niveles[a].setColor(sf::Color::Yellow);
                        }
                        tituloNiveles[a].setPosition(niveles[a].getPosition().x+50,niveles[a].getPosition().y+30);                    
                    contador++;
                }
                nivel_estamos = 1;
                break;
            case 2:
                bgNivels.setTexture(bgNiveles);
                bgNivels.setScale(1.0f,1.0f);
                bgNivels.setPosition(0,-300);
                scroll.setSmooth(true);
                sc.setTexture(scroll);
                sc.setPosition(760,-270);
                sc.setScale(0.6,78.0f/(float)Pages);
                tituloVentana.setPosition(70,-260);
                tituloVentana.setString("Dos jugadores");
                tituloVentana.setFont(fuente);
                tituloVentana.setCharacterSize(20);
                titulo.setSmooth(true);
                titul.setTexture(titulo);
                titul.setPosition(20,-270);
                titul.setScale(1.8f,1.8f);
                titul.setColor(sf::Color(255,255,255,180));
                //pintamos los niveles en el viewport
                for(int a=0;a < NumeroNiveles;a++)
                {
                    if(contador == 4)
                    {
                        contador =0;
                    }    
                    
                    if(contador == 0)
                    {
                        niveles[a].setPosition(100,-150);
                    }
                    else if(contador == 1)
                    {
                        niveles[a].setPosition(450,-150);   
                    }
                    else if(contador == 2)
                    {
                        niveles[a].setPosition(100,100);
                    }
                    else if(contador == 3)
                    {
                        niveles[a].setPosition(450,100);          
                    }
                        niveles[a].setTexture(nivel);
                        textoNiveles[a].setFont(fuente);
                        textoNiveles[a].setString(std::to_string(a+1));
                        textoNiveles[a].setPosition(niveles[a].getPosition().x+20,niveles[a].getPosition().y);
                        tituloNiveles[a].setFont(fuente);
                        tituloNiveles[a].setCharacterSize(16);
                        if(a == 0)
                        {
                            tituloNiveles[a].setString("Selva \nAlienigena");                            
                            niveles[a].setColor(sf::Color::Green);
                        }
                        else if(a == 1)
                        {
                            tituloNiveles[a].setString("Ciudad \nVerde");
                        }
                        else
                        {
                            tituloNiveles[a].setString("\nProximamente");//esto lo obtendremos de gestionarchivos
                            niveles[a].setColor(sf::Color::Yellow);
                        }
                        tituloNiveles[a].setPosition(niveles[a].getPosition().x+50,niveles[a].getPosition().y+30);                    
                    contador++;
                }      
                nivel_estamos =1;
                break;
            case 3:
                bgNivels.setTexture(bgNiveles);
                bgNivels.setScale(1.4f,1.0f);
                bgNivels.setPosition(0,-300);
                scroll.setSmooth(true);
                sc.setTexture(scroll);
                sc.setPosition(760,-270);
                sc.setScale(0.6,78.0f/(float)Pages);
                tituloVentana.setPosition(70,-260);
                tituloVentana.setString("Estadisticas");
                tituloVentana.setCharacterSize(20);
                tituloVentana.setFont(fuente);
                titulo.setSmooth(true);
                titul.setTexture(titulo);
                titul.setPosition(20,-270);
                titul.setScale(1.8f,1.8f);
                titul.setColor(sf::Color(255,255,255,180));
                //los valores de la estadistica se obtendran de FabricarNivel
                Estadisticas = new sf::Text[7];
                for(int a = 0; a < 7;a++)
                {
                    Estadisticas[a].setFont(fuente);
                }
                os << "Dolor recibido: " << info[4]+info[5];
                Estadisticas[0].setString(os.str());
                Estadisticas[0].setCharacterSize(16);
                Estadisticas[0].setPosition(30,-150);
                os.str("");
                os << "Dolor total causado: " << info[6]+info[7];
                Estadisticas[1].setString(os.str());
                Estadisticas[1].setCharacterSize(16);
                Estadisticas[1].setPosition(30,-110);
                os.str("");
                os << "Objetos Cogidos: " << info[11];
                Estadisticas[2].setString(os.str());
                Estadisticas[2].setCharacterSize(16);
                Estadisticas[2].setPosition(30,-70);
                os.str("");
                os << "Tiempo de Juego: " << info[10] << " Minutos";
                Estadisticas[3].setString(os.str());
                Estadisticas[3].setCharacterSize(16);
                Estadisticas[3].setPosition(30,-30);
                os.str("");
                os << "Partidas Individuales: " << info[8];
                Estadisticas[4].setString(os.str());
                Estadisticas[4].setCharacterSize(16);
                Estadisticas[4].setPosition(30,10);
                os.str("");
                os << "Partidas Dos Jugadores: " << info[9];                
                Estadisticas[5].setString(os.str());
                Estadisticas[5].setCharacterSize(16);
                Estadisticas[5].setPosition(30,50);
                os.str("");
                os << "Numero de veces Muerto: " << info[12];                 
                Estadisticas[6].setString(os.str());
                Estadisticas[6].setCharacterSize(16);
                Estadisticas[6].setPosition(30,90);
                delete info;
                break;
            case 4:
                bgNivels.setTexture(bgNiveles);
                bgNivels.setScale(1.4f,1.0f);
                bgNivels.setPosition(0,-300);
                scroll.setSmooth(true);
                sc.setTexture(scroll);
                sc.setPosition(760,-270);
                sc.setScale(0.6,78.0f/(float)Pages);
                tituloVentana.setPosition(70,-260);
                tituloVentana.setString("Creditos");
                tituloVentana.setFont(fuente);
                tituloVentana.setCharacterSize(20);
                titulo.setSmooth(true);
                titul.setTexture(titulo);
                titul.setPosition(20,-270);
                titul.setScale(1.8f,1.8f);
                titul.setColor(sf::Color(255,255,255,180));
                creditos.setFont(fuente);
                creditos.setString("Desarrollado para Fundamentos de los videojuegos \n\n Universidad de Alicante \n\n Creado por Hard Metaleros \n Adrian \n Jose Luis \n Alejandra(Erasmus) \n Jose Vicente");
                creditos.setCharacterSize(16);
                creditos.setPosition(90,-150);
                break;
            case 5:
                bgNivels.setTexture(bgNiveles);
                bgNivels.setScale(1.4f,1.0f);
                bgNivels.setPosition(0,-300);
                scroll.setSmooth(true);
                sc.setTexture(scroll);
                sc.setPosition(760,-270);
                sc.setScale(0.6,78.0f/(float)Pages);
                tituloVentana.setPosition(70,-260);
                tituloVentana.setString("Configuracion");
                tituloVentana.setFont(fuente);
                tituloVentana.setCharacterSize(20);
                titulo.setSmooth(true);
                titul.setTexture(titulo);
                titul.setPosition(20,-270);
                titul.setScale(1.8f,1.8f);
                titul.setColor(sf::Color(255,255,255,180));
                textconf[0].setFont(fuente);
                textconf[0].setString("Movimiento de Jugadores");
                textconf[0].setCharacterSize(20);
                textconf[0].setPosition(30,-200);
                textconf[1].setFont(fuente);
                textconf[1].setString("Teclas Fijas");
                textconf[1].setCharacterSize(20);
                textconf[1].setColor(sf::Color(255,0,0,255));      
                textconf[1].setPosition(30,0);
                textconf[2].setFont(fuente);
                textconf[2].setString(" Shift > Ataque(j1) o Aceptar \n Ctrl > Defensa(j1) o Atras \n Q > Salir \n Shift derecho > Ataque(j2) \n Ctrl derecho > Defensa(j2)");
                textconf[2].setCharacterSize(16);
                textconf[2].setPosition(30,50);
                conf[0].setTexture(c1);
                conf[0].setPosition(200,-160);
                conf[1].setTexture(c2);
                conf[1].setPosition(500,-160);                
                break;
            case 8:
                bgNivels.setTexture(bgNiveles);
                bgNivels.setScale(1.4f,1.0f);
                bgNivels.setPosition(0,-300);
                scroll.setSmooth(true);
                sc.setTexture(scroll);
                sc.setPosition(760,-270);
                sc.setScale(0.6,78.0f/(float)Pages);
                tituloVentana.setPosition(50,-260);
                tituloVentana.setString("Estadisticas de Nivel");
                tituloVentana.setFont(fuente);
                tituloVentana.setCharacterSize(20);
                titulo.setSmooth(true);
                titul.setTexture(titulo);
                titul.setPosition(20,-270);
                titul.setScale(1.8f,1.8f);
                titul.setColor(sf::Color(255,255,255,180));
                //los valores de la estadistica se obtendran de FabricarNivel
                Estadisticas = new sf::Text[7];
                for(int a = 0; a < 7;a++)
                {
                    Estadisticas[a].setFont(fuente);
                }
                os << "Presione Defensa para volver al menu";
                Estadisticas[0].setString(os.str());
                Estadisticas[0].setCharacterSize(16);
                Estadisticas[0].setPosition(30,-150);
                os.str("");
                os << "Dolor Causado Jugador 1: " << info2[1];
                Estadisticas[1].setString(os.str());
                Estadisticas[1].setCharacterSize(16);
                Estadisticas[1].setPosition(30,-110);
                os.str("");
                os << "Dolor Causado Jugador 2: " << info2[4];
                Estadisticas[2].setString(os.str());
                Estadisticas[2].setCharacterSize(16);
                Estadisticas[2].setPosition(30,-70);
                os.str("");
                os << "Dolor recibido Jugador 1: " << info2[2];
                Estadisticas[3].setString(os.str());
                Estadisticas[3].setCharacterSize(16);
                Estadisticas[3].setPosition(30,-30);
                os.str("");
                os << "Dolor recibido Jugador 2: " << info2[5];
                Estadisticas[4].setString(os.str());
                Estadisticas[4].setCharacterSize(16);
                Estadisticas[4].setPosition(30,10);
                os.str("");
                os << "Numero de veces Muerto Jugador 1: " << info2[0];                
                Estadisticas[5].setString(os.str());
                Estadisticas[5].setCharacterSize(16);
                Estadisticas[5].setPosition(30,50);
                os.str("");
                os << "Numero de veces Muerto Jugador 2: " << info2[3];                 
                Estadisticas[6].setString(os.str());
                Estadisticas[6].setCharacterSize(16);
                Estadisticas[6].setPosition(30,90);
                delete info;
                break;                
        }
    }
}

void Menus::volverMenus()
{
    Menus::cambioEstado(0);
}

void Menus::cierrePunteros()
{
    if(Estadisticas == NULL)
    {
        delete[] Estadisticas;
        Estadisticas = NULL;
    }
}

void Menus::MoverIzquierda()
{
    if(estado == 1 || estado == 2)
    {
       if(nivel_estamos == 2)
       {
            nivel_estamos = 1;
            niveles[0].setColor(sf::Color::Green);
            niveles[1].setColor(sf::Color(255,255,255));
       }
    }
}

void Menus::MoverDerecha()
{
    if(estado == 1 || estado == 2)
    {
       if(nivel_estamos == 1)
       {
           nivel_estamos = 2;
           niveles[1].setColor(sf::Color::Green);
           niveles[0].setColor(sf::Color(255,255,255));
       }        
    }
}