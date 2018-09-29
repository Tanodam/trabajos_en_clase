#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"
#include "lib.h"

int asociado_inicializarArray(Asociado* pBuffer,int limite){
    int i;
    for(i=0;i<limite;i++){
        pBuffer[i].isEmpty=1;
    }
    return 0;
}
int asociado_buscarIndiceVacio(Asociado* pBuffer,int limite,int*indice){
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
int asociado_imprimirListaAsociados(Asociado* pBuffer,int limite)
{
    int i;
    system("clear");

    for(i=0;i<limite;i++){
        if(pBuffer[i].isEmpty==0){
            printf("\nID: %d",pBuffer[i].ID);
            printf("\tNombre: %s",pBuffer[i].nombre);
            printf("\tApellido: %s",pBuffer[i].apellido);
            printf("\tDNI: %s",pBuffer[i].DNI);
            printf("\tEdad: %s",pBuffer[i].edad);
        }
    }
    return 0;
}
static int asociado_obtenerID(){
    static int ID=-1;
    ID++;
    return ID;
}
int asociado_altaAsociado(Asociado* pBuffer, int indice){
    utn_getLetras(pBuffer[indice].nombre,15,3,"Ingrese el nombre del asociado: ","Error");
    utn_getLetras(pBuffer[indice].apellido,20,3,"\nIngrese el apellido: ", "Error");
    utn_getLetrasYNumeros(pBuffer[indice].DNI,10,"Ingrese el DNI: ");
    utn_getLetrasYNumeros(pBuffer[indice].edad,4,"Ingrese la edad: ");
    pBuffer[indice].isEmpty=0;
    pBuffer[indice].ID=asociado_obtenerID();
    return 0;
}

int asociado_modificarPantallaPorIndice(Asociado* pBuffer,int indice){
    utn_getLetras(pBuffer[indice].nombre,15,3,"Ingrese el nombre: ","Error");
    utn_getLetras(pBuffer[indice].apellido,15,3,"Ingrese el apellido: ","Error");
    return 0;
}
Asociado* asociado_busquedaPorID(Asociado* pBuffer,int limite,int ID){
    int i;
    Asociado* retorno=NULL;
    for (i=0;i<limite;i++){
        if(pBuffer[i].isEmpty==0 && pBuffer[i].ID==ID){

            retorno= &pBuffer[i];
            break;
        }
    }
    return retorno;
}
int asociado_borrarPorIndice(Asociado* pBuffer,int indice){
    pBuffer[indice].isEmpty=1;
    return 0;
}
int asociado_existeID(Asociado* pBuffer,int limite,int ID){
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++){
        if(pBuffer[i].ID==ID&&pBuffer[i].isEmpty==0){
            retorno=0;
        }
    }
    return retorno;
}
int asociado_ingresoForzado(Asociado* pBuffer,int limite,char* nombre,char* apellido,char* DNI,char* edad){
    int aux;

    asociado_buscarIndiceVacio(pBuffer,limite,&aux);
    pBuffer[aux].ID=asociado_obtenerID();
    strncpy(pBuffer[aux].nombre,nombre,50);
    strncpy(pBuffer[aux].apellido,apellido,50);
    strncpy(pBuffer[aux].edad,edad,4);
    strncpy(pBuffer[aux].DNI,DNI,11);
    pBuffer[aux].isEmpty=0;
    return 0;
}
