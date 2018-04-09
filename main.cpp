//Librerias
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <sstream>
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
        nivel->juegoMultijugador(0,0);
        while (juego->execVentana())
        {
            juego->Inputs();//entradas externas
            juego->Ejecucion();//logica
            juego->Draw();//render
        }

    return 0;
}

