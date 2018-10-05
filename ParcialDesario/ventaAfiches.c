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
*\param Empleado* array es el puntero que recibe a la estructua Empleados para trabajar con ella y sus campos
*\param limite es la cantidad de empleados
*\return Retorno todos los campos de IsEmpty en 1
*/
int ventas_inicializarArray(Ventas* array,int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        array[i].isEmpty=1;
    }
    return 0;
}
/**
*\brief Funcion que busca un indice vacio comprando que el campo IsEmpty sea 1
*\param Empleado* array es el puntero que recibe a la estructua Empleados para trabajar con ella y sus campos
*\param limite es la cantidad de ventass
*\param indice es el indice del campo IsEmpty que se va a consultar
*\return Exito=0 Error=1
*/
int ventas_buscarIndiceVacio(Ventas* array,int limite,int*indice)
{
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++){
        if(array[i].isEmpty==1){
            *indice=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}
/**
*\brief Funcion que realiza el alta de un ventas
*\param Empleado* array es el puntero que recibe a la estructua Empleados para trabajar con ella y sus campos
*\param indice es el indice del campo IsEmpty que se va a consultar
*\param limite es la cantidad de ventass
*\return Exito=0 Error=1
*/
int ventas_venderAfiches(Ventas* arrayVentas, Cliente* arrayClientes, int limiteVentas, int limiteClientes, int idCliente)
{
    int retorno=-1;
    int auxIndice;
    char nombreDelArchivo[71];
    char zona[21];
    int cantidad;

    ventas_buscarIndiceVacio(arrayVentas,limiteVentas,&auxIndice);
    printf("%d",auxIndice);
    if( arrayVentas != NULL && arrayClientes != NULL && arrayVentas[auxIndice].isEmpty &&
        !array_getNombre(nombreDelArchivo,51,"\nIngrese el nombre del archivo: ", "ERROR!",3) &&
        !array_getNombre(zona,21,"\nIngrese la zona de la publicacion: ", "ERROR!",3) &&
        !array_getStringInt(&cantidad,100,"\nIngrese la cantidad de afiches","ERROR!",3))

        {
            retorno = 0;
            strncpy(arrayVentas[auxIndice].nombreDelArchivo,nombreDelArchivo,51);
            strncpy(arrayVentas[auxIndice].zona,zona,21);
            arrayVentas[auxIndice].cantidad=cantidad;
            arrayVentas[auxIndice].idCliente=idCliente;
            arrayVentas[auxIndice].id=ventas_obtenerID();
            arrayVentas[auxIndice].isEmpty=0;
            strncpy(arrayVentas[auxIndice].estadoVenta,"A COBRAR",21);
            printf("Venta Exitosa! ID de venta %d", arrayVentas[auxIndice].id);

            pausarPantalla();

        }


        return retorno;
}
/**
*\brief Funcion que busca un ventas por su ID.
*\param Empleado* array es el puntero que recibe a la estructua Empleados para trabajar con ella y sus campos
*\param limite es la cantidad de ventass
*\param ID es el identificador de usuario que hay que encontrar
*\return Retorna el indice donde esta alojado la informacion del ventas - NULL si no encuentra nada
*/
Ventas* ventas_busquedaPorID(Ventas* array, int limite, int ID)
{
    int i;
    Ventas* retorno=NULL;
    for (i=0;i<limite;i++){
        if(!array[i].isEmpty && array[i].id==ID)
        {
            retorno = array+i;
            break;
        }

    }
    return retorno;
}

/**
*\brief Funcion que hardcodea todos los campos de la estructura con informacion falsa para testeo
*\param Empleado* array es el puntero que recibe a la estructua Empleados para trabajar con ella y sus campos
*\param limite es la cantidad de ventass
*\param nombre es el string a copiar en en el campo nombre de la estructura
*\param apellido es el string a copiar en en el campo nombre de la estructura
*\param salario es el float a copiar en en el campo salario de la estructura
*\param nombre es el int a copiar en en el campo sector de la estructura
*\return Exito=0 Error=1
*/
int ventas_ingresoForzado(Ventas* array,int limite,int cantidadAfiches,char* nombreArchivo,char* zona, int idCliente)
{
    int auxiliar;

    ventas_buscarIndiceVacio(array,limite,&auxiliar);
    array[auxiliar].isEmpty=0;
    strncpy(array[auxiliar].nombreDelArchivo,nombreArchivo,51);
    strncpy(array[auxiliar].zona,zona,21);
    array[auxiliar].cantidad=cantidadAfiches;
    array[auxiliar].idCliente=idCliente;
    array[auxiliar].id=ventas_obtenerID();
    strncpy(array[auxiliar].estadoVenta,"A COBRAR",21);

    return 0;
}

/**
*\brief Funcion que imprime todos los campos de la estructura clientes
*\param Empleado* array es el puntero que recibe a la estructua Empleados para trabajar con ella y sus campos
*\param limite es la cantidad de clientes
*\return Exito=0 Error=1
*/
int ventas_imprimirListaVentas(Ventas* array,int limite)
{
    int i;

    for(i=0;i<limite;i++)
    {
        if(array[i].isEmpty==0)
        {
            printf("----%d", array[i].isEmpty);
            printf("\nID de venta: %d",array[i].id);
            printf("\nNombre del archivo: %s",array[i].nombreDelArchivo);
            printf("\nCantidad de afiches: %d",array[i].cantidad);
            printf("\nZona: %s",array[i].zona);
            printf("\nID Cliente %d",array[i].idCliente);
            printf("\nEstado %s\n\n",array[i].estadoVenta);
        }
    }
        pausarPantalla();
    return 0;
}

int ventas_editarAfiches(Ventas* array, int limite)
{
    int retorno=-1;
    char zona[51];
    int cantidad;

    printf("Se va a modificar la siguiente venta\nZona: %s\nCantidad de afiches: %d\n\n",
    array->zona, array->cantidad);
    pausarPantalla();
    if( array != NULL && !array->isEmpty &&
        !array_getNombre(zona,21,"\nIngrese la zona de la publicacion: ", "ERROR!",3) &&
        !array_getStringInt(&cantidad,100,"\nIngrese la cantidad de afiches","ERROR!",3))

        {
            retorno = 0;
            strncpy(array->zona,zona,21);
            array->cantidad=cantidad;
            retorno = 0;
        }
        return retorno;


}

int ventas_cerrarVentas(Ventas* arrayVentas, int limiteVentas, Cliente *arrayClientes, int limiteClientes)
{
    int retorno=-1;
    Cliente* clienteSeleccionado;


    printf("Se va a modificar la siguiente venta\nNombre del archivo: %s\nZona: %s\nCantidad de afiches: %d\n\n",
    arrayVentas->nombreDelArchivo,arrayVentas->zona, arrayVentas->cantidad);
    pausarPantalla();

    retorno =0;
    return retorno;


}
