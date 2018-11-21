#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "LinkedList.h"
#include "parser.h"
#include "people.h"
#include "utn.h"
#include "validator.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee);
int calcularAumento(void* this);
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee);

int main()
{
    LinkedList* listaEmpleados = ll_newLinkedList();
    if(listaEmpleados != NULL)
    {
        controller_loadFromText("datos.csv",listaEmpleados);
        ll_map(listaEmpleados,calcularAumento);
        controller_saveAsText("Aumentos10.csv",listaEmpleados);
        ll_map(listaEmpleados,employee_mostrar);
    }

    return 0;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char* ruta del archivo
 * \param pArrayListEmployee LinkedList* lista donde se va a guardar el archivo
 * \return [0] Exito y [-1] Error
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(ll_isEmpty(pArrayListEmployee))
    {
        FILE* pArchivo = fopen(path,"r");
        retorno = parser_EmployeeFromText(pArchivo,pArrayListEmployee);
        if(retorno!=-1 && !ll_isEmpty(pArrayListEmployee))
        {
            printf("ARCHIVO CARGADO CON EXITO!\nCANTIDAD DE EMPLEADOS: %d\n", ll_len(pArrayListEmployee));
            retorno = 0;
        }
        fclose(pArchivo);
    }
    else
    {
        printf("EL ARCHIVO YA FUE CARGADO\n");
    }
    return retorno;
}

int calcularAumento(void* this)
{
    int retorno = -1;
    float sueldo= 0;
    char bufferSueldo[1024];

    if(this != NULL)
    {
        employee_getSueldo(this,&sueldo);
        sueldo= sueldo+sueldo/10;
        sprintf(bufferSueldo,"%f",sueldo);
        employee_setSueldo(this,bufferSueldo);
        retorno = 0;

    }
    return retorno;
}
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* ruta del archivo
 * \param pArrayListEmployee LinkedList* lista que se va a guardar
 * \return [0] Exito y [-1] Error
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo = fopen(path,"w");
    int retorno = -1;
    if((pArchivo != NULL && !parser_SaveToText(pArchivo,pArrayListEmployee) &&
            pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0) )
    {
        retorno = 0;
        printf("ARCHIVO %s GUARDADO CON EXITO\n", path);
    }
    else
    {
        printf("\nNO HAY NINGUNA LISTA CARGADA\n");
    }
    fclose(pArchivo);
    return retorno;
}
