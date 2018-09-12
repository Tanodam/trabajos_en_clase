#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "array.h"
#define STRINGLEN 50

 int main()
{
    char miNombre[STRINGLEN];
    char miEdad[STRINGLEN];
    char miCelular[STRINGLEN];
    char miCorreo[STRINGLEN];
    int edad, i, validado = 0, contadorGuiones=0, contadorArroba=0, contadorPunto=0;

    array_getNombre(miNombre, STRINGLEN);
    printf("El nombre ingresado es %s", miNombre);

//______________________________________________________________________________________________________________

    printf("\nIngrese su edad:");
    fflush(stdin);
    fgets(miEdad, STRINGLEN, stdin);

    for (i=0; i<strlen(miEdad)-1; i++) {
        if (miEdad[i] < '0' || miEdad[i] > '9')
        {
            validado = -1;
            break;
        }
    }

    if (!validado && miEdad[i]<100)
    {
        edad = atoi(miEdad);
        printf("Mi edad es: %d", edad);
    }
    else
    {
        printf("Edad invalida!");
    }
//_____________________________________________________________________________________________

    validado = 0;
    printf("\nIngrese su celular: ");
    fflush(stdin);
    fgets(miCelular, STRINGLEN, stdin);

    for (i=0; i<strlen(miCelular)-1; i++)
    {
        if ((miCelular[i] != ' ') && (miCelular[i] != '-') && (miCelular[i] < '0' || miCelular[i] > '9'))
        {
            validado = -1;
            break;
        }
        if(miCelular[i] == '-')
        {
            contadorGuiones++;
        }
    }

    if (!validado && (contadorGuiones>=1 || contadorGuiones<=2))
    {
        printf("Mi celular es: %s", miCelular);
    }
    else
    {
        printf("Celular invalido!");
    }
    validado=0;
//_______________________________________________________________________________

    do
    {

    printf("Ingrese su correo: ");
    fflush(stdin);
    fgets(miCorreo, STRINGLEN, stdin);

    for (i=0; i<strlen(miCorreo)-1; i++)
    {
        if((miCorreo[0] = '@' || miCorreo[i] != '@') && (miCorreo[i] != '.' || miCorreo[i] != ' ') && (miCorreo[i] < 'a' || miCorreo[i] > 'z')
            && (miCorreo[i] < '0' || miCorreo[i] > '9'))
        {
            validado = -1;
            break;
        }
        if(miCorreo[i] == '@')
        {
            contadorArroba++;
        }
        if(miCorreo[i] == '.')
        {
            contadorPunto++;
        }
    }
    if (!validado && contadorArroba==1)
        {
            printf("Mi correo es: %s", miCorreo);
            validado=0;
        }
    else
        {
            printf("Correo invalido!");
            return -1;
        }
    }while(validado!=0);

    return 0;
}
