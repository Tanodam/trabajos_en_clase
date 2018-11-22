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
int controller_loadFromBinary(char* path , LinkedList* pLinkedList);
int parser_SaveToBinary(FILE* pFile , LinkedList* pLinkedListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pLinkedListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pLinkedList);

int main()
{
    LinkedList* listaEmpleados = ll_newLinkedList();

    if(listaEmpleados != NULL)
    {
        controller_loadFromBinary("datos.bin",listaEmpleados);
        //controller_loadFromText("datos.csv",listaEmpleados);
        ll_map(listaEmpleados,calcularAumento);
        controller_saveAsText("Aumentos10.csv",listaEmpleados);
        controller_saveAsBinary("datos.bin", listaEmpleados);

        //ll_map(listaEmpleados,employee_mostrar);
    }

        //listaEmpleadosSueldos = ll_clone(listaEmpleados);
    return 0;
}
///---------------------------------------------TEXTO---------------------------------------




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


///---------------------------------------------FIN TEXTO---------------------------------------




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


///---------------------------------------------BINARIO---------------------------------------

/**
 * \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 * \param path Ruta del archivo para leer
 * \param pLinkedList Es el LinkedList
 * \return retorna 0 si el array no es null y el archivo existe sino retorna -1
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pLinkedList)
{
    FILE* pArchivo = fopen(path,"rb");
    int retorno = -1;
    if(pLinkedList != NULL && path != NULL)
    {
        retorno = parser_EmployeeFromBinary(pArchivo,pLinkedList);
    }
    fclose(pArchivo);
    return retorno;
}
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pLinkedListEmployee)
{
    int retorno = -1;
    int cantidadLeida;
    Employee* pEmployee;
    Employee* aux = employee_new();

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            pEmployee = employee_new();
            cantidadLeida = fread(pEmployee,sizeof(Employee),1,pFile);
            if(pEmployee != NULL && cantidadLeida == 1)
            {
                employee_setId(aux,"0");
                ll_add(pLinkedListEmployee,pEmployee);
                retorno = 0;
            }
        }
    }
    return retorno;
}

int parser_SaveToBinary(FILE* pFile , LinkedList* pLinkedListEmployee)
{
    int retorno = -1;
    int i = 0;
    int len;
    Employee* auxEmployee;

    if(pFile != NULL && pLinkedListEmployee != NULL)
    {
        len = ll_len(pLinkedListEmployee);
        while(i != len)
        {
            auxEmployee = ll_get(pLinkedListEmployee,i);
            if(auxEmployee != NULL)
            {
                fwrite(auxEmployee,sizeof(Employee),1,pFile);
            }
            retorno = 0;
            i++;
        }
    }
    return retorno;
}

int controller_saveAsBinary(char* path , LinkedList* pLinkedList)
{
    FILE* pArchivo = fopen(path,"wb");
    int retorno = -1;

    if(pArchivo != NULL && !parser_SaveToBinary(pArchivo,pLinkedList))
    {
        retorno = 0;
    }
    fclose(pArchivo);
    return retorno;
}
