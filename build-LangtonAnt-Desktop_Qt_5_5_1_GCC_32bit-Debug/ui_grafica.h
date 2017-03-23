/********************************************************************************
** Form generated from reading UI file 'grafica.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAFICA_H
#define UI_GRAFICA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_grafica
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    QCustomPlot *customPlot;
    QPushButton *img;

    void setupUi(QWidget *grafica)
    {
        if (grafica->objectName().isEmpty())
            grafica->setObjectName(QStringLiteral("grafica"));
        grafica->resize(609, 421);
        grafica->setStyleSheet(QLatin1String("background-color: rgb(46, 46, 46);\n"
"font: 75 12pt \"Comfortaa\";"));
        gridLayout = new QGridLayout(grafica);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_2 = new QPushButton(grafica);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 1, 1, 1);

        customPlot = new QCustomPlot(grafica);
        customPlot->setObjectName(QStringLiteral("customPlot"));

        gridLayout->addWidget(customPlot, 0, 0, 1, 2);

        img = new QPushButton(grafica);
        img->setObjectName(QStringLiteral("img"));

        gridLayout->addWidget(img, 1, 0, 1, 1);


        retranslateUi(grafica);
        QObject::connect(pushButton_2, SIGNAL(clicked()), grafica, SLOT(close()));

        QMetaObject::connectSlotsByName(grafica);
    } // setupUi

    void retranslateUi(QWidget *grafica)
    {
        grafica->setWindowTitle(QApplication::translate("grafica", "Gr\303\241fica de densidades", 0));
        pushButton_2->setText(QApplication::translate("grafica", "Close", 0));
        img->setText(QApplication::translate("grafica", "Save image", 0));
    } // retranslateUi

};

namespace Ui {
    class grafica: public Ui_grafica {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAFICA_H
