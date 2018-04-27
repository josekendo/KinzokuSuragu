/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Coordenadas.hpp
 * Author: fv
 *
 * Created on April 5, 2018, 11:42 AM
 */

#ifndef COORDENADAS_HPP
#define COORDENADAS_HPP

class Coordenadas {
public:
    Coordenadas();//pone coordenadas a 0
    Coordenadas(int xi, int yi);//inicializa las coordenadas a x, y
    Coordenadas(const Coordenadas& orig);
    virtual ~Coordenadas();
    void cambiarPosicion(int xi, int yi);//esto cambia la posicion de x e y, copiandolos en ax y ay
    int getCoordenadaX();//devuelve las coordenadas x
    int getCoordenadaY();//devuelve las coordenadas y
    int getCoordenadaXI(float tiempo);//devuelve coordenada interpolada x
    int getCoordenadaYI(float tiempo);//devuelve coordenada interpolada y
    void setCoordenadasA(int iax, int iay);
    void ResetCoordenadas(int xn, int yn);
private:
    int x,y;//estados nuevos
    int ax,ay;//son los estados anteriores de ax e ay

};

#endif /* COORDENADAS_HPP */

