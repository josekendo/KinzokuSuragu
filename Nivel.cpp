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
    GestorAudio *audio = GestorAudio::getInstance();
    level = niv;
    switch(niv)
    {
        case 1:
            fabrica.construirNivel("resources/niveles/1.xml","resources/1.png");
            audio->fondoNivel(1);
        break;
        case 2:
            fabrica.construirNivel("resources/niveles/2.xml","resources/2.png");
            audio->fondoNivel(2);
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
     Hud *hud = Hud::getInstance();
     
     motor2D->drawCap1();  
     motor2D->drawCap2(); 
        
     //pintamos a enemigos y jugadores
     if(modo == 1)
     {
        //llamamos a hud para que se actualice
        hud->cambiarVida(1,jugadores [0].getVida()); 
        for (int i=0; i<10; i++)
        {
          elementos[i].drawEl();
        } 
        jugadores[0].draw();
     }
     else
     {
         //llamamos a hud para que se actualice
         hud->cambiarVida(1,jugadores [0].getVida()); 
         hud->cambiarVida(2,jugadores [1].getVida()); 
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
     
     motor2D->drawCap3();
     motor2D->drawCap4();
     
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
         
     motor2D->drawCap5();
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
    bool moverup=jugadores[jugador].moverArriba(direccion);
    
     if(caida==false && (jugadores[jugador].getPulsarBoton()==0 || jugadores[jugador].getPulsarBoton()==1 ) && moverup==true ){//ascenso mientras pulsamos salto
           jugadores[jugador].Jump(direccion);//el mira su estado actual y se movera en consecuencia (aqui deberia ir el stop cuando no se pueda mover a causa de una colision)
           jugadores[jugador].setPulsarBoton();
           jugadores[jugador].SaltoBloqueo(moverup);
           GestorAudio *audio = GestorAudio::getInstance();
           audio->saltar(jugador+1);
           //std::cout<<"condicion 1"<<std::endl;
    }
    //ascenso mientras NO pulsamos salto, el salto debe seguir subiendo aunque no estemos pulsando el boton de saltar
    else if(jugadores[jugador].getPulsarBoton()!=0 && jugadores[jugador].SaltoBloqueo(moverup)==false && moverup==true){
        jugadores[jugador].Jump(direccion);
        //std::cout<<"condicion 3"<<std::endl;
    }
    else if(caida==true){ // acuta siempre en direccion al suelo mientras no estemos en mitad de un salto
       
        if(jugadores[jugador].moverAbajo(direccion)==true){
            jugadores[jugador].setEn1();
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
        GestorAudio *audio = GestorAudio::getInstance();
        audio->cuerpoacuerpo(jugador+1);
    }
}

void Nivel::AtaqueLejano(int jugador)
{
    GestorAudio *audio = GestorAudio::getInstance();
    int ori = jugadores[jugador].getOri();
    int y = jugadores[jugador].getY() + 2;
    int elemento = jugadores[jugador].getElement();
    int tipo = jugadores[jugador].getType();
    int dano = jugadores[jugador].getDano(elemento, tipo);
    int x; 
    audio->disparar(jugador+1);
    if (ori == 1)
        x = jugadores[jugador].getX() + 40;
    else if (ori == -1)
        x = jugadores[jugador].getX() - 40;
    
    //std::cout<< "Orientacion: " << ori << endl;
    crearBala(tipo, elemento, x, y, jugador, dano, ori, 1);
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
        GestorAudio *audio = GestorAudio::getInstance();
        audio->defensa(jugador+1);
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

void Nivel::crearBala(int tipo, int elemento, int x, int y, int jugador, int dano, int ori, int amigo)
{
    bullet.push_back(new Bullet(tipo,elemento,x,y,jugador,dano, ori, amigo));
}

void Nivel::realimentarBalas()
{
    
     for(int o = 0; o < bullet.size();o++)
     {
         
            bullet[o]->realimentar(bullet[o]->getOri());
         
     }  
     
}
void Nivel::ColBalasNivel(){
    Motor2D *motor = Motor2D::getInstance();
    
    if(bullet.size()>0){
        for(int i=0;i<bullet.size();i++){
           if(motor->ColBalas(i,-1)!=-1){//-1 es para el player 0
               if(bullet[i]->getFuegoAmigo(1)==false){
                jugadores[0].setDanoVida(bullet[i]->getDano());
                bool ver = bullet[i]->matarBala(i);
                delete bullet[i];
                bullet[i] = NULL;
                bullet.erase(bullet.begin()+i);
                
               }
           }
           if(motor->ColBalas(i,-2)!=-1){//-2 es para el player 2
               if(bullet[i]->getFuegoAmigo(1)==false){
                jugadores[1].setDanoVida(bullet[i]->getDano());
                bool ver = bullet[i]->matarBala(i);
                delete bullet[i];
                bullet[i] = NULL;
                bullet.erase(bullet.begin()+i);
               }
           }
        }
    }
    if(enemigos.size()>0 && bullet.size()>0){
        for(int i=0;i<enemigos.size();i++){
            for(int j=0;j<bullet.size();j++){
                if(enemigos[i]!=NULL){
                    if(motor->ColBalas(j,enemigos[i]->getTipoEnemigo())!=-1){
                        if(bullet[j]->getFuegoAmigo(0)==false){
                        //std::cout<<"le doy al enemigo"<<std::endl;
                            bool ver = bullet[i]->matarBala(i);
                            delete bullet[i];
                            bullet[i] = NULL;
                            bullet.erase(bullet.begin()+i);
                        
                        }
                    }
                }
            }
        }
    }
    
}
void Nivel::crearEnemigo(int vid, int ataq, int ataqfisico,int element,int defen,int tipo,int x,int y)
{
    enemigos.push_back(new Enemigos(vid,ataq,ataqfisico,element,defen,tipo,x,y));
    
}

void Nivel::realimentarEnemigo()
{ 
     Motor2D *motor2D = Motor2D::getInstance();
     for(int o = 0; o < enemigos.size();o++)
     {
          if(enemigos[o]->getX()-jugadores[0].getX()<100 && enemigos[o]->getX()-jugadores[0].getX()>-100 && enemigos[o]->getY()-jugadores[0].getY()-174<50 && enemigos[o]->getY()-jugadores[0].getY()-174>-50)  {            
            if(enemigos[o]->getX()-jugadores[0].getX()-65<10 && enemigos[o]->getX()-jugadores[0].getX()-65>-90)  {   
              enemigos[o]->setOrientacion(-1);
            } 
            else if(enemigos[o]->getX()-jugadores[0].getX()-65>10 && enemigos[o]->getX()-jugadores[0].getX()-65<90)  {   
              enemigos[o]->setOrientacion(1);
            }
            else{
              enemigos[o]->realimentar();
            }
           }
           else{
              enemigos[o]->realimentar();
           }
            if(enemigos[o]->getTipoEnemigo()==1){
             crearBala(1, enemigos[o]->getTipoEnemigo(), enemigos[o]->getX()-75, enemigos[o]->getY(), 0, enemigos[o]->getAtaqueLejano(), -enemigos[o]->getOrientacion(),0);
            }
            else if(enemigos[o]->getTipoEnemigo()==2){
             crearBala(1, enemigos[o]->getTipoEnemigo(), enemigos[o]->getX(), enemigos[o]->getY(), 0, enemigos[o]->getAtaqueLejano(), -enemigos[o]->getOrientacion(),0);
             crearBala(1, enemigos[o]->getTipoEnemigo(), enemigos[o]->getX(), enemigos[o]->getY()+30, 0, enemigos[o]->getAtaqueLejano(), -enemigos[o]->getOrientacion(),0);
             crearBala(1, enemigos[o]->getTipoEnemigo(), enemigos[o]->getX(), enemigos[o]->getY()-30, 0, enemigos[o]->getAtaqueLejano(), -enemigos[o]->getOrientacion(),0);
            }
            else if(enemigos[o]->getTipoEnemigo()==5){
             crearBala(1, enemigos[o]->getTipoEnemigo(), enemigos[o]->getX()-205, enemigos[o]->getY(), 0, enemigos[o]->getAtaqueLejano(), -enemigos[o]->getOrientacion(),0);
            }
            if((motor2D->ataqueEnemigo(0,enemigos[o]->getTipoEnemigo())==true&&enemigos[o]->activacion()==true))  {
                    ataqueEnemigo();
            }
            if(modo==2){
            if((motor2D->ataqueEnemigo(1,enemigos[o]->getTipoEnemigo())==true&&enemigos[o]->activacion()==true))  {
                    ataqueEnemigo();
            }
            }
        }  
     
}

void Nivel::ataqueEnemigo()
{ 
     Motor2D *motor2D = Motor2D::getInstance();
         for(int a = 0; a < enemigos.size();a++){
                if(motor2D->ataqueEnemigo(0,enemigos[a]->getTipoEnemigo())==true)  {
                     jugadores[0].setDanoVida(enemigos[a]->getAtaqueFisico());
                 }
                if(modo==2){
                if(motor2D->ataqueEnemigo(1,enemigos[a]->getTipoEnemigo())==true)  {
                    jugadores[1].setDanoVida(enemigos[a]->getAtaqueFisico());
                 }
                }
          }
}

void Nivel::matarEnemigos()
{ 
     Motor2D *motor2D = Motor2D::getInstance();
     Juego *juego = Juego::getInstance();//clase global
    for(int m = 0; m < enemigos.size();m++)
     {
        if(juego->queEstado()!=2){
             juego->desactivarSonidos(m);
             std::cout<< "mataaaaaaaaa " << m << endl;
             bool ver = enemigos[m]->matarEnemigo(m);
             delete enemigos[m];
             enemigos[m] = NULL;
             enemigos.erase(enemigos.begin()+m);
     }  
    }
             enemigos.resize(0);
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
            //std::cout<<"Recogió el elemento"<<endl;
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