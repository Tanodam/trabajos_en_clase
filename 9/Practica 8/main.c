#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "utn.h"

int main()
{
    int numero;
    numero= utn_getNumero(&numero,"Ingrese un numero\n", "ERROR",0,9,3);
    printf("%d",numero);
    return 0;
}
