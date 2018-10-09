#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct sEmpleado
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}Empleado;

void empleado_initArrayEmpleado(Empleado arrayempleado[],int size,int valor);

int empleado_altaArray(Empleado arrayempleado[],int indice,int size);

int empleado_mostrarArray(Empleado arrayempleado[],int indice,int size);

void empleado_mostrarArrayCompleto(Empleado arrayempleado[],int size);

int empleado_buscarIndiceArray(Empleado arrayempleado[],int size);

int empleado_buscarIndiceArrayById(Empleado arrayempleado[],int id, int size);

int empleado_modificar(Empleado arrayempleado[],int indice,int size);

int empleado_bajaLogica(Empleado arrayempleado[],int indice,int size);


#endif // ARRAYEMPLOYEES_H_INCLUDED
