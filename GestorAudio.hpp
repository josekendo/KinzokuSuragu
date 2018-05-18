/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GestorAudio.hpp
 * Author: fv
 *
 * Created on May 17, 2018, 9:00 AM
 */

#ifndef GESTORAUDIO_HPP
#define GESTORAUDIO_HPP
#include <SFML/Audio.hpp>

class GestorAudio 
{

public:
    
    //clase singleton
    ~GestorAudio(void);
    static GestorAudio *getInstance()
    {
        if(unica_instancia == 0)
        unica_instancia = new GestorAudio();
        return unica_instancia;  
    }
    //fin singleton public
    
    //personajes 
    void disparar(int jugador);//suena sonido disparo
    void cuerpoacuerpo(int jugador);//suena sonido golpe cuerpo a cuerpo
    void defensa(int jugador);//suena sonido de defenderse
    void saltar(int jugador);//suena el salto
    void coger(int jugador);//suena a coger elemento
    //fin personaje
    
    //menu
    void aceptar();//se oye cuando aceptamos 
    void denegar();//se oye cuando vamos para atras
    void fondo();//sonido del menu,desactivaa fondoNivel si esta activo
    //fin menu
    
    //enemigos
    void actEnemigo(int tipo);//activa los sonidos enemigos 
    void desEnemigo(int tipo);//desactiva los sonidos enemigos
    //fin enemigos
    
    //niveles
    void fondoNivel(int nivel);//sonido ambiente del menu, desactiva fondo si esta activo
    //fin niveles
private:
    
    //clase singleton 
    GestorAudio();
    static GestorAudio* unica_instancia;
    //fin clase singleto private 
    
    //personaje
    sf::SoundBuffer dis,cc,def,jump,get;
    sf::Sound dis1,dis2,cc1,cc2,def1,def2,jump1,jump2,get1,get2;
    //fin personaje
    
    //menu
    sf::SoundBuffer acep,den,fondo2;
    sf::Sound acep1,den1,fondo1;
    //fin menu
    
    //enemigos
    sf::SoundBuffer e[7];
    sf::Sound en[7];
    //fin enemigos
    
    //nivel
    sf::SoundBuffer fondoNiv1,fondoNiv2;
    sf::Sound fondoNiv;
    //fin nivel
};

#endif /* GESTORAUDIO_HPP */
