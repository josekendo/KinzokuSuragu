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
        //nivel->juegoIndividual(0);//escogemos masculino
        nivel->juegoMultijugador(0,0);
    //nos sirve para ver el tiempo que ha pasado desde el ultimo frame
    //    int numpp = 0;//numero de animacion dentro del sprite
    //    int numest =0;//numero de estado del sprite
    //fin sprite dinamicos
    
    //prueba de que la libreria funciona bien
        b2Vec2 gravity(0.0f, -10.0f);
        b2World world(gravity);
    //fin box2d
    
    //Apartado grafico 
        //calidad buena
    //fin apartado grafico 
    
    //camara (habra solo una)
    //fin camara
    
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
                                //coor.cambiarPosicion(coor.getCoordenadaX()+80,coor.getCoordenadaY());
                            break;

                        case sf::Keyboard::Left:
                                //coor.cambiarPosicion(coor.getCoordenadaX()-80,coor.getCoordenadaY());
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
        
        /*if(animaciones.getElapsedTime().asMilliseconds() > 100)
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
        }*/
        //inicio pintura, este apartado se sustituira por juego
        //ponemos la camara del jugador1
        juego->Ejecucion();
        
        //por esta linea
        juego->Draw();
        //fin pintura
    }

    return 0;
}

