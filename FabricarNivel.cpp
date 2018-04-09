/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FabricarNivel.cpp
 * Author: fv
 * 
 * Created on April 5, 2018, 11:42 AM
 */

#include <iosfwd>
#include <string>
#include "FabricarNivel.h"


FabricarNivel::FabricarNivel() {
}

FabricarNivel::FabricarNivel(const FabricarNivel& orig) {
}

FabricarNivel::~FabricarNivel() {
}

void FabricarNivel::construirNivel(char *nivel)
{
    //se llama desde aqui a motor2d para que cargue las diferentes capas
    Motor2D *motor2D = Motor2D::getInstance();//clase global
    int altura=0;
    int anchura=0;
    int casillas=0;
    //Lo primero cargamos el archivo de nivel
    TiXmlDocument doc;
    bool load = doc.LoadFile(nivel);
    //Lo segundo nos movemos hasta alguna de las 3 capas que queremos cargar las capas tendran nombre predefinidos una sera la capa de fondo, otra la capa del nivel primera y la otra la secudaria 
    
    if(load)
    {
        TiXmlElement* root = doc.FirstChildElement("map");
        if(root->FirstChildElement("layer"))
        {

            string capa1 = root->FirstChildElement("layer")->FirstChildElement("data")->GetText(); 
            string capa2 = root->FirstChildElement("layer")->NextSibling()->FirstChild()->FirstChild()->Value();
            string capa3 = root->FirstChildElement("layer")->NextSibling()->NextSibling()->FirstChild()->FirstChild()->Value();
            
            int *cap1 = FabricarNivel::Split(capa1,',');
            int *cap2 = FabricarNivel::Split(capa2,',');
            int *cap3 = FabricarNivel::Split(capa3,',');
            
            motor2D->cargarCapa(cap1,1,32,16,8,"resources/tilesetbase.png");
            motor2D->cargarCapa(cap2,2,32,16,8,"resources/tilesetbase.png");
            motor2D->cargarCapa(cap3,3,32,16,8,"resources/tilesetbase.png");
              
        }
    }
    
    
    //cuando estan las tres cargadas se llama a cargaCompletada
    Juego *juego = Juego::getInstance();//clase global
    juego->cargaCompleta();
}
    
int FabricarNivel::numeroNiveles()
{
    return niveles;
}

//desace las cadenas en arrays de ints
int* FabricarNivel::Split(string &cadena,char delimitador)
{
                int anterior = 0,contador = 0;
                for(int a = 0;a < cadena.length();a++)
                {
                    if(cadena[a] == delimitador)
                    {
                        contador ++;
                    }
                }
                int *resultado = new int[contador];
                contador = 0;
                for(int a = 0;a < cadena.length();a++)
                {
                    if(cadena[a] == delimitador)
                    {
                        if(anterior == 0)
                        //std::cout << anterior << " - " << a << "-" << cadena.substr(anterior,(a-anterior)) << std::endl;
                        resultado[contador]=stoi(cadena.substr(anterior,(a-anterior)))-1;
                        else
                        //std::cout << anterior << " - " << a << "-" << cadena.substr(anterior+1,(a-anterior-1)) << std::endl;
                        resultado[contador]=stoi(cadena.substr(anterior+1,(a-anterior-1)))-1;
                        //resultado[contador]=stoi();
                        contador++;
                        anterior = a;
                    }
                }
                return resultado;
}