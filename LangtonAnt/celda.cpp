#include "celda.h"
#include "pos.h"
#include <iostream>
#include <QtCore>
#include <QMessageBox>

Celda::Celda(int x, int y)
{
    this->x = x;
    this->y = y;
    tamanio = 10;
    seleccionada =0;
    pressed = false;
    position = new Pos(0,x,y);
    alive = false;
    setPos(mapToParent(x*tamanio,y*tamanio));
}

QRectF Celda::boundingRect() const
{
    return QRect(0, 0, tamanio, tamanio);
}

void Celda::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush Brush(Qt::red);
    //azul QColor(204,255,255,60)
    //beige QColor(255,255,204,60)

    if(pressed || isAlive())
    {
       QTextStream(stdout)<<"Estoy pintando AZUL la celda ["<< getX() <<"]["<<getY()<<"]"<<endl;
       Brush.setColor(QColor(204,255,255,255));

       //pressed = false;
    }
    else if (pressed==false || isAlive()==false)
    {
        QTextStream(stdout)<<"Estoy pintando NEGRO la celda ["<< getX() <<"]["<<getY()<<"]"<<endl;
        Brush.setColor(Qt::black);
    }

    painter -> fillRect(rec, Brush);
    painter -> drawRect(rec);

}

void Celda::pinta(bool alive)
{
    QPainter *painter;
    const QStyleOptionGraphicsItem *option;
    QWidget *widget;
    paint(painter, option, widget);
    update();
}

void Celda::setPressed(bool j)
{
    pressed = j;
}

bool Celda::isAlive()
{
    return alive;
}

void Celda::setAlive(bool alive)
{
    this->alive=alive;
}

void Celda::setSeleccionada(int s)
{
    this->seleccionada=s;
}

int Celda::getSeleccionada()
{
    return seleccionada;
}

int Celda::getX()
{
    return x;
}

int Celda::getY()
{
    return y;
}

void Celda::setPosition(char p)
{
    position->setPos(p);
}

char Celda::getPosition()
{
    return position->getPo();
}

void Celda::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(pressed)
    {
        pressed = false;
        setSeleccionada(0);
    }

    else
    {
        pressed=true;
        setSeleccionada(1);

        position ->show();
        position->setX(x);
        position->setY(y);
        this->setPosition(position->getPo());
        QTextStream(stdout)<<"posicion asignada -> "<< getPosition()<<endl;
    }

    update();
    QGraphicsItem::mousePressEvent(event);
}

