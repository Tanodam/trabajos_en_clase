#include <stdio.h>
#include <stdlib.h>
#include  "pantalla.h"
#include "utn.h"
#include "contrataciones.h"
#include "cliente.h"
#define CANTIDAD_PANTALLAS 100
#define CANTIDAD_CONTRATACIONES 1000
int menu(int*opcion);
int main()
{
    Pantalla pantallas[CANTIDAD_PANTALLAS];
    Contratacion contrataciones [CANTIDAD_CONTRATACIONES];
    int indiceVacio;
    int opcion;
    int ID;
    char cuit[10];
    pan_inicializarArray(pantallas,CANTIDAD_PANTALLAS);
    con_inicializarArray(contrataciones,CANTIDAD_CONTRATACIONES);


    pan_ingresoForzado(pantallas,CANTIDAD_PANTALLAS,"samsung","las piedras","lcd",355);
    pan_ingresoForzado(pantallas,CANTIDAD_PANTALLAS,"sam","las piedras 4430","ldas",654);
    pan_ingresoForzado(pantallas,CANTIDAD_PANTALLAS,"sung","las edras","led",400);
    pan_ingresoForzado(pantallas,CANTIDAD_PANTALLAS,"g","las pied","lfgdfs",800);
    con_ingresoForzado(contrataciones,CANTIDAD_CONTRATACIONES,"peliculas","F4152942",3,0);
    con_ingresoForzado(contrataciones,CANTIDAD_CONTRATACIONES,"peliculas","F4152942",20,1);
    con_ingresoForzado(contrataciones,CANTIDAD_CONTRATACIONES,"revistas","B4152942",5,2);
    con_ingresoForzado(contrataciones,CANTIDAD_CONTRATACIONES,"espectro","34152942",6,0);
    con_ingresoForzado(contrataciones,CANTIDAD_CONTRATACIONES,"horror","34152942",10,1);
    con_ingresoForzado(contrataciones,CANTIDAD_CONTRATACIONES,"XXX","54152942",3,2);
    con_ingresoForzado(contrataciones,CANTIDAD_CONTRATACIONES,"XXX","54152942",40,2);


    Cliente arrayCliente[100];
    cliente_construir(arrayCliente,100,contrataciones,CANTIDAD_CONTRATACIONES);
    cliente_imprimirClientees(arrayCliente,100);


    do{
        menu(&opcion);
        switch (opcion){
            case 1:
                if(pan_buscarIndiceVacio(pantallas,CANTIDAD_PANTALLAS,&indiceVacio)==0){
                    pan_altaPantalla(pantallas,indiceVacio);
                }else {
                    printf("\nNo hay mas espacio");
                }
                break;
            case 2:
                if(utn_getEntero(&ID,3,"\nIngrese el ID de la pantalla a modificar","\nError Intente nuevamente",0,999)==0&&
                    pan_busquedaPorID(pantallas,CANTIDAD_PANTALLAS,ID,&indiceVacio)==0){
                        pan_modificarPantallaPorIndice(pantallas,indiceVacio);
                }else{
                    printf("\nEl ID ingresado no es valido");
                }
                break;
            case 3:
                if(utn_getEntero(&ID,3,"\nIngrese el ID de la pantalla a modificar","\nError Intente nuevamente",0,999)==0&&
                pan_busquedaPorID(pantallas,CANTIDAD_PANTALLAS,ID,&indiceVacio)==0){
                    pan_borrarPorIndice(pantallas,indiceVacio);
                    con_borrarPorID(contrataciones,CANTIDAD_CONTRATACIONES,ID);
                }
                break;
            case 4:
                pan_imprimirListaPantalla(pantallas,CANTIDAD_PANTALLAS);
                if(utn_getEntero(&ID,3,"\nIngrese el ID de la pantalla: ","\nError Ingrese un ID valido: ",0,999)==0&&
                    pan_existeID(pantallas,CANTIDAD_PANTALLAS,ID)==0){
                    con_contratarPublicidad(contrataciones,ID,CANTIDAD_CONTRATACIONES);
                }
                break;
            case 5:
                utn_getLetrasYNumeros(cuit,10,"\nIngrese su CUIT: ");
                if(con_imprimirPorCuit(contrataciones,CANTIDAD_CONTRATACIONES,cuit)==0){
                    utn_getEntero(&ID,0,"\nIngrese el ID de pantalla a modificar","\nError Ingrese un ID valido",0,999);
                    if(con_modificarPorIdPantalla(contrataciones,CANTIDAD_CONTRATACIONES,ID)==-1){
                        printf("\nEl ID ingresado es invalido");
                    }
                }else{
                    printf("\nEl CUIT ingresado es invalido");
                }
                break;
            case 6:
                utn_getLetrasYNumeros(cuit,10,"\nIngrese el CUIT: ");
                if(con_imprimirPorCuit(contrataciones,CANTIDAD_CONTRATACIONES,cuit)==0){
                    utn_getEntero(&ID,0,"\nIngrese el ID de pantalla a borrar","\nError Ingrese un ID valido",0,999);
                    if(con_cancelarById(contrataciones,CANTIDAD_CONTRATACIONES,ID)==-1){
                        printf("\nEl ID ingresado es invalido");
                    }
                }
                break;
            case 7:
                if(utn_getLetrasYNumeros(cuit,10,"\nIngrese el CUIT: ")==0){
                    con_listarImportePorContratacion(contrataciones,pantallas,CANTIDAD_CONTRATACIONES,cuit,CANTIDAD_PANTALLAS);
                    getchar();
                }
                break;
            case 8:
                con_imprimirContrataciones(contrataciones,CANTIDAD_CONTRATACIONES);
                getchar();
                system("clear");
                break;
            case 9:
                pan_imprimirListaPantalla(pantallas,CANTIDAD_PANTALLAS);
                getchar();
                system("clear");
                break;
            case 10:
                con_ordenarByCuit(contrataciones,CANTIDAD_CONTRATACIONES,1);
                con_listarClientesEImportes(contrataciones,pantallas,CANTIDAD_CONTRATACIONES,CANTIDAD_PANTALLAS);
                 getchar();

        }
    }while(opcion!=11);
    return 0;
}
int menu(int*opcion){
    int aux;
        //system("clear");
        printf("1- Alta de pantalla\n");
        printf("2- Modificar datos de pantalla\n");
        printf("3- Borrar Pantalla\n");
        printf("4- Contratar publicidad\n");
        printf("5- Modificar condiciones de publicacion\n");
        printf("6- Cancelar contratacion\n");
        printf("7- Consultar Facturacion\n");
        printf("8- Listar contrataciones\n");
        printf("9- Listar pantallas\n");
        printf("10-Informar\n");
        printf("11- Salir\n");
        utn_getEntero(&aux,10,"\nIngrese una opcion: ","\nError Ingrese Una Opcion Valida",1,11);
        *opcion=aux;
    return 0;
}
