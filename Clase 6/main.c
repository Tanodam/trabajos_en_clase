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
    char miApellido [STRINGLEN];
    int i, validado = 0, contadorGuiones=0, contadorArroba=0, contadorPunto=0;

    if(array_getString(miNombre,STRINGLEN,"Ingrese su nombre: ","NOMBRE INVALIDO\n")==0)
    {
        printf("El nombre ingresado es %s", miNombre);
    }
    if(array_getString(miApellido,STRINGLEN,"Ingrese su apellido: ","APELLIDO INVALIDO\n")==0)
    {
        printf("El apellido ingresado es %s", miApellido);
    }
    if(array_getStringNumerico(miEdad,STRINGLEN,"Ingrese su edad: ","EDAD INVALIDA\n")==0)
    {
        printf("La edad ingresada es %s", miEdad);
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
