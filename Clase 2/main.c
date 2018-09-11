#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#define LIMITE_ARRAY 5

//En este ejercio se va a utilizar un array para solicitar 3 numeros al usuario y encontrar MINIMOS y MAXIMOS.

int main()
{
    float numero [LIMITE_ARRAY]; //Los array se definen con []
    int i;
    float suma=0;

    for(i=0;i<LIMITE_ARRAY;i++)
    {
        printf("Numero %d:\t", i+1); //Se suma i+1 para que vaya mostrando en pantalla que numero ingresar
        while(scanf("%f", &numero[i]) != 1)
        {
            printf("Error! Numero %d\t", i+1);
            __fpurge(stdin);//funcion que sirve para vaciar el buffer de entrada
        }
    }

    for(i=0;i<LIMITE_ARRAY;i++)
    {
        suma=suma+numero[i];
    }
    printf("la suma total es %.2f:", suma);
    printf("\nel promedio es %.2f", suma/LIMITE_ARRAY);
}
