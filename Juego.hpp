/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Juego.hpp
 * Author: fv
 *
 * Created on April 5, 2018, 10:06 AM
 */

#ifndef JUEGO_HPP
#define JUEGO_HPP

#include "Estado.hpp"
#include "Nivel.hpp"
#include "Motor2D.hpp"

class Juego {
public:
    
    //clase singleton
    ~Juego(void);
    static Juego *getInstance()
    {
        if(unica_instancia == 0)
        unica_instancia = new Juego();
        return unica_instancia;  
    }
    //fin singleton public
    
    void cambiarEstado (int est);//1 sera el estado de menu, 2 jugando, 3 en estadistica
    void Draw();//llama a las diferentes draw segun estado
    void cargarNivel(int nivel);//Carga el nivel pasado por parametro
    void cargaCompleta();//cuando se carga un nivel se llama a esta funcion para que le diga a menu que esta completada la carga y quite el panel de loading
    void Ejecucion();//realiza la logica del juego 15 veces por frame
private:
    
    //clase singleton 
    Juego();
    static Juego* unica_instancia;
    //fin clase singleto private
    Motor2D *motor;
    Estado * estado;
    Estadisticas estadisticas;
    Menu menu;
    Jugando jugando;
};

#endif /* JUEGO_HPP */

