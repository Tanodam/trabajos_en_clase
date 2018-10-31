#include "Employee.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validator.h"
#include "utn.h"
#define BUFFER 1024


int static inputTeclado(char* campo, int size)
{
    int retorno = -1;
    if(campo != NULL)
    {
        getStrings(campo,size);
        fflush(stdin);
        retorno = 0;
    }
    return retorno;
}
static int isValidName(char* nombre)
{
    int retorno = 0;
    if(nombre != NULL && validacion_Letras(nombre,strlen(nombre)))
    {
        retorno = 1;
    }
    return retorno;
}
static int isValidHorasTrabajadas(char* horasTrabajadas)
{
    int retorno = 0;
    if(horasTrabajadas != NULL && array_StringIntEsValido(horasTrabajadas,strlen(horasTrabajadas)))
    {
        retorno = 1;
    }
    return retorno;
}
static int isValidSueldo(char* sueldo)
{
    int retorno = 0;
    if(sueldo != NULL && array_StringIntEsValido(sueldo,strlen(sueldo)))
    {
        retorno = 1;
    }
    return retorno;
}
static int isValidID(char* ID)
{
    int retorno = 0;
    if(ID != NULL && array_StringIntEsValido(ID,strlen(ID)))
    {
        retorno = 1;
    }
    return retorno;
}

Employee* Employee_new()
{
    Employee* this;
    this=malloc(sizeof(Employee));
    return this;
}

void Employee_delete(Employee* this)
{
    free(this);
}

Employee* Employee_newConParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* this;
    this=Employee_new();
    if(idStr!=NULL)
    {
        Employee_setNombre(this,nombreStr);
        Employee_setId(this,atoi(idStr));
        Employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr));
        Employee_setSueldo(this,atoi(sueldoStr));
        return this;
    }

    Employee_delete(this);
    return NULL;
}
Employee* Employee_nuevoEmpleado(void* pArrayListEmployee)
{
    Employee* this;
    char bufferNombre[BUFFER];
    char bufferHoras[BUFFER];
    char bufferSueldo[BUFFER];
    int bufferID[BUFFER];
    if(
        !array_getNombre(bufferNombre,1024,"\nIngrese el nombre del empleado\n","ERROR! Nombre invalido!",2)&&
        !array_getStringInt(bufferHoras,1024,"\nIngrese las horas trabajadas del empleado: \n","ERROR! Numero invalido",2)&&
        !array_getStringInt(bufferSueldo,1024,"\nIngrese el sueldo del empleado: \n","ERROR! Numero invalido\n",2)&&
        !array_getStringInt(bufferID,1024,"\nIngrese el ID del empleado: \n","ERROR! Numero invalido\n",2)
        )
    {
        printf("ENTRO 1");
        this = Employee_newConParametros(bufferID,bufferNombre,bufferHoras,bufferSueldo);
        if(this != NULL)
        {
            printf("ENTRO 2");
            ll_add(pArrayListEmployee,this);
        }
        else
        {
            Employee_delete(this);
        }
    }
    return 0;
}

int Employee_setId(Employee* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}

int Employee_getId(Employee* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int Employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int Employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

int Employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}

Employee* Employee_new_AI(char* nombre,int horasTrabajadas,int sueldo)//este no lee de un archivo
{
    Employee* this;
    this = Employee_new();

    if(
        !Employee_setId(this,-1)&&
        !Employee_setNombre(this,nombre)&&
        !Employee_setHorasTrabajadas(this,horasTrabajadas)&&
        !Employee_setSueldo(this,sueldo))
        return this;

    Employee_delete(this);
    return NULL;
}

