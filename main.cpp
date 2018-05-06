//Librerias
#include "Juego.hpp"

int main()
{
    //adaptacion nuevo main
    Juego *juego = Juego::getInstance();//clase global
    //fin adaptacion nuevo main bloque externo
        while (juego->execVentana())
        {
            juego->Inputs();//entradas externas
            juego->Ejecucion();//logica
            juego->Draw();//render
        }

    return 0;
}


