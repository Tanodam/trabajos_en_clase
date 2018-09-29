#ifndef LLAMADA_H_INCLUDED
#define LLAMADA_H_INCLUDED
#include "lib.h"
typedef struct {
    int asociadoID;
    char motivo[10];
    char estado[10];
    int id;
    int idAmbulancia;
    int tiempo;
    int isEmpty;
}Llamada;

int llamada_inicializarArray(Llamada* pBuffer,int limite);
int llamada_buscarIndiceVacio(Llamada* pBuffer,int limite,int*indice);
int llamada_imprimirListaLlamadas(Llamada* pBufferLla,int limiteLla, Asociado* pBufferAso, int limiteAso);
int llamada_obtenerID();
int llamada_altaLlamada(Llamada* pBuffer,int indice, Asociado* pBufferAso, int limiteAso, int limiteLla);
int llamada_modificarPantallaPorIndice(Llamada* pBuffer,int indice);
iLlamada* llamada_busquedaPorID(Llamada* pBuffer,int limite,int ID);
int llamada_borrarPorID(Llamada* pBuffer,int indice);
int llamada_borrarPorIndice(Llamada* pBuffer,int indice);
int llamada_existeID(Llamada* pBuffer,int limite,int ID);
int llamada_ingresoForzado(Llamada* pBuffer,int limite,char* motivo);


#endif // LLAMADA_H_INCLUDED
