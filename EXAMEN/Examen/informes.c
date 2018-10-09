#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "informes.h"
#include "cliente.h"
#include "venta.h"

static int comparacionNombreApellido(Cliente* arrayUno, Cliente* arrayDos)
{
    int retorno=-1;
    if(arrayUno != NULL && arrayDos != NULL && !arrayUno->isEmpty && !arrayDos->isEmpty)
    {
        if(strcmp(arrayUno->apellido, arrayDos->apellido)> 0 ||
        (strcmp(arrayUno->apellido, arrayDos->apellido)== 0 && strcmp(arrayUno->nombre, arrayDos->nombre) > 0))
        {
            retorno = 0;
        }
    }
    return retorno;
}

int informar_sortClientePorNombreApellido(void* arrayClientesVoid, int len)
{
    Cliente auxiliar;
    Cliente* array = arrayClientesVoid;
    int retorno=-1;
    int i;
    int j;
    if(array != NULL && len > 0 )
    {
        for(i=1; i < len; i++)
        {
            auxiliar = array[i];
            j = i - 1;
            if(!auxiliar.isEmpty)
            {
                while ((j >= 0) && !comparacionNombreApellido(&array[j], &auxiliar))
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
int informar_ventasMayorMenorAfichesNumero(void *arrayVentasVoid, int lenVentas, int *cantidadVentas,int mayorMenor, int numeroAfiches)
{
    Venta* arrayVentas = arrayVentasVoid;
    int retorno=-1;
    int i;
    if(arrayVentas != NULL && lenVentas > 0)
    {
        for(i=0; i < lenVentas; i++)
        {
            if(mayorMenor == 0 && !arrayVentas[i].isEmpty && arrayVentas[i].cantidadAfiches > numeroAfiches)
            {
                venta_mostrar(&(arrayVentas[i]), 1);
                *cantidadVentas+=1;
            }
            else if(mayorMenor == 1 && !arrayVentas[i].isEmpty && arrayVentas[i].cantidadAfiches < numeroAfiches)
            {
                venta_mostrar(&(arrayVentas[i]), 1);
                *cantidadVentas+=1;
            }
        }
        retorno = 0;
    }
    return retorno;
}
int informar_cantidadTotalDeAfiches(void* arrayVentasVoid, int lenVentas, int *cantidadTotalAfiches)
{
    Venta* arrayVentas = arrayVentasVoid;
    int retorno=-1;
    int i;
    if(arrayVentas != NULL && lenVentas > 0)
    {
        *cantidadTotalAfiches = 0;
        for(i=0; i < lenVentas; i++)
        {
            if(!arrayVentas[i].isEmpty)
            {
                *cantidadTotalAfiches+=arrayVentas[i].cantidadAfiches;
            }
        }
        retorno = 0;
    }
    return retorno;
}
int informar_cantidadTotalDeVentas(void* arrayVentasVoid, int lenVentas, int *cantidadTotalVentas)
{
    Venta* arrayVentas = arrayVentasVoid;
    int retorno=-1;
    int i;
    if(arrayVentas != NULL && lenVentas > 0)
    {
        *cantidadTotalVentas = 0;
        for(i=0; i < lenVentas; i++)
        {
            if(!arrayVentas[i].isEmpty)
            {
                *cantidadTotalVentas+=1;
            }
        }
        retorno = 0;
    }
    return retorno;
}
int informar_promedioAfichesPorVenta(void* arrayVentasVoid, int lenVentas, float *promedio)
{
    Venta* arrayVentas = arrayVentasVoid;
    int retorno=-1;
    int cantidadTotalAfiches;
    int cantidadTotalVentas;
    if( arrayVentas != NULL && lenVentas > 0 &&
        !informar_cantidadTotalDeAfiches(arrayVentas, lenVentas, &cantidadTotalAfiches) &&
        !informar_cantidadTotalDeVentas(arrayVentas, lenVentas, &cantidadTotalVentas))
    {
        *promedio = (float)cantidadTotalAfiches/cantidadTotalVentas;
        retorno = 0;
    }
    return retorno;
}

int informar_VentasSuperaOrNoPromedioAfiches(void* arrayVentasVoid,int lenVentas,int *cantidadVentas,int SuperaOrNo)
{
    Venta* arrayVentas = arrayVentasVoid;
    int retorno=-1;
    float promedio;
    if( arrayVentas != NULL && lenVentas > 0 &&
        !informar_promedioAfichesPorVenta(arrayVentas, lenVentas, &promedio) &&
        !informar_ventasMayorMenorAfichesNumero(arrayVentas, lenVentas, cantidadVentas, SuperaOrNo, promedio))
    {
        retorno = 0;
    }
    return retorno;
}
int informar_mostrarVentaPorEstado(void* arrayVentasVoid, int len, int estado)
{
    Venta* arrayVentas = arrayVentasVoid;
    int retorno = -1;
    int i;
    if(arrayVentas != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!arrayVentas[i].isEmpty && arrayVentas[i].estado == estado)
            {
                printf("\nIdcliente: %d\nAfiches: %d\nImagen: %s\nIDVenta: %d\n",
                arrayVentas[i].idCliente, arrayVentas[i].cantidadAfiches, arrayVentas[i].archivoImagen, arrayVentas[i].idVenta);
                if(arrayVentas[i].zona == CABA)
                {
                    printf("Zona: CABA\n");
                }
                else if(arrayVentas[i].zona == ZONA_SUR)
                {
                    printf("Zona: Zona Sur\n");
                }
                else if(arrayVentas[i].zona == ZONA_OESTE)
                {
                    printf("Zona: Zona Oeste\n");
                }
                if(arrayVentas[i].estado == A_COBRAR)
                {
                    printf("Estado: A cobrar\n\n");
                }
                else if(arrayVentas[i].estado == COBRADA)
                {
                    printf("Estado: Cobrado\n\n");
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}
int informar_mostrarVentaPorZona(void* arrayVentasVoid, int len, int zona)
{
    Venta* arrayVentas = arrayVentasVoid;
    int retorno = -1;
    int i;
    if(arrayVentas != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!arrayVentas[i].isEmpty && arrayVentas[i].zona == zona)
            {
                printf("\nIdcliente: %d\nAfiches: %d\nImagen: %s\nIDVenta: %d\n",
                arrayVentas[i].idCliente, arrayVentas[i].cantidadAfiches, arrayVentas[i].archivoImagen, arrayVentas[i].idVenta);
                if(arrayVentas[i].zona == CABA)
                {
                    printf("Zona: CABA\n");
                }
                else if(arrayVentas[i].zona == ZONA_SUR)
                {
                    printf("Zona: Zona Sur\n");
                }
                else if(arrayVentas[i].zona == ZONA_OESTE)
                {
                    printf("Zona: Zona Oeste\n");
                }
                if(arrayVentas[i].estado == A_COBRAR)
                {
                    printf("Estado: A cobrar\n\n");
                }
                else if(arrayVentas[i].estado == COBRADA)
                {
                    printf("Estado: Cobrado\n\n");
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}
int informar_mostrarVentaPorEstadoAndZona(void* arrayVentasVoid, int len, int estado ,int zona)
{
    Venta* arrayVentas = arrayVentasVoid;
    int retorno = -1;
    int i;
    if(arrayVentas != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!arrayVentas[i].isEmpty && arrayVentas[i].zona == zona && arrayVentas[i].estado == estado)
            {
                printf("\nIdcliente: %d\nAfiches: %d\nImagen: %s\nIDVenta: %d\n",
                arrayVentas[i].idCliente, arrayVentas[i].cantidadAfiches, arrayVentas[i].archivoImagen, arrayVentas[i].idVenta);
                if(arrayVentas[i].zona == CABA)
                {
                    printf("Zona: CABA\n");
                }
                else if(arrayVentas[i].zona == ZONA_SUR)
                {
                    printf("Zona: Zona Sur\n");
                }
                else if(arrayVentas[i].zona == ZONA_OESTE)
                {
                    printf("Zona: Zona Oeste\n");
                }
                if(arrayVentas[i].estado == A_COBRAR)
                {
                    printf("Estado: A cobrar\n\n");
                }
                else if(arrayVentas[i].estado == COBRADA)
                {
                    printf("Estado: Cobrado\n\n");
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}
