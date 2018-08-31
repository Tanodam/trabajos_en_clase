#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"


int main()
{
        int numero;
        if(utn_getNumero(&numero, "NUMERO\t", "El dato ingresado no es un numero o esta fuera de rango\n", 10, 100, 3)==0)
        {
                printf("\nEl numero ingresado es %d", numero);
        }
}

