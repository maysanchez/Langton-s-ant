#ifndef SIMULACION_H
#define SIMULACION_H
#include "hormiga.h"

class Simulacion
{
public:
    Simulacion(Hormiga* hormigas);
    void iniciaAlgoritmo();

private:
    Hormiga* hormigas;
};

#endif // SIMULACION_H
