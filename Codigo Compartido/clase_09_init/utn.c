//#include <stdio_ext.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#define BUFFER_STR 4096
#define STRINGLEN 1000

/**
    utn_getNombre :
    @param
    @param
    @return
*/
static int isValidNombre(char* pBuffer,int limite)
{
    int retorno = 0;
    int i;
    if(pBuffer != NULL && limite > 0)
    {
        retorno = 1;
        for(i=0;i < limite && pBuffer[i] != '\0';i++)
        {
            if((tolower(pBuffer[i]) < 'a' || tolower(pBuffer[i]) > 'z') && pBuffer[i]!= ' ')
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

static int isValidDescription(char* pBuffer,int size)
{
    int retorno = 0;
    int i;
    if(pBuffer != NULL && size > 0)
    {
        retorno = 1;
        for(i=0;i < size && pBuffer[i] != '\0';i++)
        {
            if((tolower(pBuffer[i]) < 'a' || tolower(pBuffer[i]) > 'z') && (pBuffer[i] < '0' || pBuffer[i] > '9') && pBuffer[i]!= ' ' )
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
    utn_getNombre :
    @param
    @param
    @return
*/
static int getString(char* pBuffer, int limite)
{
    int retorno = -1;
    char bufferStr[BUFFER_STR];
    int len;
    if(pBuffer != NULL && limite > 0)
    {
        fflush(stdin);
        //__fpurge(stdin);
        fgets(bufferStr,limite,stdin);
        len = strlen(bufferStr);
        if(len != limite-1 ||  bufferStr[limite-2] == '\n')
        {
            bufferStr[len-1] = '\0';
        }
        retorno = 0;
        strncpy(pBuffer,bufferStr,limite);
    }
    return retorno;
}


/**
    utn_getNombre :
    @param
    @param
    @return
*/
int utn_getNombre(  char* pNombre, int limite, char* msg,
                    char* msgErr, int reintentos)

{
    int retorno=-1;
    char bufferNombre[BUFFER_STR];

    if( pNombre != NULL && limite > 0 && msg != NULL &&
        msgErr != NULL && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( getString(bufferNombre,limite) == 0 &&
                isValidNombre(bufferNombre,limite))
            {
                strncpy(pNombre,bufferNombre,limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("%s",msgErr);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}

int utn_getNumeroConComa(float* pResultado,
                char mensaje[],
                char mensajeError[],
                float  minimo,
                float  maximo,
                int  reintentos)
{
    int validado = 1;
    int tienePunto = 0;
    int tieneMenos = 0;
    char stringIngresado[STRINGLEN];//aca se guarda lo que ingreso como string
    float numero;
    printf("%s",mensaje);

     for(int i = 0;i<reintentos;i++)
    {
        validado = 1;
        tienePunto = 0;
        tieneMenos = 0;
        fflush(stdin);
        //__fpurge(stdin);
        fgets(stringIngresado, STRINGLEN, stdin);//pido un string con limite de caracters (STRINGLEN)

        for (int j=0; j<strlen(stringIngresado)-1; j++)//recorro caracter por caracter
        {
            if (stringIngresado[j] < '0' || stringIngresado[j] > '9')
            {
                //NaN
                if(j > 0 && j < strlen(stringIngresado)-2)
                {
                    //no estoy en el primero ni en el ultimo caracter
                    //si o si tengo que ser un punto
                    if(stringIngresado[j] != 46 || tienePunto == 1)
                    {
                        validado = 0;
                        break;
                    }
                    tienePunto = 1;
                }
                else
                {
                    if(j > 0 || stringIngresado[j] != 45)//si es un menos en la primer posicion safa
                    {
                        validado = 0;
                        break;
                    }
                    tieneMenos++;
                }

            }
        }
        if(tieneMenos == 1 && strlen(stringIngresado)-1 == 1)
        {
            validado = 0;
        }
        if (validado)
        {
            numero = atof(stringIngresado);
            if(numero >= minimo && numero <= maximo)
            {
                *pResultado = numero;//aca se le asigna el valor de numero a la variable apuntada por pResultado
                return 0;
            }
            printf("%s",mensajeError);
        }
        else {
           printf("%s",mensajeError);
        }
    }

    return -1;
}


int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

int utn_getDescription(  char* pDescription, int size, char* msg,
                    char* msgErr, int reintentos)

{
    int retorno=-1;
    char bufferDescription[BUFFER_STR];

    if( pDescription != NULL && size > 0 && msg != NULL &&
        msgErr != NULL && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( getString(bufferDescription,size) == 0 &&
                isValidDescription(bufferDescription,size))
            {
                strncpy(pDescription,bufferDescription,size);
                retorno = 0;
                break;
            }
            else
            {
                printf("%s",msgErr);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}

















