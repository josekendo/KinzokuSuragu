//Librerias
#include "Juego.hpp"
#include "Nivel.hpp"

int main()
{
    //adaptacion nuevo main
        Juego *juego = Juego::getInstance();//clase global
        Nivel *nivel = Nivel::getInstance();//clase global
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

