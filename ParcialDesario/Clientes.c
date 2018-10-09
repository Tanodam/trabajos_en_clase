#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Clientes.h"
#include "array.h"


static int cliente_obtenerID();
/**
*\brief Funcion que obtiene el proximo ID
*\return Retorna el ID
*/
static int cliente_obtenerID()
{
    static int ID=-1;
    ID++;
    return ID;
}
/**
*\brief Funcion que inicializa todos los estados de .IsEmpty en 1 para indicar que el campo esta vacio.
*\param Cliente* array es el puntero que recibe a la estructua Cliente para trabajar con ella y sus campos
*\param limite es la cantidad de clientes
*\return Retorno todos los campos de IsEmpty en 1
*/
int cliente_inicializarArray(Cliente* array,int limite)
{
    int i;
    for(i=0;i<limite;i++){
        array[i].isEmpty=1;
    }
    return 0;
}
/**
*\brief Funcion que busca un indice vacio comprando que el campo IsEmpty sea 1
*\param Cliente* array es el puntero que recibe a la estructua Clientes para trabajar con ella y sus campos
*\param limite es la cantidad de clientes
*\param indice es el indice que se va a guardar como nuevo lugar vacio para guardar un cliente
*\return Exito=0 Error=1
*/
int cliente_buscarIndiceVacio(Cliente* array,int limite,int*indice)
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
*\brief Funcion que realiza el alta de un cliente
*\param Cliente* array es el puntero que recibe a la estructua Clientes para trabajar con ella y sus campos
*\param indice es el indice obtenido para guardar un nuevo cliente
*\param limite es la cantidad de clientes
*\return Exito=0 Error=1
*/
int cliente_altaCliente(Cliente* array,int indice, int limite)
{
    int retorno=-1;
    char nombre[51];
    char apellido[51];
    char cuit[51];

    if( array != NULL && limite > 0 && array[indice].isEmpty &&

            !array_getNombre(nombre,51,"\nIngrese el nombre del cliente: ", "ERROR!",3) &&
            !array_getNombre(apellido,51,"\nIngrese el apellido del cliente: ", "ERROR!",3) &&
            !array_getCuilOrCuit(cuit,15,"\nIngrese el cuit del cliente ","ERROR!",3))

        {
            strncpy(array[indice].nombre,nombre,51);
            strncpy(array[indice].apellido,apellido,51);
            strncpy(array[indice].cuit,cuit,15);
            array[indice].isEmpty = 0;
            array[indice].id = cliente_obtenerID();
            retorno = 0;
        }
        printf("\nALTA EXITOSA! Se genero el cliente con el ID %d\n", indice);
        pausarPantalla();
        limpiarPantalla();
        return retorno;
}
/**
*\brief Funcion que modifica un cliente
*\param Cliente* array es el puntero que recibe a la estructua Clientes para trabajar con ella y sus campos
*\param limite es la cantidad de clientes
*\return Exito=0 Error=1
*/
int cliente_modificarCliente(Cliente* array,int limite)
{
    int retorno=-1;
    char nombre[51];
    char apellido[51];
    char cuit[15];

    printf("Se va a modificar el siguiente cliente\nNombre: %s\nApellido: %s\nCuit: %s\nID: %d\n\n",
    array->nombre, array->apellido, array->cuit, array->id);
    pausarPantalla();
    if(     array != NULL && limite > 0 &&
            !array_getNombre(nombre,51,"\nIngrese el nombre del cliente: ", "ERROR!",3) &&
            !array_getNombre(apellido,51,"\nIngrese el apellido del cliente: ", "ERROR!",3) &&
            !array_getCuilOrCuit(cuit,15,"\nIngrese el cuit del cliente: ","ERROR!",3))
        {
            strncpy(array->nombre,nombre,51);
            strncpy(array->apellido,apellido,51);
            strncpy(array->cuit,cuit,15);
            retorno = 0;
        }
        return retorno;
}
/**
*\brief Funcion que busca un cliente por su ID.
*\param Cliente* array es el puntero que recibe a la estructua Clientes para trabajar con ella y sus campos
*\param limite es la cantidad de clientes
*\param ID es el identificador de usuario que hay que encontrar
*\return Retorna el indice donde esta alojado la informacion del cliente - NULL si no encuentra nada
*/
Cliente* cliente_busquedaPorID(Cliente* array, int limite, int ID)
{
    int i;
    Cliente* retorno=NULL;
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
*\brief Funcion que borra un cliente cambiando el estado del valor de IsEmpty
*\param Cliente* array
 es el puntero que recibe a la estructua Clientes para trabajar con ella y sus campos
*\param limite es la cantidad de clientes
*\return void
*/
void cliente_borrarPorID(Cliente* array,int limite)
{

    limpiarPantalla();
    printf("Se va a borrar el siguiente cliente\nNombre: %s\nApellido: %s\nCuit: %s\nID: %d\n\n",
    array->nombre, array->apellido, array->cuit, array->id);
    pausarPantalla();
    if(array != NULL && limite>0)
    {
        array->isEmpty=1;
    }
}
/**
*\brief Funcion que imprime todos los campos de la estructura clientes
*\param Cliente* array es el puntero que recibe a la estructua Clientes para trabajar con ella y sus campos
*\param limite es la cantidad de clientes
*\return Exito=0 Error=1
*/
int cliente_imprimirListaClientes(Cliente* array,int limite)
{
    int i;
    limpiarPantalla();

    for(i=0;i<limite;i++){
        if(array[i].isEmpty==0)
        {
            printf("\nID: %d",array[i].id);
            printf("\nNombre: %s, %s",array[i].nombre, array[i].apellido );
            printf("\nCuit: %s\n",array[i].cuit);
        }
    }
        pausarPantalla();
    return 0;
}
/**
*\brief Construye el menu principal del ABM y valida la opcion seleccionada
*\return Exito=0 Devuelve la opcion ingresada y validada Error=5 Devuelve 5 porque es el case de Salida del programa.
*
*/
int cliente_construirMenu()
{
        int respuesta;
        printf("1. Alta Cliente\n");
        printf("2. Modificar Cliente\n");
        printf("3. Baja Cliente\n");
        printf("4. Vender afiches\n");
        printf("5. Editar venta\n");
        printf("6. Cobrar Venta\n");
        printf("7. Imprimir Clientes\n");
        printf("8. Salir\n");
        myFlush();
        if(utn_getEntero(&respuesta,3,"Ingrese la opcion deseada\n","Opcion invalida\n", 1,8))
        {
            respuesta = 8;
        }

        return respuesta;
}
/**
*\brief Funcion que hardcodea todos los campos de la estructura con informacion falsa para testeo
*\param Cliente* array es el puntero que recibe a la estructua Clientes para trabajar con ella y sus campos
*\param limite es la cantidad de clientes
*\param nombre es el string a copiar en en el campo nombre de la estructura
*\param apellido es el string a copiar en en el campo nombre de la estructura
*\param salario es el float a copiar en en el campo salario de la estructura
*\param nombre es el int a copiar en en el campo sector de la estructura
*\return Exito=0 Error=1
*/
int cliente_ingresoForzado(Cliente* array,int limite,char* nombre,char* apellido,char* cuit)
{
    int auxiliar;

    cliente_buscarIndiceVacio(array,limite,&auxiliar);
    array[auxiliar].id=cliente_obtenerID();
    strncpy(array[auxiliar].nombre,nombre,50);
    strncpy(array[auxiliar].apellido,apellido,50);
    strncpy(array[auxiliar].cuit,cuit,15);

    array[auxiliar].isEmpty=0;
    return 0;
}
