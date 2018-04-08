//Librerias
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <sstream>
#include "Box2D.h"
#include "Juego.hpp"
#include "Motor2D.hpp"
#include "Nivel.hpp"
#include "Coordenadas.hpp"
#include "Jugadores.hpp"
#include "Enemigos.hpp"
//Constantes
#define PI 3.14159265
#define TIEMPOUPDATE 1000/15//tiempoque debera pasar para actualizar de nuevo

int main()
{
    //adaptacion nuevo main
        Juego *juego = Juego::getInstance();//clase global
        Motor2D *motor2D = Motor2D::getInstance();//clase global
        Nivel *nivel = Nivel::getInstance();//clase global
        Jugadores jugador();
        Enemigos enemigo();
    //fin adaptacion nuevo main bloque externo
        juego->cargarNivel(2);
    //coordenadas de prueba
        Coordenadas coor(20,220);
        //std::cout << coor.getCoordenadaX() << " -- " << coor.getCoordenadaY() << std::endl;
    //coordenadas prueba fin
        
    //esto es para el personaje que tenga sprites dinamicos
        sf::Clock animaciones,update;
    //nos sirve para ver el tiempo que ha pasado desde el ultimo frame
        int numpp = 0;//numero de animacion dentro del sprite
        int numest =0;//numero de estado del sprite
    //fin sprite dinamicos
    
    //prueba de que la libreria funciona bien
        b2Vec2 gravity(0.0f, -10.0f);
        b2World world(gravity);
    //fin box2d
    
    //Apartado grafico 
        //calidad buena
    //fin apartado grafico 
    
    //camara (habra solo una)
        sf::View jugador1 = sf::View(sf::FloatRect(0, 0, 800, 600));
        sf::Texture mapa,personaje_textura;
        jugador1.setCenter(400,0);
    //fin camara
    
    //cargamos todas las texturas
    if (!(mapa.loadFromFile("resources/mapabase.png") && personaje_textura.loadFromFile("resources/pp.png")))
    {
        std::cerr << "Error cargando las texturas.";
        exit(0);
    }
    //fin de carga    
    
    //Y creo el spritesheet a partir de la imagen anterior
    sf::Sprite spritepersonaje(personaje_textura),spritemapa(mapa);
    //Le pongo el centroide donde corresponde
    spritepersonaje.setOrigin(256/2,348/2);
    spritemapa.setOrigin(0,0);//en el mapa queremos que el centroide este en minimo anchura, minimo altura para que sea positiva
    //Cojo el sprite que me interesa por defecto del sheet
    spritepersonaje.setOrigin(228/2,300/2);
    spritepersonaje.setTextureRect(sf::IntRect(0*228, 0*300, 228,300));
    spritepersonaje.scale(sf::Vector2f(0.3f, 0.3f));
    spritepersonaje.setPosition(coor.getCoordenadaX(),coor.getCoordenadaY());
    spritemapa.setTextureRect(sf::IntRect(0, 0, 1056,528));
    spritemapa.setPosition(0,0);
    
    //Bucle del juego
    while (motor2D->execVentana())
    {
        //Bucle de obtención de eventos        
        sf::Event event;
        while (motor2D->getVentana().pollEvent(event))
        {            
                switch(event.type){
                //Si se recibe el evento de cerrar la ventana la cierro
                case sf::Event::Closed:
                    motor2D->getVentana().close();
                    break;
                //Se pulsó una tecla, imprimo su codigo
                case sf::Event::KeyPressed:
                    
                    //Verifico si se pulsa alguna tecla de movimiento
                    switch(event.key.code) {
                        
                        //Mapeo del cursor
                        case sf::Keyboard::Right:
                            //Escala por defecto
                            //aqui cambiariamos de estado para cargar la nueva animacion
                                coor.cambiarPosicion(coor.getCoordenadaX()+80,coor.getCoordenadaY());
                            break;

                        case sf::Keyboard::Left:
                                coor.cambiarPosicion(coor.getCoordenadaX()-80,coor.getCoordenadaY());
                            //Reflejo vertical
                        break;
                        
                        case sf::Keyboard::Up:

                        break;
                        
                        case sf::Keyboard::Down:
                            
                        break;
                        
                        //Tecla ESC para salir
                        case sf::Keyboard::Escape:
                            motor2D->getVentana().close();
                        break;
                        
                        //Tecla ESC para salir
                        case sf::Keyboard::Q:
                            motor2D->getVentana().close();
                            break;
                            
                            
                        //Cualquier tecla desconocida se imprime por pantalla su código
                        default:
                            std::cout << event.key.code << std::endl;
                            break;
                              
                    }

            }
    }
        
        if(animaciones.getElapsedTime().asMilliseconds() > 100)
        {
            if(numpp != 9)
            {
                numpp=numpp+1;
            }
            else
            {
                numpp=0;
            }   
            spritepersonaje.setTextureRect(sf::IntRect(numpp*228, numest*300, 228,300));
            animaciones.restart();
        }
        //inicio pintura, este apartado se sustituira por juego
        motor2D->getVentana().setView(jugador1);//ponemos la camara del jugador1
        motor2D->getVentana().clear(sf::Color::Black);
        //logica de render
        //std::cout << "T:" << update.getElapsedTime().asMilliseconds() << std::endl;
        
        spritepersonaje.setPosition(coor.getCoordenadaXI(update.getElapsedTime().asMilliseconds()),coor.getCoordenadaYI(update.getElapsedTime().asMilliseconds()));
        
        motor2D->getVentana().draw(spritepersonaje);
        //pintamos mapa entero
        
        if(update.getElapsedTime().asMilliseconds() > TIEMPOUPDATE)
        {
            coor.cambiarPosicion(coor.getCoordenadaX()+5,coor.getCoordenadaY());
            update.restart();
        }
        
        //por esta linea
        juego->Draw();
        //fin pintura
    }

    return 0;
}

