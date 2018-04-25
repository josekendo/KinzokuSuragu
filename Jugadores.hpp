/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Jugadores.hpp
 * Author: fv
 *
 * Created on April 5, 2018, 10:07 AM
 */

#ifndef JUGADORES_HPP
#define JUGADORES_HPP
#include "Coordenadas.hpp"
#include "Motor2D.hpp"

class Jugadores {
public:
    Jugadores();
    Jugadores(const Jugadores& orig);
    virtual ~Jugadores();
    int getVida();//devuelve la vida del personaje restante(100 maximo)
    bool setVida(int vid);//incrementa la vida en el numero vid (100 maximo)
    bool setDanoVida(int dano);//incrementa el dano a la vida restante devuelve true si el personaje se debilita(muerte)
    bool tieneDefensa();//nos sirve para saber si tiene defensa o no
    void setDefensa(int defen);//damos la defensa maximo (100), si el dano individual que le hacen es menor que la defensa no se le hace dano.
    int getDano(int element, int tipo);//si el elemento es neutro se le hara el dano base si es un elemento mas fuerte se le hara el doble, si es mas flojo la mitad
    void cambiarElemento(int element);//cambia al elemento pasado por parametro: 0(neutral),1(aire),2(tierra),3(agua),4(fuego),5(metal) - El mejor
    //estadisticas
    void addMuerte();//se agrega la muerte al marcador
    void addDano(int dano);//se agrega el dano realizado al marcador
    void initJugador(int tip, int play);//define tipo y el numero de jugador
    void draw();//llama a motor2D para pintar el personaje segun su tipo

    bool mover();//se movera segun su estado una velocidad o otro (se debera agregar la colision aqui)
    bool moverAtras();//se movera hacia atras (aplicar colisiones o factores que hagan que no se mueva)
    bool isMoving();
    int getX();//obtenemos la coordenada x

    
    void Idle();
    void Walk(int dir);
    void Shoot();
    void Kick();
    void Block();
    void Jump();
    void Die();
    

private:
    int vida,defensa,ataque,ataquefisico,muertes,danototal,elemento;  //stats  
    Coordenadas coordenadas;//coordenadas del sprite
    int tipo;//masculino 0, femenino 1
    int player;//numero de jugador
    int weapon; //tipo de arma
    Motor2D *motor;
    int estado;//nos servira para saber cuantos estados tiene la animacion
    int frame;//nos sirve para saber cuantos frames tiene la animacion
    int estado_actual;//estado en el que estamos
    int frame_actual;//frame en el que estamos
    int frame_refresh;//velocidad de refresco de la animacion en milisegundos
    int proximo;//nos da el siguiente tiempo para poner la animacion
    int orientacion;
    int stat;
    //bool mover;
    //bool moverAtras;
};

#endif /* JUGADORES_HPP */

