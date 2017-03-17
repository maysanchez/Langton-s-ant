#-------------------------------------------------
#
# Project created by QtCreator 2016-08-11T19:28:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = LangtonAnt
TEMPLATE = app


SOURCES += main.cpp\
    hormiga.cpp \
    imagen.cpp \
    simulador.cpp \
    grafica.cpp \
    qcustomplot.cpp

HEADERS  += \
    hormiga.h \
    imagen.h \
    simulador.h \
    grafica.h \
    qcustomplot.h

FORMS    += \
    simulador.ui \
    grafica.ui

RESOURCES += \
    imagenes.qrc
