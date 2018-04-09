/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Controles.h
 * Author: fv
 *
 * Created on March 24, 2018, 2:22 PM
 */

#ifndef CONTROLES_H
#define CONTROLES_H

class Controles {
private:
    Controles();
    static Controles* unica_instancia;
    int control;
    bool twoPlayer;
public:
    ~Controles(void);
    static Controles *getInstance()
    {
        if(unica_instancia == 0)
        unica_instancia = new Controles();
        return unica_instancia;  
    }
    void cambiarControl(int a);
    int getControlInvidual();
    void onTwo();
    void offTwo();
    int whatPlayer(sf::Keyboard::Key key);
    sf::Keyboard::Key moveUP();
    sf::Keyboard::Key moveDOWN();
    sf::Keyboard::Key moveLEFT();
    sf::Keyboard::Key moveRIGHT();
    sf::Keyboard::Key moveAtaque();
    sf::Keyboard::Key moveDefensa();
    sf::Keyboard::Key moveSalir();
    sf::Keyboard::Key moveAtras();
};

#endif /* CONTROLES_H */

