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
#include <iostream>

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
    std::cout << " dano recibido " << dano << "\n";
    std::cout << " vida enemigo " << vida << "\n";  
    std::cout << " defensa enemigo " << defensa << "\n";
    if(defensa < dano)
    {
        vida = vida-dano;
    }
    
    if(vida > 0){
        return true;
    }
    else{
        muerto = true;
        return false;
    }
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
    if(muerto==false){
    motor->matarEnemigo(enemigo);
    }
    muerto = true;
    return true;
}

void Enemigos::realimentar()
{ 
    
    if(activacion()&&enemigo!=5){
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
            orientacion = -1;
       }
       else if(izq==true){
           coordenadas.cambiarPosicion(coordenadas.getCoordenadaXI(motor->darUPDATE())-(velocidad*1),coordenadas.getCoordenadaY());
           orientacion = 1;
       }
       else{
           coordenadas.cambiarPosicion(coordenadas.getCoordenadaXI(motor->darUPDATE())-(velocidad*-1),coordenadas.getCoordenadaY());
           orientacion = -1;
       }
    }
}

bool Enemigos::sigoVivo()
{
    Camara *cam = Camara::getInstance();
    if(coordenadas.getCoordenadaX() < cam->coordenadaX()-450||muerto==true)
    {
        matarEnemigo(enemigo);
        muerto = true;
        return false;
    }
    else
    {
        muerto = false;
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

void Enemigos::setOrientacion(int ori)
{
    orientacion=ori;
}

int Enemigos::getX()
{
    return coordenadas.getCoordenadaX();
}

int Enemigos::getY()
{
    return coordenadas.getCoordenadaY();
}

int Enemigos::getAtaqueFisico()
{
    return ataquefisico;
}

int Enemigos::getAtaqueLejano()
{
    return ataque;
}

int Enemigos::getTipoEnemigo()
{
    return enemigo;
}
