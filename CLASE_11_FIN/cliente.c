#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"

static int getNextId();

int cliente_construir(  Cliente* pCliente,int limiteCliente,
                        Contratacion* pContrataciones,int limiteContrataciones)
{

    int retorno = -1;
    int i;
    int idCliente = 0;
    if( pCliente != NULL && limiteCliente > 0 &&
        pContrataciones != NULL && limiteContrataciones > 0)
    {
        for(i=0;i<limiteCliente;i++)
        {
            pCliente[i].isEmpty = 1;
        }
        for(i=0;i<limiteContrataciones;i++)
        {
            if(cliente_getClienteByCuit(pCliente,limiteCliente,pContrataciones[i].cuit) == NULL)
            {
                strncpy(pCliente[idCliente].cuit,pContrataciones[i].cuit,10);
                pCliente[idCliente].isEmpty = 0;
                pCliente[idCliente].idCliente = getNextId();
                idCliente++;
            }
        }
        retorno = 0;
    }
    return retorno;
}



Cliente* cliente_getClienteByCuit(Cliente* pBuffer,int limite, char* cuit)
{
    Cliente* retorno = NULL;
    int i;
    if(pBuffer != NULL && limite > 0 && cuit != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(!pBuffer[i].isEmpty && !strcmp(cuit,pBuffer[i].cuit))
            {
                retorno = &pBuffer[i]; //pBuffer+i
                break;
            }
        }
    }
    return retorno;
}


static int getNextId()
{
    static int idCliente = -1;
    idCliente++;
    return idCliente;
}


int cliente_imprimirClientees(Cliente* pBuffer,int limite)
{
    int retorno = -1;
    int i;
    if(pBuffer != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            if(!pBuffer[i].isEmpty)
            {
                printf("\nCUIT: %s",pBuffer[i].cuit);
            }
        }
        retorno = 0;
    }
    return retorno;
}


int cliente_ordenarByCuit(Cliente* pBuffer,int limite,int upOrDonw)
{

}
