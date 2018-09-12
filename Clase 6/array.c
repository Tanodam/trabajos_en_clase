#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "string.h"
#include "ctype.h"
#include "utn.h"
/**
*\brief Solicita string al usuario y lo devuelve validado mediante la funcion StringCharEsValido.
*\param pArray Puntero a la direccion de memoria donde se va almacenar el string validado
*\param mensaje[] es el mensaje que se le va a mostrar al usuario
*\param mensajeError[] es el mensaje que se le va a mostrar al usuario si hay un error en la carga de datos
*\return Exito=0 y Error=1
*
*/
char array_getString(char* pArray, int limiteArray, char mensaje[], char mensajeError[])
{
    int flagEsValido=-1;
    int i;
    int contadorIntentos=0;
    char string[limiteArray];

    myFlush();
    while(flagEsValido!=0)
    {
        printf("%s", mensaje);
        fgets(string, limiteArray, stdin);
        myFlush();

        for(i=0;i<limiteArray;i++)
        {
            string[i]=tolower(string[i]); //Convierto todos los caracteres del array a minusculas para validarlos
        }
        if(array_StringCharEsValido(string, limiteArray)==0) ///Valido los caracteres, si se cumple 0 y si no -1
        {
            string[0]=toupper(string[0]); ///Convierto a mayusculas el primer caracter.
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
/**
*\brief Solicita string al usuario y lo devuelve validado mediante la funcion StringCharEsValido.
*\param pArray Puntero a la direccion de memoria donde se va almacenar el string validado
*\param mensaje[] es el mensaje que se le va a mostrar al usuario
*\param mensajeError[] es el mensaje que se le va a mostrar al usuario si hay un error en la carga de datos
*\return Exito=0 y Error=1
*
*/
char array_getStringNumerico(char* pArray, int limiteArray, char mensaje[], char mensajeError[])
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
*\return Exito=0 y Error=-1
*/
int array_StringCharEsValido (char* pArray, int limiteArray)
{
    int validado;
    int i;

    for (i=0; i<strlen(pArray)-1; i++) ///Recorre el array hasta el ultimo caracter ingresado, no incluye el \0
        {
            if((pArray[i] != ' ') && (pArray[i] < 'a' || pArray[i] > 'z')) ///Verifica que no haya espacios ni caracteres fuera de rango
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
*\brief [Funcion interna de GetStringChar] Valida que el usuario solo haya ingresado caracteres de la A a la Z
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
            if((pArray[i] != ' ') && (pArray[i] < '0' || pArray[i] > '9'))
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

