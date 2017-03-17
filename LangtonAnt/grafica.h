#ifndef GRAFICA_H
#define GRAFICA_H
#include "hormiga.h"

#include <QWidget>

namespace Ui {
class grafica;
}

class grafica : public QWidget
{
    Q_OBJECT

public:
    explicit grafica(QWidget *parent = 0);
    ~grafica();
    Ui::grafica *ui;
    QVector<double> gen;
    QVector< QVector< double > > ants;
    void graficar(int generaciones, QVector<Hormiga *> ah,int r, int g, int b);

private slots:

    void on_img_clicked();
private:

};

#endif // GRAFICA_H
