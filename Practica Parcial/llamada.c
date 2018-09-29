#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"
#include "llamada.h"
#include "lib.h"


int llamada_inicializarArray(Llamada* pBuffer,int limite){
    int i;
    for(i=0;i<limite;i++){
        pBuffer[i].isEmpty=1;
    }
    return 0;
}
int llamada_buscarIndiceVacio(Llamada* pBuffer,int limite,int*indice){
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++){
        if(pBuffer[i].isEmpty==1){
            *indice=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}
int llamada_imprimirListaLlamadas(Llamada* pBufferLla,int limiteLla, Asociado* pBufferAso, int limiteAso)
{
    int i;

    Asociado* auxiliarAsociado;

    system("clear");
    for(i=0;i<limiteLla;i++){
        if(pBufferLla[i].isEmpty==0 && asociado_busquedaPorID(pBufferAso,limiteAso,pBufferLla[i].asociadoID) != NULL){
           {
            auxiliarAsociado=asociado_busquedaPorID(pBufferAso,limiteAso,pBufferLla[i].asociadoID);
            printf("\nID de llamada: %d",pBufferLla[i].id);
            printf("\tNombre del asociado %s, %s", auxiliarAsociado->nombre, auxiliarAsociado->apellido);
            printf("\tID de asociado: %d",pBufferLla[i].asociadoID);
            printf("\tMotivo de la llamada: %s",pBufferLla[i].motivo);
           }
        }
    }
    return 0;
}
int llamada_obtenerID(){
    static int ID=-1;
    ID++;
    return ID;
}
int llamada_altaLlamada(Llamada* pBuffer,int indice, Asociado* pBufferAso, int limiteAso, int limiteLla){
    int idAux;

    printf("\nIngrese su ID de asociado");
    __fpurge(stdin);
    scanf("%d", &idAux);
    if(!asociado_existeID(pBufferAso,limiteAso,idAux))
    {
    pBuffer[indice].asociadoID=idAux;
    utn_getLetras(pBuffer[indice].motivo,15,3,"Ingrese el motivo de la llamada: ","Error");
    pBuffer[indice].isEmpty=0;
    pBuffer[indice].id=llamada_obtenerID();
    }
    return 0;
}

int llamada_modificarPantallaPorIndice(Llamada* pBuffer,int indice){
//    utn_getLetras(pBuffer[indice].nombre,15,3,"Ingrese el nombre: ","Error");
//    utn_getLetrasYNumeros(pBuffer[indice].direccion,20,"\nIngrese la direccion: ");
//    utn_getLetras(pBuffer[indice].tipo,10,3,"Ingrese el tipo: ","Error");
//    utn_getFloat(&pBuffer[indice].precio,3,"Ingrese el precio","Error intente nuevamente",0,50000);
    return 0;
}
Llamada* llamada_busquedaPorID(Llamada* pBuffer,int limite,int ID){
    int i;
    Llamada* retorno=NULL;
    for (i=0;i<limite;i++){
        if(pBuffer[i].isEmpty==0 && pBuffer[i].id==ID){

            retorno= &pBuffer[i];
            break;
        }
    }
    return retorno;
}
int llamada_borrarPorIndice(Llamada* pBuffer,int indice){
    pBuffer[indice].isEmpty=1;
    return 0;
}
int llamada_existeID(Llamada* pBuffer,int limite,int ID){
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++){
        if(pBuffer[i].id==ID&&pBuffer[i].isEmpty==0){
            retorno=0;
        }
    }
    return retorno;
}
int llamada_ingresoForzado(Llamada* pBuffer,int limite,char* motivo){
    int aux;
    llamada_buscarIndiceVacio(pBuffer,limite,&aux);
    strcpy(pBuffer[aux].motivo,motivo);
    pBuffer[aux].id=llamada_obtenerID();
    pBuffer[aux].isEmpty=0;

    return 0;
}

int llamada_asignarAmbulancia(Llamada* pBuffer, int limiteLla, int indice)
{
    int auxiliarLlamada;
    Llamada* auxiliar;

        printf("\nIngrese su ID de llamada");
    __fpurge(stdin);
    scanf("%d", &auxiliarLlamada);
    if(!llamada_existeID(pBuffer,limite,auxiliarLlamada))
    {
    auxiliar=llamada_busquedaPorID(pBuffer,limite,pBuffer.id);
    utn_getLetrasYNumeros(pBuffer[indice].idAmbulancia,15,"Ingrese el ID de la ambulancia: ");
    strncpy(pBuffer[indice].estado, "CUMPLIDO");
    }
    return 0;


}

