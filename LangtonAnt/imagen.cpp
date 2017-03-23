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

    if(fondo==1){

  //  qDebug() << "ROSA";
    for(int w=0; w<alto; w++)
    {
        for(int h=0; h<ancho; h++)
        {
            imagen.setPixel(w,h,qRgb(255,255,128));
            vm[w][h]=0;
        }
    }
    }else{
    // qDebug() << "BLANCO";
        for(int w=0; w<alto; w++)
        {
            for(int h=0; h<ancho; h++)
            {
                imagen.setPixel(w,h,qRgb(255,255,255));
                vm[w][h]=0;
            }
        }


    }

    return imagen;
}


QImage Imagen::getImagen()
{
    return imagen;
}
