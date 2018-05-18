/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GestorAudio.cpp
 * Author: fv
 * 
 * Created on May 17, 2018, 9:01 AM
 */

#include "GestorAudio.hpp"

GestorAudio* GestorAudio::unica_instancia = 0;

GestorAudio::GestorAudio() 
{
    dis.loadFromFile("resources/Sound/Personaje/disparo1.wav");
    cc.loadFromFile("resources/Sound/Personaje/golpe.wav");
    def.loadFromFile("resources/Sound/Personaje/barrera.wav");
    jump.loadFromFile("resources/Sound/Personaje/salto.wav");
    get.loadFromFile("resources/Sound/Personaje/coger.wav"); 
    dis1.setBuffer(dis);
    dis2.setBuffer(dis);
    cc1.setBuffer(cc);
    cc2.setBuffer(cc);
    def1.setBuffer(def);
    def2.setBuffer(def);
    jump1.setBuffer(jump);
    jump2.setBuffer(jump);
    get1.setBuffer(get);
    get2.setBuffer(get);
    
    //menu
    
    acep.loadFromFile("resources/Sound/Menu/aceptar.wav");
    den.loadFromFile("resources/Sound/Menu/cancelar.wav");
    fondo2.loadFromFile("resources/Sound/Menu/sound.wav");
    acep1.setBuffer(acep);
    den1.setBuffer(den);
    fondo1.setBuffer(fondo2);
    fondo1.setLoop(true);
    
    //Niveles 
    
    fondoNiv1.loadFromFile("resources/Sound/Niveles/1.wav");
    fondoNiv2.loadFromFile("resources/Sound/Niveles/2.wav");
    fondoNiv.setLoop(true);
    
    //Enemigos
    
    e[0].loadFromFile("resources/Sound/Enemigo/giro2.ogg");
    e[1].loadFromFile("resources/Sound/Enemigo/deslizar.ogg");
    e[2].loadFromFile("resources/Sound/Enemigo/shot1.ogg");
    e[3].loadFromFile("resources/Sound/Enemigo/dog1.ogg");
    e[4].loadFromFile("resources/Sound/Enemigo/zombiesound4.ogg");
    e[5].loadFromFile("resources/Sound/Enemigo/shot3.ogg");
    e[6].loadFromFile("resources/Sound/Enemigo/shot4.ogg");
    en[0].setBuffer(e[0]);
    en[0].setVolume(100);
    en[1].setBuffer(e[1]);
    en[1].setVolume(100);
    en[2].setBuffer(e[2]);
    en[2].setVolume(100);
    en[3].setBuffer(e[3]);
    en[3].setVolume(100);
    en[4].setBuffer(e[4]);
    en[5].setBuffer(e[5]);
    en[5].setVolume(100);
    en[6].setBuffer(e[6]);
    en[6].setVolume(75);
    
}

GestorAudio::~GestorAudio() 
{
    
}

void GestorAudio::disparar(int jugador)
{
    if(jugador == 1)
    {
        dis1.play();
    }
    else
    {
        dis2.play();
    }
}

void GestorAudio::coger(int jugador)
{
    if(jugador == 1)
    {
        get1.play();
    }
    else
    {
        get2.play();
    }
}

void GestorAudio::defensa(int jugador)
{
    if(jugador == 1)
    {
        if(def1.getStatus() == sf::SoundSource::Stopped)
        def1.play();
    }
    else
    {
        if(def2.getStatus() == sf::SoundSource::Stopped)
        def2.play();
    }
}

void GestorAudio::cuerpoacuerpo(int jugador)
{
    if(jugador == 1)
    {
        if(cc1.getStatus() == sf::SoundSource::Stopped)
        cc1.play();
    }
    else
    {
        if(cc2.getStatus() == sf::SoundSource::Stopped)
        cc2.play();
    }
}

void GestorAudio::saltar(int jugador)
{
    if(jugador == 1)
    {
        jump1.play();
    }
    else
    {
        jump2.play();
    }
}

//menu

void GestorAudio::aceptar()
{
    if(acep1.getStatus() == sf::SoundSource::Stopped)
    acep1.play();
}

void GestorAudio::denegar()
{
    if(den1.getStatus() == sf::SoundSource::Stopped)
    den1.play();
}

void GestorAudio::fondo()
{
    if(!(fondoNiv.getStatus() == sf::SoundSource::Stopped))
    {
        fondoNiv.stop();
    }
    fondo1.play();
}

//enemigos

void GestorAudio::actEnemigo(int tipo)
{
    if(tipo>=0&&tipo<=5){
     if(en[tipo].getStatus() == sf::SoundSource::Stopped)
     en[tipo].play();
    if(tipo==1){
     if(en[6].getStatus() == sf::SoundSource::Stopped)
     en[6].play();
    }
    }
}

void GestorAudio::desEnemigo(int tipo)
{
    if(tipo>=0&&tipo<=5){
     if(en[tipo].getStatus() != sf::SoundSource::Stopped)
     en[tipo].stop();
    if(tipo==1){
     if(en[6].getStatus() != sf::SoundSource::Stopped)
     en[6].stop();
    }
    }
}

//nivel

void GestorAudio::fondoNivel(int nivel)
{
    if(!(fondo1.getStatus() == sf::SoundSource::Stopped))
    {
        fondo1.stop();
    }
    
    if(nivel == 1)
    {
        fondoNiv.setBuffer(fondoNiv1);
        fondoNiv.play();
    }
    else if(nivel == 2)
    {
        fondoNiv.setBuffer(fondoNiv2);
        fondoNiv.play();   
    }
}