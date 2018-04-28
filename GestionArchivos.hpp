/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GestionArchivos.hpp
 * Author: fv
 *
 * Created on April 26, 2018, 3:22 AM
 */

/*
 Funcion:
 Este archivo se encarga de gestionar los archivos de guardado y de crearlos si no existieran.
 */
#ifndef GESTIONARCHIVOS_HPP
#define GESTIONARCHIVOS_HPP
#include <iostream>
#include <iosfwd>
#include <string>
#include "tinyxml.h"
#include <dirent.h>
#if defined _MSC_VER
#include <direct.h>
#elif defined __GNUC__
#include <sys/types.h>
#include <sys/stat.h>
#endif

class GestionArchivos {
public:
    //clase singleton
    ~GestionArchivos(void);
    static GestionArchivos *getInstance()
    {
        if(unica_instancia == 0)
        unica_instancia = new GestionArchivos();
        return unica_instancia;  
    }
    //fin singleton public
    
    void crearArchivos();//crea los archivos de guardado, si existe los sobreescribe
    bool ExisteArchivos();//comprueba si existen archivos de guardado
    void cargarArchivos();//carga todos los archivos de guardado en memoria en el caso de que no exista los crea llamando a creararchivos
    void guardarArchivos(bool victoria,int modo);//esto es llamado en estadisticas para guardar la informacion nueva, no se guarda configuracion de teclado, esta funcion llama a jugadores para obtener sus valores
    
    int * devolverInformacion();

private:
    //clase singleton 
    GestionArchivos();
    static GestionArchivos* unica_instancia;
    //fin clase singleto private
    
    //valores de guardado
    //--niveles
    int nivelesDisponiblesIn;//niveles disponibles en invidual cuando se pase uno se habilitara otro hasta total
    int nivelesDisponiblesMu;//niveles disponibles en multijugador cuando se pase uno se habilitara otro hasta total
    int nivelesTotalesIn;//este valor es fijo,indica cuantos niveles tenemos en el juego individual
    int nivelesTotalesMu;//este valor es fijo,indica cuantos niveles tenemos en el juego multijugador
    //--estadisticas
    int danorecibido[2];//este dano se suma en estadistica (2 jugadores)
    int danoecho[2];//este dano se suma en estadistica (2 jugadores)
    int partidasIndi;//partidas individuales totales
    int partidasMulti;//partidas multijugador totales
    int minutosJugados;//minutos totales jugados
    int objetosCogidos;//objetos totales cogidos
    int numMuertes;//numero de muertes totales
};

#endif /* GESTIONARCHIVOS_HPP */

