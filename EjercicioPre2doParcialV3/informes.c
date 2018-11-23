
#include "informes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Informes* informes_new()
{
    Informes* this;
    this=malloc(sizeof(Informes));
    return this;
}

void informes_delete(Informes* this)
{
    free(this);
}

Informes* informes_newConParametros(int cantidadUnidadesVendidas,int cantidadVentasMayor10000,int cantidadVentasMayor20000,int cantidadDeTvs)
{
    Informes* this;
    this=informes_new();

    if(
    !informes_setCantidadUnidadesVendidas(this,cantidadUnidadesVendidas)&&
    !informes_setCantidadVentasMayor10000(this,cantidadVentasMayor10000)&&
    !informes_setCantidadVentasMayor20000(this,cantidadVentasMayor20000)&&
    !informes_setCantidadDeTvs(this,cantidadDeTvs))
        return this;

    informes_delete(this);
    return NULL;
}

int informes_setCantidadUnidadesVendidas(Informes* this,int cantidadUnidadesVendidas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidadUnidadesVendidas=cantidadUnidadesVendidas;
        retorno=0;
    }
    return retorno;
}

int informes_getCantidadUnidadesVendidas(Informes* this,int* cantidadUnidadesVendidas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidadUnidadesVendidas=this->cantidadUnidadesVendidas;
        retorno=0;
    }
    return retorno;
}

int informes_setCantidadVentasMayor10000(Informes* this,int cantidadVentasMayor10000)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidadVentasMayor10000=cantidadVentasMayor10000;
        retorno=0;
    }
    return retorno;
}

int informes_getCantidadVentasMayor10000(Informes* this,int* cantidadVentasMayor10000)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidadVentasMayor10000=this->cantidadVentasMayor10000;
        retorno=0;
    }
    return retorno;
}

int informes_setCantidadVentasMayor20000(Informes* this,int cantidadVentasMayor20000)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidadVentasMayor20000=cantidadVentasMayor20000;
        retorno=0;
    }
    return retorno;
}

int informes_getCantidadVentasMayor20000(Informes* this,int* cantidadVentasMayor20000)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidadVentasMayor20000=this->cantidadVentasMayor20000;
        retorno=0;
    }
    return retorno;
}

int informes_setCantidadDeTvs(Informes* this,int cantidadDeTvs)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidadDeTvs=cantidadDeTvs;
        retorno=0;
    }
    return retorno;
}

int informes_getCantidadDeTvs(Informes* this,int* cantidadDeTvs)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidadDeTvs=this->cantidadDeTvs;
        retorno=0;
    }
    return retorno;
}

