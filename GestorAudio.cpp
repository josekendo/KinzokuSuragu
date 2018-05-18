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
    
    e1.loadFromFile("resources/Sound/Enemigo/giro2.ogg");
    e2.loadFromFile("resources/Sound/Enemigo/deslizar.ogg");
    e3.loadFromFile("resources/Sound/Enemigo/shot1.ogg");
    e4.loadFromFile("resources/Sound/Enemigo/dog1.ogg");
    e5.loadFromFile("resources/Sound/Enemigo/zombiesound4.ogg");
    e6.loadFromFile("resources/Sound/Enemigo/shot3.ogg");
    en1.setBuffer(e1);
    en1.setVolume(75);
    en2.setBuffer(e2);
    en2.setVolume(50);
    en3.setBuffer(e3);
    en3.setVolume(50);
    en4.setBuffer(e4);
    en4.setVolume(50);
    en5.setBuffer(e5);
    en6.setBuffer(e6);
    en6.setVolume(25);
    
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

void GestorAudio::enemigo(int tipo)
{
    if(tipo=0){
    if(en1.getStatus() == sf::SoundSource::Stopped)
    en1.play();
    }
    if(tipo=1){
    if(en2.getStatus() == sf::SoundSource::Stopped)
    en2.play();
    }
    if(tipo=2){
    if(en3.getStatus() == sf::SoundSource::Stopped)
    en3.play();
    }
    if(tipo=3){
    if(en4.getStatus() == sf::SoundSource::Stopped)
    en4.play();
    }
    if(tipo=4){
    if(en5.getStatus() == sf::SoundSource::Stopped)
    en5.play();
    }
    if(tipo=5){
    if(en6.getStatus() == sf::SoundSource::Stopped)
    en6.play();
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