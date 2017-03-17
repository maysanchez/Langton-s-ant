#include "grafica.h"
#include "ui_grafica.h"


grafica::grafica(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::grafica)
{
    ui->setupUi(this);


}

grafica::~grafica()
{
    delete ui;

}




void grafica::graficar(int generaciones, QVector <Hormiga*> ah,int r,int g, int b){
    // generate some data:
        int vivas=0;
        ants.resize(ah.length()) ;
       // qDebug() << " GENERACION " << generaciones;

        gen.append(generaciones);

       // qDebug() << " GEN " << gen;


        for(int l=0; l<ah.length(); l++){
         //   qDebug() << " H" << ah[l]->densidad;
            ants[l].resize (gen.length()-1);
        }

      //  qDebug() << " SIZE " << ants.size();


        for(int k=0; k<ah.length(); k++){

                ants[k].append(ah[k]->densidad);

        }



       // qDebug() << " ANTS " << ants;

        for(int i=0;i< ah.length();i++){
        vivas=vivas+ah[i]->densidad;

        ui->customPlot->addGraph();


        ui->customPlot->graph(i)->setLineStyle(QCPGraph::lsLine);
        ui->customPlot->graph(i)->setPen(QPen(QColor(ah[i]->getR(),ah[i]->getG(),ah[i]->getB())));
        ui->customPlot->graph(i)->setName("Hormiga"+i);

        ui->customPlot->graph(i)->setData(gen, ants[i]);
        }
        //qDebug() << " VIVAS " << vivas;

        // give the axes some labels:
        ui->customPlot->xAxis->setLabel("Generaciones");
        ui->customPlot->yAxis->setLabel("Celdas activadas");
        // set axes ranges, so we see all data:
        ui->customPlot->xAxis->setRange(0, generaciones+20);
        ui->customPlot->yAxis->setRange(0, vivas+20);

        ui->customPlot->replot();
}



void grafica::on_img_clicked()
{
   // qDebug() << "Voy a guardar una grafica";
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),"/home/dalbi/Escritorio/Simulaciones/untitled.png",tr("Images (*.png *.xpm *.jpg)"));
    QPixmap pixmap(ui->customPlot->size());

    ui->customPlot->render(&pixmap);
    pixmap.save(fileName);



}
