#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

typedef struct
{
  char codigoProducto[1024];
  char fecha[30];
  float precioUnitario;
  int idVenta;
  int cantidad;
  char cuit[15];
}Venta;


Venta* venta_new();
void venta_delete();
Venta* venta_newConParametros(char* codigoProducto,char* fecha,char* precioUnitario,char* idVenta,char* unidades);

int venta_setCodigoProducto(Venta* this,char* codigoProducto);
int venta_getCodigoProducto(Venta* this,char* codigoProducto);

int venta_setFecha(Venta* this,char* fecha);
int venta_getFecha(Venta* this,char* fecha);

int venta_setCuit(Venta* this,char* cuit);
int venta_getCuit(Venta* this,char* cuit);

int venta_setPrecioUnitario(Venta* this,float precioUnitario);
int venta_getPrecioUnitario(Venta* this,float* precioUnitario);

int venta_setIdVenta(Venta* this,int idVenta);
int venta_getIdVenta(Venta* this,int* idVenta);

int venta_setCantidad(Venta* this,int cantidad);
int venta_getCantidad(Venta* this,int* cantidad);

int criterioMayorA10000(void* this);
int criterioMayorA20000(void* this);
int venta_mostrar(void* this);
int criterioTV(void* this);


#endif // VENTA_H_INCLUDED
