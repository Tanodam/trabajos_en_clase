#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "venta.h"
#include <string.h>
#include "validator.h"
#define BUFFER 4096


Venta* venta_new()
{
    Venta* this;
    this=malloc(sizeof(Venta));
    return this;
}

void venta_delete(Venta* this)
{
    free(this);
}

Venta* venta_newConParametros(char* codigoProducto,char* fecha,char* precioUnitario,char* idVenta,char* cantidad)
{
    Venta* this;
    this=venta_new();
    if(array_StringCharEsValido(codigoProducto,30) && array_StringFloatEsValido(precioUnitario,30) &&
            array_StringIntEsValido(idVenta,30) && array_StringIntEsValido(cantidad,30))
    {
        venta_setCodigoProducto(this,codigoProducto);
        venta_setFecha(this,fecha);
        venta_setPrecioUnitario(this,atof(precioUnitario));
        venta_setIdVenta(this,atoi(idVenta));
        venta_setCantidad(this,atoi(cantidad));
        return this;
    }

    venta_delete(this);
    return NULL;
}

int venta_setCodigoProducto(Venta* this,char* codigoProducto)
{
    int retorno=-1;
    if(this!=NULL && codigoProducto!=NULL)
    {
        strcpy(this->codigoProducto,codigoProducto);
        retorno=0;
    }
    return retorno;
}

int venta_getCodigoProducto(Venta* this,char* codigoProducto)
{
    int retorno=-1;
    if(this!=NULL && codigoProducto!=NULL)
    {
        strcpy(codigoProducto,this->codigoProducto);
        retorno=0;
    }
    return retorno;
}

int venta_setFecha(Venta* this,char* fecha)
{
    int retorno=-1;
    if(this!=NULL && fecha!=NULL)
    {
        strcpy(this->fecha,fecha);
        retorno=0;
    }
    return retorno;
}

int venta_getFecha(Venta* this,char* fecha)
{
    int retorno=-1;
    if(this!=NULL && fecha!=NULL)
    {
        strcpy(fecha,this->fecha);
        retorno=0;
    }
    return retorno;
}

int venta_setPrecioUnitario(Venta* this,float precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->precioUnitario=precioUnitario;
        retorno=0;
    }
    return retorno;
}

int venta_getPrecioUnitario(Venta* this,float* precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *precioUnitario=this->precioUnitario;
        retorno=0;
    }
    return retorno;
}


int venta_setIdVenta(Venta* this,int idVenta)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->idVenta=idVenta;
        retorno=0;
    }
    return retorno;
}

int venta_getIdVenta(Venta* this,int* idVenta)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idVenta=this->idVenta;
        retorno=0;
    }
    return retorno;
}

int venta_setCantidad(Venta* this,int cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

int venta_getCantidad(Venta* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}



int venta_setCuit(Venta* this,char* cuit)
{
    int retorno=-1;
    if(this!=NULL && cuit!=NULL)
    {
        strcpy(this->cuit,cuit);
        retorno=0;
    }
    return retorno;
}

int venta_getCuit(Venta* this,char* cuit)
{
    int retorno=-1;
    if(this!=NULL && cuit!=NULL)
    {
        strcpy(cuit,this->cuit);
        retorno=0;
    }
    return retorno;
}

/**
*\brief Funcion que muestra todos los campos de una estructura
*\param this es el elemento seleccionado para mostrar
*\return [0]= Mostro el elemento - [-1] ERROR
*/
int venta_mostrar(void* this)
{
    int retorno = -1;
    int auxiliarId = 0;
    char auxiliarFecha[BUFFER];
    float auxiliaPrecio;
    int auxiliarCantidad;

    if(this != NULL)
    {
        venta_getIdVenta(this,&auxiliarId);
        if(auxiliarId != -1)
        {
            venta_getIdVenta(this,&auxiliarId);
            venta_getPrecioUnitario(this,&auxiliaPrecio);
            venta_getFecha(this,auxiliarFecha);
            venta_getCantidad(this,&auxiliarCantidad);

            retorno = 0;
            printf("%d - %.2f - %s - %d\n", auxiliarId,auxiliaPrecio,auxiliarFecha,auxiliarCantidad);
        }
    }
    return retorno;
}

int criterioTV(void* this)
{
    int retorno = -1;
    char* modeloTV;

    if(this != NULL)
    {
        venta_getCodigoProducto(this,modeloTV);
        if(strcmp(modeloTV, "LCD_TV") == 0)
        {
            retorno = 0;
        }
    }
    return retorno;
}

int criterioUnidades(void* this)
{
    int retorno = 0;
    int unidades = 0;

    if(this != NULL)
    {
        venta_getCantidad(this,&unidades);
        if(unidades > 0)
        {

            retorno = retorno + unidades;
        }
    }
    return retorno;
}

int criterioMayorA10000(void* this)
{
    int retorno = -1;
    float precio = 0;
    int cantidad= 0;
    float montoTotal = 0;

    if(this != NULL)
    {
        venta_getPrecioUnitario(this,&precio);
        venta_getCantidad(this,&cantidad);
        montoTotal = precio*cantidad;

        if(montoTotal > 10000)
        {
            retorno = 0;
        }
    }
    return retorno;
}

int criterioMayorA20000(void* this)
{
    int retorno = -1;
    float precio = 0;
    int cantidad= 0;
    float montoTotal = 0;

    if(this != NULL)
    {
        venta_getPrecioUnitario(this,&precio);
        venta_getCantidad(this,&cantidad);
        montoTotal = precio*cantidad;

        if(montoTotal > 20000)
        {

            retorno = 0;
        }
    }
    return retorno;
}

