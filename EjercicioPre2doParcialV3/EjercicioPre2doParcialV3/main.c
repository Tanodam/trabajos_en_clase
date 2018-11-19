#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Parser.h"
#include "utn.h"
#include "Compra.h"

/**
    Realizar un programa que lee de un archivo los datos de compras de productos realizadas por clientes.
    Luego se le pedira al usuario que ingrese un id de un producto y el programa deberá imprimir por pantalla:
    - 1. Lista de compras filtrada segun el producto ingresado
    - 2. Monto total de cada compra considerando el valor del iva indicado.

    - 3. Por ultimo la lista filtrada obtenida con los datos ya calculados, debera ser escrita en un archivo separado por
    comas llamado "informe.csv", con el mismo formato que el original pero con una columna mas al final, en donde se
    indicara el monto total calculado.

    Para realizar el punto 1, se debera utilizar la funcion "filter".
    Para realizar el punto 2, se debera utilizar la funcion "map".
    Para imprimir por pantalla la lista, utilizar iterator.
*/

int generarArchivoInforme(char* fileName,LinkedList* listaCompras);
void* compra_filtrarPorId(void* lista);
int compra_imprimirLista(void* lista);

int main()
{
    // Definir lista de compras
    LinkedList* listaCompras;
    LinkedList* listaFiltrada;

    // Crear lista compras
    //...
    listaCompras = ll_newLinkedList();
    // Leer compras de archivo data.csv
    if(parser_parseCompras("data.csv",listaCompras))
    {
        // Filtrar
        listaFiltrada=ll_filter(listaCompras,criterioId);
        if(listaFiltrada != NULL)

        compra_imprimirLista(listaFiltrada);
        pausarPantalla();
        // Calcular montos
        printf("Calculando montos totales...\n");
        ll_map(listaFiltrada,com_calcularMonto);
        //TODO

        // Generar archivo de salida
        generarArchivoInforme("informe.csv",listaFiltrada);
    }
    else
        printf("Error leyendo compras\n");


    return 0;
}
int generarArchivoInforme(char* fileName,LinkedList* listaCompras)
{
    FILE* pArchivo = fopen(fileName,"w");
    int retorno = -1;
    if((pArchivo != NULL && !parser_SaveToText(pArchivo,listaCompras) &&
            listaCompras != NULL && ll_len(listaCompras) > 0))
    {
        retorno = 1;
        printf("ARCHIVO %s GUARDADO CON EXITO\n", fileName);
    }
    fclose(pArchivo);
    return retorno;
}

void* compra_filtrarPorId(void* lista)
{
    LinkedList* sublistaFiltrada;
    if(lista != NULL )
    {
           sublistaFiltrada = ll_filter(lista,criterioId);

    }
    return sublistaFiltrada;
}
int compra_imprimirLista(void* lista)
{
    Compra* this = NULL;
    int retorno = -1;
    int i = 0;
    char bufferNombre[1024];
    int bufferId = 0;
    float bufferprecioUnitario = 0;
    float bufferIva = 0;
    int bufferUnidades = 0;

         for(i=0; i<ll_len(lista); i++)
        {
            this = ll_get(lista,i);
            compra_getNombreCliente(this,bufferNombre);
            compra_getIdProducto(this,&bufferId);
            compra_getPrecioUnitario(this,&bufferprecioUnitario);
            compra_getIva(this,&bufferIva);
            compra_getUnidades(this,&bufferUnidades);
            printf("nombreCliente: %s\nidProducto: %d\nprecioUnitario: %.2f\nunidades: %d\niva: %.2f\n\n",bufferNombre,bufferId,bufferprecioUnitario,bufferUnidades,bufferIva);
            retorno = 0;
        }


    return retorno;
}
