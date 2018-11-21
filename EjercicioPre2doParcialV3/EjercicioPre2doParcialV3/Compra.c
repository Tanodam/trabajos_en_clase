#include "Compra.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "array.h"
#include "validator.h"

int com_calcularMonto(void* p)
{
    int retorno = -1;
    float montoTotal = 0;
    float precio= 0;
    float iva = 0;
    int unidades = 0;
    char bufferMontoTotal[1024];

    if(p != NULL && !compra_getIva(p,&iva) && !compra_getPrecioUnitario(p,&precio) && !compra_getUnidades(p,&unidades))
    {
        montoTotal=iva*(precio*unidades)/100;
        sprintf(bufferMontoTotal,"%f",montoTotal);
        compra_setMontoTotal(p,bufferMontoTotal);
        retorno = 0;
    }
    return retorno;
}
/**
*\brief Funcion que valida campo
*\param char* name campo a validar
*\return [1] si se valido el campo correctamente - [0] ERROR
*/
static int isValidName(char* name)
{
    int retorno = 0;
    int charIngresados = strlen(name);

    if(name != NULL && array_StringCharEsValido(name,charIngresados))
    {
        name[0]=toupper(name[0]);
        retorno = 1;
    }
    return retorno;
}
/**
*\brief Funcion que valida campo
*\param char* unidades campo a validar
*\return [1] si se valido el campo correctamente - [0] ERROR
*/
static int isValidUnidades(char* unidades)
{
    int retorno = 0;
    int charIngresados = strlen(unidades);

    if(unidades != NULL && array_StringIntEsValido(unidades, charIngresados))
    {
        retorno = 1;
    }
    return retorno;
}
/**
*\brief Funcion que valida campo
*\param char* precioUnitario campo a validar
*\return [1] si se valido el campo correctamente - [0] ERROR
*/
static int isValidPrecioUnitario(char* precioUnitario)
{
    int retorno = 0;
    int charIngresados = strlen(precioUnitario);

    if(precioUnitario != NULL && array_StringFloatEsValido(precioUnitario,charIngresados))
    {
        retorno = 1;
    }
    return retorno;
}
/**
*\brief Funcion que valida campo
*\param char* precioUnitario campo a validar
*\return [1] si se valido el campo correctamente - [0] ERROR
*/
static int isValidIva(char* iva)
{
    int retorno = 0;
    int charIngresados = strlen(iva);

    if(iva != NULL && array_StringFloatEsValido(iva,charIngresados))
    {
        retorno = 1;
    }
    return retorno;
}
/**
*\brief Funcion que valida campo
*\param char* id campo a validar
*\return [1] si se valido el campo correctamente - [0] ERROR
*/
static int isValidId(char* id)
{
    int retorno = 0;
    int charIngresados = strlen(id);

    if(id != NULL && isValidEntero(id,charIngresados))
    {
        retorno = 1;
    }
    else
    {
        printf("\nID NO VALIDO");
    }
    return retorno;
}
Compra* compra_new()
{
    Compra* this;
    this=malloc(sizeof(Compra));
    return this;
}
void compra_delete(Compra* this)
{
    free(this);
}

Compra* compra_newConParametros(char* nombreCliente,char* idProducto,char* precioUnitario,char* unidades,char* iva)
{
    Compra* this;
    this=compra_new();
    if(isValidName(nombreCliente) && isValidId(idProducto) && isValidPrecioUnitario(precioUnitario) && isValidUnidades(unidades) && isValidIva(iva))
    {
        compra_setNombreCliente(this,nombreCliente);
        compra_setIdProducto(this,idProducto);
        compra_setPrecioUnitario(this,precioUnitario);
        compra_setUnidades(this,unidades);
        compra_setIva(this,iva);
        return this;
    }
    else
    {
        printf("\nHubo un error en la carga\n");
        compra_delete(this);
    }

    return NULL;
}

int compra_setNombreCliente(Compra* this,char* nombreCliente)
{
    int retorno=-1;
    if(this!=NULL && nombreCliente!=NULL && array_StringCharEsValido(nombreCliente,1024))
    {
        strcpy(this->nombreCliente,nombreCliente);
        retorno=0;
    }
    return retorno;
}

int compra_getNombreCliente(Compra* this,char* nombreCliente)
{
    int retorno=-1;
    if(this!=NULL && nombreCliente!=NULL)
    {
        strcpy(nombreCliente,this->nombreCliente);
        retorno=0;
    }
    return retorno;
}

int compra_setIdProducto(Compra* this,char* idProducto)
{
    int retorno = -1;
    static int proximoId= 0;
    int idToInt = 0;
    idToInt=atoi(idProducto); ///Casteo para cumplir con el campo int de la estructura Employee

    if(this!=NULL && idToInt==0)
    {
        proximoId++;
        this->idProducto=proximoId;
        retorno = 0;
    }
    else if(idToInt>proximoId)
    {
        proximoId=idToInt;
        this->idProducto=proximoId;
        retorno = 0;
    }
    else if(idToInt<proximoId)
    {
        this->idProducto=idToInt;
        retorno = 0;
    }
    if(idToInt==-1) /// Cuando se borra una lista, hay que resetear el proximoID
    {
        proximoId = 0;
        retorno = 0;
    }
    return retorno;
}
int compra_getIdProducto(Compra* this,int* idProducto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idProducto=this->idProducto;
        retorno=0;
    }
    return retorno;
}

int compra_setPrecioUnitario(Compra* this,char* precioUnitario)
{
    int retorno=-1;
    float precioToFloat = 0;
    precioToFloat=atof(precioUnitario);
    if(this!=NULL)
    {
        this->precioUnitario=precioToFloat;
        retorno=0;
    }
    return retorno;
}

int compra_getPrecioUnitario(Compra* this,float* precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *precioUnitario=this->precioUnitario;
        retorno=0;
    }
    return retorno;
}

int compra_setUnidades(Compra* this,char* unidades)
{
    int retorno=-1;
    int unidadesToInt = 0;
    unidadesToInt=atof(unidades);
    if(this!=NULL)
    {
        this->unidades=unidadesToInt;
        retorno=0;
    }
    return retorno;
}

int compra_getUnidades(Compra* this,int* unidades)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *unidades=this->unidades;
        retorno=0;
    }
    return retorno;
}

int compra_setIva(Compra* this,char* iva)
{
    int retorno=-1;
    float ivaToFloat = 0;
    ivaToFloat=atof(iva);
    if(this!=NULL)
    {
        this->iva=ivaToFloat;
        retorno=0;
    }
    return retorno;
}

int compra_getIva(Compra* this,float* iva)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *iva=this->iva;
        retorno=0;
    }
    return retorno;
}

int compra_setMontoTotal(Compra* this,char* montoTotal)
{
    int retorno=-1;
    float montoToFloat = 0;
    montoToFloat=atof(montoTotal);
    if(this!=NULL)
    {
        this->montoTotal=montoToFloat;
        retorno=0;
    }
    return retorno;
}

int compra_getMontoTotal(Compra* this,float* montoTotal)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *montoTotal=this->montoTotal;
        retorno=0;
    }
    return retorno;
}
int compra_getById(LinkedList* pArrayListEmployee,int idIngresado)
{
    int retorno = -1;
    Compra* auxiliarCompra;
    int indice = 0;
    int auxiliarID = 0;
    idIngresado = 11;

    if(pArrayListEmployee != NULL)
    {
        for(indice=0; indice<ll_len(pArrayListEmployee); indice++)
        {
            auxiliarCompra = ll_get(pArrayListEmployee,indice);///En cada iteracion me guardo el empleado completo
            compra_getIdProducto(auxiliarCompra,&auxiliarID);///Saco el ID del empleado
            if(auxiliarID == idIngresado) /// Comparo ID's
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
int criterioId(void* this)
{
    int retorno = -1;
    char paramId[1024];
    int elementId;
    static int flag = 0;

    if(this != NULL)
    {
        if(flag == 0)
        {
            ingresoTeclado("Ingrese el el ID que esta buscando ","ERROR",paramId,1024,isValidId,2);
            flag = 1;
        }
        if(!compra_getIdProducto(this,&elementId) && elementId == atoi(paramId))
        {
            retorno = 0;
        }
    }
    return retorno;
}
