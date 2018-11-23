#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "venta.h"
#include <string.h>
#include "Controller.h"
#include "parser.h"
#include "utn.h"
#include "informes.h"

int main()
{
    LinkedList* listaVentas= ll_newLinkedList();
    int contador10000 = 0;
    int contador20000 = 0;
    int contadorTV = 0;

    if(!controller_loadFromText("datos.csv",listaVentas))
    {
        contador10000 = ll_count(listaVentas,criterioMayorA10000);
        contador20000 = ll_count(listaVentas,criterioMayorA20000);
        contadorTV = ll_count(listaVentas,criterioTV);
        informe(contador10000,contador20000,contadorTV);
    }


    return 0;

}


