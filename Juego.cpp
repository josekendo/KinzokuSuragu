/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Juego.cpp
 * Author: fv
 * 
 * Created on April 5, 2018, 10:06 AM
 */

#include "Juego.hpp"
#include "GestionArchivos.hpp"

Juego* Juego::unica_instancia = 0;

Juego::Juego() 
{
    estado = &menu;
    GestorAudio *audio = GestorAudio::getInstance();
    audio->fondo();
    motor = Motor2D::getInstance();
    camara = Camara::getInstance();
    control = Controles::getInstance();
}

void Juego::cambiarEstado(int est)
{
    GestorAudio *audio =GestorAudio::getInstance();
    if(est == 1)
    {
        audio->fondo();
    }
    switch(est)
    {
        case 1:
            estado = &menu;
            camara->setCoordenadas(400,0);
            break;
        case 2:
           estado = &jugando;
           camara->setCoordenadas(400,0);
           break;
        case 3:
            estado = &estadisticas;
            camara->setCoordenadas(400,0);
    }
}

Juego::~Juego() {
    
}

bool Juego::execVentana()
{
    return motor->execVentana();
}

void Juego::Inputs()
{
    motor->Inputs();
}

void Juego::Draw()
{
    estado->Pintar();
}

void Juego::izquierda()
{
    //menu
    if(estado->QueEstado() == 1)
    {
        if(control->getl(1))
        {
            motor->menuIZQ();
        }
    }
    //jugando
    if(estado->QueEstado() == 2)
    {
        Nivel *nivel = Nivel::getInstance();//clase global
        if(nivel->getModo() == 1)
        {
            if(control->getl(1))
            {
                nivel->moverJugadorAtras(0);
                nivel->collectElement(0);
            }
        }
        else
        {
            if(control->getl(1))
            {
                nivel->moverJugadorAtras(0);
                nivel->collectElement(0);
            }
            
            if(control->getl(2))
            {
                nivel->moverJugadorAtras(1);
                nivel->collectElement(1);
            }
        }   
    }
}

void Juego::derecha()
{
    //menu
    if(estado->QueEstado() == 1)
    {
        if(control->getr(1))
        {
            motor->menuDER();
        }
    }
    //jugando
    if(estado->QueEstado() == 2)
    {
        Nivel *nivel = Nivel::getInstance();//clase global
        if(nivel->getModo() == 1)
        {
            if(control->getr(1))
            {
                nivel->moverJugador(0);
                nivel->collectElement(0);
            }
        }
        else
        {
            if(control->getr(1))
            {
                nivel->moverJugador(0);
                nivel->collectElement(0);
            }
            
            if(control->getr(2))
            {
                nivel->moverJugador(1);
                nivel->collectElement(1);
            }
        }
    }
}

void Juego::salto()
{
    tiempo1=tiempo1+inputblock.getElapsedTime().asMilliseconds();//para el player1
    tiempo2=tiempo2+inputblock.getElapsedTime().asMilliseconds();//para el player2
    inputblock.restart();
    
    //menu
    Nivel *nivel = Nivel::getInstance();//clase global
    if(estado->QueEstado() == 1)
    {
        if(control->getu(1))
        {  
            motor->menuUP();
        }
    }
    //jugando
    if(estado->QueEstado() == 2)
    {
        Nivel *nivel = Nivel::getInstance();//clase global
        
        if(nivel->getModo() == 1)
        {
            if(control->getu(1) && tiempo1>250)
            {
                nivel->brincarJugador(0,0);//saltar jugador 0
                tiempo1=0;
            }
            else{
                nivel->brincarJugador(0,1);
            }
        }
        else
        {
            if(control->getu(1) && tiempo1>250)
            {
                nivel->brincarJugador(0,0);//saltar jugador 0
                tiempo1=0;
            }
            else{
                nivel->brincarJugador(0,1);
            }
            
            if(control->getu(2) && tiempo2>250)
            {
                nivel->brincarJugador(1,0);//saltar jugador 1
                tiempo2=0;
            }
            else{
                nivel->brincarJugador(1,1);
            }
        }
    }
}

void Juego::agacharse()
{
    //menu
    if(estado->QueEstado() == 1)
    {
        if(control->getd(1))
        {
            motor->menuDOWN();
        }
    }
    //jugando
    if(estado->QueEstado() == 2)
    {
        Nivel *nivel = Nivel::getInstance();//clase global
        if(nivel->getModo() == 1)
        {
            if(control->getd(1))
            {
                nivel->AtaqueCercano(0);//agacharse o soltar elemento 0
            }
        }
        else
        {
            if(control->getd(1))
            {
                nivel->AtaqueCercano(0);//agacharse o soltar elemento 0
            }
            
            if(control->getd(2))
            {
                nivel->AtaqueCercano(1);//agacharse o soltar elemento 1
            }
        }
    }
}

void Juego::ataque()
{
    //menu
    if(estado->QueEstado() == 1)
    {
        if(control->geta(1))
        {
            GestorAudio *audio = GestorAudio::getInstance();
            audio->aceptar();
            motor->menuSPACE();
        }
    }
    //jugando
    if(estado->QueEstado() == 2)
    {
        Nivel *nivel = Nivel::getInstance();//clase global
        if(nivel->getModo() == 1)
        {
            if(control->geta(1))
            {
                nivel->AtaqueLejano(0);//ataca jugador 0
            }
        }
        else
        {
            if(control->geta(1))
            {
                nivel->AtaqueLejano(0);//ataca jugador 0
                //nivel->crearBala(0,1,400,180,0,20);//dispara
                //ataca jugador 0
            }
            
            if(control->geta(2))
            {
                nivel->AtaqueLejano(1);//atacca jugador 1
                //nivel->crearBala(0,0,400,210,1,20);//dispara
                //atacca jugador 1
            }
        }        
    }
    //estadistica
    if(estado->QueEstado() == 3)
    {
        if(control->geta(1))
        {
            //aceptar estadisticas vuelta al menu
        }
    }
}

void Juego::defensa()
{
    //menu
    if(estado->QueEstado() == 1)
    {
        if(control->getf(1))
        {
            GestorAudio *audio = GestorAudio::getInstance();
            audio->denegar();
            motor->menuATRAS();
        }
    }
    //jugando
    if(estado->QueEstado() == 2)
    {
        Nivel *nivel = Nivel::getInstance();//clase global
        if(nivel->getModo() == 1)
        {
            if(control->getf(1) && control->geta(1) == false)
            {
                nivel->BlockJugador(0);//defensa jugador 0
            }
        }
        else
        {
            if(control->getf(1) && control->geta(1) == false)
            {
                nivel->BlockJugador(0);//defensa jugador 0
            }
            
            if(control->getf(2) && control->geta(2) == false)
            {
                nivel->BlockJugador(1);//defensa jugador 1
            }
        }      
    }
}

void Juego::quieto()
{

    if(estado->QueEstado() == 2)
    {
        Nivel *nivel = Nivel::getInstance();//clase global
        if(nivel->getModo() == 1)
        {
            if(!(control->geta(0) || control->getf(0) || control->getl(0) || control->getr(0) || control->getd(0) || control->getu(0)))
            {
                //defensa jugador 0
                nivel->IdleJugador(0);
            }
        }
        else
        {
            if(!(control->geta(1) || control->getf(1) || control->getl(1) || control->getr(1) || control->getd(1) || control->getu(1)))
            {
                //defensa jugador 0
                nivel->IdleJugador(1);
            }
            
            if(!(control->geta(0) || control->getf(0) || control->getl(0) || control->getr(0) || control->getd(0) || control->getu(0)))
            {
                //defensa jugador 1
                nivel->IdleJugador(0);
            }
        }      
    }
}

void Juego::activarSonidos(int tipo)
{ 
    GestorAudio *audio = GestorAudio::getInstance();
    audio->actEnemigo(tipo);
}

void Juego::desactivarSonidos(int tipo)
{ 
    GestorAudio *audio = GestorAudio::getInstance();
    audio->desEnemigo(tipo);
}

void Juego::sonidoMuerte()
{ 
    if(estado->QueEstado() == 2){
    GestorAudio *audio = GestorAudio::getInstance();
    audio->muerteEnemigo();
    }
}

void Juego::matarEnemigos()
{
        Nivel *niv = Nivel::getInstance();
        niv->matarEnemigos();
}

void Juego::mouse(int boton, int x, int y)
{
    //menu
    if(estado->QueEstado() == 1)
    {
        if(boton == 0)
        {
            motor->menuSPACE(x,y);
        }
        else
        {
            motor->menuATRAS();
        }
    }
}

//Nivel
void Juego::cargarNivel(int niv)
{
    Nivel *nivel = Nivel::getInstance();//clase global
    nivel->cargarNivel(niv);//llamamos a cargar nivel de nivel
    if(niv==1){
    nivel->crearEnemigo(50,10,1,3,1,1,700,222);
    nivel->crearEnemigo(50,10,1,3,1,1,1250,222);
    nivel->crearEnemigo(50,10,1,3,1,1,2100,222);
    nivel->crearEnemigo(50,10,1,3,1,1,2800,222);
    nivel->crearEnemigo(500,0,3,4,3,0,3300,155);
    nivel->crearEnemigo(50,10,1,3,1,1,4200,222);
    nivel->crearEnemigo(50,10,1,3,1,1,4900,318);
    nivel->crearEnemigo(50,10,1,3,1,1,6020,318);
    nivel->crearEnemigo(50,10,1,3,1,1,6500,254);
    nivel->crearEnemigo(50,10,1,3,1,1,7000,254);
    nivel->crearEnemigo(50,10,1,3,1,1,7700,254);
    nivel->crearEnemigo(50,10,1,3,1,1,9000,382);
    nivel->crearEnemigo(50,10,1,3,1,1,9800,254);
    nivel->crearEnemigo(1000,50,5,3,2,2,10100,222);
    }
    else if(niv==2){
    nivel->crearEnemigo(100,0,3,4,2,3,500,282);
    nivel->crearEnemigo(100,0,3,4,2,3,1200,282);
    nivel->crearEnemigo(100,0,3,4,2,3,2400,282);
    nivel->crearEnemigo(100,0,3,4,2,3,2650,282);
    nivel->crearEnemigo(100,0,3,4,2,3,3100,282);
    nivel->crearEnemigo(100,0,3,4,2,3,4065,348);
    nivel->crearEnemigo(500,0,4,2,4,4,4400,322);
    nivel->crearEnemigo(100,0,3,4,2,3,5000,188);
    nivel->crearEnemigo(100,0,3,4,2,3,5500,122);
    nivel->crearEnemigo(100,0,3,4,2,3,6300,282);
    nivel->crearEnemigo(100,0,3,4,2,3,7010,282);
    nivel->crearEnemigo(100,0,3,4,2,3,7700,282);
    nivel->crearEnemigo(100,0,3,4,2,3,9400,282);
    nivel->crearEnemigo(1000,50,5,5,6,5,11100,322);
    }
}

void Juego::cargaCompleta()
{
    //cambiaremos el estado ya que termino el loading
    cambiarEstado(2);
    //iniciamos reloj del motor
    motor->initclock();
}

void Juego::Ejecucion()
{
        if(motor->darUPDATE() > 1000/15)
        {
            //en este momento realizamos logica 
            //si hay un boton presionado hacemos la logica que sea
            if(estado->QueEstado() == 1)
            {
                ataque();
                defensa();
                agacharse();
                salto();
                derecha();            
                izquierda();
            }
            
            if(estado->QueEstado() == 2)
            {
                quieto();
                derecha();            
                izquierda();
                ataque();
                defensa();
                agacharse();
                salto();
                Nivel *niv = Nivel::getInstance();
                niv->realimentarBalas();
                niv->realimentarEnemigo();
                niv->ColBalasNivel();
            }
            
            if(estado->QueEstado() == 3)
            {
               ataque(); 
               defensa();
            }
            
            motor->reiniciarUPDATE();
        }
}

void Juego::finalNivel()
{
    GestionArchivos *gestion = GestionArchivos::getInstance();
    Nivel *nivel = Nivel::getInstance();
    gestion->guardarValores(0,nivel->getModo());
    motor->finalNivel();    
    control->offTwo();
    cambiarEstado(1);
    matarEnemigos();
}

int Juego::queEstado()
{
    return estado->QueEstado();
}