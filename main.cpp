//Librerias
#include <iostream>
#include <SFML/Graphics.hpp>
#include "TileMap.cpp"
#include <cmath>
#include <sstream>
#include "Box2D.h"
#include "Juego.hpp"
#include "Motor2D.hpp"
//Constantes
#define PI 3.14159265

int main()
{
    //adaptacion nuevo main
        Juego *juego = Juego::getInstance();//clase global
        Motor2D *Motor2D = Motor2D::getInstance();//clase global
    //fin adaptacion nuevo main bloque externo
    
        //esto es para el personaje que tenga sprites dinamicos
    sf::Clock animaciones;//nos sirve para ver el tiempo que ha pasado desde el ultimo frame
    
    int numpp = 0;//numero de animacion dentro del sprite
    int numest =0;//numero de estado del sprite
    //fin sprite dinamicos
    
    //prueba de que la libreria funciona bien
    b2Vec2 gravity(0.0f, -10.0f);
    b2World world(gravity);
    //fin box2d
    
    //Apartado grafico 
    sf::RenderWindow window(sf::VideoMode(800, 600), "Prototipo Base");
    window.setFramerateLimit(60);//calidad buena
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
    spritepersonaje.setPosition(20,220);
    spritemapa.setTextureRect(sf::IntRect(0, 0, 1056,528));
    spritemapa.setPosition(0,0);
    
    //vamos a crear la clase tiled (esta en la pagina oficial de sfml) y a crear su mapa para que se pinte por bloques pero de una forma optima
    //Nuestro Nivel(para la version completa lo cambiaremos por una clase que lea un archivo)
    const int level[] =
    {
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,8,9,9,9,10,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,53,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,8,9,10,-1,-1,-1,53,-1,1,-1,-1,-1,
        -1,-1,-1,-1,16,20,18,-1,8,9,9,9,41,-1,-1,-1,
        8,9,10,56,16,20,18,56,16,17,17,18,34,56,56,56,
    };
    //la carga de nivel (como pueden ver es muy simple)
    TileMap map;
    map.setPosition(0,43);
    //vamos a ver el primer parametro es donde esta la imagen, el vector es el tamano del recorte, y el nivel es cuanto debe cargar 
    if (!map.load("resources/tilesetbase.png", sf::Vector2u(32, 32), level, 16, 8))
        return -1;
    //fin de carga de mapa
    
    //vamos con la logica de los sprites dinamicos tendran varios estados
    //ejemplo quieto (1) o en movimiento(2)
    //la carga de los sprites se ha realizado arriba
    //dentro de cada estado tendran un limite de frames pondremos la carga a 0.2 s o 200ms 
    //Bucle del juego
    
    while (window.isOpen())
    {
        //Bucle de obtención de eventos        
        sf::Event event;
        while (window.pollEvent(event))
        {
            
           
            switch(event.type){
                //Si se recibe el evento de cerrar la ventana la cierro
                case sf::Event::Closed:
                    window.close();
                    break;
                //Se pulsó una tecla, imprimo su codigo
                case sf::Event::KeyPressed:
                    
                    //Verifico si se pulsa alguna tecla de movimiento
                    switch(event.key.code) {
                        
                        //Mapeo del cursor
                        case sf::Keyboard::Right:
                            //Escala por defecto
                            //aqui cambiariamos de estado para cargar la nueva animacion
                            break;

                        case sf::Keyboard::Left:
                            //Reflejo vertical
                        break;
                        
                        case sf::Keyboard::Up:

                        break;
                        
                        case sf::Keyboard::Down:
                            
                        break;
                        
                        //Tecla ESC para salir
                        case sf::Keyboard::Escape:
                            window.close();
                        break;
                        
                        //Tecla ESC para salir
                        case sf::Keyboard::Q:
                            window.close();
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
        window.setView(jugador1);//ponemos la camara del jugador1
        window.clear(sf::Color::Black);
        window.draw(map);//pintamos mapa entero
        window.draw(spritepersonaje);//pintamos mapa entero 
        window.display();
        //por esta linea
        juego->Draw();
        //fin pintura
    }

    return 0;
}

