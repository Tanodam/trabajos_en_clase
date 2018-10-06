#include <stdio.h>
#include <stdlib.h>
#define CANT_VENTAS 1000
#define CANT_CLIENTES 100
#include "Clientes.h"
#include "ventaAfiches.h"
#include "array.h"
#include "informar.h"

int main()
{

    int retorno = -1;
    int opcionMenu = 1;
    int indiceVacio;
    int auxId;
    int contadorClientes=0;
    int flagDatosCargados=0;
    Cliente* clienteSeleccionado;
    Ventas* ventaSeleccionada;

    Cliente clientes[CANT_CLIENTES];
    Ventas ventas[CANT_VENTAS];

    cliente_inicializarArray(clientes,CANT_CLIENTES);
    ventas_inicializarArray(ventas,CANT_VENTAS);

    cliente_ingresoForzado(clientes,CANT_CLIENTES,"Damian","Desario","20-39387106-8");
    cliente_ingresoForzado(clientes,CANT_CLIENTES,"Pedro","Gomez","24-33655833-4");
    cliente_ingresoForzado(clientes,CANT_CLIENTES,"Gino","Nazzi","22-14071756-9");


    ventas_ingresoForzado(ventas,CANT_VENTAS,3,"Nueva Publicidad","ZONASUR",2);
    ventas_ingresoForzado(ventas,CANT_VENTAS,3,"Vieja Publicidad","ZONAESTE",2);
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
                    contadorClientes++;
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
                    array_getStringInt(&auxId,4,"Ingrese el ID que hay que borrar y sus ventas ", "ERROR! Ingrese un numero valido\n", 3);
                    if(cliente_busquedaPorID(clientes,CANT_CLIENTES,auxId)!= NULL && ventas_busquedaPorIDClientes(ventas,CANT_VENTAS,auxId))
                    {
                    clienteSeleccionado = cliente_busquedaPorID(clientes,CANT_CLIENTES,auxId);
                    ventaSeleccionada = ventas_busquedaPorIDClientes(ventas,CANT_VENTAS,auxId);
                    cliente_borrarPorID(clienteSeleccionado,1);
                    ventas_borrarPorID(ventaSeleccionada,1);
                    contadorClientes--;
                    printf("\nEliminacion realizada\n");
                    pausarPantalla();
                    if(!contadorClientes)
                        {   limpiarPantalla();
                            flagDatosCargados=0;
                            printf("Ya no hay clientes en el sistema\n");
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
            case 4:
                if(flagDatosCargados!=0)
                {
                    array_getStringInt(&auxId,4,"Ingrese el ID del cliente para vender ", "ERROR! Ingrese un numero valido\n", 3);
                    if(cliente_busquedaPorID(clientes,CANT_CLIENTES,auxId)!= NULL &&
                        !ventas_venderAfiches(ventas,CANT_VENTAS,auxId))
                    {
                        break;
                    }
                    else
                    {
                        printf("No se encontro el ID\n");
                        pausarPantalla();
                        break;
                    }
                }
                else
                {
                    printf("NO HAY DATOS CARGADOS\n");
                    pausarPantalla();
                    break;
                }
            case 5:
                if(flagDatosCargados!=0)
                {
                ventas_imprimirListaVentas(ventas,CANT_VENTAS,clientes,CANT_CLIENTES);
                array_getStringInt(&auxId,4,"Ingrese el ID de la ventaque hay que editar ", "ERROR! Ingrese un numero valido\n", 3);
                if(ventas_busquedaPorID(ventas,CANT_VENTAS,auxId)!= NULL)
                {
                    ventaSeleccionada = ventas_busquedaPorID(ventas,CANT_VENTAS,auxId);
                    ventas_editarAfiches(ventaSeleccionada,1);
                    pausarPantalla();
                    limpiarPantalla();
                    break;
                }
                }
                else
                {
                    printf("NO HAY DATOS CARGADOS\n");
                    pausarPantalla();
                }
                break;
            case 6:
            if(flagDatosCargados!=0)
            {
                ventas_imprimirListaVentas(ventas,CANT_VENTAS,clientes,CANT_CLIENTES);
                array_getStringInt(&auxId,4,"Ingrese el ID de la ventaque hay que cerrar ", "ERROR! Ingrese un numero valido\n", 3);
                if(ventas_busquedaPorID(ventas,CANT_VENTAS,auxId)!= NULL)
                {
                    ventaSeleccionada = ventas_busquedaPorID(ventas,CANT_VENTAS,auxId);
                    ventas_cerrarVentas(ventaSeleccionada,CANT_VENTAS,clientes,CANT_CLIENTES);
                    limpiarPantalla();
                    break;
                }
            }
            else
            {
                printf("NO HAY DATOS CARGADOS\n");
                pausarPantalla();
            }

            break;
            case 7:
            if(flagDatosCargados!=0)
            {
                informar_ordenarApellido(clientes,CANT_CLIENTES,0);
                cliente_imprimirListaClientes(clientes,CANT_CLIENTES);
                //informar_clienteConMasAfiches(clientes,ventas,CANT_CLIENTES,CANT_VENTAS);
                //informar_listaClientesConVentasACobrar(clientes,ventas,CANT_CLIENTES,CANT_VENTAS);
                limpiarPantalla();
                break;
            }
                else
            {
                printf("NO HAY DATOS CARGADOS\n");
                pausarPantalla();
            }
            case 8:
            retorno = 0;
         }
    }
   return retorno;
}
