#include "contrataciones.h"

typedef struct {
    int idCliente;
    char cuit[10];
    int isEmpty;
}Cliente;


int cliente_construir(  Cliente* pCliente,int limiteCliente,
                        Contratacion* pContrataciones,int limiteContrataciones);
Cliente* cliente_getClienteByCuit(Cliente* pBuffer,int limite, char* cuit);

int cliente_imprimirClientees(Cliente* pBuffer,int limite);
