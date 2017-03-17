#include "hormiga.h"
#include "pos.h"
#include "ui_pos.h"
#include <QtCore>

Pos::Pos(QWidget *parent,int x, int y) :
    QDialog(parent),
    ui(new Ui::Pos)
{
    ui->setupUi(this);
    this->x = x;
    this->y = y;
    pre=false;
    nyet = false;
}

void Pos::setPos(char p)
{
    this->p=p;
}

void Pos::setX(int x)
{
    this->x = x;
}

void Pos::setY(int y)
{
    this->y = y;
}

char Pos::getPo()
{
    return p;
}

void Pos::setnyet(bool n)
{
   this->nyet = n;
}

bool Pos::getnyet()
{
    return nyet;
}

Pos::~Pos()
{
    delete ui;
}

void Pos::on_pushButton_clicked()
{
    pre=true;
    if(ui->radioButton->isChecked())
    {
        setPos('N');
        QTextStream(stdout) << "N" << endl;
    }
    else if(ui->radioButton_2->isChecked())
    {
         setPos('S');
         //QTextStream(stdout) << "S" << endl;
    }
    else if(ui->radioButton_3->isChecked())
    {
         setPos('E');
         //QTextStream(stdout) << "E" << endl;
    }
    else
    {
         setPos('O');
         //QTextStream(stdout) << "O" << endl;
    }

        /* Al hacer click sobre el botón 'aceptar' creamos una nueva hormiga
           esta se va almacenando en un arreglo de hormigas. */

        int c[3];
        c[0]= 100;
        c[1]= 100;
        c[2]= 100;
        QTextStream(stdout) << "Pase la prueba -- " << getPo() << endl;

        Hormiga *ant = new Hormiga(x,y,this->getPo(),c);

        QTextStream(stdout) << "Hormiga: " << endl;
        QTextStream(stdout) << "ant's x: " << ant->getX() << endl;
        QTextStream(stdout) << "ant's y: " << ant->getY() << endl;
        QTextStream(stdout) << "ant's posicion: " << getPo() << endl;
        QTextStream(stdout) << "ant's color: " << *ant->getC() << endl;
        setnyet(true);
        this->close();

}
