#ifndef COMPRA_H_INCLUDED
#define COMPRA_H_INCLUDED

typedef struct
{
  char nombreCliente[128];
  int idProducto;
  float precioUnitario;
  int unidades;
  float iva;
  float montoTotal;
}Compra;

int com_calcularMonto(void* p);

Compra* compra_new();
void compra_delete();
Compra* compra_newConParametros(char* nombreCliente,char* idProducto,char* precioUnitario,char* unidades,char* iva);

int compra_setNombreCliente(Compra* this,char* nombreCliente);
int compra_getNombreCliente(Compra* this,char* nombreCliente);

int compra_setIdProducto(Compra* this,char* idProducto);
int compra_getIdProducto(Compra* this,int* idProducto);

int compra_setPrecioUnitario(Compra* this,char* precioUnitario);
int compra_getPrecioUnitario(Compra* this,float* precioUnitario);

int compra_setUnidades(Compra* this,char* unidades);
int compra_getUnidades(Compra* this,int* unidades);

int compra_setIva(Compra* this,char* iva);
int compra_getIva(Compra* this,float* iva);

int compra_setMontoTotal(Compra* this,char* montoTotal);
int compra_getMontoTotal(Compra* this,float* montoTotal);

int criterioId(void* this);


#endif // COMPRA_H_INCLUDED
