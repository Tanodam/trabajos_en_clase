#ifndef CONTRATACIONES_H_INCLUDED
#define CONTRATACIONES_H_INCLUDED
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"
#include "pantalla.h"
typedef struct {
    int ID;
    char video[15];
    char cuit[10];
    int dias;
    int idPantalla;
    int isEmpty;
}Contratacion;

int con_inicializarArray(Contratacion* pBuffer,int limite);
int con_borrarPorID(Contratacion* pBuffer,int limite,int id);
int con_obtenerID();
int con_contratarPublicidad(Contratacion* pBuffer,int indice,int limite);
int con_imprimirPorCuit(Contratacion* pBuffer,int limite,char* cuit);
int con_modificarPorIdPantalla(Contratacion* pBuffer,int limite,int idPantalla);
int con_cancelarById(Contratacion* pBuffer,int limite,int idPantalla);
int con_imprimirContrataciones(Contratacion* pBuffer,int limite);
int con_listarImportePorContratacion(Contratacion* pBufferCon,Pantalla* pBufferPan,int limiteCon,char* cuit,int limitePan);
int con_ordenarByCuit(Contratacion* pBuffer,int limite,int upOrDonw);
int con_intercambiarPocionEstructura(Contratacion* pBuffer,int indiceDestino,int indiceOrigen);
int con_agruparPosiciones(Contratacion* pBuffer,int limite);
int con_ingresoForzado(Contratacion* pBuffer,int limite,char* video,char* cuit,int dias,int idPantalla);
int con_listarClientesEImportes(Contratacion * pBufferCon,Pantalla* pbufferPan,int limiteCon,int limitePan);
#endif
