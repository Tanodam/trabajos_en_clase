#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
   float numero;

   numero=utn_getNumeroFlotante(&numero, "Ingrese un numero\t", "ERROR! Fuera de rango", -1000.00, 1000.00, 3);
   printf("%.2f", numero);
}
