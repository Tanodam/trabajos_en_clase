#include "informes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int informe(int mayor10000, int mayor20000, int contadorTV)
{
    int retorno = -1;
    FILE* pArchivo = fopen("informes.txt","w");
    if(pArchivo != NULL)
    {
        fprintf(pArchivo,"Cantidad de ventas por un monto mayor a $10.0000 %d\n"
                        "Cantidad de ventas por un monto mayor a $2.0000 %d\n"
                        "Cantidad de TV's LCD vendidas %d",mayor10000,mayor20000,contadorTV);
        retorno = 0;
    }

return retorno;
}

