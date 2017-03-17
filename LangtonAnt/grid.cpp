#include "grid.h"
#include "ui_grid.h"
#include "celda.h"
#include "hormiga.h"
#include "imagen.h"
#include <QtCore>
#include <QVector>
#include <QMatrix>
#include <QThread>
#include <QFileDialog>
#include <QMessageBox>
#include <sstream>
#include <QtGlobal>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
bool Grid::inicia = false;
int Grid::cg = 0;

Grid::Grid(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Grid)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    //ui->graphicsView->setScene(scene);

    this->setWindowState(Qt::WindowMaximized);
    int ancho = 100;//ui->graphicsView->width();
    int alto = 100; //ui->graphicsView->height();
    QColor co = QColor(0,0,0);

    QTextStream(stdout) << "ancho: " << ancho << endl;
    QTextStream(stdout) << "alto: " << alto << endl;


    this->pausa = false;
    reanuda=false;
    configuracion = false;
    this->image=new Imagen(ancho, alto, co);
    scene->addPixmap(QPixmap::fromImage(image->pintaGrid()));
    ui->graphicsView->setScene(scene);
}

void Grid::armaArrays()
{
    int co[3];
    co[0]= 100;
    co[1]= 100;
    co[2]= 100;

    image->imagen.setPixel(50,50,qRgb(204,255,255));
    image->imagen.setPixel(10,10,qRgb(204,255,255));
    //image->imagen.setPixel(70,70,qRgb(204,255,255));

    //Recorremos la imagen para encontrar los pixeles seleccionados
    for(int x=0; x < 100; x++)//image->width() ; x++)
    {
        for(int y=0; y < 100; y++)//image->height(); y++)
        {


           QRgb colorTem = image->getImagen().pixel(QPoint(x,y));
           QColor c(colorTem);
           //204,255,255,255
           if(c.red()== 204 && c.green()==255 && c.blue()==255 && c.alpha()==255)
           {
               char p = 'N';

               QTextStream(stdout) << " ENCONTRE HORMIGA" <<endl;
               Hormiga* ant = new Hormiga(x,y,p,co);
               ah << ant;
               QTextStream(stdout) << "Se guardo una hormiga "<< endl;
               QTextStream(stdout) << "Imagen[" << x << "]" << "["<< y << "]" << "=" << "seleccionada "<< endl;
               QTextStream(stdout) << "x :" << x <<endl;
               QTextStream(stdout) << "y :" << y <<endl;

            }


        }

    }
}

void Grid::iniciaAlgoritmo()
{
    QTextStream(stdout) << " ************** INICIA ALGORITMO ************** " <<endl;
    for(int h=0; h<ah.size();h++)
    {
        if(ah[h]->getX()>99)
            ah[h]->setX(0);
        else if(ah[h]->getX()<0)
            ah[h]->setX(99);

        if(ah[h]->getY()>99)
            ah[h]->serY(0);
        else if(ah[h]->getY()<0)
            ah[h]->serY(99);

       // if(rejilla[ah[h]->getX()][ah[h]->getY()]->isAlive() == false)

        if(image->vm[ah[h]->getX()][ah[h]->getY()] == 0)
        {
            QTextStream(stdout) << "ESTA MUERTA  "<<endl;
            image->vm[ah[h]->getX()][ah[h]->getY()]=1;
            QTextStream(stdout) << "AHORA ESTA VIVA "<< image->vm[ah[h]->getX()][ah[h]->getY()]<<endl;
            image->imagen.setPixel(ah[h]->getX(),ah[h]->getY(),qRgb(204,255,255));
            ah[h]->invierteColor();
            ah[h]->giraDerecha();

            QTextStream(stdout) << "Ya gire a la DERECHA " <<endl;
            QTextStream(stdout) << "Hormiga " << h+1 << endl;
            QTextStream(stdout) << "x- " << ah[h]->getX() << endl;
            QTextStream(stdout) << "y- " << ah[h]->getY() << endl;
            QTextStream(stdout) << "p- " << ah[h]->getP() << endl;
            QTextStream(stdout) << "Ahora esta " << image->vm[ah[h]->getX()][ah[h]->getY()] <<endl;

            /*rejilla[ah[h]->getX()][ah[h]->getY()]->setAlive(true);
            rejilla[ah[h]->getX()][ah[h]->getY()]->pinta( rejilla[ah[h]->getX()][ah[h]->getY()]->isAlive());
            ah[h]->invierteColor();
            ah[h]->giraDerecha();*/
        }
        else
        {
            QTextStream(stdout) << "ESTA VIVA   " <<endl;
            image->vm[ah[h]->getX()][ah[h]->getY()]=0;
            QTextStream(stdout) << "AHORA ESTA MUERTA "<< image->vm[ah[h]->getX()][ah[h]->getY()]<<endl;
            image->imagen.setPixel(ah[h]->getX(),ah[h]->getY(),qRgb(0,0,0));
            ah[h]->invierteColor();
            ah[h]->giraIzquierda();

            QTextStream(stdout) << "Ya gire a la IZQUIERDA " <<endl;
            QTextStream(stdout) << "Hormiga " << h+1 << endl;
            QTextStream(stdout) << "x- " << ah[h]->getX() << endl;
            QTextStream(stdout) << "y- " << ah[h]->getY() << endl;
            QTextStream(stdout) << "p- " << ah[h]->getP() << endl;
            QTextStream(stdout) << "Ahora esta " << image->vm[ah[h]->getX()][ah[h]->getY()] <<endl;

            /*rejilla[ah[h]->getX()][ah[h]->getY()]->setAlive(false);
            QTextStream(stdout) << "AHORA ESTA MUERTA "<<rejilla[ah[h]->getX()][ah[h]->getY()]->isAlive()<<endl;
            rejilla[ah[h]->getX()][ah[h]->getY()]->pinta( rejilla[ah[h]->getX()][ah[h]->getY()]->isAlive());
            ah[h]->invierteColor();
            ah[h]->giraIzquierda();*/
            /*QTextStream(stdout) << "Ya gire a la izquierda " <<endl;
            QTextStream(stdout) << "Hormiga " << h+1 << endl;
            QTextStream(stdout) << "x- " << ah[h]->getX() << endl;
            QTextStream(stdout) << "y- " << ah[h]->getY() << endl;
            QTextStream(stdout) << "p- " << ah[h]->getP() << endl;
            QTextStream(stdout) << "Ahora esta " << rejilla[ah[h]->getX()][ah[h]->getY()]->isAlive() <<endl;*/
        }
    }
    //reconvertImage();
    //repaint( image->imagen.hasAlphaBuffer() );

    //scene->update();
    //ui->graphicsView->setScene(scene);
    //ui->graphicsView->update();

    scene->addPixmap(QPixmap::fromImage(image->repintaGrid()));
    ui->graphicsView->setScene(scene);
}

void Grid::delay(int seg)
{
    QTime dieTime  = QTime::currentTime().addMSecs(seg);
    while(QTime::currentTime() < dieTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents,1);
    }
    //QTime::currentTime().restart();
}

void Grid::saveFile()
{
    QFile file(curFile);
    QString s;

    if(file.open(QFile::WriteOnly))
    {
        QTextStream text_stream_for_writing(&file);

        //file.seek(0);
        //text_stream_for_writing.seek(0);

        for(int i=0; i<100; i++)
        {
            for (int j=0; j<100;j++)
            {
                //s = QString::number(image->vm[j][i]);
               //file.write(s);
               text_stream_for_writing  << QString::number(image->vm[j][i]);
            }
            text_stream_for_writing << "\r\n";
        }
        text_stream_for_writing.seek(10200); //10198


      for(int h=0; h<ah.size();h++)
        {
          text_stream_for_writing << QString::number(ah[h]->getX());;
          text_stream_for_writing<<",";
          text_stream_for_writing << QString::number(ah[h]->getY());
          text_stream_for_writing<<",";
          text_stream_for_writing<<ah[h]->getP();
          text_stream_for_writing << "\n";
        }
          text_stream_for_writing << "*";
        file.close();

    }else{
        QMessageBox::warning(this,"Saving",tr("Cannot write file"));
    }
}

Grid::~Grid()
{
    delete ui;
}

bool Grid::maybeSave()
{

}

void Grid::on_pushButton_clicked()
{

    if(!reanuda){
        inicia = true;
        armaArrays();

        QTextStream(stdout) << "Se preciono el boton start *" << endl;
        while(cg<50 && inicia == true){
            iniciaAlgoritmo();
            delay(1500);
            cg++;
        }
     }
    else{
        while(cg<50 && inicia == true){
            iniciaAlgoritmo();
            delay(1500);
            cg++;
        }
    }



}

void Grid::on_horizontalSlider_valueChanged(int value)
{
    QMatrix matrix;
    matrix.scale(value,  value);
    ui->graphicsView->setMatrix(matrix);
}

void Grid::on_pushButton_3_clicked() //Save
{
    inicia = false;
    QString fileName = QFileDialog::getSaveFileName(this,"Guarda Configuracion","home/maytee/Escritorio/Configuraciones","Text Files (*.txt)");
 //   QString fileName = QFileDialog::getSaveFileName(this,"Guarda Configuracion","C:/Users/May/Desktop/Configuraciones","Text Files (*.txt);;All Files (*.*)");

    if(!fileName.isEmpty())
    {
        curFile = fileName;
    //    QTextStream(stdout) << "Mandando a llamar saveFile"<<endl;
        saveFile();
    }
    inicia = true;
}

void Grid::on_pushButton_2_clicked() //Stop
{
    if(inicia){
        inicia = false;
        reanuda = false;
        QTextStream(stdout) << "Pause la ejecucion"<<endl;
        QTextStream(stdout) << "inicia = "<<inicia<<endl;
        QTextStream(stdout) << "cg = "<<cg<<endl;
    }

    else if(!inicia){
        inicia=true;
        reanuda=true;
        QTextStream(stdout) << "Reanude ejecucion"<< endl;
        QTextStream(stdout) << "inicia = " << inicia <<endl;
        QTextStream(stdout) << "cg = " << cg <<endl;

        while(cg<50 && inicia == true)
        {
            iniciaAlgoritmo();
            delay(1500);
            cg++;
        }
    }
}

void Grid::on_pushButton_4_clicked() //Carga configuracion
{

    QString fileName = QFileDialog::getOpenFileName(this,"Abre Configuracion","home/maytee/Escritorio/Configuraciones/","Text Files (*.txt)");

        if(!fileName.isEmpty()){
            QFile file(fileName);
            if(file.open(QFile::ReadOnly)){

                QTextStream text_stream_for_reading(&file);
                text_stream_for_reading.seek(0);
                QString text;
                int y=1;

                int co[3];
                co[0]= 100;
                co[1]= 100;
                co[2]= 100;

                for(int i=0; i<100; i++)
                {
                    text = text_stream_for_reading.readLine();
                    qDebug() << text.length();
                    qDebug()<< text;

                    for(int j=0; j<text.length(); j++){
                        if(text[j]=='0')
                            image->vm[j][i]=0;
                        else
                            image->vm[j][i]=1;
                    }

                    if(i>0)
                        y=y+102;
                    else
                        y=y+101;

                    text_stream_for_reading.seek(y);
                  }

                //text_stream_for_reading.seek(y-1);
                /*QString text=",";
                      while (!in.atEnd())*/
                while(text != "*"){
                    text = text_stream_for_reading.readLine();
                    qDebug() << text.length();
                    qDebug()<< text;

                    if(text.length()>1)
                    {
                        QStringList myStringList = text.split(",");
                        qDebug() << myStringList.at(0);
                        qDebug() << myStringList.at(1);
                        qDebug() << myStringList.at(2);

                        QByteArray array = myStringList.at(2).toLocal8Bit();
                        char* buffer = array.data();

                        Hormiga* ant = new Hormiga(myStringList.at(0).toInt(),myStringList.at(1).toInt(),buffer[0],co);
                        ah << ant;
                    }

                 }
              file.close();

              scene->addPixmap(QPixmap::fromImage(image->repintaGrid()));
              ui->graphicsView->setScene(scene);

              for(int h=0; h<ah.size();h++)
              {
                  qDebug() << "HORMIGA " << h;
                  qDebug() << ah[h]->getX();
                  qDebug() << ah[h]->getY();
                  qDebug() << ah[h]->getP();
              }

            } else{
                QMessageBox::warning(this,"Carga configuracion",tr("Cannot read File %1.\nError: %2").arg(fileName).arg(file.errorString()));
            }

            reanuda = true;
            inicia = true;

    }


}
