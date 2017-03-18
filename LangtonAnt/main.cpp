#include "grid.h"
#include "simulador.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SImulador s;
    s.show();

    return a.exec();
}
