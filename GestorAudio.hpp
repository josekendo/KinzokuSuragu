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
    //fin enemigos
    
    //nivel
    sf::SoundBuffer fondoNiv1,fondoNiv2;
    sf::Sound fondoNiv;
    //fin nivel
};

<<<<<<< HEAD
#endif /* GESTORAUDIO_HPP */
=======
#endif /* GESTORAUDIO_HPP */

>>>>>>> 387d132ea04062d6257be34d37211f1bd3c004c3
