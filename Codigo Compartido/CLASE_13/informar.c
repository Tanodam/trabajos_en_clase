#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Contratacion.h"
#include "utn.h"
#include "pantalla.h"
#include "informar.h"

int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit)
{
    int retorno = -1;

    return retorno;
}



int informar_ListarContrataciones(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;

    return retorno;
}


int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;

    return retorno;
}

/**
* \brief Funcion que ordena el array comparando apellidos, si el apellido es igual, ordena el sector.
* \param array Es el array que se recorre
* \param limite Es el limite de empleados
* \param orden Es el numero que indica el sentido del ordenamiento [0] (Ascendente) [1] (Descendente)
* \return El retorno es 0 si se realizo el ordenamiento, si no el retorno es -1.
*/
int informar_ordenarPrecioYNombre(Pantalla* array, int limite, int orden)
{
    int retorno=-1;
    int i;
    int j;
    Pantalla auxiliar;

    if(array != NULL && limite > 0 && (orden == 0 || orden == 1))
    {
        for(i=1; i < limite; i++)
        {
            auxiliar = array[i];
            j = i - 1;
            if(orden == 0)
            {
                while ((j >= 0) && informar_comparacionPrecioYNombre(&array[j], &auxiliar))
                {
                    array[j + 1] = array[j];
                    j--;
                }
                array[j + 1] = auxiliar;
            }
            if(orden == 1)
            {
                while ((j >= 0) && informar_comparacionPrecioYNombre(&auxiliar, &array[j]))
                {
                    array[j + 1] = array[j];
                    j--;
                }
                array[j + 1] = auxiliar;
            }
        }
        retorno = 0;
    }
    return retorno;
}
/**
* \brief Funcion que compara empleados por apellido y por sector [Funcion interna de ordenarApellidoYSector]
* \param arrayUno es el primer empleado que se va a comparar
* \param arrayDos es el segundo empleado que se va a comparar
* \return si el primero es mayor devuelve 0(para que se realice el swap), si no -1
*/
int informar_comparacionPrecioYNombre(Pantalla* pantalla1, Pantalla* pantalla2)
{
    int retorno=-1;
    if(pantalla1 != NULL && pantalla2 != NULL)
    {

        if((pantalla1->precio < pantalla2->precio) ||
            (pantalla1->precio == pantalla2->precio) && (strcmp(pantalla1->nombre, pantalla2->nombre)>0))
        {
            retorno = 0;
        }
    }
    return retorno;
}

int informar_valorPantalla(Pantalla* array, int limite)
{
    int i;
    int retorno=-1;
    int contadorMenorIgual10=0;
    int contadorMayor10=0;

    if(array != NULL && limite > 0 )
    {
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].precio <= 10)
            {
                contadorMenorIgual10++;
                retorno = 0;
            }
            if(!array[i].isEmpty && array[i].precio > 10)
            {
                contadorMayor10++;
                retorno = 0;

            }

        }
    }
    printf("La cantidad de pantallas que valen menos o igual a 10 son :%d\n",contadorMenorIgual10);
    printf("La cantidad de pantallas que valen mas de 10 son :%d\n",contadorMayor10);
    return retorno;
}

int informar_promediosValores(Pantalla* array, int limite)
{
    int i;
    int retorno=-1;
    float total=0;
    int contadorPantallas=0;
    int contadorEncimaDelPromedio=0;
    int contadorDebajoDelPromedio=0;
    float promedio=0;

        if(array != NULL && limite > 0 )
        {
            retorno = 1;
            for(i=0;i<limite;i++)
            {
                if(array[i].precio > 0 && !array[i].isEmpty)
                {
                    contadorPantallas++;
                    total= total+array[i].precio;
                }
            }
        promedio=total/contadorPantallas;
        printf("total: %.2f\n", total);
        printf("El promedio de los valores de las pantallas es: %.2f\n",promedio);
        for(i=0;i<limite;i++)
            {
                if(array[i].precio > promedio && !array[i].isEmpty)
                {
                    contadorEncimaDelPromedio++;

                }
                if(array[i].precio < promedio && !array[i].isEmpty)
                {
                    contadorDebajoDelPromedio++;
                }
            }
            printf("Cantidad de pantallas por encima del promedio %d\n", contadorEncimaDelPromedio);
            printf("Cantidad de pantallas por debajo del promedio %d\n", contadorDebajoDelPromedio);
        }
        return retorno;
}

int informar_contratacionesDiasIgualMenorDiez(Pantalla* arrayPan, Contratacion* arrayCon, int limitePan, int limiteCon)
{
    int i;
    int retorno=-1;
    int idAuxiliar;
    Pantalla* auxiliarPan;
    float precioTotal;


    if(arrayPan != NULL && arrayCon != NULL && limitePan > 0 && limiteCon > 0 )
        {
            for(i=0;i<limiteCon;i++)
            {
                if(arrayCon[i].dias <= 10 && !arrayCon[i].isEmpty)
                {
                    retorno=0;
                    idAuxiliar = arrayCon[i].idPantalla;
                    auxiliarPan = pantalla_busquedaPorID(arrayPan, limitePan, idAuxiliar);
                    precioTotal=auxiliarPan->precio*arrayCon[i].dias;
                    printf("\n%s - %.2f - %d - %2.f",auxiliarPan->nombre,auxiliarPan->precio,arrayCon[i].dias,precioTotal);
                }
            }
        }
        return retorno;
}
int informar_contrataciones
