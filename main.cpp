//Librerias
#include "Juego.hpp"
#include "Nivel.hpp"

int main()
{
    //adaptacion nuevo main
        Juego *juego = Juego::getInstance();//clase global
            //borrar esto para ver el menu,estas lineas son para los que se tienen que centrar en el nivel(provisional)
            Nivel *nivel = Nivel::getInstance();//clase global
            juego->cargarNivel(1);
            nivel->juegoMultijugador(0,0);
    //fin adaptacion nuevo main bloque externo
        while (juego->execVentana())
        {
            juego->Inputs();//entradas externas
            juego->Ejecucion();//logica
            juego->Draw();//render
        }

    return 0;
}

