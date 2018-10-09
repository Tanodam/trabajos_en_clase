
#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#define CABA 1
#define ZONA_SUR 2
#define ZONA_OESTE 3
#define A_COBRAR 1
#define COBRADA 2

typedef struct
{
    int idCliente;
    int cantidadAfiches;
    char archivoImagen[51];
    int zona;
    int estado;
    int idVenta;
    int isEmpty;
}Venta;

Venta* venta_getById(Venta* array, int len, int id);
Venta* venta_getByIdCliente(Venta* array, int len, int id);
int venta_alta(Venta* arrayVentas, int lenVentas, void* arrayClientesVoid, int lenClientes);
int venta_modificar(Venta* array, int len, int reintentos);
int venta_cobrar(Venta* array, int len, void *arrayClientesVoid,int lenClientes,int reintentos);
int venta_ingresoForzado(Venta* array, int len, int idCliente, int afiches, char *archivo, int zona, int estado);
int venta_mostrar(Venta* array, int len);
int venta_init(Venta* array, int len);
#endif
