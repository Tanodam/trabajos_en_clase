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

static int getFloat(float* numeroIngresado)
{
    myFlush();
    return scanf("%f", numeroIngresado);
}
//
//static int getString(int* textoIngresado)
//{
//    __fpurge(stdin);
//    return scanf("%d", textoIngresado);
//}

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
float utn_getNumeroFlotante(float* pResultado,
                            char mensaje[],
                            char mensajeError[],
                            float minimo,
                            float maximo,
                            int reintentos)
{
    float numero;
    int i;

    for(i=0;i<reintentos;i++)
    {
        printf("%s", mensaje);
        myFlush();
        while(getFloat(&numero)!=1)
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
*\brief Funcion que reccore un array y encuentra la suma total.
*\param miArray[], es el array que recorrer
*\param cant, es el tamñao del array a recorrer.
*\return Retorna la suma de todos los elementos del array
*/
int retornarTotal(int miArray[], int cant)
{
    int i;
    int suma=0;

    for(i=0;i<cant;i++)
    {
       suma=suma+miArray[i];
    }
    return suma;
}
/**
*\brief Funcion que reccore un array y calcula el promedio
*\param miArray[], es el array que recorrer
*\param cant, es el tamñao del array a recorrer.
*\return Retorna el promedio de todos los elementos del array
*/
int retornarPromedio(int miArray[], int cant)
{
    int suma=0;//En suma se va a guardar el valor que retorne la funcion retornarToral
    float promedio=0;

    suma=retornarTotal(miArray, cant);
    promedio=suma/cant;
    return promedio;
}
/**
*\brief Funcion que reccore un array y carga el indice
*\param miArray[], es el array que recorrer
*\param cant, es el tamñao del array a recorrer.
*/
void cargarListado(int miArray[], int cant)
{
    int i;
    int numeroIngresado;
    for(i=0;i<cant;i++)
    {
        printf("Ingrese la nota nota nº%d:\t", i+1);
        scanf("%d", &numeroIngresado);
        miArray[i]=numeroIngresado;
    }
}
/**
*\brief Funcion que reccore un array y muestra todos los valores que hay cargados en los indices.
*\param miArray[], es el array que recorrer
*\param cant, es el tamñao del array a recorrer.
*/
void mostrarListado(int miArray[], int cant)
{
    int i;
    for(i=0;i<cant;i++)
    {
        printf("\nLa nota ingresada es: %d", miArray[i]);
    }
}
/**
*\brief Funcion que reccore un array y muestra numero mayor,menor, promedio, cantidad de pares, cantidad de numeros entre 0y3,4y5,6y10.
*\param miArray[], es el array que recorrer
*\param cant, es el tamñao del array a recorrer.

*/
void mostrarInformacionDelArray(int miArray[], int cant)
{
    int mayor;
    int menor;
    int suma=0;
    float promedio=0;
    int pares;
    int aprobados;
    int desaprobados;
    int promocionDirecta;

    mayor=obtenerMayor(miArray, cant);
    suma=retornarTotal(miArray, cant);
    promedio=retornarPromedio(miArray, cant);
    menor=obtenerMenor(miArray, cant);
    pares=calcularPares(miArray, cant);
    aprobados=retornarCantidadEntreNotas(miArray,cant,4,5);
    desaprobados=retornarCantidadEntreNotas(miArray,cant,0,3);
    promocionDirecta=retornarCantidadEntreNotas(miArray,cant,6,10);

    printf("\nEl mayor es: %d\t", mayor);
    printf("\nEl menor es: %d\t", menor);
    printf("\nLa suma es: %d\t", suma);
    printf("\nEl promedio es: %.2f\t", promedio);
    printf("\nLa cantidad de pares es: %d\t", pares);
    printf("\nLa cantidad de aprobados es: %d\t", aprobados);
    printf("\nLa cantidad de desaprobados es: %d\t", desaprobados);
    printf("\nLa cantidad de aprobados SIN FINAL es: %d\t", promocionDirecta);

}
/**
*\brief Funcion que reccore un array y obtiene el numero mayor.
*\param miArray[], es el array que recorrer
*\param cant, es el tamñao del array a recorrer.
*\return Retorna el numero mayor encontrado
*/
int obtenerMayor (int miArray[], int cant)
{
    int i;
    int mayor;
    for(i=0;i<cant;i++)
    {
        if(i==0 || miArray[i]>mayor)
        {
            mayor=miArray[i];
        }
    }
    return mayor;

}
/**
*\brief Funcion que reccore un array y encuentra el numero menor.
*\param miArray[], es el array que recorrer
*\param cant, es el tamñao del array a recorrer.
*\return Retorna el numero menor encontrado.
*/
int obtenerMenor (int miArray[], int cant)
{
    int i;
    int menor;
    for(i=0;i<cant;i++)
    {
        if(i==0 || miArray[i]<menor)
        {
            menor=miArray[i];
        }
    }
    return menor;

}
/**
*\brief Funcion que reccore un array y encuentra la cantidad de numeros pares
*\param miArray[], es el array que recorrer
*\param cant, es el tamñao del array a recorrer.
*\return Retorna la cantidad de numeros pares
*/
int calcularPares (int miArray[], int cant)
{
    int i;
    int pares=0;

    for(i=0;i<cant;i++)
    {
        if(miArray[i]%2==0)
        {
           pares++;
        }
    }
    return pares;

}
/**
*\brief Funcion que reccore un array y ordena los numeros segun limites establecidos
*\param miArray[], es el array que recorrer
*\param cant, es el tamñao del array a recorrer.
*\return Retorna la cantidad de numeros ordenados segun limites establecdos
*/
int retornarCantidadEntreNotas(int miArray[], int cant, int limiteMinimo, int limiteMaximo)
{
    int i;
    int cantidadDeNumeros=0;

    for(i=0;i<cant;i++)
    {
        if(miArray[i] <= limiteMaximo && miArray[i]>= limiteMinimo)
        {
           cantidadDeNumeros++;
        }
    }
    return cantidadDeNumeros;
}


