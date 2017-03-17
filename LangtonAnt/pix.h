#ifndef PIX_H
#define PIX_H
#include "pos.h"

class Pix
{
public:
    Pix(int x, int y);
    void setAlive(bool alive);
    void setSeleccionada(int s);
    void setPosition(char p);
    int getX();
    int getY();
    char getPosition();
    int getSeleccionada();
    bool isAlive();
    void pinta(bool alive );
    void setPressed(bool j);

private:
    int x;
    int y;
    int tamanio;
    bool pressed;
    bool alive;
    int seleccionada;
    Pos *position;

};

#endif // PIX_H
