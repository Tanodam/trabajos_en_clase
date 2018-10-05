#ifndef VENTAAFICHES_H_INCLUDED
#define VENTAAFICHES_H_INCLUDED

typedef struct
{
    int id;
    int isEmpty;
    int idCliente;
    char nombreDelArchivo[71];
    char zona[21];
    int cantidad;
    char estadoVenta[11];

}Ventas;

int ventas_inicializarArray(Ventas* array,int limite);
int ventas_buscarIndiceVacio(Ventas* array,int limite,int*indice);
int ventas_venderAfiches(Ventas* arrayVentas, Cliente* arrayClientes, int limiteVentas, int limiteClientes, int idCliente);
int ventas_modificarVentas(Ventas* array,int limite);
Ventas* ventas_busquedaPorID(Ventas* array, int limite, int ID);
void ventas_borrarPorID(Ventas* pBuffer,int limite);
int ventas_imprimirListaVentas(Ventas* array,int limite);
int ventas_ingresoForzado(Ventas* array,int limite,int cantidadAfiches,char* nombreArchivo,char* zona, int idCliente);
int ventas_cerrarVentas(Ventas* arrayVentas, int limiteVentas, Cliente *arrayClientes, int limiteClientes);



#endif // VENTAAFICHES_H_INCLUDED
