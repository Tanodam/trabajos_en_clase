#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


#define CANTIDAD_EMPLEADOS 6

int main()
{
    char nombres[15][50];
    int i;

    for(i=0;i < CANTIDAD_EMPLEADOS;i++)
    {
        array_getString(nombres,CANTIDAD_EMPLEADOS,"ingrese","error",3);
    }
    for(i=0;i < CANTIDAD_EMPLEADOS;i++)
    {
        printf("%s", nombres);
    }

    return 0;
}






