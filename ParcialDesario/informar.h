#ifndef INFORMAR_H_INCLUDED
#define INFORMAR_H_INCLUDED

int informar_listaClientesConVentasACobrar(Cliente* arrayClientes, Ventas* arrayVentas, int limiteClientes, int limiteVentas);
int informar_ordenarApellido(Cliente* array, int limite, int orden);
int informar_clienteConMasAfiches(Cliente* arrayClientes, Ventas* arrayVentas, int limiteClientes, int limiteVentas);
int informar_listaClientesConVentasCobradas(Cliente* arrayClientes, Ventas* arrayVentas, int limiteClientes, int limiteVentas);
#endif // INFORMAR_H_INCLUDED
