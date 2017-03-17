#include "hormiga.h"
#include <QtCore>

Hormiga::Hormiga(int x, int y, char p, int *rgb)
{
    this->x = x;
    this->y = y;
    this->posicion = p;
    this->rgb[0] = *(rgb);
    this->rgb[1] = *(rgb + 1);
    this->rgb[2] = *(rgb + 2);
    celdaActual = false;
    densidad=0;

    this->xInicial = x;
    this->yInicial = y;
    this->pInicial = p;
}

void Hormiga::giraDerecha()
{
    if(posicion == 'N')
    {
        setX(getX()+1);
        posicion = 'E';
    }
    else if(posicion == 'S')
    {
        setX(x - 1);
        posicion = 'O';
    }
    else if(posicion == 'E')
    {
        y = y + 1;
        posicion = 'S';
    }
    else //'O'
    {
        y = y - 1;
        posicion = 'N';
    }
}

void Hormiga::giraIzquierda()
{
    if(posicion == 'N')
    {
        x = x - 1;
        posicion = 'O';
    }
    else if(posicion == 'S')
    {   x = x + 1;
        posicion = 'E';
    }
    else if(posicion == 'E')
    {
        y = y - 1;
        posicion = 'N';
    }
   else// if(posicion == 'O')
    {
        y = y + 1;
        posicion = 'S';
    }
}

/*void Hormiga::Avanza()
{
    if(p == N)
    {
        x = x - 1;
        y = y;
        p = O;
    }
    if(p == S)
    {   x = x + 1;
        y = y;
        p = E;
    }
    if(p == E)
    {
        x = x;
        y = y - 1;
        p = N;
    }
    else //p == O
    {
        x = x;
        y = y + 1;
        p = S;
    }
}*/

int* Hormiga::invierteColor()
{
    int* color;
    if (celdaActual)
    {
        color[0]=255;
        color[1]=255;
        color[2]=255;
        return color;
        celdaActual=false;
        densidad--;
    }
    else
    {
        //return rgb = rgb;
        celdaActual=true;
        densidad++;
    }

}

int Hormiga::getX()
{
    return x;
}

int Hormiga::getY()
{
    return y;
}

int Hormiga::getR()
{
    return rgb[0];
}

int Hormiga::getG()
{
    return rgb[1];
}

int Hormiga::getB()
{
    return rgb[2];
}

int *Hormiga::getC()
{
    return rgb;
}

char Hormiga::getP()
{
    return posicion;
}

void Hormiga::setX(int x)
{
    this->x = x;
}

void Hormiga::serY(int y)
{
    this->y = y;
}

void Hormiga::serPosition(char p)
{
    this->posicion = p;
}

void Hormiga::setRgb(int r, int g, int b)
{
    rgb[0] = r;
    rgb[1] = g;
    rgb[2] = b;
}

bool Hormiga::checaCelda(int x, int y)
{
    if(celdaActual==false)
        return false;

    else
        return true;
}

void Hormiga::setCeldaActual(bool ca)
{
    celdaActual = ca;
}

bool Hormiga::getCeldaActual()
{
    return celdaActual;
}

void Hormiga::actualiza(char p, int rgb[])
{
    serPosition(p);
    setRgb(rgb[0],rgb[1],rgb[2]);
}

int Hormiga::getxInicial()
{
    return xInicial;
}

int Hormiga::getyInicial()
{
    return yInicial;
}

char Hormiga::getpInicial()
{
    return pInicial;
}

void Hormiga::setxInicial(int xi)
{
    xInicial = xi;
}

void Hormiga::setyInicial(int yi)
{
    yInicial  = yi;
}

void Hormiga::setpInicial(char pi)
{
    pInicial = pi;
}

