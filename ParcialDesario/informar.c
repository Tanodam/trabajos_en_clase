#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Clientes.h"
#include "ventaAfiches.h"
#include "array.h"


int informar_listaClientesConVentasACobrar(Cliente* arrayClientes, Ventas* arrayVentas, int limiteClientes, int limiteVentas)
{
    int retorno=-1;
    int i, j;
    int contadorVentasACobrar=0;

    if(arrayClientes != NULL && arrayVentas != NULL)
    {
        for (i=0; i<limiteClientes; i++)
        {
            if(arrayClientes[i].isEmpty==0)
            {
                contadorVentasACobrar=0;
                for(j=0; j<limiteVentas; j++)
                {
                    if(arrayVentas[j].idCliente == arrayClientes[i].id && // Para cambiar criterio de busqueda en alguna venta modificar el strcmp
                            strcmp(arrayVentas[j].estadoVenta, "A COBRAR")==0)
                    {
                        contadorVentasACobrar++;

                    }
                }

                        printf("\nID: %d",arrayClientes[i].id);
                        printf("\nNombre: %s, %s",arrayClientes[i].nombre, arrayClientes[i].apellido);
                        printf("\nCuit: %s",arrayClientes[i].cuit);
                        printf("\nCantidad de ventas a cobrar: %d\n",contadorVentasACobrar);
            }

        }


    }
    pausarPantalla();
    retorno = 0;
    return retorno;
}
