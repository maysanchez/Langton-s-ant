/********************************************************************************
** Form generated from reading UI file 'simulador.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULADOR_H
#define UI_SIMULADOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SImulador
{
public:
    QAction *actionSave_configuration;
    QAction *actionOpen_configuration;
    QAction *actionSave_image;
    QAction *actionRandom_inizialitation;
    QAction *actionEdit_cell;
    QAction *actionBackground_color;
    QAction *actionGrid;
    QAction *actionInitialize_Configuration;
    QAction *actionDensities;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_2;
    QGroupBox *groupConfiguration;
    QSlider *speedSlider;
    QSlider *zoomSlider;
    QComboBox *positionBox;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pickColor;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *generation;
    QLabel *label_4;
    QLabel *ants;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *startButton;
    QPushButton *pauseButton;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menuFilae;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuGraph;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SImulador)
    {
        if (SImulador->objectName().isEmpty())
            SImulador->setObjectName(QStringLiteral("SImulador"));
        SImulador->resize(805, 536);
        QIcon icon;
        QString iconThemeName = QStringLiteral("Hormiga");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QStringLiteral("../../Descargas/CBLA.png"), QSize(), QIcon::Normal, QIcon::Off);
            icon.addFile(QStringLiteral(":/imagenes/CBLA.png"), QSize(), QIcon::Selected, QIcon::On);
        }
        SImulador->setWindowIcon(icon);
        SImulador->setStyleSheet(QLatin1String("background-color: rgb(46, 46, 46);\n"
"font: 75 12pt \"Comfortaa\";"));
        SImulador->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        SImulador->setUnifiedTitleAndToolBarOnMac(true);
        actionSave_configuration = new QAction(SImulador);
        actionSave_configuration->setObjectName(QStringLiteral("actionSave_configuration"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/imagenes/tag.png"), QSize(), QIcon::Active, QIcon::On);
        icon1.addFile(QStringLiteral(":/imagenes/Descargas/122910-linear-color-seo/png/tag.png"), QSize(), QIcon::Selected, QIcon::On);
        actionSave_configuration->setIcon(icon1);
        actionOpen_configuration = new QAction(SImulador);
        actionOpen_configuration->setObjectName(QStringLiteral("actionOpen_configuration"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/imagenes/search-2.png"), QSize(), QIcon::Active, QIcon::On);
        icon2.addFile(QStringLiteral(":/imagenes/Descargas/122910-linear-color-seo/png/search-2.png"), QSize(), QIcon::Selected, QIcon::On);
        actionOpen_configuration->setIcon(icon2);
        actionSave_image = new QAction(SImulador);
        actionSave_image->setObjectName(QStringLiteral("actionSave_image"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/imagenes/photo-camera.png"), QSize(), QIcon::Active, QIcon::On);
        icon3.addFile(QStringLiteral(":/imagenes/Descargas/122910-linear-color-seo/png/photo-camera.png"), QSize(), QIcon::Selected, QIcon::On);
        actionSave_image->setIcon(icon3);
        actionRandom_inizialitation = new QAction(SImulador);
        actionRandom_inizialitation->setObjectName(QStringLiteral("actionRandom_inizialitation"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/imagenes/pixel.png"), QSize(), QIcon::Selected, QIcon::On);
        actionRandom_inizialitation->setIcon(icon4);
        actionEdit_cell = new QAction(SImulador);
        actionEdit_cell->setObjectName(QStringLiteral("actionEdit_cell"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/imagenes/Descargas/122910-linear-color-seo/png/cursor.png"), QSize(), QIcon::Active, QIcon::On);
        icon5.addFile(QStringLiteral(":/imagenes/cursor.png"), QSize(), QIcon::Selected, QIcon::On);
        actionEdit_cell->setIcon(icon5);
        actionBackground_color = new QAction(SImulador);
        actionBackground_color->setObjectName(QStringLiteral("actionBackground_color"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/imagenes/layers.png"), QSize(), QIcon::Selected, QIcon::On);
        actionBackground_color->setIcon(icon6);
        actionGrid = new QAction(SImulador);
        actionGrid->setObjectName(QStringLiteral("actionGrid"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/imagenes/distort.png"), QSize(), QIcon::Selected, QIcon::On);
        actionGrid->setIcon(icon7);
        actionInitialize_Configuration = new QAction(SImulador);
        actionInitialize_Configuration->setObjectName(QStringLiteral("actionInitialize_Configuration"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/imagen.png"), QSize(), QIcon::Selected, QIcon::On);
        actionInitialize_Configuration->setIcon(icon8);
        actionDensities = new QAction(SImulador);
        actionDensities->setObjectName(QStringLiteral("actionDensities"));
        actionDensities->setEnabled(false);
        centralwidget = new QWidget(SImulador);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setEnabled(true);
        graphicsView->setMinimumSize(QSize(100, 100));
        graphicsView->setFrameShape(QFrame::NoFrame);
        graphicsView->setFrameShadow(QFrame::Plain);
        graphicsView->setLineWidth(0);

        horizontalLayout_2->addWidget(graphicsView);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));

        verticalLayout_3->addWidget(widget_2);

        groupConfiguration = new QGroupBox(centralwidget);
        groupConfiguration->setObjectName(QStringLiteral("groupConfiguration"));
        groupConfiguration->setEnabled(true);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(42, 42, 42, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(35, 35, 35, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(14, 14, 14, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(18, 18, 18, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        QBrush brush7(QColor(28, 28, 28, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        groupConfiguration->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Comfortaa"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        groupConfiguration->setFont(font);
        groupConfiguration->setCursor(QCursor(Qt::PointingHandCursor));
        groupConfiguration->setMouseTracking(false);
        groupConfiguration->setAutoFillBackground(false);
        groupConfiguration->setStyleSheet(QLatin1String("QGroupBox {\n"
"    border: 1px solid rgb(0, 0, 0);\n"
"    border-radius: 9px;\n"
"    margin-top: 0.5em;\n"
"	background-color: rgb(0, 0, 0)\n"
"}\n"
"QGroupBox::title {\n"
"	font: 105 25pt \"Utopia\";\n"
"	color: rgb(153, 0, 76);\n"
"    subcontrol-origin: margin;\n"
"    left: 5 px;\n"
"    padding: 0 3px 0 3px;\n"
"}\n"
"\n"
""));
        groupConfiguration->setFlat(false);
        speedSlider = new QSlider(groupConfiguration);
        speedSlider->setObjectName(QStringLiteral("speedSlider"));
        speedSlider->setGeometry(QRect(40, 50, 121, 20));
        speedSlider->setMinimum(1);
        speedSlider->setMaximum(16);
        speedSlider->setSingleStep(1);
        speedSlider->setPageStep(0);
        speedSlider->setValue(1);
        speedSlider->setSliderPosition(1);
        speedSlider->setOrientation(Qt::Horizontal);
        zoomSlider = new QSlider(groupConfiguration);
        zoomSlider->setObjectName(QStringLiteral("zoomSlider"));
        zoomSlider->setGeometry(QRect(40, 80, 121, 20));
        zoomSlider->setOrientation(Qt::Horizontal);
        zoomSlider->setInvertedControls(true);
        zoomSlider->setTickPosition(QSlider::NoTicks);
        positionBox = new QComboBox(groupConfiguration);
        positionBox->setObjectName(QStringLiteral("positionBox"));
        positionBox->setGeometry(QRect(10, 20, 101, 22));
        positionBox->setStyleSheet(QLatin1String("QComboBox {\n"
"	font: rgb(0, 0, 0) 19pt \"Utopia\";\n"
"}\n"
"	\n"
""));
        positionBox->setEditable(true);
        label_2 = new QLabel(groupConfiguration);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setEnabled(true);
        label_2->setGeometry(QRect(10, 50, 21, 17));
        label_2->setMouseTracking(false);
        label_2->setStyleSheet(QStringLiteral("background-color: rgb(8, 3, 3);"));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/search-1.png")));
        label_2->setScaledContents(true);
        label_3 = new QLabel(groupConfiguration);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 80, 31, 31));
        label_3->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/speedometer.png")));
        label_3->setScaledContents(true);
        pickColor = new QPushButton(groupConfiguration);
        pickColor->setObjectName(QStringLiteral("pickColor"));
        pickColor->setGeometry(QRect(130, 20, 25, 22));
        pickColor->setAutoFillBackground(false);
        pickColor->setStyleSheet(QLatin1String("QPushButton{\n"
"   background-color: rgb(205, 203, 203);\n"
"	border-color: rgb(205, 203, 203);\n"
"}"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/imagenes/rgb.png"), QSize(), QIcon::Normal, QIcon::Off);
        pickColor->setIcon(icon9);
        pickColor->setFlat(true);
        zoomSlider->raise();
        positionBox->raise();
        label_2->raise();
        label_3->raise();
        pickColor->raise();
        speedSlider->raise();

        verticalLayout_3->addWidget(groupConfiguration);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFont(font);
        groupBox->setStyleSheet(QLatin1String("QGroupBox {\n"
"    border: 1px solid rgb(0, 0, 0);\n"
"    border-radius: 9px;\n"
"    margin-top: 0.5em;\n"
"	background-color: rgb(0, 0, 0)\n"
"}\n"
"QGroupBox::title {\n"
"	font: 105 19pt \"Utopia\";\n"
"	color: rgb(153, 0, 76);\n"
"    subcontrol-origin: margin;\n"
"    left: 5px;\n"
"    padding: 0 3px 0 3px;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush8(QColor(190, 190, 190, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label->setPalette(palette1);
        label->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(label);

        generation = new QLabel(groupBox);
        generation->setObjectName(QStringLiteral("generation"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        generation->setPalette(palette2);
        generation->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(generation);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_4->setPalette(palette3);
        label_4->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(label_4);

        ants = new QLabel(groupBox);
        ants->setObjectName(QStringLiteral("ants"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        ants->setPalette(palette4);
        ants->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(ants);

        label_4->raise();
        generation->raise();
        ants->raise();
        label->raise();

        verticalLayout_3->addWidget(groupBox);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));

        verticalLayout_3->addWidget(widget_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/imagenes/flechas.png"), QSize(), QIcon::Active, QIcon::On);
        startButton->setIcon(icon10);

        horizontalLayout->addWidget(startButton);

        pauseButton = new QPushButton(centralwidget);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/imagenes/signos.png"), QSize(), QIcon::Active, QIcon::On);
        pauseButton->setIcon(icon11);

        horizontalLayout->addWidget(pauseButton);


        verticalLayout_2->addLayout(horizontalLayout);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/imagenes/flechas-3.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon12);

        verticalLayout_2->addWidget(pushButton);


        verticalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout_2->addLayout(verticalLayout_3);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        SImulador->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SImulador);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 805, 22));
        menuFilae = new QMenu(menubar);
        menuFilae->setObjectName(QStringLiteral("menuFilae"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuGraph = new QMenu(menubar);
        menuGraph->setObjectName(QStringLiteral("menuGraph"));
        SImulador->setMenuBar(menubar);
        statusbar = new QStatusBar(SImulador);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SImulador->setStatusBar(statusbar);

        menubar->addAction(menuFilae->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuGraph->menuAction());
        menuFilae->addAction(actionSave_configuration);
        menuFilae->addAction(actionOpen_configuration);
        menuFilae->addAction(actionSave_image);
        menuFilae->addAction(actionInitialize_Configuration);
        menuEdit->addAction(actionRandom_inizialitation);
        menuEdit->addAction(actionEdit_cell);
        menuView->addAction(actionBackground_color);
        menuView->addAction(actionGrid);
        menuGraph->addAction(actionDensities);

        retranslateUi(SImulador);

        QMetaObject::connectSlotsByName(SImulador);
    } // setupUi

    void retranslateUi(QMainWindow *SImulador)
    {
        SImulador->setWindowTitle(QApplication::translate("SImulador", "Langton's Ant", 0));
        actionSave_configuration->setText(QApplication::translate("SImulador", "Save configuration", 0));
        actionOpen_configuration->setText(QApplication::translate("SImulador", "Open configuration", 0));
        actionSave_image->setText(QApplication::translate("SImulador", "Save image ", 0));
        actionRandom_inizialitation->setText(QApplication::translate("SImulador", "Random initialization", 0));
        actionEdit_cell->setText(QApplication::translate("SImulador", "Edit cell", 0));
        actionBackground_color->setText(QApplication::translate("SImulador", "Background color", 0));
        actionGrid->setText(QApplication::translate("SImulador", "Grid", 0));
        actionInitialize_Configuration->setText(QApplication::translate("SImulador", "Initialize Configuration", 0));
        actionDensities->setText(QApplication::translate("SImulador", "Densities", 0));
        groupConfiguration->setTitle(QApplication::translate("SImulador", "Configuration", 0));
        positionBox->clear();
        positionBox->insertItems(0, QStringList()
         << QApplication::translate("SImulador", "Norte", 0)
         << QApplication::translate("SImulador", "Sur", 0)
         << QApplication::translate("SImulador", "Este", 0)
         << QApplication::translate("SImulador", "Oeste", 0)
        );
        positionBox->setCurrentText(QApplication::translate("SImulador", "Norte", 0));
        groupBox->setTitle(QApplication::translate("SImulador", "Data statistics", 0));
        label->setText(QApplication::translate("SImulador", "Generation    ::", 0));
        generation->setText(QString());
        label_4->setText(QApplication::translate("SImulador", "Alive cells       ::", 0));
        ants->setText(QString());
        startButton->setText(QApplication::translate("SImulador", "Start", 0));
        pauseButton->setText(QApplication::translate("SImulador", "Pause", 0));
        pushButton->setText(QApplication::translate("SImulador", "Clear", 0));
        menuFilae->setTitle(QApplication::translate("SImulador", "File", 0));
        menuEdit->setTitle(QApplication::translate("SImulador", "Edit", 0));
        menuView->setTitle(QApplication::translate("SImulador", "View", 0));
        menuGraph->setTitle(QApplication::translate("SImulador", "Graph", 0));
    } // retranslateUi

};

namespace Ui {
    class SImulador: public Ui_SImulador {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULADOR_H
