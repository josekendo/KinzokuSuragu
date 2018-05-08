/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bullet.cpp
 * Author: fv
 * 
 * Created on April 9, 2018, 10:09 AM
 */

#include "Bullet.hpp"
#include "Motor2D.hpp"
#include "Camara.hpp"
using namespace std;

Bullet::Bullet(int tipo, int elemento, int x, int y, int jugador, int dano, int ori)
{
    //creamos bala en el motor2d
    Motor2D *motor = Motor2D::getInstance();
    motor->crearBala(tipo,elemento, ori);
    //fin de creacion
    orientacion = ori;
    tipob =tipo;
    elementob = elemento;
    jugadorb = jugador;
    danob = dano;
    coordenadas = Coordenadas(x,y);
    velocidad = 14;
    ini = true;
}

Bullet::~Bullet() {
}

void Bullet::draw(int point)
{
    //aqui llamamos a motor
    Motor2D *motor = Motor2D::getInstance();
    motor->drawBala(point,coordenadas.getCoordenadaXI(motor->darUPDATE()),coordenadas.getCoordenadaYI(motor->darUPDATE()));
}

bool Bullet::matarBala(int point)
{
    Motor2D *motor = Motor2D::getInstance();
    motor->matarBala(point);
    return true;
}

void Bullet::realimentar(int ori)
{
    Motor2D *motor = Motor2D::getInstance();
    /*if (ori == -1)
        Coordenadas(coordenadas.getCoordenadaX())*/
    coordenadas.cambiarPosicion(coordenadas.getCoordenadaXI(motor->darUPDATE())+(velocidad*ori),coordenadas.getCoordenadaY());
    
    //if(ori == -1)
        //std::cout<< "Orientacion ha cambiado" << ori << endl;
        //std::cout<< "Posicion de bala en X: " << coordenadas.getCoordenadaXI(motor->darUPDATE()) << endl;
}

int Bullet::getOri()
{
    return orientacion;
}

bool Bullet::sigoViva()
{
    Camara *cam = Camara::getInstance();
    if(coordenadas.getCoordenadaX() > cam->coordenadaX()+400 || coordenadas.getCoordenadaX() < cam->coordenadaX()-400)
    {
        return false;
    }
    else
    {
        return true;
    }
}


