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
   direccion=1;
}

void Nivel::cargarNivel(int niv)
{
    level = niv;
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
    
    switch(level)
    {
        case 1:
            jugadores[0].ResetCoordenadas(40,48);
            break;
        case 2:
            jugadores[0].ResetCoordenadas(40,48);
            break;
    }
    
    for (int i=0; i<10; i++)
    {
      elementos[i].initEl(i);
      std::cout<<"Se generó elemento en posiciones: "<<elementos[i].getX()<< "  "<<elementos[i].getY()<<endl; 
    } 
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
    switch(level)
    {
        case 1:
            jugadores[0].ResetCoordenadas(40,48);
            jugadores[1].ResetCoordenadas(80,48);
            break;
        case 2:
            jugadores[0].ResetCoordenadas(40,48);
            jugadores[1].ResetCoordenadas(80,48);
            break;
    }
    for (int i=0; i<10; i++)
    {
      elementos[i].initEl(i);
      std::cout<<"Se generó elemento en posiciones: "<<elementos[i].getX()<< "  "<<elementos[i].getY(); 
    } 
    
  
}

void Nivel::draw()
{
     Motor2D *motor2D = Motor2D::getInstance();//clase global
     Juego *juego = Juego::getInstance();//clase global
     if(level==1){
     motor2D->drawCap3();
     motor2D->drawCap1();
     }
     else{
     motor2D->drawCap3();
     motor2D->drawCap1();
     motor2D->drawCap2();
     }
     //pintamos a enemigos y jugadores
     if(modo == 1)
     {
        for (int i=0; i<10; i++)
        {
          elementos[i].drawEl();
        } 
        jugadores[0].draw();
     }
     else
     {
         //std::cout << "draw de nivel m 2"  << std::endl;
        for (int i=0; i<10; i++)
        {
          elementos[i].drawEl();
        } 
        jugadores[0].draw();
        jugadores[1].draw();
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
         if(enemigos[a]->sigoVivo()&&enemigos[a]->activacion()&&juego->queEstado()==2){
            enemigos[a]->draw(); 
         }
         else
         {
             if(enemigos[a]->activacion()==true&&juego->queEstado()!=2){
             bool ver = enemigos[a]->matarEnemigo(a);
             delete enemigos[a];
             enemigos[a] = NULL;
             enemigos.erase(enemigos.begin()+a);
             }
         }
     }
         
     if(level==1){
     motor2D->drawCap2();
     }
}


void Nivel::moverJugador(int jugador)
{
    direccion=1;
    jugadores[jugador].mover();//el mira su estado actual y se movera en consecuencia (aqui deberia ir el stop cuando no se pueda mover a causa de una colision)
        
    //std::cout << "entro en nivel " << jugador << std::endl;
    if (jugadores[jugador].mover() == 1)
    {
        jugadores[jugador].Walk(1);//Función para desplazar a personaje hacia adelante
    }
    
}

void Nivel::moverJugadorAtras(int jugador)
{
    direccion=-1;
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

void Nivel::brincarJugador(int jugador,bool caida)
{  
    bool moverup=false;
    moverup=jugadores[jugador].moverArriba(direccion);
    
     if(caida==false && (jugadores[jugador].getPulsarBoton()==0) && moverup==true ){
           jugadores[jugador].Jump(direccion);//el mira su estado actual y se movera en consecuencia (aqui deberia ir el stop cuando no se pueda mover a causa de una colision)
           jugadores[jugador].setPulsarBoton();
           //std::cout<<"condicion 1"<<std::endl;
    }
     else if(caida==false && (jugadores[jugador].getPulsarBoton()==1)&& moverup==true){
         jugadores[jugador].Jump(direccion);
         jugadores[jugador].setPulsarBoton();
         jugadores[jugador].SaltoBloqueo(moverup);
         //std::cout<<"condicion 2"<<std::endl;
     }
     else if(jugadores[jugador].getPulsarBoton()!=0 && jugadores[jugador].SaltoBloqueo(moverup)==false && moverup==true){// caida en salto
        jugadores[jugador].Jump(direccion);
        //std::cout<<"condicion 3"<<std::endl;
    }
     else if(jugadores[jugador].getPulsarBoton()!=0 && jugadores[jugador].SaltoBloqueo(moverup)==true){//caida en salto
        //std::cout<<"condicion 4"<<std::endl;
        if(jugadores[jugador].moverAbajo(direccion)==true){
            //std::cout<<"condicion 4.1"<<std::endl;
             //std::cout << "entro en nivel " << jugador << std::endl;
            jugadores[jugador].Caida(direccion);
        }
        else{
            //std::cout<<"condicion 4.2"<<std::endl;
            jugadores[jugador].resetPulsarBoton(); // detecta colosion (toca suelo) y reinicia los saltos
        }
    }
    else if(caida==true){ // caida libre
        //std::cout<<"condicion 5"<<std::endl;
        if(jugadores[jugador].moverAbajo(direccion)==true){
            //std::cout<<"condicion 5.1"<<std::endl;
             //std::cout << "entro en nivel " << jugador << std::endl;
            jugadores[jugador].Caida(direccion);
        }
        else{
            //std::cout<<"condicion 5.2"<<std::endl;
            jugadores[jugador].resetPulsarBoton(); // detecta colosion (toca suelo) y reinicia los saltos
        }
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
    //std::cout<< "Orientacion: " << ori << endl;
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

void Nivel::crearEnemigo(int vid, int ataq, int ataqfisico,int element,int defen,int tipo,int x,int y)
{
    enemigos.push_back(new Enemigos(vid,ataq,ataqfisico,element,defen,tipo,x,y));
    crearBala(1, tipo, x, y, 0, ataq, 1);
}

void Nivel::realimentarEnemigo()
{ 
    for(int o = 0; o < enemigos.size();o++)
     {
            enemigos[o]->realimentar();
     }  
}

void Nivel::ataqueEnemigo()
{ 
         for(int a = 0; a < enemigos.size();a++){
                if(enemigos[a]->getX()-100-jugadores[0].getX()<10 && enemigos[a]->getX()-100-jugadores[0].getX()>-50 && enemigos[a]->getY()-174-jugadores[0].getY()<10 && enemigos[a]->getY()-174-jugadores[0].getY()>-10)  {
                     std::cout<< "ataqueeeee2 " << jugadores[0].getY() << endl;
                     std::cout<< "ataqueeeee " << enemigos[a]->getY() << endl;
                     jugadores[0].setDanoVida(enemigos[a]->getAtaqueFisico());
                 }
                if(modo==1){
                    if(enemigos[a]->getX()-100-jugadores[1].getX()<10 && enemigos[a]->getX()-100-jugadores[1].getX()>-50 && enemigos[a]->getY()-174-jugadores[1].getY()<10 && enemigos[a]->getY()-174-jugadores[1].getY()>-10)  {
                     std::cout<< "ataqueeeee " << enemigos[a]->getX() << endl;
                     std::cout<< "ataqueeeee2 " << jugadores[1].getX() << endl;
                     jugadores[1].setDanoVida(enemigos[a]->getAtaqueFisico());
                 }
                }
          }
}

void Nivel::matarEnemigo()
{ 
    for(int o = 0; o < enemigos.size();o++)
     {
            enemigos[o]->matarEnemigo(o);
     }  
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

void Nivel::collectElement(int jugador)
{
    for (int i = 0; i < 10; i++)
    {
        if (jugadores[jugador].ColisionElemento(jugador, i) == true)
        {
            std::cout<<"Recogió el elemento"<<endl;
            if (i == 0 || i == 5)
                jugadores[jugador].cambiarElemento(0);
            else if (i == 1 || i == 6)
                jugadores[jugador].cambiarElemento(1);
            else if (i == 2 || i == 7)
                jugadores[jugador].cambiarElemento(2);
            else if (i == 3 || i == 8)
                jugadores[jugador].cambiarElemento(3);
            else if (i == 4 || i == 9)
                jugadores[jugador].cambiarElemento(4);

            elementos[i].ChangeCoords(elementos[i].getX(), -500);
        }
    }
    
        
                
        
}

Nivel::~Nivel()
{
    unica_instancia = 0;
}

void Nivel::resetJugador(int jug,int xr,int yr)
{
    jugadores[jug].ResetCoordenadas(xr,yr);
}