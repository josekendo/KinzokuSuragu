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
    #if defined _MSC_VER
        _mkdir(dir.c_str());
        archivo = fopen(arch.c_str(),"w");
        fclose(archivo);
    #elif defined __GNUC__
        mkdir(dir.c_str(),0777);
        archivo = fopen(arch.c_str(),"w");
        fclose(archivo);
    #endif

    //escribimos por primera vez en el archivo
    std::ofstream buffer;    
    buffer.open(arch,std::ofstream::out);
    if(buffer.fail())
    {
        std::cout << "No se pudo abrir el archivo" << "\n";
    }
    else
    {
        int *info = devolverInformacion();
        for(int a=0;a < 13;a++)
        {
            buffer << info[a] << "\n";
        }
        buffer.close();
        std::cout << "Se han creado archivos de guardado.";
        delete info;
    }
}

void GestionArchivos::cargarArchivos()
{
    std::ifstream buffer;
    std::string arch;
    #if defined _MSC_VER
    arch = "saves\save";
    #elif defined __GNUC__
    arch = "saves/save";
    #endif

    buffer.open(arch.c_str(),std::ifstream::in);
    int valores[13];
    int contador = 0;
    std::string texto;
    int valor;
    if(!buffer.fail())
    {
        while(!buffer.eof())
        {
            getline(buffer,texto);
            std::istringstream(texto) >> valor;
            valores[contador] = valor;
            //std::cout << contador << " "<< texto << "\n";
            contador++;
        }
         nivelesTotalesIn = valores[0];
         nivelesTotalesMu = valores[1];
         nivelesDisponiblesIn = valores[2];
         nivelesDisponiblesIn = valores[3];
         danorecibido[0] = valores[4];
         danorecibido[1] = valores[5];
         danoecho[0] = valores[6];
         danoecho[1] = valores[7];
         partidasIndi = valores[8];
         partidasMulti = valores[9];
         minutosJugados = valores[10];
         objetosCogidos = valores[11];
         numMuertes = valores[12];
         std::cout << "Carga Completa." << "\n";
    }
}

void GestionArchivos::guardarArchivos()
{
    std::string arch;
    #if defined _MSC_VER
    arch = "saves\save";
    #elif defined __GNUC__
    arch = "saves/save";
    #endif
    std::ofstream buffer;   
    buffer.open(arch,std::ofstream::out);
    if(!buffer.fail())
    {
        int *info = devolverInformacion();
        for(int a=0;a < 13;a++)
        {
            buffer << info[a] << "\n";
        }
        buffer.close();
        delete info;
        std::cout << "Guardado exitoso.";
    }
    else
    {
        std::cout << "Error al guardar.";
    }
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

void GestionArchivos::guardarValores(bool victoria, int modo)
{
    Nivel *nivel = Nivel::getInstance();
    Motor2D *motor = Motor2D::getInstance();
    int *valores = devolverInformacion();
    int *vala = nivel->devolverEstadisticas();
    if(modo == 2)
    {
        minutosJugados = valores[10]+motor->finisclock();
        objetosCogidos = valores[11]+nivel->getElementos();
        numMuertes = valores[12]+(vala[0]+vala[3]);
        danorecibido[0] = valores[4]+(vala[2]);
        danorecibido[1] = valores[5]+(vala[5]);
        danoecho[0] = valores[6]+(vala[1]);
        danoecho[1] = valores[7]+(vala[4]);           
        partidasMulti = valores[9]+1;
        if(victoria)
        {
            if(nivelesTotalesMu >= (nivelesDisponiblesMu+1))
            {
                nivelesDisponiblesMu=nivelesDisponiblesMu+1;
            }
        }
    }
    else
    {
        minutosJugados = valores[10]+motor->finisclock();
        objetosCogidos = valores[11]+nivel->getElementos();
        numMuertes = valores[12]+(vala[0]);
        partidasIndi = valores[8]+1;
        danorecibido[0] = valores[4]+(vala[2]);
        danoecho[0] = valores[6]+(vala[1]);
        if(victoria)
        {
            if(nivelesTotalesIn >= (nivelesDisponiblesIn+1))
            {
                nivelesDisponiblesIn=nivelesDisponiblesIn+1;
            }
        }
    }
    
    guardarArchivos();
    delete valores;
    delete vala;
}