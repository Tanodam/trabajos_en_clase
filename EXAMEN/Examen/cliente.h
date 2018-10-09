#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    char nombre[51];
    char apellido[51];
    char cuit[20];
    int idCliente;
    int isEmpty;
}Cliente;
Cliente* cliente_getById(Cliente* array, int len, int id);
int cliente_alta(Cliente* array, int len);
int cliente_modificar(Cliente* array, int len, int reintentos);
int cliente_baja(Cliente* array, int len, void* arrayVentas, int lenVentas, int reintentos);
int cliente_ingresoForzado(Cliente* array, int len, char *nombre, char *apellido, char *cuit);
int cliente_mostrar(Cliente* array, int len);
int cliente_mostrarVentas(Cliente* array, int len, void* arrayVentasVoid, int lenVentas);
int cliente_init(Cliente* array, int len);
#endif

