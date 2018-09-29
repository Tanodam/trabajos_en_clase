#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int ID;
    char nombre[21];
    char apellido[21];
    char DNI [11];
    char edad [5];
    int isEmpty;
    int isActive;
}Asociado;

int asociado_inicializarArray(Asociado* pBuffer,int limite);
int asociado_buscarIndiceVacio(Asociado* pBuffer,int limite,int*indice);
int asociado_imprimirListaAsociados(Asociado* pBuffer,int limite);
int asociado_altaPantalla(Asociado* pBuffer,int indice);
int asociado_modificarPantallaPorIndice(Asociado* pBuffer,int indice);
Asociado* asociado_busquedaPorID(Asociado* pBuffer,int limite,int ID);
int asociado_borrarPorID(Asociado* pBuffer,int indice);
int asociado_borrarPorIndice(Asociado* pBuffer,int indice);
int asociado_existeID(Asociado* pBuffer,int limite,int ID);
int asociado_ingresoForzado(Asociado* pBuffer,int limite,char* nombre,char* apellido,char* DNI,char* edad);




#endif // LIB_H_INCLUDED
