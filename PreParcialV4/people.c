#include "people.h"
#include "array.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validator.h"
#include "utn.h"
#define BUFFER 1024

//int static employee_setidDos(Employee* this,char* id);
/**
*\brief Funcion que valida campo
*\param char* name campo a validar
*\return [1] si se valido el campo correctamente - [0] ERROR
*/
static int isValidName(char* name)
{
    int retorno = 0;
    int charIngresados = strlen(name);

    if(name != NULL && array_StringCharEsValido(name,charIngresados))
    {
        name[0]=toupper(name[0]);
        retorno = 1;
    }
    return retorno;
}

/**
*\brief Funcion que valida campo
*\param char* sueldo campo a validar
*\return [1] si se valido el campo correctamente - [0] ERROR
*/
static int isValidSueldo(char* sueldo)
{
    int retorno = 0;
    int charIngresados = strlen(sueldo);

    if(sueldo != NULL && isValidEntero(sueldo,charIngresados))
    {
        retorno = 1;
    }
    return retorno;
}
/**
*\brief Funcion que valida campo
*\param char* id campo a validar
*\return [1] si se valido el campo correctamente - [0] ERROR
*/
static int isValidId(char* id)
{
    int retorno = 0;
    int charIngresados = strlen(id);

    if(id != NULL && isValidEntero(id,charIngresados))
    {
        retorno = 1;
    }
    else
    {
        printf("\nID NO VALIDO");
    }
    return retorno;
}
///--------------------------------------------------------------ORDENAR-----------------------------------------------------------------------------
/**
*\brief Funcion maestra de ordenamiento, ejecuta switch que permite al usuario seleccionar criterio[NOMBRE - SUELDO - ID] y orden [ASCENDENTE - DESCENDENTE]
*\param void* pArrayListEmployee lista de elementos que se va a ordenar
*\return void
*/
void seleccionarCriterioOrdenamiento(void* pArrayListEmployee)
{
    int opcion = 0;
    int orden = -1;
    limpiarPantalla();
    printf("\n******************************\nEL ORDENAMIENTO PUEDE DEMORAR!\n******************************\n");
    utn_getEntero(&opcion,2,"\nSELECCIONE EL CRITERIO DE ORDENAMIENTO\n1. NOMBRE\n2. SUELDO\n3. ID\n4. Volver\n", "\nOPCION INVALIDA\n",1,4);
    if(opcion >= 1 && opcion < 4)
    {
        utn_getEntero(&orden,2,"\nSELECCIONE EL ORDEN \n[1] ASCENDENTE - [0] DESCENDENTE\n", "\nOPCION INVALIDA\n",0,1);

        switch(opcion)
        {
        case 1:
            ll_sort(pArrayListEmployee,employee_criterioNombre,orden);
            printf("\nORDENAMIENTO FINALIZADO");
            break;
        case 2:
            ll_sort(pArrayListEmployee,employee_criterioSueldo,orden);
            printf("\nORDENAMIENTO FINALIZADO");
            break;
        case 3:
            ll_sort(pArrayListEmployee,employee_criterioID,orden);
            printf("\nORDENAMIENTO FINALIZADO");
            break;
        }
    }
}
/**
*\brief Funcion esclava de ordenamiento, compara el campo sueldo
*\param void* thisA elemento A de la estructura que contiene el campo a comparar
*\param void* thisB elemento B de la estructura que contiene el campo a comparar
*\return [1] si thisA->sueldo es mayor a thisB->sueldo
*        [-1] si thisA->sueldo es menor a thisB->sueldo
*        [0] si thisA->sueldo es igual a thisB->sueldo
*/
int employee_criterioSueldo(void* thisA, void* thisB)
{
    int retorno = 0;
    if(((Employee*)thisA)->sueldo > ((Employee*)thisB)->sueldo)
    {
        retorno = 1;
    }
    if(((Employee*)thisA)->sueldo < ((Employee*)thisB)->sueldo)
    {
        retorno = -1;
    }

    return retorno;
}
/**
*\brief Funcion esclava de ordenamiento, compara el campo sueldo
*\param void* thisA elemento A de la estructura que contiene el campo a comparar
*\param void* thisB elemento B de la estructura que contiene el campo a comparar
*\return [1] si thisA->ID es mayor a thisB->ID
*        [-1] si thisA->ID es menor a thisB->ID
*        [0] si thisA->ID es igual a thisB->ID
*/
int employee_criterioID(void* thisA, void* thisB)
{
    int retorno = 0;
    if(((Employee*)thisA)->id > ((Employee*)thisB)->id)
    {
        retorno = 1;
    }
    if(((Employee*)thisA)->id < ((Employee*)thisB)->id)
    {
        retorno = -1;
    }

    return retorno;
}
/**
*\brief Funcion esclava de ordenamiento, compara el campo nombre
*\param void* thisA elemento A de la estructura que contiene el campo a comparar
*\param void* thisB elemento B de la estructura que contiene el campo a comparar
*\return [1] si bufferNombreUno es mayor a bufferNombreDos
*        [-1] si bufferNombreUno es menor a bufferNombreDos
*        [0] si bufferNombreUno es igual a bufferNombreDos
*/
int employee_criterioNombre(void* thisA,void* thisB)
{
    int retorno = 0;
    char bufferNombreUno[BUFFER];
    char bufferNombreDos[BUFFER];

    employee_getNombre(((Employee*)thisA),bufferNombreUno);
    employee_getNombre(((Employee*)thisB),bufferNombreDos);

    if(strcmp(bufferNombreUno,bufferNombreDos) < 0)
    {
        retorno = -1;
    }
    else if(strcmp(bufferNombreUno,bufferNombreDos) > 0)
    {

        retorno = 1;
    }
    return retorno;
}
///----------------------------------------------------------------------------------------------------------------------------
/**
 * \brief Funcion que crea una sublista en base al criterio seleccionado por el usuario
 * \param void* pArrayLinkedList lista a partir de la cual se va a generar la sublista
 * \return [subList] si pudo generar la subliista correctamente - [NULL] ERROR
 */
void* employee_subList(void* pArrayLinkedList)
{
    int option;
    LinkedList* subList = NULL;
    limpiarPantalla();
    utn_getEntero(&option,2,"1. Crear una lista de los primeros 250 empleados\n"
                            "2. Crear una una lista desde el empleado 250 hasta el 500\n"
                            "3. Crear una una lista desde el empleado 500 hasta el 750\n"
                            "4. Crear una una lista desde el empleado 750 hasta el ultimo\n"
                            "5. Salir\nINGRESE EL CRITERIO DESEADO\nOpcion: ", "ERROR! INGRESE UNA OPCION VALIDA (1-5)",1,5);
    switch(option)
    {
        case 1:
            subList = ll_subList(pArrayLinkedList,0,250);
            break;
        case 2:
            subList = ll_subList(pArrayLinkedList,250,500);
            break;
        case 3:
            subList = ll_subList(pArrayLinkedList,500,750);
            break;
        case 4:
            subList = ll_subList(pArrayLinkedList,750,ll_len(pArrayLinkedList));
            break;
        case 5:
            break;
        default:
            break;
    }
    return subList;
}
/**
*\brief Funcion que muestra todos los campos de una estructura
*\param this es el elemento seleccionado para mostrar
*\return [0]= Mostro el elemento - [-1] ERROR
*/
int employee_mostrar(void* this)
{
    int retorno = -1;
    int auxiliarId;
    char auxiliarNombre[BUFFER];
    char auxiliarApellido[BUFFER];
    char auxiliarIsEmpty[BUFFER];
    float auxiliarSueldo = 0;

    if(this != NULL)
    {
            employee_getId(this,&auxiliarId);
            employee_getNombre(this,auxiliarNombre);
            employee_getApellido(this,auxiliarApellido);
            employee_getSueldo(this,&auxiliarSueldo);
            employee_getIsEmpty(this,auxiliarIsEmpty);
            printf("\nID: %d -- %s - %s - %.2f - %s",auxiliarId, auxiliarNombre, auxiliarApellido, auxiliarSueldo, auxiliarIsEmpty);
            retorno = 0;
    }
    return retorno;
}
/**
*\brief Funcion que reserva espacio dinamicamente para el sizeof de Employee
*\return THIS si se pudo reservar memoria para el empleado
*        NULL si no se pudo reservar memoria
*/
Employee* employee_new()
{
    Employee* this = NULL;
    this=malloc(sizeof(Employee));
    if(this != NULL)
    {
        return this;
    }
    else
    {
        printf("\nNo hay mas espacio");
    }
    return this;
}
/**
*\brief Se recorre array para encontrar elemento por ID
*\param LinkedList* pArrayListEmployee es la lista que se reccore
*\param int idIngresado es el ID a encontrar
*\return auxiliarEmpleado si encontre el empleado - NULL si no lo encontre
*/
Employee* employee_getById(LinkedList* pArrayListEmployee,int idIngresado)
{
    Employee* retorno = NULL;
    Employee* auxiliarEmpleado;
    int indice = 0;
    int auxiliarID = 0;

    if(pArrayListEmployee != NULL)
    {
        for(indice=0; indice<ll_len(pArrayListEmployee); indice++)
        {
            auxiliarEmpleado = ll_get(pArrayListEmployee,indice);///En cada iteracion me guardo el empleado completo
            employee_getId(auxiliarEmpleado,&auxiliarID);///Saco el ID del empleado
            if(auxiliarID == idIngresado) /// Comparo ID's
            {
                retorno = auxiliarEmpleado;
                break;
            }
        }
    }
    return retorno;
}
///**
//*\brief Funcion que modifica todos los campos de la estructura, ejecuta switch para que el usuario que campo seleccionar
//*       se mantiene en funcionamiento hasta que el usuario agote intentos o seleccione 4 = Regresa al menu principal
//*\param LinkedList* pArrayListEmployee es la lista donde se almacenan los empleados
//*\return [0]= Exito y [-1]= ERROR
//*/
//int employee_editarEmpleado(void* pArrayListEmployee)
//{
//    Employee* this = NULL;
//    Employee* auxEmpleado;
//    int retorno = -1;
//    char bufferID[BUFFER];
//    int opcion;
//    int idIngresado=0;
//    int index;
//
//    if(pArrayListEmployee != NULL )
//    {
//        ingresoTeclado("\nIngrese el ID a buscar ","ERROR!",bufferID,BUFFER,isValidId,2); ///Pido el ID y valido que sea un ID valido mediante puntero a la funcion Is ValidId
//        idIngresado = atoi(bufferID); ///Casteo el ID a int para usar la funcion getById
//        limpiarPantalla();
//        this = employee_getById(pArrayListEmployee,idIngresado); ///Guardo en this el empleado encontrado para editar
//        index = ll_indexOf(pArrayListEmployee,this); /// Guardo el index el empleado actual para despues pisarlo con el ll_push
//        if(this != NULL && ll_contains(pArrayListEmployee, this))
//        {
//            printf("\nID ENCONTRADO\n");
//            auxEmpleado = employee_copy(this);
//            do
//            {
//                limpiarPantalla();
//                employee_mostrar(auxEmpleado); ///Muestro el empleado para verificar que sea el hay que modificar
//                printf("\n\nSeleccione el campo que desea modificar\n1) Nombre\n2) Horas trabajadas\n3) Sueldo\n4) Volver");
//                utn_getEntero(&opcion,3,"\nOpcion: ","\nERROR! Ingrese un numero",1,4);
//                retorno = 0;
//                switch(opcion)
//                {
//                case 1 :
//                    employee_modificarEmpleado(auxEmpleado,"\nNOMBRE\n",isValidName,employee_setNombre);///Pido nombre, valido y seteo en el campo
//                    break;
//                case 2 :
//                    employee_modificarEmpleado(auxEmpleado,"\nHORAS TRABAJADAS\n",isValidHoras,employee_setHorasTrabajadas);///Pido horas trabajadas, valido y seteo en el campo
//                    break;
//                case 3 :
//                    employee_modificarEmpleado(auxEmpleado,"\nSUELDO\n",isValidSueldo,employee_setSueldo);///Pido sueldo, valido y seteo en el campo
//                    break;
//                case 4 :
//                    ll_set(pArrayListEmployee,index,auxEmpleado);
//                    break;
//                }
//            }
//            while(opcion != 4);
//        }
//        else
//        {
//            printf("\nID NO ENCONTRADO");
//        }
//    }
//    return retorno;
//}
///**
//*\brief Funcion que copia los datos del empleado pasado por parametro en un usuario auxiliar.d
//        [FUNCION CREADA ADREDE PARA PODER USAR LL_SET EN EMPLOYEE_EDITAR]
//*\param Employee* source es el empleado que hay que copiar en Employee* destination
//*\return [0]= Exito y [-1]= ERROR
//*/
//Employee* employee_copy(Employee* source)
//{
//    Employee* destination = employee_new();
//    char id[BUFFER];
//    char horas[BUFFER];
//    char sueldo[BUFFER];
//
//    if(source != NULL)
//    {
//        sprintf(id,"%d",source->id);
//        sprintf(horas,"%d",source->horasTrabajadas);
//        sprintf(sueldo,"%d",source->sueldo);
//        employee_setNombre(destination,source->nombre);
//        employee_setHorasTrabajadas(destination,horas);
//        employee_setSueldo(destination,sueldo);
//        employee_setidDos(destination,id);
//    }
//    return destination;
//}
/**
*\brief Funcion que modifica los campos de la estructura
*\param Employee* this Es el elemento a modificar
*\param char* mensaje a mostrar al usuario
*\param int (*validacion)(char*) puntero a la funcion que validara el campo
*\param int (*set)(Employee*,char*) puntero a la funcion que setea el campo
*\return [0] = Exito y [-1] ERROR
*/
int employee_modificarEmpleado(Employee* this, char* mensaje, int (*validacion)(char*),int (*set)(Employee*,char*))
{
    int retorno = -1;
    char opcion[2];
    char buffer[BUFFER];

    if(this != NULL && mensaje != NULL && validacion != NULL && set != NULL)
    {
        ingresoTeclado(mensaje,"\nERROR en ingreso desde teclado",buffer,BUFFER,(*validacion),2);
        array_getLetras(opcion,2,"\nMODIFICAR DATO? S/N\n","\nERROR!",2);
        if(buffer != NULL && !strcasecmp(opcion,"s"))
        {

            (*set)(this,buffer);

            retorno = 0;
        }
    }
    return retorno;
}
/**
*\brief Funcion que genera un empleado nuevo dinamicamente y guarda todos sus campos mediante la funcion set_campo
*\param char* idStr ID
*\param char* nombreStr Nombre
*\param char* horasTrabajadasStr Horas Trabajadas
*\param char* sueldoStr Sueldo
*\return THIS para realizar el ll_add y NULL si hubo algun error en las validaciones
*/
Employee* employee_newConParametros(char* idStr,char* nombreStr,char* apellidoStr ,char* sueldoStr, char* isEmpty)
{
    Employee* this;
    this=employee_new();
    if(isValidName(nombreStr) && isValidSueldo(sueldoStr) && isValidId(idStr))
    {
        employee_setNombre(this,nombreStr);
        employee_setId(this,idStr);
        employee_setApellido(this,apellidoStr);
        employee_setSueldo(this,sueldoStr);
        employee_setisEmpty(this,isEmpty);
        return this;
    }
    else
    {
        printf("\nHubo un error en la carga\n");
        employee_delete(this);
    }

    return NULL;
}
/**
*\brief Libera espacio en memoria ocupado por elemento
*\param tihs Es el elemento a eliminar
*\return Retorna 0 si logra liberar sino retorna -1
*/
int employee_delete(Employee* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}
/**
*\brief Funcion que elimina un empleado pero mantiene su puntero a la estructura en un array statico de "arrayElementosBaja"
*\param void* pArrayListEmployee es la lista de elementos de la cual hay que eliminar el elemento indicado
*\return Employee* arrayEmpleadosBaja es el array del tipo elemento donde se van a guardar los punteros eliminados
*/
int employee_eliminarEmpleado(void* pArrayListEmployee,void* listaEmpleadosBaja)
{
    Employee* this = NULL;
    int retorno = -1;
    char bufferId[BUFFER];
    int idIngresado;
    char opcion[2];
    int indice;

    if(!ingresoTeclado("\nINGRESE EL ID DEL EMPLEADO A BORRAR ","\nERROR!",bufferId,BUFFER,isValidId,2))
    {
        idIngresado = atoi(bufferId); ///Casteo el ID a int para usar la funcion getById
        this = employee_getById(pArrayListEmployee,idIngresado); ///Guardo el empleado completo
        if(this != NULL && ll_contains(pArrayListEmployee, this))///Valido que se haya encontrado un elemento
        {
            employee_mostrar(this); ///Ultima verificacion antes de borrar
            array_getLetras(opcion,2,"\nDesea dar de baja? S/N ","\nError",2);
            if(!strcasecmp("s",opcion))
            {
                indice = ll_indexOf(pArrayListEmployee,this);
                ll_pop(pArrayListEmployee,indice);
                ll_add(listaEmpleadosBaja,this);
                retorno = 0;
            }
        }
        else
        {
            printf("\nEl ID ingresado no existe");
        }
    }
    return retorno;
}
///**
// * \brief Funcion que carga un empleado desde el teclado
// * \param void* pArrayListEmployee es la lista del array donde se va a cargar
// * \param input Array donde se cargará el texto ingresado
// * \return void
// */
//int employee_nuevoEmpleado(void* pArrayListEmployee)
//{
//    int retorno = -1;
//    Employee* this = NULL;
//    char bufferNombre[BUFFER];
//    char bufferHoras[BUFFER];
//    char bufferSueldo[BUFFER];
//    int auxiliarHoras, auxiliarID, auxiliarSueldo = 0;
//    if(
//        !array_getNombre(bufferNombre,1024,"\nINGRESE EL NOMBRE DEL EMPLEADO: \n","ERROR! NOMBRE INVALIDO!",2)&&
//        !utn_getEntero(&auxiliarHoras,2,"\nINGRESE LAS HORAS TRABAJADAS DEL EMPLEADO: \n","ERROR! NUMERO INVALIDO",1,10000000)&&
//        !utn_getEntero(&auxiliarSueldo,2,"\nINGRESE EL SUELDO DEL EMPLEADO: \n","ERROR! NUMERO INVALIDO\n",1,10000000)
//    )
//    {
//        sprintf(bufferHoras,"%d",auxiliarHoras);///Funcion para pasar las horas de int a buffer para el newConParamentros
//        sprintf(bufferSueldo,"%d",auxiliarSueldo);///Funcion para pasar el sueldo de int a buffer para el newConParamentros
//        this = employee_newConParametros("0",bufferNombre,bufferHoras,bufferSueldo);
//        if(this != NULL)
//        {
//            retorno = 0;
//            employee_getId(this, &auxiliarID);
//            printf("\nID: %d", auxiliarID);
//            ll_add(pArrayListEmployee,this);
//        }
//        else
//        {
//            employee_delete(this);
//        }
//    }
//    return retorno;
//}
/**
 * \brief Funcion que re-incorpora un empleado que esta de baja mediante ll_push
 * \param void* pArrayListEmployee es la lista donde se va a realizar el push
 * \param void* listaEmpleadosBaja es la lista de donde se va a sacar el empleado a re-incorporar
 * \return [0] = Exito [1] = Error
 */
int employee_reincorporarEmpleado(void* pArrayListEmployee, void* listaEmpleadosBaja)
{
    int retorno = -1;
    Employee* auxEmpleadoAnterior;
    Employee* auxEmpleadoAReincorporar;
    int indexAnterior = 0;
    char bufferId[BUFFER];
    int idIngresado = 0;
    char opcion[2];

    if(!ll_isEmpty(listaEmpleadosBaja) && !ll_isEmpty(pArrayListEmployee)&&
            !ingresoTeclado("\nINGRESE EL ID DEL EMPLEADO A REINCORPORAR ","\nERROR!",bufferId,BUFFER,isValidId,2))
    {
        idIngresado = atoi(bufferId);
        auxEmpleadoAReincorporar = employee_getById(listaEmpleadosBaja,idIngresado); ///Obtengo el usuario a reincorporar
        if(ll_contains(listaEmpleadosBaja,auxEmpleadoAReincorporar) && auxEmpleadoAReincorporar != NULL)
        {
            employee_mostrar(auxEmpleadoAReincorporar);
            array_getLetras(opcion,2,"\nDesea re-incorporar? S/N ","\nError",2);
            if(!strcasecmp("s",opcion))
            {
                do
                {
                    auxEmpleadoAnterior = employee_getById(pArrayListEmployee,idIngresado-1);///Busco el empleado anterior en la nomina de acitvos
                    idIngresado--;///Si el empleado anterior es NULL, busco el anterior al anterior.
                   // printf("\nUSUARIO ANTERIOR %p", auxEmpleadoAnterior);
                }
                while(auxEmpleadoAnterior == NULL); ///Itero hasta encontrar un empleado distinto de NULL

                indexAnterior = ll_indexOf(pArrayListEmployee,auxEmpleadoAnterior);///Me guardo el index del empleado anterior encontado
                ll_push(pArrayListEmployee, indexAnterior+1,auxEmpleadoAReincorporar);///Hago un push en el indice del anterior +1 en la nomina de activos
                ll_remove(listaEmpleadosBaja,ll_indexOf(listaEmpleadosBaja,auxEmpleadoAReincorporar));
                retorno = 0;
            }
        }
    }
    return retorno;
}
///--------------------------------------------SETTERS----------------------------------------------------------------------------
///**
// * \brief Funcion que setea el campo ID de manera arcaica, se utiliza en el employee_copy
// * \param Employee* this Empleado al que se le va a setear el ID
// * \param char* id string del ID a setear, se realiza un atoi antes del seteo
// * \return [0] EXITO - [-1] ERROR
// */
//int static employee_setidDos(Employee* this,char* id)
//{
//    int retorno=-1;
//    int idToInt;
//    idToInt = atoi(id);///Casteo para cumplir con el campo int de la estructura Employee
//
//    if(this!=NULL)
//    {
//        this->id=idToInt;
//        retorno=0;
//    }
//    return retorno;
//}
/**
 * \brief Funcion que setea el campo ID
 * \param Employee* this Empleado al que se le va a setear el ID
 * \param char* id string del ID a setear, se realiza un atoi antes del seteo
 * \return [0] EXITO - [-1] ERROR
 */
int employee_setId(Employee* this,char* id)
{
    int retorno = -1;
    static int proximoId= 0;
    int idToInt = 0;
    idToInt=atoi(id); ///Casteo para cumplir con el campo int de la estructura Employee

    if(this!=NULL && idToInt==0)
    {
        proximoId++;
        this->id=
        proximoId;
        retorno = 0;
    }
    else if(idToInt>proximoId)
    {
        proximoId=idToInt;
        this->id=proximoId;
        retorno = 0;
    }
    else if(idToInt<proximoId)
    {
        this->id=idToInt;
        retorno = 0;
    }
    if(idToInt==-1) /// Cuando se borra una lista, hay que resetear el proximoID
    {
        proximoId = 0;
        retorno = 0;
    }
    return retorno;
}
/**
 * \brief Funcion que setea el campo nombre
 * \param Employee* this Empleado al que se le va a setear el nombre
 * \param char* nombre string del nombre a setear
 * \return [0] EXITO - [-1] ERROR
 */
int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}
/**
 * \brief Funcion que setea el campo nombre
 * \param Employee* this Empleado al que se le va a setear el nombre
 * \param char* nombre string del nombre a setear
 * \return [0] EXITO - [-1] ERROR
 */
int employee_setApellido(Employee* this,char* apellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL)
    {
        strcpy(this->apellido,apellido);
        retorno=0;
    }
    return retorno;
}
/**
 * \brief Funcion que setea el campo horasTrabajadas
 * \param Employee* this Empleado al que se le va a setear el horasTrabajadas
 * \param char* horasTrabajadas string de horasTrabajadas a setear, se realiza un atoi antes del seteo
 * \return [0] EXITO - [-1] ERROR
 */
int employee_setisEmpty(Employee* this,char* isEmpty)
{
    int retorno=-1;
    if(this!=NULL && isEmpty!=NULL)
    {
        strcpy(this->isEmpty,isEmpty);
        retorno=0;
    }
    return retorno;
}
/**
 * \brief Funcion que setea el campo sueldo
 * \param Employee* this Empleado al que se le va a setear el sueldo
 * \param char* sueldo string de sueldo a setear, se realiza un atoi antes del seteo
 * \return [0] EXITO - [-1] ERROR
 */
int employee_setSueldo(Employee* this,char* sueldo)
{
    int retorno=-1;
    int sueldoTofloat=0;
    sueldoTofloat=atof(sueldo);///Casteo para cumplir con el campo int de la estructura Employee

    if(this!=NULL)
    {
        this->sueldo=sueldoTofloat;
        retorno=0;
    }
    return retorno;
}
///--------------------------------------------GETTERS----------------------------------------------------------------------------
/**
 * \brief Funcion que lee el campo sueldo
 * \param Employee* this Empleado al que se le va a leer el sueldo
 * \param int* sueldo Puntero auxiliar a int donde se va a almacenar la direccion de memoria del campo sueldo del usuario
 * \return [0] EXITO - [-1] ERROR
 */
int employee_getSueldo(Employee* this,float* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}
/**
 * \brief Funcion que lee el campo nombre
 * \param Employee* this Empleado al que se le va a leer el nombre
 * \param char* nombre string donde se va a almacenar el campo sueldo del nombre
 * \return [0] EXITO - [-1] ERROR
 */
int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}
/**
 * \brief Funcion que lee el campo nombre
 * \param Employee* this Empleado al que se le va a leer el nombre
 * \param char* nombre string donde se va a almacenar el campo sueldo del nombre
 * \return [0] EXITO - [-1] ERROR
 */
int employee_getApellido(Employee* this,char* apellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL)
    {
        strcpy(apellido,this->apellido);
        retorno=0;
    }
    return retorno;
}
/**
 * \brief Funcion que lee el campo id
 * \param Employee* this Empleado al que se le va a leer el id
 * \param int* id Puntero auxiliar a int donde se va a almacenar la direccion de memoria del campo id del usuario
 * \return [0] EXITO - [-1] ERROR
 */
int employee_getId(Employee* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}
/**
 * \brief Funcion que lee el campo horasTrabajadas
 * \param Employee* this Empleado al que se le va a leer el horasTrabajadas
 * \param int* horasTrabajadas Puntero auxiliar a int donde se va a almacenar la direccion de memoria del campo horasTrabajadas del usuario
 * \return [0] EXITO - [-1] ERROR
 */
int employee_getIsEmpty(Employee* this,char* isEmpty)
{
    int retorno=-1;
    if(this!=NULL && isEmpty!=NULL)
    {
        strcpy(isEmpty,this->isEmpty);
        retorno=0;
    }
    return retorno;
}
//int employee_filtrarEmpleadosHoras(void* pElemento)
//{
//    int auxHoras = 0;
//    int filtro = -1;
//    utn_getEntero(&filtro,2,"\nIngrese el numero de horas para hacer el filtro ","ERROR!",0,1000);
//
//    if(pElemento != NULL)
//    {
//        Employee_getHorasTrabajadas(pElemento,&auxHoras);
//        if(auxHoras >= filtro)
//        {
//            return 0;
//        }
//
//    }
//    return 1;
//}
