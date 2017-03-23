#include "simulador.h"
#include "ui_simulador.h"
#include "celda.h"
#include "hormiga.h"
#include "imagen.h"
#include <QtCore>
#include <QVector>
#include <QMatrix>
#include <QThread>
#include <QFileDialog>
#include <QColorDialog>
#include <QMessageBox>
#include <sstream>
#include <QtGlobal>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
//#include <math.h>
#include <QApplication>
//#include <QGraphicsScene>
#include <QPixmap>
#include <QTime>
#include <QThread>
#include <QInputDialog>


#define ALTO 1000 //x 1000
#define ANCHO 1000 //y 1087
#define GENERACIONES 20000
//#define RETARDO 1500

bool SImulador::inicia = false;
int SImulador:: cg = 1;
//int del;

SImulador::SImulador(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SImulador)
{

    ui->setupUi(this);
    scene = new QGraphicsScene(this);

    this->setWindowState(Qt::WindowMaximized);
    int ancho = ANCHO; //y
    int alto = ALTO;   //x
    QColor co = QColor(255,255,128); //Color de fondo AMARILLO

    QTextStream(stdout) << "ancho: " << ancho << endl;
    QTextStream(stdout) << "alto: " << alto << endl;

    pausa = false;
    reanuda = false;
    configuracion = false;
    inicializacion = false;
    lineas=0;
    fondo=1;
    random=0;
    robots =0;
    r = 255; //Color rosa
    g = 0;
    b = 170;
    ractual = r;
    gactual = g;
    bactual = b;
    p = 'N';
    pactual = p;
    maximo = 0;
    w = 0;
    retardo=100;
    time = QTime::currentTime();
    qsrand((uint)time.msec());


    this->image = new Imagen(alto, ancho, co);
    //coo.resize(2);
    graph= new grafica();

    pm = QPixmap::fromImage(image->pintaGrid(fondo));
    scene->addPixmap(pm);


    pintaLineas(robots);


    ui->graphicsView->setScene(scene);
    //ui->graphicsView->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOn );
    //ui->graphicsView->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOn );


}



void SImulador::iniciaAlgoritmo()
{
    QTextStream(stdout) << " ************** INICIA ALGORITMO ************** " <<endl;
    th=0;

        /* Todas las hormigas verifican la celda donde se encuentran paradas */
        for(int h=0; h<ah.size();h++){
            if(image->vm[ah[h]->getX()][ah[h]->getY()] == 0)
                ah[h]->setCeldaActual(false);
            else
                ah[h]->setCeldaActual(true);
          }


         /* Todas las hormigas actúan segun la celda donde se encuentran */
         for(int h=0; h<ah.size();h++){
             if(ah[h]->getX()>ANCHO)
                 ah[h]->setX(0);
             else if(ah[h]->getX()<0)
                 ah[h]->setX(ANCHO);
             if(ah[h]->getY()>ALTO)
                 ah[h]->serY(0);
             else if(ah[h]->getY()<0)
                 ah[h]->serY(ALTO);

             if(ah[h]->getCeldaActual() == false){
                 image->vm[ah[h]->getX()][ah[h]->getY()]=1;
                 /*GUardamos coordenadas en el arreglo de casillas visitadas*/
                 agregaCasilla(ah[h]->getX(), ah[h]->getY());
                 image->imagen.setPixel(ah[h]->getX(),ah[h]->getY(),qRgb(ah[h]->getR(),ah[h]->getG(),ah[h]->getB())); //255,0,170
                 ah[h]->giraDerecha();
             }
             else{
                 image->vm[ah[h]->getX()][ah[h]->getY()]=0;
                 /*Quitamos coordenadas en el arreglo*/
                 eliminaCasilla(ah[h]->getX(), ah[h]->getY());
                 if(fondo==1){
                 image->imagen.setPixel(ah[h]->getX(),ah[h]->getY(),qRgb(255,255,128));
                 }else{
                 image->imagen.setPixel(ah[h]->getX(),ah[h]->getY(),qRgb(255,255,255));

                 }
                 ah[h]->giraIzquierda();
            }
        }

    for(int r=0; r<ah.length(); r++)
        ah[r]->densidad = cuentaCasillas(ah[r]->getR(),ah[r]->getG(),ah[r]->getB());

    pm = QPixmap(QPixmap::fromImage(image->imagen));
    actualizaGrid();
    pintaLineas(robots);

    ui->generation->setText(QString::number(cg));

    for(int y=0; y<ah.length(); y++)
        th = ah[y]->densidad + th;

    ui->ants->setText(QString::number(th));

     if(th > maximo)
         maximo = th;

       delay(retardo);
       graph->graficar(cg,ah,ractual,gactual,bactual);

}

void SImulador::delay(int seg)
{


    QTime dieTime  = QTime::currentTime().addMSecs(seg);
        while(QTime::currentTime() < dieTime)
        {
            QCoreApplication::processEvents(QEventLoop::AllEvents,1);
        }
}

void SImulador::saveFile()
{
    QFile file(curFile);
    QVector <int> vr;
    QVector <int> vg;
    QVector <int> vb;
    QString s;
    bool existe = false;

    if(file.open(QFile::WriteOnly))
    {
        QTextStream text_stream_for_writing(&file);

        for(int i=0; i<ALTO; i++){
            for (int j=0; j<ANCHO;j++){
                if(image->vm[j][i] == 1){
                    QRgb colorTem = image->getImagen().pixel(QPoint(j,i));
                    QColor c(colorTem);

                    /*if((std::find(vr.begin(), vr.end(), c.red()) == vr.end()) && (std::find(vg.begin(), vg.end(), c.green()) == vg.end()) && (std::find(vb.begin(), vb.end(), c.blue()) == vb.end())){
                        vr << c.red();
                        vg << c.green();
                        vb << c.blue();
                    }*/
                    for(int a=0; a<vr.length(); a++){
                        if(vr[a] == c.red()){
                            if(vg[a] == c.green()){
                                if(vb[a] == c.blue()){
                                   // qDebug() << "el COLOR YA EXISTE";
                                    existe = true;
                                    a=vr.length();
                                }
                            }
                        }
                    }

                    if(!existe){
                        vr << c.red();
                        vg << c.green();
                        vb << c.blue();
                    }

                    //qDebug() << "LOngitud de vectorR "<<vr.length();
                    existe = false;

                    for(int lv=0; lv<vr.length(); lv++){
                        if(c.red() == vr[lv] && c.green() == vg[lv] && c.blue() == vb[lv])
                            text_stream_for_writing  << QString::number((lv+1));
                    }
                }else
                    text_stream_for_writing  << QString::number(image->vm[j][i]);
            }
            text_stream_for_writing << "\r\n";
        }
        text_stream_for_writing.seek((ALTO*ANCHO)+(ALTO*2)); //1183752  10200


        for(int h=0; h<ah.size();h++){
          text_stream_for_writing << QString::number(ah[h]->getX());
          text_stream_for_writing<<",";
          text_stream_for_writing << QString::number(ah[h]->getY());
          text_stream_for_writing<<",";
          text_stream_for_writing<< ah[h]->getP();
          text_stream_for_writing<<",";
          text_stream_for_writing<< QString::number(ah[h]->getR());
          text_stream_for_writing<<",";
          text_stream_for_writing<< QString::number(ah[h]->getG());
          text_stream_for_writing<<",";
          text_stream_for_writing<< QString::number(ah[h]->getB());
          text_stream_for_writing << "\n";
        }
        text_stream_for_writing << " ";
        text_stream_for_writing << QString::number(cg);
        text_stream_for_writing << "\r\n";

        text_stream_for_writing << "*";
        file.close();
    }else{
        QMessageBox::warning(this,"Saving",tr("Error al escribir en el archivo"));
    }
}

void SImulador::pintaCelda(int x, int y, int c[3])
{
    image->imagen.setPixel(x,y,qRgb(c[0],c[1],c[2]));
    pm = QPixmap(QPixmap::fromImage(image->imagen));
    actualizaGrid();

}



void SImulador::pintaLineas(int robots)
{


    if(lineas==0){
        //qDebug() << "con lineas" ;
    if (robots==1){

        for (int x=0; x<ALTO; x+=3)
            scene->addLine(x,0,x,ALTO, QPen(Qt::black,0.01));

        for (int y=0; y<ANCHO; y+=3)
            scene->addLine(0,y,ANCHO,y, QPen(Qt::black,0.01));

    }else{
    for (int x=0; x<ALTO; x+=1)
        scene->addLine(x,0,x,ALTO, QPen(Qt::black,0.01));

    for (int y=0; y<ANCHO; y+=1)
        scene->addLine(0,y,ANCHO,y, QPen(Qt::black,0.01));
     }
    }
    else{

       // qDebug() << "sin lineas" ;



    }
}

void SImulador::agregaCasilla(int x, int y)
{
    coo<< x;
    coo<< y;
   // qDebug() << "tam casillasVisitadas:: " << CasillasVisitadas.length();

    if(std::find(CasillasVisitadas.begin(), CasillasVisitadas.end(), coo) == CasillasVisitadas.end()){
       CasillasVisitadas << coo;
    }

   // qDebug() << "Agregue casilla";
   // qDebug() << CasillasVisitadas;
    coo.clear();
}

void SImulador::eliminaCasilla(int x, int y)
{
    coo << x;
    coo << y;
   // qDebug() << "Voy a borrar :: "<< coo;

    int f = CasillasVisitadas.indexOf(coo);
    if(f >= 0)
        CasillasVisitadas.remove(f);
    coo.clear();
}

int SImulador::cuentaCasillas(int r, int g, int b)
{
    QRgb colorTem;
    QColor c;
    QVector <int> v;
    int total = 0;

    for(int h=0; h<CasillasVisitadas.length(); h++ ){
        v << CasillasVisitadas[h];
        colorTem = image->getImagen().pixel(QPoint(v[0],v[1]));
        QColor c(colorTem);

        if(c.red()==r && c.green()==g && c.blue()==b && c.alpha()==255)
            total = total + 1;

        v.clear();
    }

    return total;

}

void SImulador::actualizaGrid()
{
    scene->clear();
    scene->addPixmap(pm);
}

void SImulador::on_startButton_clicked()
{
    ui->actionDensities->setEnabled(true);

    inicializacion = false;
    if(!reanuda){
        inicia = true;

        while(cg<GENERACIONES && inicia == true){
            ui->startButton->setDisabled(true); // ->setText(QString::number(cg));
            iniciaAlgoritmo();
            cg++;
        }
     }
    else{
        while(cg<GENERACIONES && inicia == true){
               iniciaAlgoritmo();
               ui->startButton->setDisabled(true);
            cg++;
        }
    }

     pm = QPixmap(QPixmap::fromImage(image->imagen));
     actualizaGrid();
     pintaLineas(robots);

     ui->startButton->setEnabled(true);
}

void SImulador::on_pauseButton_clicked()
{
    ui->startButton->setDisabled(true);

    if(inicia){
        inicia = false;
        reanuda = false;
    }

    else if(!inicia){
        inicia=true;
        reanuda=true;

        while(cg<GENERACIONES && inicia == true)
        {
            iniciaAlgoritmo();
            cg++;
        }
    }
}

void SImulador::on_actionSave_configuration_triggered()
{
    inicia = false;
    QString fileName = QFileDialog::getSaveFileName(this,"Guarda Configuracion","/home/maytee/Escritorio/Pruebas/Archivos/h.txt","Text Files (*.txt)");

    if(!fileName.isEmpty())
    {
        curFile = fileName;
        saveFile();
    }
    inicia = true;
}

void SImulador::on_actionOpen_configuration_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Carga Configuracion","/home/maytee/Escritorio/Pruebas/Archivos/","Text Files (*.txt)");

        if(!fileName.isEmpty()){
            QFile file(fileName);
            if(file.open(QFile::ReadOnly)){

                QTextStream text_stream_for_reading(&file);
                text_stream_for_reading.seek(0);
                QString text;
                int y=1;
                QVector <int> ifi;
                QVector <int> jfi;
                QVector <int> is;
                QVector <int> js;

                int co[3];
                for(int i=0; i<ALTO; i++) //ALTO
                {
                    text = text_stream_for_reading.readLine();
                  //  qDebug() << text.length();
                  //  qDebug()<< text;

                    for(int j=0; j<text.length(); j++){
                        if(text[j]=='0')
                            image->vm[j][i]=0;
                        else{
                            image->vm[j][i]=1;

                            if(text[j]=='1'){
                                ifi << i;
                                jfi <<  j;
                            }
                            else if(text[j] == '2'){
                                is << i;
                                js <<  j;
                            }

                        }
                    }

                    if(i>0)
                        y=y+(ANCHO+2);
                    else
                        y=y+(ANCHO+1);

                    text_stream_for_reading.seek(y);
                  }

                while(text != "*"){
                    text = text_stream_for_reading.readLine();
                   // qDebug() << text.length();
                   // qDebug() << text;

                    if(text.length()>8) //if(text.length()>1)
                    {
                        QStringList myStringList = text.split(",");
                       /* qDebug() << myStringList.at(0);
                        qDebug() << myStringList.at(1);
                        qDebug() << myStringList.at(2);
                        qDebug() << myStringList.at(3);
                        qDebug() << myStringList.at(4);
                        qDebug() << myStringList.at(5);*/

                        co[0]= myStringList.at(3).toInt();
                        co[1]= myStringList.at(4).toInt();
                        co[2]= myStringList.at(5).toInt();

                        QByteArray array = myStringList.at(2).toLocal8Bit();
                        char* buffer = array.data();

                        Hormiga* ant = new Hormiga(myStringList.at(0).toInt(),myStringList.at(1).toInt(),buffer[0],co);
                        ah << ant;
                    }

                    //else if(text[0] == " ")
                    else if( text.startsWith(' ')){
                      cg = text.toInt();
                    }


                   // qDebug()<<"EL archivo tiene -- " << text.toInt();
                   // qDebug()<<"cg = "<< cg;
                 }                

              file.close();
              /*Se pintan hormigas*/
              QVector <int> vr;
              QVector <int> vg;
              QVector <int> vb;

              for(int k=0; k<ah.length();k++)
              {
                  vr << ah[k]->getR();
                  vg << ah[k]->getG();
                  vb << ah[k]->getB();
              }

              for(int p=0; p<ifi.length(); p++)
                   image->imagen.setPixel(jfi[p],ifi[p],qRgb(vr[0],vg[0],vb[0]));

              for(int t=0; t<is.length(); t++)
                   image->imagen.setPixel(js[t],is[t],qRgb(vr[1],vg[1],vb[1]));

              //actualizaGrid();
              scene->clear();
              scene->addPixmap(QPixmap::fromImage(image->imagen));
              ui->generation->setText(QString::number(cg));

            }else{
                QMessageBox::warning(this,"Carga configuracion",tr("Error al cargar el archivo %1.\nError: %2").arg(fileName).arg(file.errorString()));
            }
       reanuda = true;
       inicia = true;
    }

}

void SImulador::on_speedSlider_valueChanged(int value)
{
    step = pow(2,value);
    step = step/2;
    QMatrix matrix;
    matrix.scale(step, step);
    ui->graphicsView->setMatrix(matrix);
}

void SImulador::on_pickColor_clicked()
{
    pausa = true;
    QColor color;
    color = QColorDialog::getColor(Qt::black, this);
    /*QTextStream(stdout) << "Se selecciono el color R: " << color.red() << endl;
    QTextStream(stdout) << "Se selecciono el color G: " << color.green() << endl;
    QTextStream(stdout) << "Se selecciono el color B: " << color.blue() << endl;*/

    ractual=color.red();
    gactual=color.green();
    bactual=color.blue();
}

void SImulador::mousePressEvent(QMouseEvent *event)
{
    double x=0.0, y=0.0;
    bool presente = false;
    w += 1;

    if(inicializacion){
         QPoint remapped = ui->graphicsView->mapFromParent( event->pos() );

         if ( ui->graphicsView->rect().contains( remapped ) )
         {
             int co[3];
             co[0]= ractual;
             co[1]= gactual;
             co[2]= bactual;

              QPointF mousePoint = ui->graphicsView->mapToScene( remapped );
              if(escala==1){
                  mousePoint.setY( mousePoint.y() - 21);
              }else{
                  mousePoint.setY( mousePoint.y() - 1);
                  mousePoint.setX( mousePoint.x() - 1);
              }

              mousePoint.setX(mousePoint.x());
              x = mousePoint.x();
              y = mousePoint.y();

              x=ceil(x);
              y=ceil(y);

            //  qDebug() << mousePoint;
            //  qDebug() << "x " << x;
            //  qDebug() << "y " << y;

              pintaCelda(x,y,co);
              pintaLineas(robots);

              /*Guarda hormiga*/
              Hormiga* ant = new Hormiga(x,y,pactual,co);

              if (ah.isEmpty()){
                  ah << ant;
              }
              else{
                  for(int u=0; u< ah.length(); u++){
                      if(ah[u]->getX() == x     &&     ah[u]->getY() == y){
                          presente = true;
                          ah[u]->actualiza(pactual, co);
                          u = ah.length();
                      }
                  }

                  if(!presente){
                      ah << ant;
                  }
              }
         }
    }
}

void SImulador::on_actionInitialize_Configuration_triggered()
{
    inicializacion = true;
}

void SImulador::on_positionBox_highlighted(const QString &arg1)
{
    QString ps = arg1;
        if(ps == "Norte")
            pactual='N';
        else if(ps == "Sur")
            pactual='S';
        else if(ps == "Este")
            pactual='E';
        else if(ps == "Oeste")
            pactual='O';
}

void SImulador::on_actionSave_image_triggered()

{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),"/home/dalbi/Escritorio/Simulaciones/untitled.png",tr("Images (*.png *.xpm *.jpg)"));

    QImage img(scene->height(),scene->width(),QImage::Format_ARGB32_Premultiplied);
    QPainter p(&img);
    scene->render(&p);
    p.end();
    img.save(fileName);



}

void SImulador::on_zoomSlider_valueChanged(int value)
{

  // qDebug() << " value = "<< value;
  // qDebug() << " del = "<< retardo;

    retardo = (100 - value);
}


void SImulador::on_actionDensities_triggered()
{
  //  qDebug() << " Voy a graficar... ";

    graph->show();
}

SImulador::~SImulador()
{
    delete ui;
}


void SImulador::on_pushButton_clicked()
{
    for(int x=0; x<ALTO; x++){
        for(int y=0; y<ANCHO;y++){
            if(image->vm[x][y]==1)
                image->vm[x][y]=0;
        }
    }

    pausa = false;
    reanuda = false;
    configuracion = false;
    inicializacion = false;
    inicia = false;
    cg = 0;

    ui->pushButton->setEnabled(true);
    for(int h=0; h<ah.length(); h++){
        ah[h]->setX(ah[h]->getxInicial());
        ah[h]->serY(ah[h]->getyInicial());
        ah[h]->serPosition(ah[h]->getpInicial());
        ah[h]->densidad = 0;
     }

    pm = QPixmap::fromImage(image->pintaGrid(fondo));
    for(int p=0; p<ah.length(); p++)
         image->imagen.setPixel(ah[p]->getX(),ah[p]->getY(),qRgb(ah[p]->getR(),ah[p]->getG(),ah[p]->getB()));

    scene->addPixmap(pm);
    pintaLineas(robots);

}

void SImulador::on_actionGrid_triggered()
{
  //  qDebug() << " LINEAS " << lineas;

    if(lineas==1){
    lineas=0;}else{
    lineas=1;}

   // qDebug() << " LINEAS " << lineas;

    actualizaGrid();
    pintaLineas(robots);


}

void SImulador::on_actionBackground_color_triggered()
{
    if(fondo==1){
    fondo=0;}else{
    fondo=1;}
  //  qDebug() << " Background " ;



    image->pintaGrid(fondo);

    pm = QPixmap(QPixmap::fromImage(image->imagen));
    actualizaGrid();
    pintaLineas(robots);



}

void SImulador::on_actionRandom_inizialitation_triggered()
{

    random=1;
    int co[3];
    int x,y;
    bool presente = false;



    co[0]= 0;
    co[1]= 0;
    co[2]= 0;

   // qDebug() << " Random " ;



    int n = QInputDialog::getInt(this,"Random initialization","Enter the desired density..." );

   // qDebug() << " Densidad " << n;


    densidad = n;


    for(int i;i<n;i++){

    x=qrand() % 500;
    y=qrand() % 500;

    Hormiga* ant = new Hormiga(x,y,pactual,co);
    pintaCelda(x,y,co);


    if (ah.isEmpty()){
        ah << ant;
    }
    else{
        for(int u=0; u< ah.length(); u++){
            if(ah[u]->getX() == x     &&     ah[u]->getY() == y){
                presente = true;
                ah[u]->actualiza(pactual, co);
                u = ah.length();
            }
        }

        if(!presente){
            ah << ant;
        }
    }

    }
    pintaLineas(robots);


}




void SImulador::on_radioButton_clicked()
{
    robots=0;
    qDebug() << " biologica "<< robots;


    lineas=0;
    actualizaGrid();
    pintaLineas(robots);
}

void SImulador::on_radioButton_2_clicked()
{
    robots=1;
    qDebug() << " robotica "<< robots;

    lineas=0;
    actualizaGrid();
    pintaLineas(robots);
}

