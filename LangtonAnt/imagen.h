#ifndef IMAGEN_H
#define IMAGEN_H

//#include <QWidget>
#include <QImage>
#include "pix.h"

class Imagen : public QWidget
{
    Q_OBJECT
public:
    explicit Imagen(QWidget *parent = 0);
    Imagen(int x, int y, QColor c);
    QImage pintaGrid(int fondo);
    QImage repintaGrid(int fondo);
    QImage getImagen();
    QImage imagen;
    int vm[1000][1000];//
    int alto;
    int ancho;

private:
    QColor colorFondo;

};

#endif // IMAGEN_H
