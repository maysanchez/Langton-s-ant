/********************************************************************************
** Form generated from reading UI file 'pos.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POS_H
#define UI_POS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Pos
{
public:
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QPushButton *pushButton;

    void setupUi(QDialog *Pos)
    {
        if (Pos->objectName().isEmpty())
            Pos->setObjectName(QStringLiteral("Pos"));
        Pos->resize(150, 104);
        radioButton = new QRadioButton(Pos);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(20, 10, 41, 21));
        radioButton_2 = new QRadioButton(Pos);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(20, 30, 41, 31));
        radioButton_3 = new QRadioButton(Pos);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(20, 60, 82, 16));
        radioButton_4 = new QRadioButton(Pos);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setGeometry(QRect(20, 80, 82, 17));
        pushButton = new QPushButton(Pos);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 40, 75, 23));

        retranslateUi(Pos);

        QMetaObject::connectSlotsByName(Pos);
    } // setupUi

    void retranslateUi(QDialog *Pos)
    {
        Pos->setWindowTitle(QApplication::translate("Pos", "Dialog", 0));
        radioButton->setText(QApplication::translate("Pos", "\342\206\221", 0));
        radioButton_2->setText(QApplication::translate("Pos", "\342\206\223", 0));
        radioButton_3->setText(QApplication::translate("Pos", "\342\206\222", 0));
        radioButton_4->setText(QApplication::translate("Pos", "\342\206\220", 0));
        pushButton->setText(QApplication::translate("Pos", "Aceptar", 0));
    } // retranslateUi

};

namespace Ui {
    class Pos: public Ui_Pos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POS_H
