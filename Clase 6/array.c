#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "string.h"
#include "ctype.h"
#include "utn.h"
#define BUFFER_STR 4097

static int getString (char* pArray, int limiteaArray)
{
    int retorno = -1;
    char buffer[BUFFER_STR];
    char len;
    if(pArray!=NULL && limiteaArray > 0)
    {
        myFlush();
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
*\brief Solicita string al usuario y lo devuelve validado mediante la funcion StringCharEsValido.
*\param pArray Puntero a la direccion de memoria donde se va almacenar el string validado
*\param mensaje[] es el mensaje que se le va a mostrar al usuario
*\param mensajeError[] es el mensaje que se le va a mostrar al usuario si hay un error en la carga de datos
*\return Exito=0 y Error=1
*
*/
char array_getNombre(char* pArray, int limiteArray, char* mensaje, char* mensajeError, int reintentos)
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
            {
                myFlush();

                for(i=0;i<limiteArray;i++)
                {
                    buffer[i]=tolower(buffer[i]); //Convierto todos los caracteres del array a minusculas para validarlos
                }
                if(array_StringCharEsValido(buffer, limiteArray)==1) ///Valido los caracteres, si se cumple 1 y si no
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
            }
        }while(contadorIntentos <= reintentos);
    }

    return retorno;
}
/**
*\brief Solicita string al usuario y lo devuelve validado mediante la funcion StringCharEsValido.
*\param pArray Puntero a la direccion de memoria donde se va almacenar el string validado
*\param mensaje[] es el mensaje que se le va a mostrar al usuario
*\param mensajeError[] es el mensaje que se le va a mostrar al usuario si hay un error en la carga de datos
*\return Exito=0 y Error=1
*
*/
char array_getStringInt(char* pArray, int limiteArray, char mensaje[], char mensajeError[])
{
    int flagEsValido=-1;
    int contadorIntentos=0;
    char string[limiteArray];


    myFlush();
    while(flagEsValido!=0)
    {
        printf("%s", mensaje);
        fgets(string, limiteArray, stdin);
        myFlush();

        if(array_StringIntEsValido(string,limiteArray)==0) ///Valido los caracteres, si se cumple 0 y si no -1
        {
            flagEsValido=0;
        }
        else
        {
            contadorIntentos++;
            printf("%s", mensajeError);
            myFlush();
            flagEsValido=-1;
            if(contadorIntentos==3)
            {
                printf("\nSe han superado los intenos maximos permitidos");
                return -1;
            }
        }
    }

    if(flagEsValido==0)
    {
        strcpy(pArray,string); ///Copio en el puntero a pArray el valor de string
        return 0;
    }
    return -2;
}
char array_getStringFloat(char* pArray, int limiteArray, char mensaje[], char mensajeError[])
{
    int flagEsValido=-1;
    int contadorIntentos=0;
    char string[limiteArray];


    myFlush();
    while(flagEsValido!=0)
    {
        printf("%s", mensaje);
        fgets(string, limiteArray, stdin);
        myFlush();

        if(array_StringFloatEsValido(string,limiteArray)==0) ///Valido los caracteres, si se cumple 0 y si no -1
        {
            flagEsValido=0;
        }
        else
        {
            contadorIntentos++;
            printf("%s", mensajeError);
            myFlush();
            flagEsValido=-1;
            if(contadorIntentos==3)
            {
                printf("\nSe han superado los intenos maximos permitidos");
                return -1;
            }
        }
    }

    if(flagEsValido==0)
    {
        strcpy(pArray,string); ///Copio en el puntero a pArray el valor de string
        return 0;
    }
    return -2;
}


int array_mostrar(int* pArray, int limiteArray)
{
    int i;
    for(i=0;i<limiteArray;i++)
    {
        printf("\nIndex:%d - Value:%d - Add: %p",i,pArray[i],&pArray[i]);
    }
    return 0;
}

int array_calcularMaximo(int* pArray, int limiteArray, int* pMaximo)
{

    int retorno=-1;
    int i;
    int maximo;
    int flagPrimerMaximo = false;

    if(pArray != NULL && limiteArray > 0)
    {

        for(i=0;i<limiteArray;i++)
        {
            if(pArray[i] != DATO_INVALIDO)
            {
                if(flagPrimerMaximo == false)
                {
                    maximo = pArray[i];
                    flagPrimerMaximo = true;
                }
                else if(pArray[i] > maximo)
                {
                    maximo = pArray[i];
                }
            }
        }

        if(flagPrimerMaximo == 0)
        {
            retorno = -2;
        }
        else
        {
            retorno = 0;
        }
    }
    return retorno;
}
int array_init(int* pArray, int limiteArray, int valor)
{
    int retorno=-1;
    int i;

    if(pArray != NULL && limiteArray > 0)
    {
        for(i=0;i<limiteArray;i++)
        {
            pArray[i] = valor;
        }
        retorno = 0;
    }
    return retorno;
}
int array_minimoDesde(int* pArray, int limiteArray, int desde, int* pMinimo)
{
    int retorno=-1;
    int i;
    int auxiliarValorMinimo;
    int auxiliarIndiceMinimo;

    if(pArray != NULL && limiteArray > 0 && limiteArray >= desde && pMinimo != NULL)
    {
        for(i=desde;i<limiteArray;i++)
        {
           if(i==desde || pArray[i]< auxiliarValorMinimo)
           {
                auxiliarValorMinimo=pArray[i];
                auxiliarIndiceMinimo=i;
           }
           else if(pArray[i]< auxiliarValorMinimo)
           {
                auxiliarValorMinimo=pArray[i];
                auxiliarIndiceMinimo=i;
           }

        }
        *pMinimo=auxiliarIndiceMinimo;
        retorno = 0;
    }
    return retorno;
}
void array_swap(int* elementoA, int*elementoB)
{
    int auxiliar;
    auxiliar= *elementoA;
    *elementoA= *elementoB;
    *elementoB=auxiliar;

}
void array_ordenarArray(int* pArray, int limiteArray, int orden)
{
    int i;
    //int auxiliar;
    int continuar = 1;

    while(continuar)
    {
        continuar = 0;
        for (i = 1; i < limiteArray; i++)
        {
            if (pArray[i] < pArray[i - 1] && orden==0)
            {
                array_swap(&pArray[i], &pArray[i-1]);
//                auxiliar = pArray[i];
//                pArray[i] = pArray[i - 1];
//                pArray[i - 1] = auxiliar;
                continuar = 1;
            }
            else if (pArray[i] > pArray[i - 1] && orden==1)
            {
                array_swap(&pArray[i], &pArray[i-1]);
//                auxiliar = pArray[i];
//                pArray[i] = pArray[i - 1];
//                pArray[i - 1] = auxiliar;
                continuar = 1;
            }
        }
    }
}
void array_imprimirIntArray(int* pArray, int limiteArray)
{
	int i;
	for(i = 0; i < limiteArray; i++)
	{
	    printf("\n%d",pArray[i]);
	}
}
void array_ordenarArrayInsercion(int* pArray, int limiteArray)
{
	int i;
	int j;
	int auxiliar;

	for(i = 1; i < limiteArray; i++)
	{
		auxiliar = pArray[i];
		j = i;
		while(j > 0 && auxiliar > pArray[j - 1]) //Cambiar simbolo entre auxilar - pArray para cambiar orden
		{
			pArray[j] = pArray[j - 1];
			j--;
		}
		pArray[j] = auxiliar;
	}
}
/**
*\brief [Funcion interna de GetStringChar] Valida que el usuario solo haya ingresado caracteres de la A a la Z
*\param pArray Puntero a la direccion de memoria donde esta almacenada el string a validar
*\param limiteArray tamaño del array
*\return Exito=1 y Error=-0
*/
int array_StringCharEsValido (char* pArray, int limiteArray)
{
    int retorno=0;
    int i;

    if(pArray!= NULL && limiteArray > 0)
    {
        retorno = 1;
        for (i=0; i<strlen(pArray)-1; i++) ///Recorre el array hasta el ultimo caracter ingresado, no incluye el \0
            {
                if(pArray[i] < 'a' || pArray[i] > 'z') ///Verifica que no haya espacios ni caracteres fuera de rango
                {
                    retorno = 0;
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
int array_StringIntEsValido (char* pArray, int limiteArray)
{
    int validado;
    int i;

    for (i=0; i<strlen(pArray)-1; i++) ///Recorre el array hasta el ultimo caracter ingresado, no incluye el \0
        {
            if((pArray[i] == '.' || pArray[i] == ' ') && (pArray[i] < '0' || pArray[i] > '9'))
            {
                validado = -1;
                break;
            }
        }
        if (validado!=-1)
        {
            return 0;
        }
        else
        {
            return -1;
        }
}
/**
*\brief [Funcion interna de GetStringFloat] Valida que el usuario solo haya ingresado caracteres del 0 al 9
*\param pArray Puntero a la direccion de memoria donde esta almacenada el string a validar
*\param limiteArray tamaño del array
*\return Exito=0 y Error=-1
*/
int array_StringFloatEsValido (char* pArray, int limiteArray)
{
    int validado;
    int i;

    for (i=0; i<strlen(pArray)-1; i++) ///Recorre el array hasta el ultimo caracter ingresado, no incluye el \0
        {

            if((pArray[0] != '-')  && (pArray[0] == '.' || pArray[i] != '.') && (pArray[i] < '0' || pArray[i] > '9'))
            {
                validado = -1;
                break;
            }
        }

        if (validado!=-1)
        {
            return 0;
        }
        else
        {
            return -1;
        }
}

