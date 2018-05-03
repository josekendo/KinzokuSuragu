/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Enemigos.cpp
 * Author: fv
 * 
 * Created on April 5, 2018, 10:07 AM
 */

#include "Enemigos.hpp"
#include "Camara.hpp"
#include "Nivel.hpp"


Enemigos::Enemigos() 
{
    muerto = false;
    activado = false;
    vida = 100;
    defensa = 0;
    ataque = 4;
    ataquefisico = 7;
    danototal = 0;
    elemento = 0;
    motor = Motor2D::getInstance();
    motor->initEnemigo(enemigo,0);
    coordenadas = Coordenadas(400,220);
    cx = 400;
    cy = 220;
    cxo = 400;
    cyo = 220;
    //animacion
    estado = 7;//estados
    frame = 7;//numero de frames
    estado_actual= 0;
    frame_actual=-1;
    frame_refresh=80;//milisegundos
    proximo = 0;
    weapon = 0; //arma con la que inicia
    orientacion = 1;
    velocidad = 3;
}

Enemigos::Enemigos(int vid, int ataq, int ataqfisico,int element,int defen,int tipo,int x, int y) 
{
    muerto = false;
    activado = false;
    vida = vid;
    defensa = defen;
    ataque = ataq;
    ataquefisico = ataqfisico;
    danototal = 0;
    elemento = element;
    motor = Motor2D::getInstance();
    enemigo = tipo;
    motor->initEnemigo(enemigo,0);
    coordenadas = Coordenadas(x,y);
    cx = x;
    cy = y;
    cxo = x;
    cyo = y;
    //animacion
    estado = 7;//estados
    frame = 7;//numero de frames
    estado_actual= 0;
    frame_actual=-1;
    frame_refresh=80;//milisegundos
    proximo = 0;
    weapon = 0; //arma con la que inicia
    orientacion = 1;
    velocidad = 3;
}

Enemigos::Enemigos(const Enemigos& orig) {
}

Enemigos::~Enemigos() {
}

int Enemigos::getVida()
{
    return vida;
}

void Enemigos::addDano(int dano)
{
    danototal = danototal+dano;
}

void Enemigos::cambiarElemento(int element)
{
    if(element >= 0 && element <= 5)
    elemento = element;
}

void Enemigos::setDefensa(int defen)
{
    if(defen >= 0 && defen <= 100)
        defensa = defen;
}

bool Enemigos::tieneDefensa()
{
    if(defensa > 0)
        return true;
    else
        return false;
}

bool Enemigos::setDanoVida(int dano)
{
    if(defensa < dano)
    {
        vida = vida-dano;
    }
    
    if(vida > 0)
        return true;
    else
        return false;
}

int Enemigos::getDano(int element,int tipo)
{
    if(element == 0)
    {
        if(tipo == 0)//largos
        return ataque;
        else
        return ataquefisico;
    }
    
    if(element < elemento)
    {
        if(tipo == 0)//largos
        return (ataque*2);
        else
        return (ataquefisico*2);
    }
    
    if(element > elemento)
    {
        if(tipo == 0)//largos
        return (ataque/2);
        else
        return (ataquefisico/2);
    }
    
    return ataque;
}

void Enemigos::draw()
{ 
    if(proximo <= motor->darAnimacion())
    {
        proximo = motor->darAnimacion()+frame_refresh;
        
        if(frame > frame_actual)
        {
            frame_actual = frame_actual+1;
        }
        else
        {
            frame_actual = 0;
        }
    }
    //aqui llamamos a motor
    motor->drawEnemigo(enemigo,estado_actual,frame_actual, orientacion, coordenadas.getCoordenadaXI(motor->darUPDATE()),coordenadas.getCoordenadaYI(motor->darUPDATE()));
}

bool Enemigos::matarEnemigo(int point)
{
    motor->matarEnemigo(enemigo);
    return true;
}

void Enemigos::realimentar(int orientacion)
{ 
    
    if(activacion()){
       if(coordenadas.getCoordenadaX()<cxo-50){
            der = true;
            izq = false;
       }
       else if(coordenadas.getCoordenadaX()>cxo+50){
            izq = true;
            der = false;
       }
       
       if(der==true){
            coordenadas.cambiarPosicion(coordenadas.getCoordenadaXI(motor->darUPDATE())-(velocidad*-1),coordenadas.getCoordenadaY());
       }
       else if(izq==true){
           coordenadas.cambiarPosicion(coordenadas.getCoordenadaXI(motor->darUPDATE())-(velocidad*1),coordenadas.getCoordenadaY());
       }
       else{
           coordenadas.cambiarPosicion(coordenadas.getCoordenadaXI(motor->darUPDATE())-(velocidad*orientacion),coordenadas.getCoordenadaY());
       }
    }
}

bool Enemigos::sigoVivo()
{
    Camara *cam = Camara::getInstance();
    if(coordenadas.getCoordenadaX() < cam->coordenadaX()-400)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Enemigos::activacion()
{
    Camara *cam = Camara::getInstance();
    if(coordenadas.getCoordenadaX() > cam->coordenadaX()+600)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int Enemigos::getOrientacion()
{
    return orientacion;
}

int Enemigos::getX()
{
    return coordenadas.getCoordenadaX();
}

int Enemigos::getY()
{
    return coordenadas.getCoordenadaY();
}

void Enemigos::ataqueEnemigo()
{
    Nivel *niv = Nivel::getInstance();
    niv->ataqueEnemigo();
}