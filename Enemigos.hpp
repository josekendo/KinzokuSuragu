/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Enemigos.hpp
 * Author: fv
 *
 * Created on April 5, 2018, 10:07 AM
 */

#ifndef ENEMIGOS_HPP
#define ENEMIGOS_HPP
#include "Coordenadas.hpp"
#include "Motor2D.hpp"

class Enemigos {
public:
    Enemigos();
    Enemigos(int vid, int ataq, int ataqfisico,int element,int defen,int tipo, int x, int y);
    Enemigos(const Enemigos& orig);
    virtual ~Enemigos();
    int getVida();//devuelve la vida del personaje restante(100 maximo)
    bool setDanoVida(int dano);//incrementa el dano a la vida restante devuelve true si el personaje se debilita(muerte)
    bool tieneDefensa();//nos sirve para saber si tiene defensa o no
    void setDefensa(int defen);//damos la defensa maximo (100), si el dano individual que le hacen es menor que la defensa no se le hace dano.
    int getDano(int element, int tipo);//si el elemento es neutro se le hara el dano base si es un elemento mas fuerte se le hara el doble, si es mas flojo la mitad
    void cambiarElemento(int element);//cambia al elemento pasado por parametro: 0(neutral),1(aire),2(tierra),3(agua),4(fuego),5(metal) - El mejor
    //estadisticas
    void addDano(int dano);//se agrega el dano realizado al marcador
    void draw();//se le llama a pintar esa bala en el motor
    bool sigoVivo();//si sigue vivo devuelve true si no false
    bool activacion();//si la camará entra en un rango cercano devuelve true
    bool matarEnemigo(int point);//mata a su sprite en el motor 
    int getAtaqueFisico();
    int getAtaqueLejano();
    int getTipoEnemigo();
    void realimentar();//realimentamos su velocidad
    int getOrientacion();
    int getX();
    int getY();
private:
    int vida,defensa,ataque,ataquefisico,danototal,elemento,velocidad;    
    Coordenadas coordenadas;
    int enemigo;
    int weapon; //tipo de arma
    Motor2D *motor;
    int estado;//nos servira para saber cuantos estados tiene la animacion
    int frame;//nos sirve para saber cuantos frames tiene la animacion
    int estado_actual;//estado en el que estamos
    int frame_actual;//frame en el que estamos
    int frame_refresh;//velocidad de refresco de la animacion en milisegundos
    int proximo;//nos da el siguiente tiempo para poner la animacion
    int orientacion;
    int orientacion_actual;
    int stat;
    int danoecho;
    int danorecibido;
    bool muerto;
    bool activado;
    int cx, cy;
    int cxo, cyo;
    bool izq, der;
};

#endif /* ENEMIGOS_HPP */

