#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    char apellido[128];
    float sueldo;
    char isEmpty[10];
}Employee;

Employee* employee_new();
Employee* employee_newConParametros(char* idStr,char* nombreStr,char* apellido ,char* sueldoStr, char* isEmpty);

int employee_setId(Employee* this,char* id);
int employee_setNombre(Employee* this,char* isEmpty);
int employee_setisEmpty(Employee* this,char* nombre);
int employee_setApellido(Employee* this,char* apellido);
int employee_setSueldo(Employee* this,char* sueldo);

int employee_getId(Employee* this,int* id);
int employee_getIsEmpty(Employee* this,char* isEmpty);
int employee_getNombre(Employee* this,char* nombre);
int employee_getApellido(Employee* this,char* apellido);
int employee_getSueldo(Employee* this,float* sueldo);

int employee_delete(Employee* this);
int employee_nuevoEmpleado(void* pArrayListEmployee);
int employee_editarEmpleado(void* pArrayListEmployee);
int employee_mostrar(void* this);
int employee_modificarEmpleado(Employee* this, char* mensaje, int (*validacion)(char*),int (*set)(Employee*,char*));
int employee_eliminarEmpleado(void* pArrayListEmployee,void* listaEmpleadosBaja);

int employee_criterioID(void* thisA, void* thisB);
int employee_criterioNombre(void* thisA,void* thisB);
int employee_criterioSueldo(void* thisA, void* thisB);
void seleccionarCriterioOrdenamiento(void* pArrayListEmployee);

int employee_filtrarEmpleadosHoras(void* pElemento);
int employee_reincorporarEmpleado(void* pArrayListEmployee, void* listaEmpleadosBaja);
Employee* employee_copy(Employee* source);
void* employee_subList(void* pArrayLinkedList);
int employee_getNextId();

#endif // employee_H_INCLUDED
