#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Clientes.h"
#include "ventaAfiches.h"
#include "array.h"


static int ventas_obtenerID();
/**
*\brief Funcion que obtiene el proximo ID
*\return Retorna el ID
*/
static int ventas_obtenerID()
{
    static int ID=1;
    ID++;
    return ID;
}

/**
*\brief Funcion que inicializa todos los estados de .IsEmpty en 1 para indicar que el campo esta vacio.
*\param Ventas* array es el puntero que recibe a la estructua Ventas para trabajar con ella y sus campos
*\param limite es la cantidad de ventas
*\return Exito=0 Error=1
*/
int ventas_inicializarArray(Ventas* array,int limite)
{
    int i;
    for(i=0; i<limite; i++)
    {
        array[i].isEmpty=1;
    }
    return 0;
}
/**
*\brief Funcion que busca un indice vacio comprando que el campo IsEmpty sea 1
*\param Ventas* array es el puntero que recibe a la estructua ventas para trabajar con ella y sus campos
*\param limite es la cantidad de ventas
*\param indice es el puntero donde se va a guardar el indice vacio obtenido
*\return Exito=0 Error=1
*/
int ventas_buscarIndiceVacio(Ventas* array,int limite,int*indice)
{
    int i;
    int retorno=-1;
    for(i=0; i<limite; i++)
    {
        if(array[i].isEmpty==1)
        {
            *indice=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}
/**
*\brief Funcion que realiza la venta de un afiche
*\param ventas* array es el puntero que recibe a la estructua ventas para trabajar con ella y sus campos
*\param indice es el indice del campo IsEmpty que se va a consultar
*\param limite es la cantidad de ventass
*\return Exito=0 Error=1
*/
int ventas_venderAfiches(Ventas* array, int limite, int idCliente)
{
    int retorno=-1;
    int auxIndice;
    char nombreDelArchivo[71];
    int zona;
    int cantidad;

    ventas_buscarIndiceVacio(array,limite,&auxIndice);
    if( array != NULL && array[auxIndice].isEmpty &&
            !array_getNombre(nombreDelArchivo,51,"\nIngrese el nombre del archivo: ", "ERROR!",3) &&
            !utn_getEntero(&zona,3,"\nIngrese la zona de la publicacion\n1-CABA\n2-Zona Sur\n3-Zona Oeste\n", "ERROR!",1,3) &&
            !array_getStringInt(&cantidad,100,"\nIngrese la cantidad de afiches: ","ERROR!",3))

    {
        retorno = 0;
        strncpy(array[auxIndice].nombreDelArchivo,nombreDelArchivo,51);
        array[auxIndice].zona=zona;
        array[auxIndice].cantidad=cantidad;
        array[auxIndice].idCliente=idCliente;
        array[auxIndice].id=ventas_obtenerID();
        array[auxIndice].isEmpty=0;
        strncpy(array[auxIndice].estadoVenta,"A COBRAR",11);
        printf("Venta Exitosa!\t ID de venta %d\n", array[auxIndice].id);

        pausarPantalla();

    }
    else
    {
        printf("No se pudo realizar la venta\n");
        pausarPantalla();
        limpiarPantalla();
    }
    return retorno;
}
/**
*\brief Funcion que busca una venta por su ID.
*\param venta* array es el puntero que recibe a la estructua ventas para trabajar con ella y sus campos
*\param limite es la cantidad de ventas
*\param ID es el identificador de ventas que hay que encontrar
*\return Retorna el indice donde esta alojado la informacion del ventas - NULL si no encuentra nada
*/
Ventas* ventas_busquedaPorID(Ventas* array, int limite, int ID)
{
    int i;
    Ventas* retorno=NULL;
    for (i=0; i<limite; i++)
    {
        if(!array[i].isEmpty && array[i].id==ID)
        {
            retorno = array+i;
            break;
        }

    }
    return retorno;
}
/**
*\brief Funcion que busca una venta por su ID de lciente
*\param venta* array es el puntero que recibe a la estructua ventas para trabajar con ella y sus campos
*\param limite es la cantidad de ventass
*\param ID es el identificador de usuario que hay que encontrar
*\return Retorna el indice donde esta alojado la informacion del ventas - NULL si no encuentra nada
*/
Ventas* ventas_busquedaPorIDClientes(Ventas* array, int limite, int IDCliente)
{
    int i;
    Ventas* retorno=NULL;
    for (i=0; i<limite; i++)
    {
        if(!array[i].isEmpty && array[i].idCliente==IDCliente)
        {
            retorno = array+i;
            break;
        }

    }
    return retorno;
}
/**
*\brief Funcion que borra un cliente cambiando el estado del valor de IsEmpty
*\param venta* array es el puntero que recibe a la estructua ventas para trabajar con ella y sus campos
*\param limite es la cantidad de clientes
*\return void
*/
void ventas_borrarPorID(Ventas* array,int limite)
{
    if(array != NULL && limite>0)
    {
        array->isEmpty=1;
    }
}
/**
*\brief Funcion que hardcodea todos los campos de la estructura con informacion falsa para testeo
*\param venta* array es el puntero que recibe a la estructua ventas para trabajar con ella y sus campos
*\param limite es la cantidad de ventass
*\param cantidadAfiches es el string a copiar en en el campo cantidad de la estructura
*\param nombreArchivo es el string a copiar en en el campo nombreDelArchivo de la estructura
*\param zona es el int a copiar en en el campo zona de la estructura
*\param idCliente es el int a copiar en en el campo IdCliente de la estructura
*\return Exito=0 Error=1
*/
int ventas_ingresoForzado(Ventas* array,int limite,int cantidadAfiches,char* nombreArchivo,int zona, int idCliente)
{
    int auxiliar;

    ventas_buscarIndiceVacio(array,limite,&auxiliar);
    array[auxiliar].isEmpty=0;
    strncpy(array[auxiliar].nombreDelArchivo,nombreArchivo,51);
    array[auxiliar].zona=zona;
    array[auxiliar].cantidad=cantidadAfiches;
    array[auxiliar].idCliente=idCliente;
    array[auxiliar].id=ventas_obtenerID();
    strncpy(array[auxiliar].estadoVenta,"A COBRAR",11);

    return 0;
}

/**
*\brief Funcion que imprime todos los campos de la estructura ventas
*\param venta* arrayventas es el puntero que recibe a la estructua ventas para trabajar con ella y sus campos
*\param limiteVentas es la cantidad de ventas
*\param cliente* arrayclientes es el puntero que recibe a la estructua clientes para trabajar con ella y sus campos
*\param limiteClientes es la cantidad de clientes
*\return Exito=0 Error=1
*/
int ventas_imprimirListaVentas(Ventas* arrayVentas,int limiteVentas, Cliente* arrayClientes, int limiteClientes)
{

    int i;
    Cliente* clienteSeleccionado;

    for(i=0; i<limiteVentas; i++)
    {
        if(arrayVentas[i].isEmpty==0 && clienteSeleccionado!=NULL)
        {
            clienteSeleccionado = cliente_busquedaPorID(arrayClientes,limiteClientes,arrayVentas[i].idCliente);
            printf("\nID de venta: %d",arrayVentas[i].id);
            printf("\nNombre del archivo: %s",arrayVentas[i].nombreDelArchivo);
            printf("\nCantidad de afiches: %d",arrayVentas[i].cantidad);
            if(arrayVentas[i].zona == CABA)
            {
                printf("\nZona: CABA");
            }
            else if(arrayVentas[i].zona == ZONA_SUR)
            {
                printf("\nZona: Zona Sur");
            }
            else if(arrayVentas[i].zona == ZONA_OESTE)
            {
                printf("\nZona: Zona Oeste");
            }
            printf("\nNombre: %s, %s",clienteSeleccionado->nombre, clienteSeleccionado->apellido);
            printf("\nID Cliente %d",arrayVentas[i].idCliente);
            printf("\nEstado %s\n\n",arrayVentas[i].estadoVenta);
        }
    }
    pausarPantalla();
    return 0;
}
/**
*\brief Funcion que edita una venta permitiendo cambiar zona y cantidad de afiches
*\param venta* array es el puntero que recibe a la estructua ventas para trabajar con ella y sus campos
*\param limite es la cantidad de clientes
*\return void
*/
int ventas_editarAfiches(Ventas* array, int limite)
{
    int retorno=-1;
    int zona;
    int cantidad;
    limpiarPantalla();
    printf("Se va a modificar la siguiente venta\nNombre del archivo %s\nCantidad de afiches: %d",array->nombreDelArchivo,
            array->cantidad);
    if(array->zona == CABA)
            {
                printf("\nZona: CABA");
            }
            else if(array->zona == ZONA_SUR)
            {
                printf("\nZona: Zona Sur");
            }
            else if(array->zona == ZONA_OESTE)
            {
                printf("\nZona: Zona Oeste");
            }
    if( array != NULL && !array->isEmpty &&
        !utn_getEntero(&zona,3,"\nIngrese la zona de la publicacion\n1-CABA\n2-Zona Sur\n3-Zona Oeste\n", "ERROR!",1,3) &&
        !array_getStringInt(&cantidad,100,"\nIngrese la cantidad de afiches: ","ERROR!",3))

    {
        retorno = 0;
        array->zona=zona;
        array->cantidad=cantidad;
        retorno = 0;
    }
    return retorno;


}
/**
*\brief Funcion que cierra una venta cambiando el estado del valor estadoVenta
*\param venta* array es el puntero que recibe a la estructua ventas para trabajar con ella y sus campos
*\param limiteVentas es la cantidad de ventas
*\param cliente* array es el puntero que recibe a la estructua cliente para trabajar con ella y sus campos
*\param limiteCliente es la cantidad de ventas
*\return Exito=0 Error=1
*/
int ventas_cerrarVentas(Ventas* arrayVentas, int limiteVentas, Cliente *arrayClientes, int limiteClientes)
{
    int retorno=-1;
    Cliente* clienteSeleccionado;

    limpiarPantalla();
    if( arrayVentas != NULL && strcmp(arrayVentas->estadoVenta,"A COBRAR")==0)
    {
        clienteSeleccionado=cliente_busquedaPorID(arrayClientes,limiteClientes,arrayVentas->idCliente);
        printf("Se va a cerrar la siguiente venta\nNombre del archivo: %s\nCantidad de afiches: %d",
               arrayVentas->nombreDelArchivo, arrayVentas->cantidad);
            if(arrayVentas->zona == CABA)
            {
                printf("\nZona: CABA");
            }
            else if(arrayVentas->zona == ZONA_SUR)
            {
                printf("\nZona: Zona Sur");
            }
            else if(arrayVentas->zona == ZONA_OESTE)
            {
                printf("\nZona: Zona Oeste");
            }
        printf("\n\nInformacion del cliente\nNombre: %s, %s\nCuit: %s\n\n",
               clienteSeleccionado->nombre, clienteSeleccionado->apellido, clienteSeleccionado->cuit);
        pausarPantalla();

        retorno = 0;
        strncpy(arrayVentas->estadoVenta,"COBRADA", 11);
        limpiarPantalla();
        printf("VENTA CERRADA!");
        pausarPantalla();
    }
    else
    {
        printf("No se puede cerrar esta venta\n");
        pausarPantalla();
    }
    return retorno;
}
