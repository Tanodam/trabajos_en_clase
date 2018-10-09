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
* \brief    Se utiliza esta funcion para obtener el primer lugar libre de un array de tipo cliente
*           recorriendo el array hasta encontrar un isEmpty en 1
* \param array Es el array que se recorre
* \param len Es el limite de clientes que puede guardar el array
* \return devuelve el indice de la posicion libre, sino el return es -1.
*/
static int getLugarLibre(Cliente* array, int len)
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
* \brief    Se utiliza esta funcion para inicializar un array de tipo cliente,
*           recorriendo el array y poniendo cada isEmpty en 1
* \param array Es el array que se recorre
* \param len Es el limite de clientes que puede guardar el array
* \return El retorno es 0 si se realizo de manera correcta, si no el retorno es -1.
*/
int cliente_init(Cliente* array, int len)
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
* \brief    Se utiliza esta funcion para encontrar un cliente a través de un id,
*           recorriendo el array y comparando los id (donde el isEmpty es 0)
* \param array Es el array que se recorre
* \param len Es el limite de clientes que puede guardar el array
* \param id Es el id con que se compara cada id del array
* \return   retorna la direccion de la struct del cliente donde se encontro el id,
*           si no el retorno es NULL.
*/
Cliente* cliente_getById(Cliente* array, int len, int id)
{
    Cliente* retorno = NULL;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!array[i].isEmpty && array[i].idCliente == id)
            {
                retorno = &array[i];
                break;
            }
        }
    }
    return retorno;
}
/**
* \brief    Se utiliza esta funcion para dar de alta un cliente generando un id
*           de manera automatica y el usuario introduce el resto de datos,
*           si se realiza todo correctamente se guardan los datos y se coloca el isEmpty en 0
* \param array Es el array que se recorre
* \param len Es el limite de clientes que puede guardar el array
* \return El retorno es 0 si se realizo de manera correcta, si no el retorno es -1.
*/
int cliente_alta(Cliente* array, int len)
{
    int retorno = -1;
    int indice;
    char nombre[51];
    char apellido[51];
    char cuit [20];
    indice = getLugarLibre(array,len);
    if( array != NULL && len > 0 && indice >= 0 &&
        indice < len && array[indice].isEmpty &&
        !utn_getNombre( nombre, 51,"Nombre cliente?\n",
                        "nombre no valido\nDebe empezar por mayuscula y el resto minusculas\n",2) &&
        !utn_getNombre( apellido, 51,"Apellido cliente?\n",
                        "apellido no valido\nDebe empezar por mayuscula y el resto minusculas\n",2) &&
        !utn_getCuilOrCuit(cuit, 20, "Cuit cliente?\n","cuit no valido\n", 2))
    {
        strncpy(array[indice].nombre, nombre,51);
        strncpy(array[indice].apellido, apellido, 51);
        strncpy(array[indice].cuit, cuit, 20);
        array[indice].isEmpty = 0;
        array[indice].idCliente = getNextId();
        printf("Alta cliente ID %d realizada\n", array[indice].idCliente);
        retorno = 0;
    }
    return retorno;
}
/**
* \brief    Se utiliza esta funcion para modificar todos los datos de un cliente
*           el usuario elige a traves de un id e introduce todos los datos por teclado
* \param array Es el array que se recorre
* \param len Es el limite de clientes que puede guardar el array
* \param reintentos Veces que el usuario podra volver a introducir el id
* \return El retorno es 0 si se realizo de manera correcta, si no el retorno es -1.
*/
int cliente_modificar(Cliente* array, int len, int reintentos)
{
    int retorno = -1;
    Cliente *clienteModificado = NULL;
    int id;
    int i;
    char nombre[51];
    char apellido[51];
    char cuit[20];
    if(array != NULL && len > 0 && reintentos >= 0)
    {
        cliente_mostrar(array, len);
        for(i=0; i <= reintentos; i++)
        {
            if( !utn_getEntero(&id, len, "Introduzca el Id que desea modificar\n", "", 0) &&
                cliente_getById(array, len, id) != NULL)
            {
                clienteModificado = cliente_getById(array, len, id);
                break;
            }
            else
            {
                printf("Id Erroneo\n");
            }
        }
    }
    if( clienteModificado != NULL &&
        !utn_getNombre( nombre, 51,"Nombre cliente?\n",
        "nombre no valido\nDebe empezar por mayuscula y el resto minusculas\n",2) &&
        !utn_getNombre( apellido, 51,"Apellido cliente?\n",
        "apellido no valido\nDebe empezar por mayuscula y el resto minusculas\n",2) &&
        !utn_getCuilOrCuit(cuit, 20, "Cuit cliente?\n", "apellido no valido\n", 2))
    {
        strncpy(clienteModificado->nombre, nombre, 51);
        strncpy(clienteModificado->apellido, apellido, 51);
        strncpy(clienteModificado->cuit, cuit, 20);
        retorno = 0;
    }
    return retorno;
}
/**
* \brief    Se utiliza esta funcion para dar de baja (baja logica) un cliente
* \param array Es el array que se recorre
* \param len Es el limite de clientes que puede guardar el array
* \param reintentos Veces que el usuario podra volver a introducir el id
* \return El retorno es 0 si se realizo de manera correcta, si no el retorno es -1.
*/
int cliente_baja(Cliente* array, int len, void* arrayVentasVoid, int lenVentas, int reintentos)
{
    int retorno = -1;
    Cliente *clienteModificado;
    char confirmarBaja[10];
    int id;
    int i;
    Venta* arrayVentas = arrayVentasVoid;
    Venta* auxiliarBorrado;
    if(array != NULL && len > 0 && reintentos >= 0)
    {
        cliente_mostrar(array, len);
        for(i=0; i<= reintentos; i++)
        {
            if( !utn_getEntero(&id, len, "Introduzca el Id que desea dar de baja\n", "", 0) &&
                cliente_getById(array, len, id) != NULL)
            {
                clienteModificado = cliente_getById(array, len, id);
                printf("Se eliminara el siguiente cliente\n");
                cliente_mostrar(clienteModificado, 1);
                if( !utn_getTexto(confirmarBaja, 10, "Pulse 1 para confirmar\n", "Error\n", 2) &&
                    strcmp(confirmarBaja, "1") == 0)
                {
                    for(i=0; i<lenVentas; i++)
                    {
                        auxiliarBorrado = venta_getByIdCliente(arrayVentas, lenVentas, id);
                        if(auxiliarBorrado != NULL)
                        {
                            auxiliarBorrado->isEmpty = 1;
                        }
                    }
                    clienteModificado->isEmpty = 1;
                    retorno = 0;
                }
                break;
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
* \brief    Se utiliza esta funcion para cargar los datos de un
*           cliente del array (nombre, apellidos,cuit)
*           el id se genera de manera automatica y se pone el isEmpty en 0
* \param array Es el array que se recorre
* \param len Es el limite de clientes que puede guardar el array
* \return El retorno es 0 si se mostraron los datos, si no el retorno es -1.
*/
int cliente_ingresoForzado(Cliente* array, int len, char *nombre, char *apellido, char *cuit)
{
    int retorno = -1;
    int indice;
    indice = getLugarLibre(array,len);
    if( array != NULL && len > 0 && nombre != NULL &&
        apellido != NULL && cuit != NULL)
    {
        strncpy(array[indice].nombre, nombre, 51);
        strncpy(array[indice].apellido, apellido, 51);
        strncpy(array[indice].cuit, cuit, 20);
        array[indice].idCliente = getNextId();
        array[indice].isEmpty = 0;
        retorno = 0;
    }
    return retorno;
}
/**
* \brief    Se utiliza esta funcion para mostrar todos los datos de los
*           clientes del array (nombre, apellidos, cuit)
* \param array Es el array que se recorre
* \param len Es el limite de clientes que puede guardar el array
* \return El retorno es 0 si se mostraron los datos, si no el retorno es -1.
*/
int cliente_mostrar(Cliente* array, int len)
{
    int retorno = -1;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!array[i].isEmpty)
            {
                printf("\nNombre: %s\nApellido: %s\nCuit: %s\nID: %d\n\n",
                array[i].nombre, array[i].apellido, array[i].cuit, array[i].idCliente);
            }
        }
        retorno = 0;
    }
    return retorno;
}


int cliente_mostrarVentas(Cliente* array, int len, void* arrayVentasVoid, int lenVentas)
{
    int retorno = -1;
    Venta* arrayVentas = arrayVentasVoid;
    int i;
    int j;
    int contadorDeVentas = 0;
    if(array != NULL && len > 0 && arrayVentas != NULL && lenVentas > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!array[i].isEmpty)
            {
                contadorDeVentas = 0;
                for(j=0;j<lenVentas; j++)
                {
                    if(venta_getByIdCliente(&arrayVentas[j], 1, array[i].idCliente) != NULL &&
                        arrayVentas[j].estado == A_COBRAR)
                    {
                        contadorDeVentas++;
                    }
                }
                printf("\nNombre: %s\nApellido: %s\nCuit: %s\nID: %d\nCantidadDeVentas: %d\n\n",
                array[i].nombre, array[i].apellido, array[i].cuit, array[i].idCliente, contadorDeVentas);
            }
        retorno = 0;
        }
    }
    return retorno;
}
