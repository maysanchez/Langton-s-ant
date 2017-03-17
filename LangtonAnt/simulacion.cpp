#include "simulacion.h"

Simulacion::Simulacion(Hormiga *hormigas)
{
    this->hormigas=hormigas;

}

void Simulacion::iniciaAlgoritmo()
{
    int totalHormigas = sizeof(hormigas);
    for(int i=0; i<totalHormigas; i++)
    {
       if(hormigas[i].checaCelda()==false) //Falso=blanco
       {
           hormigas[i].giraDerecha();
           hormigas[i].invierteColor();
       }

    }

}

