#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"

typedef struct {
    int ID;
    char nombre[15];
    char direccion[20];
    char tipo[10];
    int isEmpty;
    float precio;
}Pantalla;

int pan_inicializarArray(Pantalla* pBuffer,int limite);
int pan_buscarIndiceVacio(Pantalla* pBuffer,int limite,int*indice);
int pan_imprimirListaPantalla(Pantalla* pBuffer,int limite);
int pan_obtenerID();
int pan_altaPantalla(Pantalla* pBuffer,int indice);
int pan_modificarPantallaPorIndice(Pantalla* pBuffer,int indice);
int pan_busquedaPorID(Pantalla* pBuffer,int limite,int ID,int* indiceID);
int pan_borrarPorID(Pantalla* pBuffer,int indice);
int pan_borrarPorIndice(Pantalla* pBuffer,int indice);
int pan_existeID(Pantalla* pBuffer,int limite,int ID);
int pan_ingresoForzado(Pantalla* pBuffer,int limite,char* nombre,char*direccion,char* tipo,float precio);
#endif
