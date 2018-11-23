#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "venta.h"
#include <string.h>

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char* ruta del archivo
 * \param pArrayListEmployee LinkedList* lista donde se va a guardar el archivo
 * \return [0] Exito y [-1] Error
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pArchivo = fopen(path,"r");
    if(ll_isEmpty(pArrayListEmployee))
    {

        retorno = parser_ventaFromText(pArchivo,pArrayListEmployee);
        if(retorno!=-1 && !ll_isEmpty(pArrayListEmployee))
        {
            printf("ARCHIVO CARGADO CON EXITO!\nCANTIDAD DE ARTICULOS: %d\n", ll_len(pArrayListEmployee));
            retorno = 0;
        }
        else
        {
            printf("EL ARCHIVO %s ESTA VACIO\n", path);

        }

    }
    fclose(pArchivo);

    return retorno;
}
