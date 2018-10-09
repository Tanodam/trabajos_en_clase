#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
int informar_sortClientePorNombreApellido(void* array, int len);
int informar_ventasMayorMenorAfichesNumero(void *arrayVentasVoid, int lenVentas, int *cantidadVentas,int mayorMenor, int numeroAfiches);
int informar_cantidadTotalDeAfiches(void* arrayVentasVoid, int lenVentas, int *cantidadTotalAfiches);
int informar_cantidadTotalDeVentas(void* arrayVentasVoid, int lenVentas, int *cantidadTotalVentas);
int informar_promedioAfichesPorVenta(void* arrayVentasVoid, int lenVentas, float *promedio);
int informar_VentasSuperaOrNoPromedioAfiches(void* arrayVentasVoid,int lenVentas,int *cantidadVentas,int SuperaOrNo);
int informar_mostrarVentaPorEstado(void* arrayVentasVoid, int len, int estado);
int informar_mostrarVentaPorZona(void* arrayVentasVoid, int len, int zona);
int informar_mostrarVentaPorEstadoAndZona(void* arrayVentasVoid, int len, int estado ,int zona);
#endif
