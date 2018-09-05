#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 5
#include "utn.h"

int main()
{
    int listadoDeNotas[CANTIDAD];
    int mayor;
    int menor;
    int suma=0;
    float promedio=0;
    int pares;


    cargarListado(listadoDeNotas, CANTIDAD);
    mostrarListado(listadoDeNotas, CANTIDAD);
    mostrarInformacionDelArray(listadoDeNotas, CANTIDAD);




    return 0;
}

