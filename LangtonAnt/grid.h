#ifndef GRID_H
#define GRID_H
#include <QGraphicsScene>
# include <QVector>
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QTime>
#include <QtGlobal>
#include "celda.h"
#include "hormiga.h"
#include "imagen.h"

namespace Ui {
class Grid;
}

class Grid : public QDialog
{
    Q_OBJECT

public:
     Grid(QWidget *parent = 0);
     void armaArrays();
     void iniciaAlgoritmo();
     void delay(int seg);
     void saveFile();
     Celda *rejilla[126][70];
     Imagen *image;
     QVector <Hormiga*> ah;
     static bool inicia;
    ~Grid();
     Ui::Grid *ui;
     QGraphicsScene *scene;
     bool pausa;
     //static bool inicia;
     static int cg;
     bool reanuda;
     bool configuracion;
     bool maybeSave();

private slots:
    void on_pushButton_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();
    
    void on_pushButton_4_clicked();

private:
    //Ui::Grid *ui;
    //QGraphicsScene *scene;
    QString curFile;

};

#endif // GRID_H
