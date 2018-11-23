#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "venta.h"
#include <string.h>
#define BUFFER 4096

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 * \param FILE* pFile Puntero del tipo file al archivo que hay que parsear
 * \param pArrayListEmployee LinkedList* lista donde se van a a guardar los empleados
 * \return Exito=1 y Error=-0
 */
int parser_ventaFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Venta* pVenta;
    char string[2000];
    char bufferCodigoProducto[BUFFER];
    char bufferFecha[BUFFER];
    char bufferId[BUFFER];
    char bufferCantidad[BUFFER];
    char bufferPrecioUnitario[BUFFER];
    char bufferCuit[BUFFER];
    int retorno = -1;

    if(pFile != NULL)
    {
        fgets(string,sizeof(string),pFile);
        while(!feof(pFile))
        {
            fgets(string,sizeof(string),pFile);
            if(strlen(string) > 5)
            {
                strncpy(bufferId,strtok(string, ","),BUFFER);
                strncpy(bufferFecha,strtok(NULL,","),BUFFER);
                strncpy(bufferCodigoProducto,strtok(NULL,","),BUFFER);
                strncpy(bufferCantidad,strtok(NULL,","),BUFFER);
                strncpy(bufferPrecioUnitario,strtok(NULL,","),BUFFER);
                strncpy(bufferCuit,strtok(NULL,"\n"),BUFFER);
                pVenta = venta_newConParametros(bufferCodigoProducto,bufferFecha,bufferPrecioUnitario,bufferId,bufferCantidad);
                //printf("%s - %s - %s - %s\n", bufferId,bufferFecha,bufferCuit,bufferPrecioUnitario);

                if(pVenta != NULL && !ll_add(pArrayListEmployee,pVenta))
                {
                    retorno = 1;
                }
            }
        }
    }
    fclose(pFile);
    return retorno; // OK
}
