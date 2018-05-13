/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Colision.hpp
 * Author: fv
 *
 * Created on April 25, 2018, 8:45 AM
 */

#ifndef COLISION_HPP
#define COLISION_HPP
#include "Coordenadas.hpp"
#include <SFML/Graphics.hpp>

class Colision {
public:
    
    ~Colision(void);
    static Colision *getInstance(){
        if(unica_instancia == 0)
        unica_instancia = new Colision();
        return unica_instancia;  
    }
    
    void generarMatriz(int* matriz,int capa,int altura, int anchura);
    bool ColisionSuelo(int x, int y, sf::Vector2f dim,int dir);
    bool ColisionTecho(int x, int y,sf::Vector2f dim,int dir);
    bool ColisionLateral(int x,int y,sf::Vector2f dim,int dir);
    
private: 
    
    Colision();
    static Colision* unica_instancia;
    Coordenadas cordenadas;
    int filas;
    int col;
    int** capa1;
    int** capa2;
    int** capa3;
    int** capa4;
    int** capa5;
};

#endif /* COLISION_HPP */

