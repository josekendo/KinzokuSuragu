/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nivel.cpp
 * Author: fv
 * 
 * Created on April 5, 2018, 10:18 AM
 */

#include "Nivel.hpp"
#include "Hud.hpp"

Nivel* Nivel::unica_instancia = 0;

Nivel::Nivel() 
{
    
}

void Nivel::cargarNivel(int niv)
{
    switch(niv)
    {
        case 1:
            fabrica.construirNivel("resources/niveles/1.xml","resources/1.png");
        break;
        case 2:
            fabrica.construirNivel("resources/niveles/2.xml","resources/2.png");
        break;
        case 3:
            fabrica.construirNivel("resources/niveles/3.xml","resources/3.png");
        break;
        case 4:
            fabrica.construirNivel("resources/niveles/4.xml","resources/4.png");
        break;
    }
}
//carga de un jugador
void Nivel::juegoIndividual(int tipo)
{
    Controles *con = Controles::getInstance();
    con->offTwo();
    modo = 1;
    
    if(tipo == 0)//masculino jugador 1
    {
      jugadores[0].initJugador(0,1);  
      
    }
    else if(tipo == 1)//femenino jugador 1
    {
      jugadores[0].initJugador(1,1);  
    }    
    
    jugadores[0].ResetCoordenadas(40,48);
    
    //elementos[0].initEl(0); 
}
//carga de dos jugadores
void Nivel::juegoMultijugador(int tipo1, int tipo2)
{
    Controles *con = Controles::getInstance();
    con->onTwo();
    modo = 2;
    if(tipo1 == 0)//masculino jugador 1
    {
        jugadores[0].initJugador(0,1);  
    }
    if(tipo1 == 1)//femenino jugador 1
    {
        jugadores[0].initJugador(1,1);  
    }
    if(tipo2 == 0)//maculino jugador 2
    {
        jugadores[1].initJugador(0,2);  
    }
    if(tipo2 == 1)//femenino jugador 2
    {
        jugadores[1].initJugador(1,2);  
    }
    jugadores[0].ResetCoordenadas(40,48);
    jugadores[1].ResetCoordenadas(80,48);
    elementos[0].initEl(0);
  
}

void Nivel::draw()
{
     Motor2D *motor2D = Motor2D::getInstance();//clase global
     motor2D->drawCap3();
     motor2D->drawCap1();
     //pintamos a enemigos y jugadores
     if(modo == 1)
     {
          //for (int i = 0; i > 5; i++)
         //{
         //}
         std::cout << "draw de nivel m 1" << std::endl;
         elementos[0].drawEl();
         jugadores[0].draw();
         
         //jugadores[0].Idle(1);
        
     }
     else
     {
         //std::cout << "draw de nivel m 2"  << std::endl;
         jugadores[0].draw();
         elementos[0].drawEl();
         
        //jugadores[0].Idle(1); //Estado default
         jugadores[1].draw();
         //jugadores[1].Idle(1); //Estado default
         
         /*for (int i = 0; i > 10; i++)
         {
             elementos[i]->drawElemento(i);
         */
   
     } 
     //pintamos balas
      
     int contador = 0;
     for(int a = 0; a < bullet.size();a++)
     {
         if(bullet[a]->sigoViva())
            bullet[a]->draw(a);
         else
         {
             
             bool ver = bullet[a]->matarBala(a);
             delete bullet[a];
             bullet[a] = NULL;
             bullet.erase(bullet.begin()+a);
             //std::cout << "se borra bala " << a << "\n";
         }
     }
      for(int a = 0; a < enemigos.size();a++)
     {
         if(enemigos[a]->sigoVivo())
            enemigos[a]->draw();
         else
         {
             
             bool ver = enemigos[a]->matarEnemigo(a);
             delete enemigos[a];
             enemigos[a] = NULL;
             enemigos.erase(enemigos.begin()+a);
             //std::cout << "se borra bala " << a << "\n";
         }
     }
         
     
     motor2D->drawCap2();
}

void Nivel::moverJugador(int jugador)
{
    jugadores[jugador].mover();//el mira su estado actual y se movera en consecuencia (aqui deberia ir el stop cuando no se pueda mover a causa de una colision)
        
    //std::cout << "entro en nivel " << jugador << std::endl;
    if (jugadores[jugador].mover() == 1)
    {
        jugadores[jugador].Walk(1);//Función para desplazar a personaje hacia adelante
    
    }
    
}

void Nivel::moverJugadorAtras(int jugador)
{
    //std::cout << "entro en nivel " << jugador << std::endl;
    jugadores[jugador].moverAtras();//el mira su estado actual y se movera en consecuencia (aqui deberia ir el stop cuando no se pueda mover a causa de una colision)
    
      //std::cout << "entro en nivel " << jugador << std::endl;
    if (jugadores[jugador].moverAtras() == 1)
    {
       
        jugadores[jugador].Walk(-1);//función para desplazar a personaje hacia atrás
    
    }
    else if (jugadores[jugador].moverAtras() == 0)
    {
        jugadores[jugador].Idle();//Función de estado default
    }
}

void Nivel::brincarJugador(int jugador)
{
    jugadores[jugador].mover();//el mira su estado actual y se movera en consecuencia (aqui deberia ir el stop cuando no se pueda mover a causa de una colision)
        
    //std::cout << "entro en nivel " << jugador << std::endl;
    if (jugadores[jugador].mover() == 1)
    {
        jugadores[jugador].Jump();//Función para desplazar que brinque el personaje
    
    }
    else if (jugadores[jugador].mover() == 0)
    {
        jugadores[jugador].Idle();//Función de estado default
    }
    
}

void Nivel::AtaqueCercano(int jugador)
{
    if (jugadores[jugador].isMoving() != 1)
    {
        jugadores[jugador].Kick(); //Función para que el personaje Patee (ataquecercano) 
    }
}

void Nivel::AtaqueLejano(int jugador)
{
   
    
    int x = jugadores[jugador].getX();
    int y = jugadores[jugador].getY();
    int elemento = jugadores[jugador].getElement();
    int tipo = jugadores[jugador].getType();
    int dano = jugadores[jugador].getDano(elemento, tipo);
    int ori = jugadores[jugador].getOri();
    std::cout<< "Orientacion: " << ori << endl;
    crearBala(tipo, elemento, x, y, jugador, dano, ori);
    jugadores[jugador].Shoot();//Función para que el personaje Dispare (ataquelejano)
    
}
    


void Nivel::IdleJugador(int jugador)
{
    jugadores[jugador].Idle();//Función de estado default
}

void Nivel::BlockJugador(int jugador)
{
    if (jugadores[jugador].isMoving() != 1 )
    {
        jugadores[jugador].Block(); //Función para que el personaje Patee (ataquecercano) 
    }
}




int Nivel::getModo()
{
    return modo;
}

int Nivel::separacion()
{
    if(modo == 2)
    {
        int newS = jugadores[0].getX() - jugadores[1].getX();
        return abs(newS);
    }       
    return 0;
}

void Nivel::crearBala(int tipo, int elemento, int x, int y, int jugador, int dano, int ori)
{
    bullet.push_back(new Bullet(tipo,elemento,x,y,jugador,dano, ori));
}

void Nivel::realimentarBalas()
{
    
     for(int o = 0; o < bullet.size();o++)
     {
         
            bullet[o]->realimentar(bullet[o]->getOri());
         
     }  
     
}

void Nivel::crearEnemigo(int vid, int ataq, int ataqfisico,int element,int defen,int tipo)
{
    enemy = tipo;
    enemigos.push_back(new Enemigos(vid,ataq,ataqfisico,element,defen,tipo));
}

void Nivel::realimentarEnemigo()
{
}

int * Nivel::devolverEstadisticas()
{
    int * jug = new int[6];
    int * jug1 = jugadores[0].devolverEstadisticas();
    int * jug2 = jugadores[1].devolverEstadisticas();
    jug[0] = jug1[0];
    jug[1] = jug1[1];
    jug[2] = jug1[2];
    jug[3] = jug2[0];
    jug[4] = jug2[1];
    jug[5] = jug2[2];
    delete jug1;
    delete jug2;
    return jug;
}

/*void Nivel::collectElement()
{
    if (modo == 1) //SI SOLO HAY UN JUGADOR
    {
        for (int i = 0; i > 5; i++)
        {
            if (jugadores[0].getX() == elementos[i].getX() && jugadores[0].getY() == elementos[i].getY()) // SI HAY COLISION DE JUGADOR Y ELEMENTO
            {
                if (i == 0)
                    jugadores[0].cambiarElemento(i);
                else if (i == 1)
                    jugadores[0].cambiarElemento(i);
                else if (i == 2)
                    jugadores[0].cambiarElemento(i);
                else if (i == 3)
                    jugadores[0].cambiarElemento(i);
                else if (i == 4)
                    jugadores[0].cambiarElemento(i);
                
                
                elementos[i].eraseEl(i);
            
            }
        
        
        }
    }
    
    else if (modo == 2) //SI HAY DOS JUGADORES
    {
        
        for (int k = 0; k > 10; k++)
        {
            if (jugadores[0].getX() == elementos[k].getX() && jugadores[0].getY() == elementos[k].getY()) // SI HAY COLISION DE JUGADOR Y ELEMENTO
            {
                
                if (k == 0 || k == 5)
                    jugadores[0].cambiarElemento(0);
                else if (k == 1|| k == 6)
                    jugadores[0].cambiarElemento(1);
                else if (k == 2|| k == 7)
                    jugadores[0].cambiarElemento(2);
                else if (k == 3|| k == 8)
                    jugadores[0].cambiarElemento(3);
                else if (k == 4|| k == 9)
                    jugadores[0].cambiarElemento(4);
                
                elementos[k].eraseEl(k);
            
            }
            
            if (jugadores[1].getX() == elementos[k].getX() && jugadores[1].getY() == elementos[k].getY()) // SI HAY COLISION DE JUGADOR Y ELEMENTO
            {
                
                 if (k == 0 || k == 5)
                    jugadores[1].cambiarElemento(0);
                else if (k == 1|| k == 6)
                    jugadores[1].cambiarElemento(1);
                else if (k == 2|| k == 7)
                    jugadores[1].cambiarElemento(2);
                else if (k == 3|| k == 8)
                    jugadores[1].cambiarElemento(3);
                else if (k == 4|| k == 9)
                    jugadores[1].cambiarElemento(4);
                
                elementos[k].eraseEl(k);
            
            }
        
        }
    
    }

}*/