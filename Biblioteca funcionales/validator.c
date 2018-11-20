#include <stdio.h>
#include <stdlib.h>

#include "string.h"
#include "ctype.h"
#include "utn.h"

/**
*\brief [Funcion interna de GetMail] Valida que el usuario haya ingresado un mail correcto
*\param pArray Puntero a la direccion de memoria donde esta almacenada el string a validar
*\param limiteArray tamaño del array
*\return Exito=1 y Error=-0
*/
int array_StringMailEsValido (char* pBuffer, int limite)
{
    int retorno = 0;
    int contadorDeArrobas = 0;
    int contadorDePuntosTrasArroba = 0;
    int flagLetraIntroducida = 0;
    int i;
    if( pBuffer != NULL && limite > 0 &&
        strlen(pBuffer) > 0 &&
        tolower(pBuffer[0]) >= 'a' &&
        tolower(pBuffer[0]) <= 'z')
    {
        retorno = 1;
        flagLetraIntroducida = 1;
        for(i=0; i < limite && pBuffer[i] != '\0'; i++)
        {
            if( (tolower(pBuffer[i]) >= 'a' && tolower(pBuffer[i]) <= 'z' ) ||
                    (pBuffer[i] >= '0' && tolower(pBuffer[i]) <= '9' && contadorDeArrobas == 0))
            {
                flagLetraIntroducida = 1;
            }
            else if(pBuffer[i] == '@' && contadorDeArrobas == 0 && flagLetraIntroducida == 1)
            {
                contadorDeArrobas++;
                flagLetraIntroducida = 0;
            }
            else if(pBuffer[i] == '.' && flagLetraIntroducida == 1)
            {
                flagLetraIntroducida = 0;
                if(contadorDeArrobas == 1)
                {
                    contadorDePuntosTrasArroba++;
                }
            }
            else if(pBuffer[i] == '_' && flagLetraIntroducida == 1 && contadorDeArrobas == 0)
            {
                flagLetraIntroducida = 0;
            }
            else
            {
                retorno = 0;
                break;
            }
        }
    }
    if(retorno == 1 && contadorDeArrobas == 1 && contadorDePuntosTrasArroba > 0)
    {
        retorno = 1;
    }
    else
    {
        printf("\nejemplo_123@mail.com.ar");
        retorno = 0;
    }
    return retorno;
}
/**
*\brief [Funcion interna de GetStringFloat] Valida que el usuario solo haya ingresado caracteres del 0 al 9
*\param pArray Puntero a la direccion de memoria donde esta almacenada el string a validar
*\param limiteArray tamaño del array
*\return Exito=0 y Error=-1
*/
int array_StringFloatEsValido (char* pArray, int limiteArray)
{
    int i=0;
    int retorno = 0;
    int contadorPuntos = 0;


    if(pArray != NULL && limiteArray > 0)
    {
        retorno = 1;
        for(i=0; i < limiteArray && pArray[i] != '\0'; i++)
        {
            switch(pArray[i])
            {
            case 46: //Punto
                if(i==0 || i==(strlen(pArray)-1))
                {
                    retorno = 0;
                    break;
                }
                contadorPuntos++;
                break;
            default:          ///0                 9
                if((pArray[i] < 48 || pArray[i] > 57) || contadorPuntos == 1)
                {
                    retorno = 0;
                }
                break;
            }
        }
    }

    return retorno;
}
/**
*\brief [Funcion interna de GetStringInt] Valida que el usuario solo haya ingresado caracteres del 0 al 9
*\param pArray Puntero a la direccion de memoria donde esta almacenada el string a validar
*\param limiteArray tamaño del array
*\return Exito=0 y Error=-1
*/
int array_StringIntEsValido(char* pArray, int limiteArray)
{
    int i=0;
    int retorno = 0;

    if(pArray != NULL && limiteArray > 0)
    {
        retorno = 1;
        for(i=0; i < limiteArray && pArray[i] != '\0'; i++)
        {
            switch(pArray[i])
            {
            default:          ///0                 9
                if((pArray[i] < 48 || pArray[i] > 57))
                {
                    retorno = 0;
                }
                break;
            }
        }
    }

    return retorno;
}
/**
*\brief [Funcion interna de GetStringChar] Valida que el usuario solo haya ingresado caracteres de la A a la Z
*\param pArray Puntero a la direccion de memoria donde esta almacenada el string a validar
*\param limiteArray tamaño del array
*\return Exito=1 y Error=0
*/
int array_StringCharEsValido (char* pArray, int limiteArray)
{
    int retorno=-1;
    int i;
    int indiceEspacio=0;

    if((pArray!= NULL && limiteArray > 0) && (strlen(pArray) > 0))
    {
        retorno = 1;

        for (i=1; i<limiteArray && pArray[i] != '\0'; i++) ///Recorre el array hasta el ultimo caracter ingresado, no incluye el \0
        {
            switch(pArray[i])
            {
            case 39: ///Apostrofe
                break;
            case 45: ///Guion
                break;
            case 32: ///Espacio
                indiceEspacio=i;
                if(indiceEspacio!=0)
                {
                    pArray[indiceEspacio+1]=toupper(pArray[indiceEspacio+1]);
                }
                break;
            default:           ///a                  z
                if((pArray[i] < 97) || (pArray[i] > 122))///Verifica que no haya espacios ni caracteres fuera de rango
                {
                    ///A                   Z
                    if((pArray[i] < 65) || (pArray[i] > 90))
                    {
                        retorno = 0;
                    }
                }
                break;
            }
        }
    }
    return retorno;
}

/**
* \brief Evalua si es un Cuil o Cuit (XX-XXXXXXXX-X)
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 1, si no 0
*
*/
int array_StringCuitEsValido(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    int contador=0;
    if( pBuffer != NULL && limite > 0 && strlen(pBuffer) == 13 &&
            pBuffer[2] == '-' && pBuffer[11] == '-')
    {
        retorno = 1;
        for(i=0; i < limite && pBuffer[i] != '\0'; i++)
        {
            switch(pBuffer[i])
            {
            case 45: ///Guion
                contador++;
            default:
                if((pBuffer[i] < '0' || pBuffer[i] > '9') && i!=2 && i!=11 && contador == 2)
                {
                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}

/**
 * \brief Verifica si el string recibido tiene solo letras
 * \param array Es el array para validar su tipo
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int array_StringCharEsValidoDos(char* array,int size)
{
    int retorno = 0;
    int i;
    int digitosIngresados;

    digitosIngresados = strlen(array);

    if(array != NULL)
    {
        retorno = 1;
        for(i=0; i < digitosIngresados && array[i] != '\0'; i++)
        {
            if((tolower(array[i]) < 'a' || tolower(array[i]) > 'z') && array[i]!= ' ' && array[i]!= '-')
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
* \brief Evalua si se trata de un entero
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el numero maximo de cifras
* \return En caso de exito retorna 1, si no 0
*
*/
int isValidEntero(char *array, int size)
{
    int retorno = 0;
    int i;

    if(array != NULL && size > 0)
    {
        retorno = 1;
        for(i=0; i < size && array[i] != '\0'; i++)
        {
            if((array[i] < '0') && (array[i] > '9'))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
