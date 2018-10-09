#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "venta.h"
#include "informes.h"
/**
* \brief    Se utiliza esta funcion para obtener un nuevo id
*           declarando una variable static para el id y suma 1 al anterior
* \return devuelve un id nuevo
*/
static int getNextId()
{
    static int ultimoId=-1;
    ultimoId++;
    return ultimoId;
}
/**
* \brief    Se utiliza esta funcion para obtener el primer lugar libre de un array de tipo venta
*           recorriendo el array hasta encontrar un isEmpty en 1
* \param array Es el array que se recorre
* \param len Es el limite de ventas que puede guardar el array
* \return devuelve el indice de la posicion libre, sino el return es -1.
*/
static int getLugarLibreVenta(Venta* array, int len)
{
    int retorno = -1;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(array[i].isEmpty)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
/**
* \brief    Se utiliza esta funcion para inicializar un array de tipo venta,
*           recorriendo el array y poniendo cada isEmpty en 1
* \param array Es el array que se recorre
* \param len Es el limite de ventas que puede guardar el array
* \return El retorno es 0 si se realizo de manera correcta, si no el retorno es -1.
*/
int venta_init(Venta* array, int len)
{
    int retorno = -1;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            array[i].isEmpty = 1;
        }
        retorno = 0;
    }
    return retorno;
}
/**
* \brief    Se utiliza esta funcion para encontrar un venta a través de un id,
*           recorriendo el array y comparando los id (donde el isEmpty es 0)
* \param array Es el array que se recorre
* \param len Es el limite de ventas que puede guardar el array
* \param id Es el id con que se compara cada id del array
* \return   retorna la direccion de la struct del venta donde se encontro el id,
*           si no el retorno es NULL.
*/
Venta* venta_getByIdCliente(Venta* array, int len, int idCliente)
{
    Venta* retorno = NULL;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!array[i].isEmpty && array[i].idCliente == idCliente)
            {
                retorno = &array[i];
                break;
            }
        }
    }
    return retorno;
}
/**
* \brief    Se utiliza esta funcion para encontrar un venta a través de un id,
*           recorriendo el array y comparando los id (donde el isEmpty es 0)
* \param array Es el array que se recorre
* \param len Es el limite de ventas que puede guardar el array
* \param id Es el id con que se compara cada id del array
* \return   retorna la direccion de la struct del venta donde se encontro el id,
*           si no el retorno es NULL.
*/
Venta* venta_getById(Venta* array, int len, int id)
{
    Venta* retorno = NULL;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!array[i].isEmpty && array[i].idVenta == id)
            {
                retorno = &array[i];
                break;
            }
        }
    }
    return retorno;
}
/**
* \brief    Se utiliza esta funcion para dar de alta un venta generando un id
*           de manera automatica y el usuario introduce el resto de datos,
*           si se realiza todo correctamente se guardan los datos y se coloca el isEmpty en 0
* \param array Es el array que se recorre
* \param len Es el limite de ventas que puede guardar el array
* \return El retorno es 0 si se realizo de manera correcta, si no el retorno es -1.
*/
int venta_alta(Venta* arrayVentas, int lenVentas, void* arrayClientesVoid, int lenClientes)
{
    int retorno = -1;
    Cliente* arrayClientes = arrayClientesVoid;
    int indice;
    int idCliente;
    int cantidadAfiches;
    char archivoImagen[51];
    int zona;
    cliente_mostrar(arrayClientes, lenClientes);
    indice = getLugarLibreVenta(arrayVentas,lenVentas);
    if( arrayVentas != NULL && lenVentas > 0 &&
        arrayClientes != NULL && lenClientes > 0 && indice >= 0 &&
        indice < lenVentas && arrayVentas[indice].isEmpty &&
        !utn_getEnteroSoloNumeros(&idCliente, 10, "ID cliente?\n", "ID no valido\n", 2) &&
        cliente_getById(arrayClientes, lenClientes, idCliente) != NULL &&
        !utn_getEnteroSoloNumeros(&cantidadAfiches, 10,"cantidad afiches?\n", "cantidad no valida\n",2) &&
        cantidadAfiches != 0 &&
        !utn_getArchivo(archivoImagen, 51, "Nombre Archivo?\n", "archivo No Valido\n", 2) &&
        !utn_getEnteroSoloNumeros(&zona, 10, "Ingrese zona\n1-CABA\n2-Zona Sur\n3-Zona Oeste\n", "zona no valida\n", 2) &&
        zona > 0 && zona <=3)
    {
        arrayVentas[indice].idCliente = idCliente;
        arrayVentas[indice].cantidadAfiches = cantidadAfiches;
        strncpy(arrayVentas[indice].archivoImagen, archivoImagen, 51);
        arrayVentas[indice].zona = zona;
        arrayVentas[indice].estado = 1;
        arrayVentas[indice].isEmpty = 0;
        arrayVentas[indice].idVenta = getNextId();
        printf("Alta venta ID %d realizada\n", arrayVentas[indice].idVenta);
        retorno = 0;
    }
    return retorno;
}
/**
* \brief    Se utiliza esta funcion para modificar todos los datos de un venta
*           el usuario elige a traves de un id e introduce todos los datos por teclado
* \param array Es el array que se recorre
* \param len Es el limite de ventas que puede guardar el array
* \param reintentos Veces que el usuario podra volver a introducir el id
* \return El retorno es 0 si se realizo de manera correcta, si no el retorno es -1.
*/
int venta_modificar(Venta* array, int len, int reintentos)
{
    int retorno = -1;
    Venta *ventaModificado = NULL;
    int id;
    int i;
    int cantidadAfiches;
    int zona;
    if(array != NULL && len > 0 && reintentos >= 0)
    {
        venta_mostrar(array, len);
        for(i=0; i <= reintentos; i++)
        {
            if( !utn_getEntero(&id, len, "Introduzca el Id que desea modificar\n", "", 0) &&
                venta_getById(array, len, id) != NULL)
            {
                ventaModificado = venta_getById(array, len, id);
                break;
            }
            else
            {
                printf("Id Erroneo\n");
            }
        }
    }
    if( ventaModificado != NULL &&
        !utn_getEnteroSoloNumeros(&cantidadAfiches, 10,"cantidad afiches?\n", "cantidad no valida\n",2) &&
        cantidadAfiches != 0 &&
        !utn_getEnteroSoloNumeros(&zona, 10, "Ingrese zona\n1-CABA\n2-Zona Sur\n3-Zona Oeste\n", "zona no valida\n", 2) &&
        zona > 0 && zona <=3)
    {
        ventaModificado->cantidadAfiches = cantidadAfiches;
        ventaModificado->zona = zona;
        retorno = 0;
    }
    return retorno;
}
/**
* \brief    Se utiliza esta funcion para dar de baja (baja logica) una venta,
* \param array Es el array que se recorre
* \param len Es el limite de ventas que puede guardar el array
* \param reintentos Veces que el usuario podra volver a introducir el id
* \return El retorno es 0 si se realizo de manera correcta, si no el retorno es -1.
*/
int venta_cobrar(Venta* array, int len, void *arrayClientesVoid,int lenClientes,int reintentos)
{
    int retorno = -1;
    Venta *ventaCobrar;
    Cliente *arrayClientes = arrayClientesVoid;
    Cliente *clienteMostrar = NULL;
    char confirmarBaja[10];
    int id;
    int i;
    if(array != NULL && len > 0 && reintentos >= 0)
    {
        venta_mostrar(array, len);
        for(i=0; i<= reintentos; i++)
        {
            if( !utn_getEntero(&id, len, "Introduzca el Id que cobrar\n", "", 0) &&
                venta_getById(array, len, id) != NULL)
            {
                ventaCobrar = venta_getById(array, len, id);
                if(ventaCobrar->estado == A_COBRAR)
                {
                    printf("Se cobrara la venta de este cliente\n");
                    clienteMostrar = cliente_getById(arrayClientes, lenClientes, ventaCobrar->idCliente);
                    if(clienteMostrar != NULL)
                    {
                        cliente_mostrar(clienteMostrar, 1);
                    }
                    if( !utn_getTexto(confirmarBaja, 10, "Pulse 1 para confirmar\n", "Error\n", 2) &&
                        strcmp(confirmarBaja, "1") == 0)
                    {
                        ventaCobrar->estado = COBRADA;
                        retorno = 0;
                    }
                    break;
                }
                else
                {
                    printf("La venta ya esta cobrada\n");
                }
            }
            else
            {
                printf("Id Erroneo\n");
            }
        }
    }
    return retorno;
}
/**
* \brief    Se utiliza esta funcion para cargar los datos de una venta
* \param array Es el array que se recorre
* \param len Es el limite de ventas que puede guardar el array
* \return El retorno es 0 si se mostraron los datos, si no el retorno es -1.
*/
int venta_ingresoForzado(Venta* array, int len, int idCliente, int afiches, char *archivo, int zona, int estado)
{
    int retorno = -1;
    int indice;
    indice = getLugarLibreVenta(array,len);
    if( array != NULL && len > 0)
    {
        array[indice].idCliente = idCliente;
        array[indice].cantidadAfiches = afiches;
        strncpy(array[indice].archivoImagen, archivo, 51);
        array[indice].zona = zona;
        array[indice].estado = estado;
        array[indice].idVenta = getNextId();
        array[indice].isEmpty = 0;
        retorno = 0;
    }
    return retorno;
}
/**
* \brief    Se utiliza esta funcion para mostrar todos los datos de las ventas
* \param array Es el array que se recorre
* \param len Es el limite de ventas que puede guardar el array
* \return El retorno es 0 si se mostraron los datos, si no el retorno es -1.
*/
int venta_mostrar(Venta* array, int len)
{
    int retorno = -1;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!array[i].isEmpty)
            {
                printf("\nIdcliente: %d\nAfiches: %d\nImagen: %s\nIDVenta: %d\n",
                array[i].idCliente, array[i].cantidadAfiches, array[i].archivoImagen, array[i].idVenta);
                if(array[i].zona == CABA)
                {
                    printf("Zona: CABA\n");
                }
                else if(array[i].zona == ZONA_SUR)
                {
                    printf("Zona: Zona Sur\n");
                }
                else if(array[i].zona == ZONA_OESTE)
                {
                    printf("Zona: Zona Oeste\n");
                }
                if(array[i].estado == A_COBRAR)
                {
                    printf("Estado: A cobrar\n\n");
                }
                else if(array[i].estado == COBRADA)
                {
                    printf("Estado: Cobrado\n\n");
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}
