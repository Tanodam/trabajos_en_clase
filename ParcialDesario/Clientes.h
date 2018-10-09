#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct
{
    int id;
    int isEmpty;
    char nombre[51];
    char apellido[51];
    char cuit[15];

}Cliente;

int cliente_inicializarArray(Cliente* array,int limite);
int cliente_buscarIndiceVacio(Cliente* array,int limite,int*indice);
int cliente_altaCliente(Cliente* array,int indice, int limite);
int cliente_modificarCliente(Cliente* array,int limite);
Cliente* cliente_busquedaPorID(Cliente* array, int limite, int ID);
void cliente_borrarPorID(Cliente* pBuffer,int limite);
int cliente_imprimirListaClientes(Cliente* pBuffer,int limite);
int cliente_construirMenu();
int cliente_ingresoForzado(Cliente* array,int limite,char* nombre,char* apellido,char* cuit);
int cliente_ordenarApellidoYSector(Cliente* pBuffer, int limite, int orden);
int cliente_comparacionApellidoYSector(Cliente* cliente1, Cliente* cliente2);



#endif // CLIENTES_H_INCLUDED
