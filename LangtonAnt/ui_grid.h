/********************************************************************************
** Form generated from reading UI file 'grid.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRID_H
#define UI_GRID_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_Grid
{
public:
    QGridLayout *gridLayout;
    QSlider *horizontalSlider;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QGraphicsView *graphicsView;

    void setupUi(QDialog *Grid)
    {
        if (Grid->objectName().isEmpty())
            Grid->setObjectName(QStringLiteral("Grid"));
        Grid->resize(491, 300);
        gridLayout = new QGridLayout(Grid);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSlider = new QSlider(Grid);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 1, 0, 1, 1);

        pushButton = new QPushButton(Grid);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(Grid);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 2, 1, 1);

        pushButton_3 = new QPushButton(Grid);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 1, 3, 1, 1);

        pushButton_4 = new QPushButton(Grid);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 1, 4, 1, 1);

        graphicsView = new QGraphicsView(Grid);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 5);


        retranslateUi(Grid);

        QMetaObject::connectSlotsByName(Grid);
    } // setupUi

    void retranslateUi(QDialog *Grid)
    {
        Grid->setWindowTitle(QApplication::translate("Grid", "Grid", 0));
        pushButton->setText(QApplication::translate("Grid", "Start", 0));
        pushButton_2->setText(QApplication::translate("Grid", "Stop", 0));
        pushButton_3->setText(QApplication::translate("Grid", "Save", 0));
        pushButton_4->setText(QApplication::translate("Grid", "Add", 0));
    } // retranslateUi

};

namespace Ui {
    class Grid: public Ui_Grid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRID_H
