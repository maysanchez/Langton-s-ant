#include "pix.h"

Pix::Pix(int x, int y)
{
    this->x = x;
    this->y = y;
    seleccionada = 0;
    pressed = false;
    position = new Pos(0,x,y);
    alive = false;
}

void Pix::setAlive(bool alive)
{
    this->alive = alive;
}

void Pix::setSeleccionada(int s)
{
    this->seleccionada = s;
}

void Pix::setPosition(char p)
{
    this->position->setPos(p);
}

int Pix::getX()
{
    return x;
}

int Pix::getY()
{
    return y;
}

char Pix::getPosition()
{
    return position->getPo();
}

int Pix::getSeleccionada()
{
    return seleccionada;
}

bool Pix::isAlive()
{
    return alive;
}
