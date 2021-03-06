/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nivel.hpp
 * Author: fv
 *
 * Created on April 5, 2018, 10:18 AM
 */

#ifndef NIVEL_HPP
#define NIVEL_HPP


#include "Jugadores.hpp"
#include "Enemigos.hpp"
#include "FabricarNivel.h"
#include "Bullet.hpp"
#include "Els.hpp"
#include <vector> 
#include <iostream>
#include "Controles.h"
#include "GestorAudio.hpp"

class Nivel {
public:
    //clase singleton
    ~Nivel(void);
    static Nivel *getInstance()
    {
        if(unica_instancia == 0)
        unica_instancia = new Nivel();
        return unica_instancia;  
    }
    
    static void ResetInstance()
    {
        delete unica_instancia;
        unica_instancia = 0;
    }
    //fin singleton public
    void cargarNivel(int niv);//carga el nivel pasado empezando por 1
    void juegoIndividual(int tipo);//prepara el personaje con el tipo 0-masculino, 1-femenino
    void juegoMultijugador(int tipo1,int tipo2);//prepara los personajes con los tipos(0 masculino, 1 femenino)
    void moverJugador(int jugador);//mueve el jugador hacia delante
    void moverJugadorAtras(int jugador);//mueve el jugador pasado hacia atras
    void brincarJugador(int jugador, bool caida);
   
    void AtaqueCercano(int jugador);
    void AtaqueLejano(int jugador);
    void IdleJugador(int jugador);
    
   
    
    
    void draw();//llama a pintar a todas las partes relacionadas con el nivel
    void resetJugador(int jug,int xr,int yr);
    void BlockJugador(int jugador);
    int getModo();//nos devuelve el modo de juego
    int separacion();//devuelve la separacion entre los jugadores solo en modo 2 si no devuelve 0 siempre
    int notificarActivacion(int x,int y);//este parametro notifica las coordenadas de la camara cada vez que se mueve para darselo a los enemigos
    
    void crearBala(int tipo, int elemento,int x,int y,int jugador, int dano, int ori,int amigo);//creamos una nueva bala
    void matarBala(int point);//elimina la bala
    void realimentarBalas();//le da propulsion a la bala
    void ColBalasNivel();
    
    void crearEnemigo(int vid, int ataq, int ataqfisico,int element,int defen,int tipo,int x,int y);//creamos un nuevo enemigo
    void realimentarEnemigo();//movimiento enemigo
    void ataqueEnemigo();
    void matarEnemigos();
    void matarEnemigo(int point);
    
    int * devolverEstadisticas();//devuelve las estadisticas de los jugadores
    
    void collectElement(int jugador);
    int getElementos();
private:
    //clase singleton 
    Nivel();
    static Nivel* unica_instancia;
    int direccion;
    //fin clase singleto private
    FabricarNivel fabrica;
    Jugadores jugadores[2];//array de jugadores
    Els elementos[10];
    std::vector<Enemigos*> enemigos;//array autodimensionable de enemigos
    vector<Bullet*> bullet;//array autodimensionable de proyectiles
    int modo;//modo un jugador(0), dos jugadores(1)
    int level;//identifica el nivel en el que estamos
    int c=0;
    int p=0;
    
};  

#endif /* NIVEL_HPP */