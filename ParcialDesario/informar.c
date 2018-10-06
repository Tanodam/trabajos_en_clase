#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Clientes.h"
#include "ventaAfiches.h"
#include "array.h"


int informar_listaClientesConVentasACobrar(Cliente* arrayClientes, Ventas* arrayVentas, int limiteClientes, int limiteVentas)
{
    int retorno=-1;
    int i, j;
    int contadorVentasACobrar=0;

    if(arrayClientes != NULL && arrayVentas != NULL)
    {
        for (i=0; i<limiteClientes; i++)
        {
            if(arrayClientes[i].isEmpty==0)
            {
                contadorVentasACobrar=0;
                for(j=0; j<limiteVentas; j++)
                {
                    if(arrayVentas[j].idCliente == arrayClientes[i].id && // Para cambiar criterio de busqueda en alguna venta modificar el strcmp
                            strcmp(arrayVentas[j].estadoVenta, "A COBRAR")==0)
                    {
                        retorno = 0;
                        contadorVentasACobrar++;

                    }
                }

                printf("\nID: %d",arrayClientes[i].id);
                printf("\nNombre: %s, %s",arrayClientes[i].nombre, arrayClientes[i].apellido);
                printf("\nCuit: %s",arrayClientes[i].cuit);
                printf("\nCantidad de ventas a cobrar: %d\n",contadorVentasACobrar);
            }

        }


    }
    pausarPantalla();
    return retorno;
}
int informar_clienteConMasAfiches(Cliente* arrayClientes, Ventas* arrayVentas, int limiteClientes, int limiteVentas)
{
    int retorno=-1;
    int i, j;
    int contadorVentas=0;
    int ventasMaximo, clienteMaximoConMasVentas, ventasMinimo, ClienteMinimoConMenosVentas;

    if(arrayClientes != NULL && arrayVentas != NULL)
    {
        for (i=0; i<limiteClientes; i++)
        {
            if(arrayClientes[i].isEmpty==0)
            {
                contadorVentas=0;
                for(j=0; j<limiteVentas; j++)
                {
                    if(arrayVentas[j].idCliente == arrayClientes[i].id && // Para cambiar criterio de busqueda en alguna venta modificar el strcmp
                            arrayVentas[j].isEmpty== 0)
                    {
                        retorno = 0;
                        contadorVentas++;

                    }
                }
                if(contadorVentas>ventasMaximo || i==0)
                {
                    ventasMaximo=contadorVentas;
                    clienteMaximoConMasVentas=i;
                }
                if(contadorVentas<ventasMinimo || i==0)
                {
                    ventasMinimo=contadorVentas;
                    ClienteMinimoConMenosVentas=i;
                }

            }

        }//Maximo
        printf("\nEl clinete con mas ventas es:");
        printf("\nID: %d",arrayClientes[clienteMaximoConMasVentas].id);
        printf("\nNombre: %s, %s",arrayClientes[clienteMaximoConMasVentas].nombre,
        arrayClientes[clienteMaximoConMasVentas].apellido);
        printf("\nCuit: %s",arrayClientes[clienteMaximoConMasVentas].cuit);
        printf("\nCantidad de ventas: %d\n",ventasMaximo);
       //Minimo
        printf("\nEl clinete con menos ventas es:");
        printf("\nID: %d",arrayClientes[ClienteMinimoConMenosVentas].id);
        printf("\nNombre: %s, %s",arrayClientes[ClienteMinimoConMenosVentas].nombre,
        arrayClientes[ClienteMinimoConMenosVentas].apellido);
        printf("\nCuit: %s",arrayClientes[ClienteMinimoConMenosVentas].cuit);
        printf("\nCantidad de ventas: %d\n",ventasMinimo);


    }
    pausarPantalla();
    return retorno;
}

/**
* \brief Funcion que ordena el array comparando apellidos, si el apellido es igual, ordena el sector.
* \param array Es el array que se recorre
* \param limite Es el limite de empleados
* \param orden Es el numero que indica el sentido del ordenamiento [0] (Ascendente) [1] (Descendente)
* \return El retorno es 0 si se realizo el ordenamiento, si no el retorno es -1.
*/
int informar_ordenarApellido(Cliente* array, int limite, int orden)
{
    int retorno=-1;
    int i;
    int j;
    Cliente auxiliar;

    if(array != NULL && limite > 0 && (orden == 0 || orden == 1))
    {
        for(i=1; i < limite; i++)
        {
            auxiliar = array[i];
            j = i - 1;
            if(orden == 0)
            {
                while ((j >= 0) && !informar_comparacionApellido(&array[j], &auxiliar))
                {
                    array[j + 1] = array[j];
                    j--;
                }
                array[j + 1] = auxiliar;
            }
            if(orden == 1)
            {
                while ((j >= 0) && !informar_comparacionApellido(&auxiliar, &array[j]))
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
int informar_comparacionApellido(Cliente* cliente1, Cliente* cliente2)
{
    int retorno=-1;
    if(cliente1 != NULL && cliente2 != NULL)
    {
        if( strcmp(cliente1->apellido, cliente2->apellido) > 0 ||
            (strcmp(cliente1->apellido, cliente2->apellido) == 0))
        {
            retorno = 0;
        }
    }
    return retorno;
}

