/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GestionArchivos.cpp
 * Author: fv
 * 
 * Created on April 26, 2018, 3:22 AM
 */

#include "GestionArchivos.hpp"

GestionArchivos* GestionArchivos::unica_instancia = 0;

GestionArchivos::GestionArchivos() 
{
    nivelesTotalesIn= 2;
    nivelesTotalesMu= 2;
    if(!ExisteArchivos())
    {
        nivelesDisponiblesIn = 1;
        nivelesDisponiblesMu = 1;
        danorecibido[0] = 0;
        danorecibido[1] = 0;
        danoecho[0] = 0;
        danoecho[1] = 0;
        partidasIndi = 0;
        partidasMulti = 0;
        minutosJugados = 0;
        objetosCogidos = 0;
        numMuertes = 0;
        crearArchivos();
    }
    else
    {
        cargarArchivos();
    }
}

GestionArchivos::~GestionArchivos() 
{
    
}

void GestionArchivos::crearArchivos()
{
    std::string dir,arch;
    dir = "saves";
    #if defined _MSC_VER
    arch = "saves\save";
    #elif defined __GNUC__
    arch = "saves/save";
    #endif

    FILE * archivo;
    std::cout << "Se crean archivos de guardado" << "\n";
    #if defined _MSC_VER
        _mkdir(dir.c_str());
        archivo = fopen(arch.c_str(),"w");
        fclose(archivo);
    #elif defined __GNUC__
        mkdir(dir.c_str(),0777);
        archivo = fopen(arch.c_str(),"w");
        fclose(archivo);
    #endif
    
}

void GestionArchivos::cargarArchivos()
{

}

void GestionArchivos::guardarArchivos(bool victoria, int modo)
{

}

bool GestionArchivos::ExisteArchivos()
{
    std::string dir,arch;
    dir = "saves";
    #if defined _MSC_VER
    arch = "saves\save";
    #elif defined __GNUC__
    arch = "saves/save";
    #endif
    
    if(opendir(dir.c_str()))
    {
        if(fopen(arch.c_str(),"r"))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

int * GestionArchivos::devolverInformacion()
{
    int * infor = new int[13];
    infor[0] = nivelesTotalesIn;
    infor[1] = nivelesTotalesMu;
    infor[2] = nivelesDisponiblesIn;
    infor[3] = nivelesDisponiblesIn;
    infor[4] = danorecibido[0];
    infor[5] = danorecibido[1];
    infor[6] = danoecho[0];
    infor[7] = danoecho[1];
    infor[8] = partidasIndi;
    infor[9] = partidasMulti;
    infor[10] = minutosJugados;
    infor[11] = objetosCogidos;
    infor[12] = numMuertes;
    return infor;
}