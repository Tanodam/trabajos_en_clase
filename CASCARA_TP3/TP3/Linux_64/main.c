#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 1;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        switch(option)
        {
            case 1:
                printf("Tamanio de lista :%d\n", ll_len(listaEmpleados));
                controller_loadFromText("data.csv",listaEmpleados);
                printf("Tamanio de lista :%d", ll_len(listaEmpleados));
                option = 6;
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                option = 10;
                break;
            case 3:
                break;
        }
    }while(option != 10);
    return 0;
}
