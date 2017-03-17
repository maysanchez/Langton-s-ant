#ifndef CELDA_H
#define CELDA_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <pos.h>

class Celda : public QGraphicsItem
{
public:
    Celda(int,int);
    void setAlive(bool alive);
    void setSeleccionada(int s);
    void setPosition(char p);
    int getSeleccionada();
    int getX();
    int getY();
    char getPosition();
    bool isAlive();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void pinta(bool alive );
    void setPressed(bool j);


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    int x;
    int y;
    int tamanio;
    bool pressed;
    bool alive;
    int seleccionada;
    Pos *position;

};

#endif // CELDA_H
