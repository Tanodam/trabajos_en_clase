#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#define TAMANIO 500
int main()
{
    char miString[TAMANIO];
    char miEdad [TAMANIO];
    int edad;
    int comparacion;
    int i, validado=0;

//        strncpy(miString,"Pepe",TAMANIO);
//        comparacion=(strncmp("Pepo", miString, TAMANIO));
//        printf("%s\n", miString);
//        printf("%d", comparacion);
//        if (!strncmp("pepe", miString, TAMANIO));

        //Para ingresar un nombre
//        printf("Ingrese su nombre\n");
//        fgets(miString, TAMANIO, stdin);
//        printf("%s\n", miString);

        //Para pedir edad
        printf("Ingrese su edad\n");
        __fpurge;
        fgets(miEdad, TAMANIO, stdin);
        for(i=0;i<strlen(miEdad)-1; i++)
        {
            if(miEdad[i] > '0' || miEdad[i] < '9')
            {
                validado=-1;
                break;
            }
        }
    if(!validado)
        {
            edad=atoi(miEdad);
            printf("Mi edad es:%d", edad);
        }
        else
        {
            printf("Error");
        }


        return 0;
}





