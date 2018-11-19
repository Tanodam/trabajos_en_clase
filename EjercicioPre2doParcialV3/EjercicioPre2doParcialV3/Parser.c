#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <string.h>
#include "Compra.h"

int parser_parseCompras(char* fileName, LinkedList* lista)
{
    FILE* pFile;
    pFile = fopen(fileName, "r");
    Compra* pCompra;
    char string[2000];
    char bufferNombre[1024];
    char bufferUnidades[1024];
    char bufferIdProducto[1024];
    char bufferPrecioUnitario[1024];
    char bufferIva[1024];


    if(pFile != NULL)
    {
        fgets(string,sizeof(string),pFile);
        while(!feof(pFile))
        {
            fgets(string,sizeof(string),pFile);
            if(strlen(string) > 5)
            {
                strncpy(bufferNombre,strtok(string, ","),1024);
                strncpy(bufferIdProducto,strtok(NULL,","),1024);
                strncpy(bufferPrecioUnitario,strtok(NULL,","),1024);
                strncpy(bufferUnidades,strtok(NULL,","),1024);
                strncpy(bufferIva,strtok(NULL,"\n"),1024);
                pCompra = compra_newConParametros(bufferNombre,bufferIdProducto,bufferPrecioUnitario,bufferUnidades,bufferIva);
               //printf("%s - %s - %s - %s - %s\n", bufferNombre,bufferIdProducto,bufferPrecioUnitario,bufferUnidades,bufferIva);

                if(pCompra != NULL)
                {
                    ll_add(lista,pCompra);
                }
            }
        }
    }
    return 1; // OK
}
int parser_SaveToText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Compra* this = NULL;
    int retorno = -1;
    int i = 0;
    char bufferNombre[1024];
    int bufferId = 0;
    float bufferprecioUnitario = 0;
    float bufferMontoTotal = 0;
    float bufferIva = 0;
    int bufferUnidades = 0;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            if(i==0)
            {
                fprintf(pFile,"nombreCliente,idProducto,precioUnitario,unidades,iva,montoTotal\n");///Agrega la cabecera al archivo de texto
            }
            this = ll_get(pArrayListEmployee,i);
            compra_getNombreCliente(this,bufferNombre);
            compra_getIdProducto(this,&bufferId);
            compra_getPrecioUnitario(this,&bufferprecioUnitario);
            compra_getIva(this,&bufferIva);
            compra_getUnidades(this,&bufferUnidades);
            compra_getMontoTotal(this,&bufferMontoTotal);
            fprintf(pFile,"%s,%d,%.2f,%d,%.2f,%.2f\n",bufferNombre,bufferId,bufferprecioUnitario,bufferUnidades,bufferIva,bufferMontoTotal);
            retorno = 0;
        }
    }
    return retorno;
}
