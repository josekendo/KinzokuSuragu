/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Jugadores.cpp
 * Author: fv
 * 
 * Created on April 5, 2018, 10:07 AM
 */

#include "Jugadores.hpp"
#include "Camara.hpp"
#include "Nivel.hpp"
#include <iostream>
#define kVel 5
using namespace std;

Jugadores::Jugadores() 
{
    vida = 100;
    defensa = 0;
    ataque = 4;
    ataquefisico = 7;
    muertes = 0;
    danototal = 0;
    elemento = 0;
    //Fin stats
    motor = Motor2D::getInstance();
    //animacion
    estado = 7;//estados
    frame = 7;//numero de frames
    estado_actual= 0;
    frame_actual=-1;
    frame_refresh=80;//milisegundos
    proximo = 0;
    weapon = 0; //arma con la que inicia
    orientacion = 1;
    stat = 0; //dice si el personaje está en movimiento o no
    danoecho = 0;
    boton=0;
    saltoref=-500;
    aceleracion=0;
    dimensiones= motor->getDimensiones(-1);//el -1 es para el sprite del heroe/gato
}

Jugadores::Jugadores(const Jugadores& orig) {
}

Jugadores::~Jugadores() {
}


int Jugadores::getVida()
{
    return vida;
}

void Jugadores::addMuerte()
{
    muertes= muertes+1;
    
    Die();
}

void Jugadores::Idle()
{
    estado = 0;
    estado_actual = estado;
    frame = 7;
    stat = 0;
    //draw();
    
}

void Jugadores::Walk(int dir)
{
    
    estado = 1;
    frame = 7;
    Camara *camara = Camara::getInstance();
    //SI DIR = 1 VA A LA DERECHA
    //SI DIR = -1 VA A LA IZQUIERDA
     estado_actual = estado;
    orientacion = dir;
    orientacion_actual = orientacion;
    stat = 1;
    if (dir == 1)
    {  
        if(camara->mePuedoMover(coordenadas.getCoordenadaXI(motor->darUPDATE())+kVel,coordenadas.getCoordenadaYI(motor->darUPDATE())))
        coordenadas.cambiarPosicion(coordenadas.getCoordenadaXI(motor->darUPDATE())+kVel,coordenadas.getCoordenadaYI(motor->darUPDATE()));
        //posX = coordenadas.getCoordenadaX();
        //std::cout<<"Nueva posicion en X"<<posX<<endl;
    }
    else if (dir == -1)
    {
        if(camara->mePuedoMover(coordenadas.getCoordenadaXI(motor->darUPDATE())-kVel,coordenadas.getCoordenadaYI(motor->darUPDATE())))
        coordenadas.cambiarPosicion(coordenadas.getCoordenadaXI(motor->darUPDATE())-kVel,coordenadas.getCoordenadaYI(motor->darUPDATE()));
    }
    //draw();
   
    //std::cout<< "Mover está en estado: " << mover() << std::endl;
}



void Jugadores::Shoot()
{
    frame = 7;
    
    if (stat == 0)
    {
        estado = 2;
        estado_actual = estado;
    }
    else if (stat == 1)
    {
        estado = 7;
        estado_actual = estado;
    
    }
}

void Jugadores::Kick()
{
    estado = 3;
    estado_actual = estado;
    frame = 7;
    stat = 0;
  
    
}

void Jugadores::Block()
{
    if(estado == 4)//esto significa que ya estaba este estado por lo que tenemos que ponerlo en el frame de bloqueo
    {
        estado_actual = 4;
        if(frame_actual >= 4)
        {
            frame_actual = 4;
            stat = 0;
            frame = 7;
        }
    }
    else
    {
        estado = 4;
        estado_actual = estado;
        frame = 7;
        stat = 0;    
    }
}

void Jugadores::Jump(int dir)
{
    estado = 5;
    estado_actual = estado;
    orientacion = dir;
    frame = 9;
    stat = 0;
    int x=coordenadas.getCoordenadaXI(motor->darUPDATE());
    int y=coordenadas.getCoordenadaYI(motor->darUPDATE())-((kVel*8));
    /*if(aceleracion<kVel*2){
        aceleracion=aceleracion+0.3;
    }*/
        coordenadas.cambiarPosicion(x,y);
        
    draw();
}
void Jugadores::Caida(int dir){
    estado = 5;
    estado_actual = estado;
    orientacion = dir;
    frame = 9;
    stat = 0;
    int x=coordenadas.getCoordenadaXI(motor->darUPDATE());
    int y=coordenadas.getCoordenadaYI(motor->darUPDATE())+(kVel*2);
    /*if(aceleracion<kVel*2){
        aceleracion=aceleracion+0.3;
    }*/
    coordenadas.cambiarPosicion(x,y);
}
bool Jugadores::SaltoBloqueo(bool moverup){ //controla la altura maxima del salto
    bool bloqueo=false;
    float n=2;
    
    int y=coordenadas.getCoordenadaYI(motor->darUPDATE());
    
    if(getPulsarBoton()==2){//solo en estos dos casos actualizara la referencia de salto
        saltoref=y;
        //aceleracion=0;
        setEn4();
        //std::cout<<"botton dos veces pulsado"<<std::endl;
    }
    else if(getPulsarBoton()==1 && saltoref==-500){
        saltoref=y;
        //std::cout<<"boton una vez pulsado"<<std::endl;
    }
    
    if(saltoref>-500){
        if(saltoref-y>32*n || moverup==false){
            saltoref=-600;
            //aceleracion=0;
            bloqueo=true;
        }
        else{
            bloqueo=false;
        }
    }
    else if(saltoref==-600){
         //std::cout<<"salto ref -600**"<<std::endl;
        bloqueo=true;
    }
   
    return bloqueo;
}
void Jugadores::Die()
{
    estado = 6;
    estado_actual = estado;
    //SI DIR = 1 VA A LA DERECHA
    //SI DIR = -1 VA A LA IZQUIERDA
    
    
        if(proximo <= motor->darAnimacion()) // ANIMACIÓN DE DEFENSA 
        {
            proximo = motor->darAnimacion()+frame_refresh;

            if(frame > frame_actual)
            {
                frame_actual = frame_actual+1;
            }
            else
            {

            }
        }
        motor->drawPersonaje(player-1,estado_actual,frame_actual, orientacion, coordenadas.getCoordenadaXI(motor->darUPDATE()),coordenadas.getCoordenadaYI(motor->darUPDATE()));
        //CHECK COLISION == FALSE;
}


void Jugadores::addDano(int dano)
{
    danototal = danototal+dano;
}

void Jugadores::cambiarElemento(int element)
{
    if(element >= 0 && element <= 5)
    elemento = element;
}

void Jugadores::setDefensa(int defen)
{
    if(defen >= 0 && defen <= 100)
        defensa = defen;
}

void Jugadores::initJugador(int tip, int play)
{
    //std::cout << play << " tipo textura - " << tip  << " t "<< std::endl;
    motor->initPersonaje(play,tip);
    tipo = tip;
    
    player = play;
    
    if(play <= 1)
    {
        coordenadas = Coordenadas(20,220);
    }
    else
    {
        coordenadas = Coordenadas(80,220);
    }
}

void Jugadores::draw()
{
    //std::cout << " x " << coordenadas.getCoordenadaX() << " y " << coordenadas.getCoordenadaY() << std::endl;
    /*comprobamos que animacion sea mayor que el frame que le hayamos dado de refresco*/
    
    if(proximo <= motor->darAnimacion())
    {
        proximo = motor->darAnimacion()+frame_refresh;
        
        if(frame > frame_actual)
        {
            frame_actual = frame_actual+1;
        }
        else
        {
            if (estado == 4)
                frame_actual = 7;
            else if (estado == 6)
                frame_actual = 7;
            else
                frame_actual = 0;
        }
    }
    //std::cout<< "Se está dibujando el personaje " << std::endl;
    
    if (stat == 1)
    {
        motor->drawPersonaje(player-1,estado_actual,frame_actual,orientacion, coordenadas.getCoordenadaX(),coordenadas.getCoordenadaY());
    }
    else if (stat == 0)
    {
        motor->drawPersonaje(player-1,estado_actual,frame_actual, orientacion, coordenadas.getCoordenadaXI(motor->darUPDATE()),coordenadas.getCoordenadaYI(motor->darUPDATE()));
    
    }
    
}

bool Jugadores::mover() 
{
    //segun estado ponemos una velocidad o otra
    //comprobar colisiones
    //obtenemos la posicion en la que estamos segun su tiempo de interpolacion
    //std::cout << "entro en jugador" << std::endl;
    //int mov = 5;
    int mov = kVel;
    int x=coordenadas.getCoordenadaXI(motor->darUPDATE())+mov;
    int y=coordenadas.getCoordenadaYI(motor->darUPDATE());
    Camara *camara = Camara::getInstance();
    Nivel *niv = Nivel::getInstance();
    if(colision->ColisionLateral(x,y,dimensiones,1)==false)
    {
        //std::cout << "true moviendo" << std::endl;  
        //coordenadas.cambiarPosicion(coordenadas.getCoordenadaXI(motor->darUPDATE())+mov,coordenadas.getCoordenadaYI(motor->darUPDATE()));
       
        return 1;
    }
    else //obtenemos el movimiento maximo
    {
        //std::cout << "false moviendo" << std::endl;
        
        return 0;
    }
        
}

bool Jugadores::moverAtras()
{
    //segun estado ponemos una velocidad o otra
    //comprobar colisiones
    //obtenemos la posicion en la que estamos segun su tiempo de interpolacion
    //std::cout << "entro en jugador" << std::endl;
   
    int mov = -kVel;
    int x=coordenadas.getCoordenadaXI(motor->darUPDATE())-mov;
    int y=coordenadas.getCoordenadaYI(motor->darUPDATE());
    Camara *camara = Camara::getInstance();
    
    if(colision->ColisionLateral(x,y,dimensiones,-1)==false)
    {
        
        return  1;
    }
    else //obtenemos el movimiento maximo
    {
        //std::cout << "false moviendo" << std::endl;
       
        return 0;
    }
}
bool Jugadores::moverAbajo(int direccion){
    int mov=kVel*2;
    int x=coordenadas.getCoordenadaXI(motor->darUPDATE());
    int y=coordenadas.getCoordenadaYI(motor->darUPDATE())+mov;
    
    if(colision->ColisionSuelo(x,y,dimensiones,direccion)==true){//si colisiona
        return false;
    }
    else{
        return true;
    }
}
bool Jugadores::moverArriba(int direccion){
    int mov=kVel*8;
    int x=coordenadas.getCoordenadaXI(motor->darUPDATE());
    int y=coordenadas.getCoordenadaYI(motor->darUPDATE())-mov;
    
    if(colision->ColisionTecho(x,y,dimensiones,direccion)==true){//si colisiona
        return false;
    }
    else{
        
        return true;
    }
}

bool Jugadores::isMoving() 
{
    if(stat == 1)
    {
        return 1;
    }
    else 
    {
        //std::cout << "false moviendo" << std::endl;
        return 0;
    }
}

bool Jugadores::tieneDefensa()
{
    if(defensa > 0)
        return true;
    else
        return false;
}

bool Jugadores::setDanoVida(int dano)
{
    if(defensa < dano)
    {
        vida = vida-dano;
        addDano((dano));
    }
    
    if(tieneDefensa() == 1)
    {
        if (defensa == 100)
        {
            vida = vida - (dano/2);
            addDano((dano/2));
        }
    
    }
    
    if(vida > 0)
        return true;
    else
    {
        addMuerte();
        return false;
    }
}

bool Jugadores::setVida(int vid)
{
    if(vid < 100)
    {
        if((vid+vida) >= 100)
        {
            vida = 100;
            return true;
        }
        else
        {
            vida = (vid+vida);
            return true;
        }
    }
    
    return false;
}

int Jugadores::getDano(int element,int tipo)
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

int Jugadores::getX()
{
    return coordenadas.getCoordenadaX();
}

int Jugadores::getY()
{
    return coordenadas.getCoordenadaY();
}

int Jugadores::getElement()
{
    return elemento;
}

int Jugadores::getType()
{
    return tipo;
}

int Jugadores::getOri()
{
    return orientacion_actual;
}

void Jugadores::ResetCoordenadas(int xn, int yn)
{
    coordenadas.ResetCoordenadas(xn,yn);
}

int * Jugadores::devolverEstadisticas()
{
    int * estas = new int[3];//muertes, danoecho, danototal(recibido)
    estas[2] = danototal;
    estas[1] = danoecho;
    estas[0] = muertes;
    return estas;
}
int Jugadores::getPulsarBoton(){
    
    return boton;
}
void Jugadores::setPulsarBoton(){
    if(boton<3){
        boton++;
    }
}
void Jugadores::setEn4(){
    boton=4;;
}
void Jugadores::resetPulsarBoton(){
    boton=0;
    saltoref=-500;
    aceleracion=0;
}

bool Jugadores::ColisionElemento(int player, int el)
{
    if (motor->ElementCol(player, el) == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
