#include <stdio.h>
#include <stdlib.h>
#define CANT_VENTAS 1000
#define CANT_CLIENTES 100
#include "Clientes.h"
#include "ventaAfiches.h"
#include "array.h"

int main()
{

    int retorno = -1;
    int opcionMenu = 1;
    int indiceVacio;
    int auxId;
    int contadorClientes=0;
    int flagDatosCargados=0;
    Cliente* clienteSeleccionado;

    Ventas *ventaSeleccionada;

    Cliente clientes[CANT_CLIENTES];
    Ventas ventas[CANT_VENTAS];

    cliente_inicializarArray(clientes,CANT_CLIENTES);

    cliente_ingresoForzado(clientes,CANT_CLIENTES,"Damian","Desario","20-39387106-8");
    cliente_ingresoForzado(clientes,CANT_CLIENTES,"Pedro","Gomez","24-33655833-4");
    cliente_ingresoForzado(clientes,CANT_CLIENTES,"Gino","Nazzi","22-14071756-9");

    ventas_inicializarArray(ventas,CANT_VENTAS);

    ventas_ingresoForzado(ventas,CANT_VENTAS,3,"Nueva Publicidad","ZONASUR",2);
    ventas_ingresoForzado(ventas,CANT_VENTAS,6,"Burger Kong", "Zona Oeste",1);
    ventas_ingresoForzado(ventas,CANT_VENTAS,14,"Nuevas Abidas HiperSport3", "CABA",0);

    flagDatosCargados=1;
    contadorClientes=3;

    while(retorno!=0)
    {
        limpiarPantalla();
         opcionMenu=cliente_construirMenu();
         switch(opcionMenu)
         {
            case 1:
                if(!cliente_buscarIndiceVacio(clientes, CANT_CLIENTES,&indiceVacio))
                {
                    cliente_altaCliente(clientes,indiceVacio,CANT_CLIENTES);
                    flagDatosCargados=1;
                    pausarPantalla();
                    limpiarPantalla();
                    printf("ALTA EXITOSA! Se genero el cliente con el ID %d", indiceVacio);
                }
                else
                {
                    printf("No hay espacio disponible\n");
                    pausarPantalla();
                }
                break;

            case 2:
                if(flagDatosCargados!=0)
                {
                    array_getStringInt(&auxId,4,"Ingrese el ID que hay que modificar ", "ERROR! Ingrese un numero valido\n", 3);
                    if(cliente_busquedaPorID(clientes,CANT_CLIENTES,auxId)!= NULL)
                    {
                    clienteSeleccionado = cliente_busquedaPorID(clientes,CANT_CLIENTES,auxId);
                    limpiarPantalla();
                    cliente_modificarCliente(clienteSeleccionado,CANT_CLIENTES);
                    printf("\nModificacion realizada\n");
                    pausarPantalla();
                    }
                    else
                    {
                        printf("\nNo existe el ID\n");
                        pausarPantalla();
                    }
                }
                else
                {
                    printf("NO HAY DATOS CARGADOS\n");
                    pausarPantalla();
                }

            break;

            case 3:
                if(flagDatosCargados!=0)
                {
                    array_getStringInt(&auxId,4,"Ingrese el ID que hay que borrar ", "ERROR! Ingrese un numero valido\n", 3);
                    if(cliente_busquedaPorID(clientes,CANT_CLIENTES,auxId)!= NULL)
                    {
                    clienteSeleccionado = cliente_busquedaPorID(clientes,CANT_CLIENTES,auxId);
                    pausarPantalla();
                    limpiarPantalla();
                    cliente_borrarPorID(clienteSeleccionado,CANT_CLIENTES);
                    contadorClientes--;
                    printf("\nEliminacion realizada\n");
                    pausarPantalla();
                    if(!contadorClientes)
                        {   limpiarPantalla();
                            flagDatosCargados=0;
                            printf("Ya no hay usuarios en el sistema\n");
                            pausarPantalla();
                        }
                    }
                    else
                    {
                        printf("No existe el ID\n");
                        pausarPantalla();
                    }
                }
                else
                {
                    printf("NO HAY DATOS CARGADOS\n");
                    pausarPantalla();
                }
                break;

                break;

            case 4:
                if(flagDatosCargados!=0)
                {
                array_getStringInt(&auxId,4,"Ingrese el ID del cliente para vender ", "ERROR! Ingrese un numero valido\n", 3);
                if(cliente_busquedaPorID(clientes,CANT_CLIENTES,auxId)!= NULL && ventas_venderAfiches(ventas,clientes,CANT_VENTAS,CANT_CLIENTES,auxId))
                {
                    printf("No se puedo realizar la venta");
                    pausarPantalla();
                    limpiarPantalla();
                }
                }
                break;
            case 5:
                if(flagDatosCargados!=0)
                {
                    ventas_imprimirListaVentas(ventas,CANT_VENTAS);
                    array_getStringInt(&auxId,4,"Ingrese el ID de la ventaque hay que editar ", "ERROR! Ingrese un numero valido\n", 3);
                    if(ventas_busquedaPorID(ventas,CANT_VENTAS,auxId)!= NULL)
                    {
                    ventaSeleccionada = ventas_busquedaPorID(ventas,CANT_VENTAS,auxId);
                    ventas_editarAfiches(ventas,CANT_VENTAS);
                    pausarPantalla();
                    limpiarPantalla();
                    }
                    else
                    {
                    printf("NO HAY DATOS CARGADOS\n");
                    pausarPantalla();
                    }
                }
                break;
            case 6:
            if(flagDatosCargados!=0)
                {
                    ventas_imprimirListaVentas(ventas,CANT_VENTAS);
                    array_getStringInt(&auxId,4,"Ingrese el ID de la ventaque hay que cerrar ", "ERROR! Ingrese un numero valido\n", 3);
                    if(ventas_busquedaPorID(ventas,CANT_VENTAS,auxId)!= NULL)
                    {
                    ventaSeleccionada = ventas_busquedaPorID(ventas,CANT_VENTAS,auxId);
                    ventas_cerrarVentas(ventas,CANT_VENTAS,clientes,CANT_CLIENTES);
                    pausarPantalla();
                    limpiarPantalla();
                    }
                    else
                    {
                    printf("NO HAY DATOS CARGADOS\n");
                    pausarPantalla();
                    }
                }

                break;
            case 7:
                cliente_imprimirListaClientes(clientes,CANT_CLIENTES);
                limpiarPantalla();
                break;
         }
    }
    return 0;
}
