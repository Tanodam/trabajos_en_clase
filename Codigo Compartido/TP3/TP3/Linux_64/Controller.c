#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo = fopen(path,"r");
    int retorno = -1;
    retorno = parser_EmployeeFromText(pArchivo,pArrayListEmployee);
    fclose(pArchivo);
    if(retorno!=-1)
    {
        printf("Archivo cargado con exito!\nCantidad empleados: %d\n", ll_len(pArrayListEmployee));
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(pArrayListEmployee != NULL)
    {
        if(!Employee_nuevoEmpleado(pArrayListEmployee))
        {
            retorno = 0;
            printf("\nSe agrego un nuevo usuario");
        }
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        if(!Employee_editarEmpleado(pArrayListEmployee))
        {
            printf("\nEl empleado fue modificado");
            retorno = 0;
        }
    }
return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    Employee* auxPunteroEmpleado;
    char nombre[50];
    int horasTrabajadas = 0;
    int sueldo = 0;
    int id=0;
    if(pArrayListEmployee!= NULL)
    {
        retorno = 0;
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            auxPunteroEmpleado = ll_get(pArrayListEmployee,i);
            Employee_getNombre(auxPunteroEmpleado,nombre);
            Employee_getId(auxPunteroEmpleado,&id);
            Employee_getSueldo(auxPunteroEmpleado,&sueldo);
            Employee_getHorasTrabajadas(auxPunteroEmpleado,&horasTrabajadas);
            printf("\nID: %d \t Nombre: %s \t HorasTrabajadas: %d \t Sueldo: %d",id,nombre,horasTrabajadas,sueldo);
        }
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

void controller_init()
{
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        system("clear");
        utn_getEntero(&option,2,"1. Carga de empleados (modo texto)\n"
                      "2. Carga de empleados (modo binario)\n"
                      "3. Alta empleado\n"
                      "4. Modificar empleado\n"
                      "5. Baja empleado\n"
                      "6. Listar empleados\n"
                      "7. Ordenar empleados\n"
                      "8. Guardar empleados (modo texto)\n"
                      "9. Guardar empleados (modo binario)\n"
                      "10. Salir\n","Opcion invalida\n", 1,10);
                      switch(option)
                  {
                      case 1:
                      controller_loadFromText("data.csv",listaEmpleados);
                      break;
                      case 2:
                      controller_loadFromBinary("data.csv",listaEmpleados);
                      break;
                      case 3:
                      controller_addEmployee(listaEmpleados);
                      break;
                      case 4:
                      controller_editEmployee(listaEmpleados);
                      break;
                      case 5:
                      controller_removeEmployee(listaEmpleados);
                      break;
                      case 6:
                      controller_ListEmployee(listaEmpleados);
                      break;
                      case 7:
                      controller_sortEmployee(listaEmpleados);
                      break;
                      case 8:
                      controller_saveAsText("data.csv",listaEmpleados);
                      break;
                      case 9:
                      controller_saveAsBinary("data.csv",listaEmpleados);
                      break;
                      case 10:
                      break;
                      default:
                      printf("Opcion Incorrecta\n");
                      break;
                  }
                      printf("\nPulse Enter para continuar");
                      __fpurge(stdin);
                      getchar();
                  }while(option != 10);
                      return 0;
                  }
