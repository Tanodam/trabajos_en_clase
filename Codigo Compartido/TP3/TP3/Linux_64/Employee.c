#include "Employee.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validator.h"
#include "utn.h"
#define BUFFER 1024

static int isValidName(char* name)
{
    int retorno = 0;
    int charIngresados = strlen(name);

    if(name != NULL && array_StringCharEsValido(name,charIngresados))
    {
        retorno = 1;
    }
    return retorno;
}

static int isValidHoras(char* horas)//CORREGIR
{
    int retorno = 0;
    int charIngresados = strlen(horas);

    if(horas != NULL && array_StringIntEsValido(horas,charIngresados))
    {
        retorno = 1;
    }
    return retorno;
}

static int isValidSueldo(char* sueldo)//CORREGIR
{
    int retorno = 0;
    int charIngresados = strlen(sueldo);

    if(sueldo != NULL && array_StringIntEsValido(sueldo,charIngresados))
    {
        retorno = 1;
    }
    return retorno;
}

static int isValidId(char* id)//CORREGIR
{
    int retorno = 0;
    int charIngresados = strlen(id);

    if(id != NULL && array_StringIntEsValido(id,charIngresados))
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
/**
*\brief Se recorre array para encontrar elemento por ID
*\param pArray Es el array para recorrer
*\param idIngresado Es ID para encontrar
*\return Retorna el elemento sino retorna NULL
*/
Employee* Employee_getById(void* pArrayListEmployee,int idABuscar)
{
    Employee* retorno = NULL;
    Employee* auxiliarEmpleado;
    int indice;
    int auxiliarID;

    if(pArrayListEmployee != NULL)
    {
        for(indice=0;indice<ll_len(pArrayListEmployee);indice++)//Recorro todo el array hasta el LEN
        {
            auxiliarEmpleado = ll_get(pArrayListEmployee,indice);//Obtengo el elemento del array en posicion indice
            Employee_getId(auxiliarEmpleado,&auxiliarID);//Obtengo el ID del elemento
            if(auxiliarID == idABuscar)
            {
                retorno = auxiliarEmpleado;
                break;
            }
        }
    }
    return retorno;
}

void Employee_delete(Employee* this)
{
    free(this);
}
int input(char* mensaje,char* campo,int size, int (*validacion)(char*))
{
    int retorno = -1;
    int reintentos = 2;

    if(campo != NULL)
    {
        do
        {
            printf("\nIngrese %s: ",mensaje);
            array_getStringAll(campo,size);
            if((*validacion)(campo))//Validar segun tipo
            {
                campo = (char*)realloc(campo,sizeof(char)*strlen(campo));//Ver realloc
                retorno = 0;
                break;
            }
            else
            {
                printf("\nIntente nuevamente");
            }
            reintentos--;
        }while(reintentos > 0);
    }
    return retorno;
}

Employee* Employee_editarEmpleado(void* pArrayListEmployee)
{
    Employee* this = NULL;
    int retorno = -1;
    char bufferID[BUFFER];
    int opcion;
    int idIngresado;;

    if(pArrayListEmployee != NULL && array_getStringInt(bufferID,BUFFER,"\nIngrese el id que hay que buscar","\nERROR! Ingrese un numero",2))
    {
        idIngresado = atoi(bufferID);
        this = Employee_getById(pArrayListEmployee,idIngresado);
        if(this != NULL)
        {
            do
            {
                //employee_show(this);
                printf("\n1) Nombre\n2) Sueldo\n3) Horas trabajadas\n4) Volver");
                utn_getEntero(&opcion,2,"\nIngrese una opcion","\nERROR! Ingrese un numero",1,4);
                switch(opcion)
                {
                    retorno = 0;
                    case 1 :
                        employee_modify(this,"nombre",isValidName,Employee_setNombre);
                        break;
                    case 2 :
                        employee_modify(this,"sueldo",isValidSueldo,Employee_setSueldo);
                        break;
                    case 3 :
                        employee_modify(this,"horas trabajadas",isValidHoras,Employee_setHorasTrabajadas);
                        break;
                    case 4 :
                        break;
                    default :
                        printf("\nOpcion invalida");
                }
            }while(opcion != 4);
        }
        else
        {
            printf("\nID no encontrado");
        }
    }
return retorno;
}
Employee* Employee_newConParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* this;
    this=Employee_new();
    if(isValidName(nombreStr) && isValidHoras(horasTrabajadasStr) && isValidSueldo(sueldoStr))
    {
        Employee_setNombre(this,nombreStr);
        Employee_setId(this,atoi(idStr));
        Employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr));
        Employee_setSueldo(this,atoi(sueldoStr));
        return this;
    }
    else
    {
        printf("\nHubo un error en la carga\n");
        Employee_delete(this);
    }

    return NULL;
}
/**
*\brief Se modifica un campo del elemento
*\param this Es el elemento a modificar
*\param validacion Es el puntero a la funcion de validacion
*\param set Es el puntero a la funcion set del campo
*\return Retorna 0 si logra modificar campo sino retorna -1
*/
int employee_modify(Employee* this, char* mensaje, int (*validacion)(char*),int (*set)(Employee*,char*))
{
    int retorno = -1;
    char option[2];
    char buffer[BUFFER];

    if(this != NULL && mensaje != NULL && validacion != NULL && set != NULL)
    {
        input(mensaje,buffer,BUFFER,(*validacion));
        array_getLetras(option,2,"\nDesea modificar dato? S/N\n","\nError.Dato invalido",2);
        if(buffer != NULL && !strcasecmp("s",option))
        {
            (*set)(this,buffer);
            //employee_show(this);
            retorno = 0;
        }
    }
    else
    {
        printf("\nError");
    }
    return retorno;
}
/**
 * \brief Funcion que carga un empleado desde el teclado
 * \param void* pArrayListEmployee es la lista del array donde se va a cargar
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
Employee* Employee_nuevoEmpleado(void* pArrayListEmployee)
{
    int retorno = -1;
    Employee* this;
    char bufferNombre[BUFFER];
    char bufferHoras[BUFFER];
    char bufferSueldo[BUFFER];
    char bufferID[BUFFER];
    int auxiliarID = Employee_getNextID(pArrayListEmployee);
    sprintf(bufferID,"%d",auxiliarID);///Funcion para pasar el ID de int a buffer para el newConParamentros
    printf("%s",bufferID);
    if(
        !array_getNombre(bufferNombre,1024,"\nIngrese el nombre del empleado\n","ERROR! Nombre invalido!",2)&&
        !array_getStringInt(bufferHoras,1024,"\nIngrese las horas trabajadas del empleado: \n","ERROR! Numero invalido",2)&&
        !array_getStringInt(bufferSueldo,1024,"\nIngrese el sueldo del empleado: \n","ERROR! Numero invalido\n",2)
    )
    {
        this = Employee_newConParametros(bufferID,bufferNombre,bufferHoras,bufferSueldo);
        if(this != NULL)
        {
            retorno = 0;
            ll_add(pArrayListEmployee,this);
        }
        else
        {
            Employee_delete(this);
        }
    }
    return retorno;
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
int Employee_getNextID(void* pArrayListEmployee)
{
    int retorno=-1;
    int index;
    Employee* auxEmployee;
    int auxID;

    if(pArrayListEmployee != NULL)
    {
        for(index=0; index<ll_len(pArrayListEmployee); index++) //Recorro todo el array hasta el LEN
        {
            auxEmployee = ll_get(pArrayListEmployee,index);//Obtengo el elemento del array en posicion index
            Employee_getId(auxEmployee,&auxID);//Obtengo el ID del elemento
        }
        retorno = auxID+1;//Retorno el ID del ultimo elemento más uno
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

