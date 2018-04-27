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
    /*control dos punto cero*/
    void pu(int play){if(play == 1){up = true;}else{up2=true;}};//se pulsa arriba
    void pd(int play){if(play == 1){down = true;}else{down2=true;}};//se pulsa abajo
    void pr(int play){if(play == 1){right = true;}else{right2=true;}};//se pulsa derecha
    void pl(int play){if(play == 1){left = true;}else{left2=true;}};//se pulsa izquierda
    void pa(int play){if(play == 1){ataque = true;}else{ataque2=true;}};//se pulsa ataque
    void pf(int play){if(play == 1){defensa = true;}else{defensa2=true;}};//se pulsa defensa
    void du(int play){if(play == 1){up = false;}else{up2=false;}};//se despulsa arriba
    void dd(int play){if(play == 1){down = false;}else{down2=false;}};//se despulsa abajo
    void dr(int play){if(play == 1){right = false;}else{right2=false;}};//se despulsa derecha
    void dl(int play){if(play == 1){left = false;}else{left2=false;}};//se despulsa izquierda
    void da(int play){if(play == 1){ataque = false;}else{ataque2=false;}};//se despulsa ataque
    void df(int play){if(play == 1){defensa = false;}else{defensa2=false;}};//se despulsa defensa
    bool getu(int play){if(play == 1){return up;}else{return up2;}};
    bool getd(int play){if(play == 1){return down;}else{return down2;}};
    bool getr(int play){if(play == 1){return right;}else{return right2;}};
    bool getl(int play){if(play == 1){return left;}else{return left2;}};
    bool geta(int play){if(play == 1){return ataque;}else{return ataque2;}};
    bool getf(int play){if(play == 1){return defensa;}else{return defensa2;}};
    
    bool up=false,down=false,right=false,left=false,ataque=false,defensa=false,up2=false,down2=false,right2=false,left2=false,ataque2=false,defensa2=false;
};

#endif /* CONTROLES_H */

