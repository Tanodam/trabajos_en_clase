#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

struct S_Empleado
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
};
typedef struct S_Empleado Empleado;

void em_calcularSueldo(void* p);

Empleado* empleado_new();
Empleado* Empleado_newConParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

int empleado_setId(Empleado* this,char* id);
int empleado_setNombre(Empleado* this,char* nombre);
int empleado_setHorasTrabajadas(Empleado* this,char* horasTrabajadas);
int empleado_setSueldo(Empleado* this,char* sueldo);

int empleado_getId(Empleado* this,int* id);
int empleado_getNombre(Empleado* this,char* nombre);
int empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas);
int empleado_getSueldo(Empleado* this,int* sueldo);
int empleado_mostrar(Empleado* this);
int empleado_modificarEmpleado(Empleado* this, char* mensaje, int (*validacion)(char*),int (*set)(Empleado*,char*));
int Empleado_delete(Empleado* this);
int Empleado_getNextID(void* pArrayListEmpleado);

#endif // EMPLEADO_H_INCLUDED
