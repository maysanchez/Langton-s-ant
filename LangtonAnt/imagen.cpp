#include "imagen.h"
#include <QDebug>
#include <QMouseEvent>

Imagen::Imagen(QWidget *parent) : QWidget(parent)
{

}

Imagen::Imagen(int x, int y, QColor c)
{
    this->ancho = x;
    this->alto = y;
    this->colorFondo = c;
    imagen = QImage(alto, ancho, QImage::Format_RGB32);

}

QImage Imagen::pintaGrid(int fondo)
{
    imagen.fill(qRgb(255,255,128));
    return imagen;
}


QImage Imagen::getImagen()
{
    return imagen;
}
