#ifndef VENTAAFICHES_H_INCLUDED
#define VENTAAFICHES_H_INCLUDED
#define CABA 1
#define ZONA_SUR 2
#define ZONA_OESTE 3

typedef struct
{
    int id;
    int isEmpty;
    int idCliente;
    char nombreDelArchivo[71];
    int zona;
    int cantidad;
    char estadoVenta[11];

}Ventas;

int ventas_inicializarArray(Ventas* array,int limite);
int ventas_buscarIndiceVacio(Ventas* array,int limite,int*indice);
int ventas_venderAfiches(Ventas* array, int limite, int idCliente);
int ventas_modificarVentas(Ventas* array,int limite);
Ventas* ventas_busquedaPorID(Ventas* array, int limite, int ID);
Ventas* ventas_busquedaPorIDClientes(Ventas* array, int limite, int IDCliente);
void ventas_borrarPorID(Ventas* array,int limite);
int ventas_imprimirListaVentas(Ventas* arrayVentas,int limiteVentas, Cliente* arrayClientes, int limiteClientes);
int ventas_ingresoForzado(Ventas* array,int limite,int cantidadAfiches,char* nombreArchivo,int zona, int idCliente);
int ventas_cerrarVentas(Ventas* arrayVentas, int limiteVentas, Cliente *arrayClientes, int limiteClientes);
int ventas_editarAfiches(Ventas* array, int limite);


#endif // VENTAAFICHES_H_INCLUDED
