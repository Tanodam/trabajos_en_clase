#include <stdio.h>
#include <stdlib.h>
#include  "llamada.h"
#include  "lib.h"
#include "utn.h"
#define CANTIDAD_ASOCIADOS 100
#define CANTIDAD_LLAMADAS 1000


int main()
{
    Asociado asociados[CANTIDAD_ASOCIADOS];
    Llamada llamadas[CANTIDAD_LLAMADAS];
    int indiceVacio;
    int opcion;
    int ID;
    asociado_inicializarArray(asociados,CANTIDAD_ASOCIADOS);
    llamada_inicializarArray(llamadas,CANTIDAD_LLAMADAS);


    asociado_ingresoForzado(asociados,CANTIDAD_ASOCIADOS,"Damian","Desario","39387106","22");
    asociado_ingresoForzado(asociados,CANTIDAD_ASOCIADOS,"Leandro","Egea","35328587","31");
    asociado_ingresoForzado(asociados,CANTIDAD_ASOCIADOS,"Gabriel","Saliba","15489357","48");
    asociado_ingresoForzado(asociados,CANTIDAD_ASOCIADOS,"Gabriel", "Gato", "28134836","50");
    llamada_ingresoForzado(llamadas,CANTIDAD_LLAMADAS,"GRIPE");
    llamada_ingresoForzado(llamadas,CANTIDAD_LLAMADAS,"TOS");
    llamada_ingresoForzado(llamadas,CANTIDAD_LLAMADAS,"ACV");
    llamada_ingresoForzado(llamadas,CANTIDAD_LLAMADAS,"MUERTE");

    asociado_imprimirListaAsociados(asociados,CANTIDAD_ASOCIADOS);
//    if(llamada_buscarIndiceVacio(llamadas,CANTIDAD_LLAMADAS,&indiceVacio)==0){
//        llamada_altaLlamada(llamadas,indiceVacio,asociados,CANTIDAD_ASOCIADOS,CANTIDAD_LLAMADAS);
//        }
//        else {
//                printf("\nNo hay mas espacio");
//            }

    llamada_imprimirListaLlamadas(llamadas,CANTIDAD_LLAMADAS,asociados,CANTIDAD_ASOCIADOS);




}
