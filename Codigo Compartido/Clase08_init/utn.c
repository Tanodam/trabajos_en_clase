#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"
#define BUFFER_STR 4097

/**
    utn_getNombre :
    @param
    @param
    @return
*/
static int isValidNombre(char* pBuffer)
{
    return 1;
}

/**
    utn_getNombre :
    @param
    @param
    @return
*/
static int getString (char* pArray, int limiteaArray)
{
    int retorno = -1;
    char buffer[BUFFER_STR];
    char len;
    if(pArray!=NULL && limiteaArray > 0)
    {
        fgets(buffer, limiteaArray,stdin);
        len=strlen(buffer);
        if(len != limiteaArray-1 && buffer[limiteaArray-2]=='\n')
        {
            buffer[len-1] = '\0';
        }
        retorno = 0;
        strncpy(pArray,buffer,limiteaArray);
    }
    return retorno;

}

/**
    utn_getNombre :
    @param
    @param
    @return
*/
char array_getString(char* pArray, int limiteArray, char* mensaje, char* mensajeError, int reintentos)

{
    int i;
    int retorno=-1;
    int contadorIntentos=0;
    char buffer[BUFFER_STR];

    if(pArray != NULL && limiteArray > 0)
    {
        do
        {
            printf("%s", mensaje);
            contadorIntentos++;
            if(getString(buffer,limiteArray)==0)
//            fgets(buffer, limiteArray, stdin);
            myFlush();

            for(i=0;i<limiteArray;i++)
            {
                buffer[i]=tolower(buffer[i]); //Convierto todos los caracteres del array a minusculas para validarlos
            }
            if(array_StringCharEsValido(buffer, limiteArray)== 0) ///Valido los caracteres, si se cumple 0 y si no -1
            {
                buffer[0]=toupper(buffer[0]); ///Convierto a mayusculas el primer caracter.
                strncpy(pArray,buffer,limiteArray); ///Copio en el puntero a pArray el valor de string
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
                if(contadorIntentos==reintentos)
                {
                    printf("\nSe han superado los intenos maximos permitidos");
                    retorno = -1;
                    break;
                }
            }
        }while(contadorIntentos <= reintentos);
    }

    return retorno;
}




















