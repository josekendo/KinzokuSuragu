/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hud.hpp
 * Author: fv
 *
 * Created on April 25, 2018, 7:38 AM
 */

#ifndef HUD_HPP
#define HUD_HPP

class Hud {
public:
    //clase singleton
    ~Hud(void);
    static Hud *getInstance()
    {
        if(unica_instancia == 0)
        unica_instancia = new Hud();
        return unica_instancia;  
    }
    //fin singleton public
    
    //funciones para jugadores
    
    void cambiarVida(int player,int vida);//servira para cambiar su marcador de vida
    void cambiarDefensa(int player, int defensa);//servira para cambiar su marcador de defensa
    void cambiarMunicion(int player, int municion);//servira para cambiar su marcador de municion
    
    //fin de funciones para jugadores
    
    
    //funciones para nivel
    
    void draw(int modo);//esta funcion llama a motor2d con los valores para pintar sus propiedades 
    
    //fin funciones para nivel
private:

    //clase singleton 
    Hud();
    static Hud* unica_instancia;
    //fin clase singleto private
    
    int vidas[2];
    int defensas[2];
    int municiones[2];
};

#endif /* HUD_HPP */

