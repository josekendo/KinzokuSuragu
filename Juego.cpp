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

Juego* Juego::unica_instancia = 0;

Juego::Juego() 
{
    estado = &menu;
    motor = Motor2D::getInstance();
    camara = Camara::getInstance();
    control = Controles::getInstance();
}

void Juego::cambiarEstado(int est)
{
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
    //jugando
    if(estado->QueEstado() == 2)
    {
        Nivel *nivel = Nivel::getInstance();//clase global
        if(nivel->getModo() == 1)
        {
            if(control->getl(1))
            {
                nivel->moverJugadorAtras(0);
            }
        }
        else
        {
            if(control->getl(1))
            {
                nivel->moverJugadorAtras(0);
            }
            
            if(control->getl(2))
            {
                nivel->moverJugadorAtras(1);
            }
        }   
    }
}

void Juego::derecha()
{
    //jugando
    if(estado->QueEstado() == 2)
    {
        Nivel *nivel = Nivel::getInstance();//clase global
        if(nivel->getModo() == 1)
        {
            if(control->getr(1))
            {
                nivel->moverJugador(0);
            }
        }
        else
        {
            if(control->getr(1))
            {
                nivel->moverJugador(0);
            }
            
            if(control->getr(2))
            {
                nivel->moverJugador(1);
            }
        }
    }
}

void Juego::salto()
{
    //menu
    Nivel *nivel = Nivel::getInstance();//clase global
    if(estado->QueEstado() == 1)
    {
        if(control->getu(1))
        {
            motor->menuUP();
            nivel->brincarJugador(0);
        }
    }
    //jugando
    if(estado->QueEstado() == 2)
    {
        Nivel *nivel = Nivel::getInstance();//clase global
        if(nivel->getModo() == 1)
        {
            if(control->getu(1))
            {
                nivel->brincarJugador(0);//saltar jugador 0
            }
        }
        else
        {
            if(control->getu(1))
            {
                nivel->brincarJugador(0);//saltar jugador 0
            }
            
            if(control->getu(2))
            {
                nivel->brincarJugador(1);//saltar jugador 1
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
<<<<<<< HEAD
                nivel->AtaqueLejano(0);//ataca jugador 0
=======
                nivel->crearBala(0,1,400,180,0,20);//dispara
                //ataca jugador 0
>>>>>>> master
            }
            
            if(control->geta(2))
            {
<<<<<<< HEAD
                nivel->AtaqueLejano(1);//atacca jugador 1
=======
                nivel->crearBala(0,0,400,210,1,20);//dispara
                //atacca jugador 1
>>>>>>> master
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
        motor->menuATRAS();
    }
    //jugando
    if(estado->QueEstado() == 2)
    {
        Nivel *nivel = Nivel::getInstance();//clase global
        if(nivel->getModo() == 1)
        {
            if(control->getf(1))
            {
                nivel->BlockJugador(0);//defensa jugador 0
            }
        }
        else
        {
            if(control->getf(1))
            {
                nivel->BlockJugador(0);//defensa jugador 0
            }
            
            if(control->getf(2))
            {
                nivel->BlockJugador(1);//defensa jugador 1
            }
        }      
    }
}

void Juego::quieto()
{
    //
    if(estado->QueEstado() == 2)
    {
        Nivel *nivel = Nivel::getInstance();//clase global
        if(nivel->getModo() == 1)
        {
            if(control->getf(1))
            {
                //defensa jugador 0
            }
        }
        else
        {
            if(control->getf(1))
            {
                //defensa jugador 0
            }
            
            if(control->getf(2))
            {
                //defensa jugador 1
            }
        }      
    }
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
    //jugando
    if(estado->QueEstado() == 2)
    {
    
    }
    //estadistica
    if(estado->QueEstado() == 3)
    {
    
    }
}

//Nivel
void Juego::cargarNivel(int niv)
{
    Nivel *nivel = Nivel::getInstance();//clase global
    nivel->cargarNivel(niv);//llamamos a cargar nivel de nivel
}

void Juego::cargaCompleta()
{
    //cambiaremos el estado ya que termino el loading
    cambiarEstado(2);
}

void Juego::Ejecucion()
{
        if(motor->darUPDATE() > 1000/15)
        {
            //en este momento realizamos logica 
            //si hay un boton presionado hacemos la logica que sea
            derecha();            
            izquierda();
            ataque();
            defensa();
            agacharse();
            salto();
            Nivel *niv = Nivel::getInstance();
            niv->realimentarBalas();
            motor->reiniciarUPDATE();
        }
}