#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"

void myFlush()
{
    //fflush(stdin);
    __fpurge(stdin);
}
static int getInt(int* numeroIngresado)
{
    __fpurge(stdin);
    return scanf("%d", numeroIngresado);
}

static int getChar(char* caracterIngresado)
{
    __fpurge(stdin);
    return scanf("%c", caracterIngresado);
}

static int getFloat(int* numeroIngresado)
{
    __fpurge(stdin);
    return scanf("%f", numeroIngresado);
}

static int getString(int* textoIngresado)
{
    __fpurge(stdin);
    return scanf("%d", textoIngresado);
}




/**
*\brief Solicita un número al usuario, lo valida y devuelve el resultado
*\param pResultado Puntero a la variable resultado
*\param mensaje[] es el mensaje que se le va a mostrar al usuario
*\param mensajeError[] es el mensaje que se le va a mostrar al usuario si hay un error en la carga de datos
*\param minimo es el numero minimo aceptado
*\param maximo es el numero maximo aceptado
*\param reintentos es el numero maximo de reintentos aceptados
*\return Exito=0 y Error=1
*
*/
int utn_getNumero(  int* pResultado,
                    char mensaje[],
                    char mensajeError[],
                    int minimo,
                    int maximo,
                    int reintentos)
{
    int numero;
    int i;

    for(i=0;i<reintentos;i++)
    {
        printf("%s", mensaje);
        __fpurge(stdin);
        while(getInt(&numero)!=1)
        {
            //__fpurge(stdin);
            break;
        }

        if(numero>=minimo && numero<=maximo)
        {
            *pResultado=numero;
            return 0;
        }
        else
        {
            printf("%s", mensajeError);

        }
    }
    printf("Usted ha superado la cantidad de reintentos permitidos");
    return -1;
}

/**
*\brief Solicita un caracter al usuario, lo valida y devuelve el resultado
*\param pResultado Puntero a la variable resultado
*\param mensaje[] es el mensaje que se le va a mostrar al usuario
*\param mensajeError[] es el mensaje que se le va a mostrar al usuario si hay un error en la carga de datos
*\param minimo es el caracter minimo aceptado
*\param maximo es el caracter maximo aceptado
*\param reintentos es el numero maximo de reintentos aceptados
*\return Exito=0 y Error=1
*
*/
int utn_getCaracter(    char* pResultado,
                        char mensaje[],
                        char mensajeError[],
                        char minimo,
                        char maximo,
                        int reintentos)
{
    char caracter;
    int i;

    for(i=0;i<reintentos;i++)
    {
        printf("%s", mensaje);
        __fpurge(stdin);
        while(getChar(&caracter)!=1)
        {
            //__fpurge(stdin);
            break;
        }

        if(caracter>=minimo && caracter<=maximo)
        {
            *pResultado=caracter;
            return 0;
        }
        else
        {
            printf("%s", mensajeError);

        }
    }
    printf("Usted ha superado la cantidad de reintentos permitidos");
    return -1;
}
/**
*\brief Solicita un número al usuario, lo valida y devuelve el resultado
*\param pResultado Puntero a la variable resultado
*\param mensaje[] es el mensaje que se le va a mostrar al usuario
*\param mensajeError[] es el mensaje que se le va a mostrar al usuario si hay un error en la carga de datos
*\param minimo es el numero minimo aceptado
*\param maximo es el numero maximo aceptado
*\param reintentos es el numero maximo de reintentos aceptados
*\return Exito=0 y Error=1
*
*/
float utn_getNumeroFlotante(  float* pResultado,
                            char mensaje[],
                            char mensajeError[],
                            float minimo,
                            float maximo,
                            int reintentos)
{
    return 0;
}

