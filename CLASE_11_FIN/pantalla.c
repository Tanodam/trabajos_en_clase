#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"
#include "pantalla.h"

int pan_inicializarArray(Pantalla* pBuffer,int limite){
    int i;
    for(i=0;i<limite;i++){
        pBuffer[i].isEmpty=1;
    }
    return 0;
}
int pan_buscarIndiceVacio(Pantalla* pBuffer,int limite,int*indice){
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
int pan_imprimirListaPantalla(Pantalla* pBuffer,int limite)
{
    int i;
    system("clear");
    for(i=0;i<limite;i++){
        if(pBuffer[i].isEmpty==0){
            printf("\nID: %d",pBuffer[i].ID);
            printf("\tNombre: %s",pBuffer[i].nombre);
            printf("\tDescripcion: %s",pBuffer[i].direccion);
            printf("\tTipo: %s",pBuffer[i].tipo);
            printf("\tTipo: %.2f",pBuffer[i].precio);
        }
    }
    return 0;
}
int pan_obtenerID(){
    static int ID=0;
    return ID++;
}
int pan_altaPantalla(Pantalla* pBuffer,int indice){
    utn_getLetras(pBuffer[indice].nombre,15,3,"Ingrese el nombre de la pantalla: ","Error");
    utn_getLetrasYNumeros(pBuffer[indice].direccion,20,"\nIngrese la direccion: ");
    utn_getLetras(pBuffer[indice].tipo,10,3,"Ingrese el tipo: ","Error");
    utn_getFloat(&pBuffer[indice].precio,3,"Ingrese el precio","Error intente nuevamente",0,50000);
    pBuffer[indice].isEmpty=0;
    pBuffer[indice].ID=pan_obtenerID();
    return 0;
}

int pan_modificarPantallaPorIndice(Pantalla* pBuffer,int indice){
    utn_getLetras(pBuffer[indice].nombre,15,3,"Ingrese el nombre: ","Error");
    utn_getLetrasYNumeros(pBuffer[indice].direccion,20,"\nIngrese la direccion: ");
    utn_getLetras(pBuffer[indice].tipo,10,3,"Ingrese el tipo: ","Error");
    utn_getFloat(&pBuffer[indice].precio,3,"Ingrese el precio","Error intente nuevamente",0,50000);
    return 0;
}
int pan_busquedaPorID(Pantalla* pBuffer,int limite,int ID,int* indiceID){
    int i;
    int retorno=-1;
    for (i=0;i<limite;i++){
        if(pBuffer[i].ID==ID&& pBuffer[i].isEmpty==0){
            *indiceID=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}
int pan_borrarPorIndice(Pantalla* pBuffer,int indice){
    pBuffer[indice].isEmpty=1;
    return 0;
}
int pan_existeID(Pantalla* pBuffer,int limite,int ID){
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++){
        if(pBuffer[i].ID==ID&&pBuffer[i].isEmpty==0){
            retorno=0;
        }
    }
    return retorno;
}
int pan_ingresoForzado(Pantalla* pBuffer,int limite,char* nombre,char*direccion,char* tipo,float precio){
    int aux;
    pan_buscarIndiceVacio(pBuffer,limite,&aux);
    strcpy(pBuffer[aux].nombre,nombre);
    strcpy(pBuffer[aux].tipo,tipo);
    strcpy(pBuffer[aux].direccion,direccion);
    pBuffer[aux].ID=pan_obtenerID();
    pBuffer[aux].isEmpty=0;
    pBuffer[aux].precio=precio;
    return 0;
}
