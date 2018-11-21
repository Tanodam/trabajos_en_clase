#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "people.h"
#include <string.h>
#define BUFFER 1024

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 * \param FILE* pFile Puntero del tipo file al archivo que hay que parsear
 * \param pArrayListEmployee LinkedList* lista donde se van a a guardar los empleados
 * \return Exito=1 y Error=-0
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;
    char string[2000];
    char bufferNombre[BUFFER];
    char bufferApellido[BUFFER];
    char bufferId[BUFFER];
    char bufferSueldo[BUFFER];
    char bufferIsEmpty[BUFFER];
    int retorno = -1;
    char prueba[1024];


    if(pFile != NULL)
    {
        fgets(string,sizeof(string),pFile);
        while(!feof(pFile))
        {
            fgets(string,sizeof(string),pFile);
            if(strlen(string) > 5 && prueba != NULL)
            {
                strncpy(bufferId,strtok(string, ";"),BUFFER);
                strncpy(bufferNombre,strtok(NULL,";"),BUFFER);
                strncpy(bufferApellido,strtok(NULL,";"),BUFFER);
                strncpy(bufferIsEmpty,strtok(NULL,";"),BUFFER);
                strncpy(bufferSueldo,strtok(NULL,"\n"),BUFFER);
                pEmpleado = employee_newConParametros(bufferId,bufferNombre,bufferApellido,bufferSueldo,bufferIsEmpty);
                //printf("%s - %s - %s - %s\n", bufferId,bufferNombre,bufferApellido,bufferSueldo);

                if(pEmpleado != NULL && !ll_add(pArrayListEmployee,pEmpleado))
                {
                    retorno = 1;
                }
            }
        }
    }
    fclose(pFile);
    return retorno; // OK
}

//    int retorno = -1;
//    int flagPrimeraVuelta=1;
//    char bufferID[1024];
//    char bufferNombre[1024];
//    char bufferHorasTrabajadas[1024];
//    char bufferSueldo[1024];
//
//    Employee* pEmpleado = NULL;
//
//    if(pFile!=NULL)
//    {
//        while(!feof(pFile))
//        {
//            if(flagPrimeraVuelta)
//            {
//                flagPrimeraVuelta = 0;
//                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
//                       bufferID,
//                       bufferNombre,
//                       bufferHorasTrabajadas,
//                       bufferSueldo);
//            }
//            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
//                   bufferID,
//                   bufferNombre,
//                   bufferHorasTrabajadas,
//                   bufferSueldo);
//
//            pEmpleado = Employee_newConParametros(bufferID,
//                                                  bufferNombre,
//                                                  bufferHorasTrabajadas,
//                                                  bufferSueldo);
//
//            if(pEmpleado != NULL)
//            {
//                retorno = 0;
//                ll_add(pArrayListEmployee,pEmpleado);
//            }
//        }
//    }
//
//    return retorno;
//}
/** \brief Parsea los datos los datos de los empleados desde el archivo data.dat (modo texto).
 * \param FILE* pFile Puntero del tipo file al archivo que hay que parsear
 * \param pArrayListEmployee LinkedList* lista donde se van a a guardar los empleados
 * \return Exito=1 y Error=-0
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
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
                ll_add(pArrayListEmployee,pEmployee);
                retorno = 0;
            }
        }
    }
    return retorno;
}
/** \brief Parsea los datos los datos de los empleados al archivo data.csv (modo texto).
 * \param FILE* pFile Puntero del tipo file al archivo que hay que parsear
 * \param pArrayListEmployee LinkedList* lista desde donde se van a a guardar los empleados
 * \return Exito=1 y Error=-0
 */
int parser_SaveToText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* this = NULL;
    int retorno = -1;
    int i = 0;
    char bufferNombre[1024];
    int bufferId = 0;
    char bufferIsEmpty[1024];
    char bufferApellido[1024];
    float bufferSueldo = 0;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        for(i=0; i<1000; i++)
        {
            if(i==0)
            {
                fprintf(pFile,"id;first_name;last_name;is_empty;salary\n");///Agrega la cabecera al archivo de texto
            }
            this = ll_get(pArrayListEmployee,i);
            employee_getNombre(this,bufferNombre);
            employee_getApellido(this,bufferApellido);
            employee_getSueldo(this,&bufferSueldo);
            employee_getIsEmpty(this,bufferIsEmpty);
            employee_getId(this,&bufferId);
            fprintf(pFile,"%d;%s;%s;%s;%.2f\n",bufferId,bufferNombre,bufferApellido,bufferIsEmpty,bufferSueldo);
            retorno = 0;
        }
    }
    return retorno;
}
/** \brief Parsea los datos los datos de los empleados al archivo data.dat (modo texto).
 * \param FILE* pFile Puntero del tipo file al archivo que hay que parsear
 * \param pArrayListEmployee LinkedList* lista desde donde se van a a guardar los empleados
 * \return Exito=1 y Error=-0
 */
int parser_SaveToBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxiliarEmpleado = NULL;
    int retorno = -1;
    int i = 0;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(i != ll_len(pArrayListEmployee))
        {
            auxiliarEmpleado = ll_get(pArrayListEmployee,i);
            if(auxiliarEmpleado != NULL)
            {
                fwrite(auxiliarEmpleado,sizeof(Employee),1,pFile);
            }
            retorno = 0;
            i++;
        }
    }
    return retorno;
}
