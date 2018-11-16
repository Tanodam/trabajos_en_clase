#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#include <ctype.h>
#include "array.h"
#include "utn.h"
#include "LinkedList.h"
#include "validator.h"
#define BUFFER 1024
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
*\param char* horas campo a validar
*\return [1] si se valido el campo correctamente - [0] ERROR
*/
static int isValidHoras(char* horas)
{
    int retorno = 0;
    int charIngresados = strlen(horas);

    if(horas != NULL && array_StringIntEsValido(horas, charIngresados))
    {
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

void em_calcularSueldo(void* p)
{
    int retorno = -1;
    int auxHoras = 0;
    int auxSueldo = 0;
    char sueldo[1024];

    empleado_getHorasTrabajadas(p,&auxHoras);
    /*
        - Las primeras 120 horas la hora vale $180
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350*/
    if(auxHoras <= 120)
    {
        auxSueldo = auxHoras * 180;
        sprintf(sueldo,"%d",auxSueldo);
        empleado_setSueldo(p,sueldo);
    }
    else if (auxHoras > 120 && auxHoras <= 160)
    {
        auxSueldo = auxHoras * 240;
        sprintf(sueldo,"%d",auxSueldo);
        empleado_setSueldo(p,sueldo);
    }
    else if (auxHoras > 160 && auxHoras <= 240)
    {
        auxSueldo = auxHoras * 350;
        sprintf(sueldo,"%d",auxSueldo);
        empleado_setSueldo(p,sueldo);
    }

}
///--------------------------------------------------------------ORDENAR-----------------------------------------------------------------------------



///----------------------------------------------------------------------------------------------------------------------------
/**
*\brief Funcion que muestra todos los campos de una estructura
*\param this es el elemento seleccionado para mostrar
*\return [0]= Mostro el elemento - [-1] ERROR
*/
int empleado_mostrar(Empleado* this)
{
    int retorno = -1;
    int auxiliarId = 0;
    char auxiliarNombre[BUFFER];
    int auxiliaHorasTrabajadas;
    int auxiliarSueldo;

    if(this != NULL)
    {
        empleado_getId(this,&auxiliarId);
        if(auxiliarId != -1)
        {
            empleado_getNombre(this,auxiliarNombre);
            empleado_getId(this,&auxiliarId);
            empleado_getHorasTrabajadas(this,&auxiliaHorasTrabajadas);
            empleado_getSueldo(this,&auxiliarSueldo);

            retorno = 0;
            printf("\nID: %d\tNombre: %s\tHoras trabajadas: %dhs\tSueldo: $%d",auxiliarId,auxiliarNombre,auxiliaHorasTrabajadas,auxiliarSueldo);
        }
    }
    return retorno;
}
/**
*\brief Funcion que reserva espacio dinamicamente para el sizeof de Empleado
*\return THIS si se pudo reservar memoria para el empleado
*        NULL si no se pudo reservar memoria
*/
Empleado* Empleado_new()
{
    Empleado* this = NULL;
    this=malloc(sizeof(Empleado));
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
*\param LinkedList* pArrayListEmpleado es la lista que se reccore
*\param int idIngresado es el ID a encontrar
*\return auxiliarEmpleado si encontre el empleado - NULL si no lo encontre
*/
Empleado* Empleado_getById(LinkedList* pArrayListEmpleado,int idIngresado)
{
    Empleado* retorno = NULL;
    Empleado* auxiliarEmpleado;
    int indice = 0;
    int auxiliarID = 0;

    if(pArrayListEmpleado != NULL)
    {
        for(indice=0; indice<ll_len(pArrayListEmpleado); indice++)
        {
            auxiliarEmpleado = ll_get(pArrayListEmpleado,indice);///En cada iteracion me guardo el empleado completo
            empleado_getId(auxiliarEmpleado,&auxiliarID);///Saco el ID del empleado
            if(auxiliarID == idIngresado) /// Comparo ID's
            {
                retorno = auxiliarEmpleado;
                break;
            }
        }
    }
    return retorno;
}
/**
*\brief Funcion que modifica todos los campos de la estructura, ejecuta switch para que el usuario que campo seleccionar
*       se mantiene en funcionamiento hasta que el usuario agote intentos o seleccione 4 = Regresa al menu principal
*\param LinkedList* pArrayListEmpleado es la lista donde se almacenan los empleados
*\return [0]= Exito y [-1]= ERROR
*/
int Empleado_editarEmpleado(void* pArrayListEmpleado)
{
    Empleado* this = NULL;
    int retorno = -1;
    char bufferID[BUFFER];
    int opcion;
    int idIngresado=0;

    if(pArrayListEmpleado != NULL )
    {
        ingresoTeclado("\nIngrese el ID a buscar ","ERROR!",bufferID,BUFFER,isValidId,2); ///Pido el ID y valido que sea un ID valido mediante puntero a la funcion Is ValidId
        idIngresado = atoi(bufferID); ///Casteo el ID a int para usar la funcion getById
        limpiarPantalla();
        this = Empleado_getById(pArrayListEmpleado,idIngresado); ///GGuardo en this el empleado encontrado para editar
        if(this != NULL)
        {
            do
            {
                limpiarPantalla();
                printf("USUARIO ENCONTRADO\n");
                empleado_mostrar(this); ///Muestro el empleado para verificar que sea el hay que modificar
                printf("\n\nSeleccione el campo que desea modificar\n1) Nombre\n2) Horas trabajadas\n3) Sueldo\n4) Volver");
                utn_getEntero(&opcion,3,"\nOpcion: ","\nERROR! Ingrese un numero",1,4);
                retorno = 0;
                switch(opcion)
                {
                case 1 :
                    empleado_modificarEmpleado(this,"\nNOMBRE\n",isValidName,empleado_setNombre);///Pido nombre, valido y seteo en el campo
                    break;
                case 2 :
                    empleado_modificarEmpleado(this,"\nHORAS TRABAJADAS\n",isValidHoras,empleado_setHorasTrabajadas);///Pido horas trabajadas, valido y seteo en el campo
                    break;
                case 3 :
                    empleado_modificarEmpleado(this,"\nSUELDO\n",isValidSueldo,empleado_setSueldo);///Pido sueldo, valido y seteo en el campo
                    break;
                case 4 :
                    break;
                }
            }
            while(opcion != 4);
        }
        else
        {
            printf("\nID no encontrado");
        }
    }
    return retorno;
}
/**
*\brief Funcion que modifica los campos de la estructura
*\param Empleado* this Es el elemento a modificar
*\param char* mensaje a mostrar al usuario
*\param int (*validacion)(char*) puntero a la funcion que validara el campo
*\param int (*set)(Empleado*,char*) puntero a la funcion que setea el campo
*\return [0] = Exito y [-1] ERROR
*/
int empleado_modificarEmpleado(Empleado* this, char* mensaje, int (*validacion)(char*),int (*set)(Empleado*,char*))
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
        else
        {
            printf("\nNO SE GUARDO LA MODIFICACION");
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
Empleado* Empleado_newConParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Empleado* this;
    this=Empleado_new();
    if(isValidName(nombreStr) && isValidHoras(horasTrabajadasStr) && isValidSueldo(sueldoStr) && isValidId(idStr))
    {
        empleado_setNombre(this,nombreStr);
        empleado_setId(this,idStr);
        empleado_setHorasTrabajadas(this,horasTrabajadasStr);
        empleado_setSueldo(this,sueldoStr);
        return this;
    }
    else
    {
        printf("\nHubo un error en la carga\n");
        Empleado_delete(this);
    }

    return NULL;
}
/**
*\brief Libera espacio en memoria ocupado por elemento
*\param tihs Es el elemento a eliminar
*\return Retorna 0 si logra liberar sino retorna -1
*/
int Empleado_delete(Empleado* this)
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
*\param void* pArrayListEmpleado es la lista de elementos de la cual hay que eliminar el elemento indicado
*\return Empleado* arrayEmpleadosBaja es el array del tipo elemento donde se van a guardar los punteros eliminados
*/
int Empleado_eliminarEmpleado(void* pArrayListEmpleado,void* listaEmpleadosBaja)
{
    Empleado* this = NULL;
    int retorno = -1;
    char bufferId[BUFFER];
    int idIngresado;
    char opcion[2];
    int indice;

    if(!ingresoTeclado("\nINGRESE EL ID DEL EMPLEADO A BORRAR ","\nERROR!",bufferId,BUFFER,isValidId,2))
    {
        idIngresado = atoi(bufferId); ///Casteo el ID a int para usar la funcion getById
        this = Empleado_getById(pArrayListEmpleado,idIngresado); ///Guardo el empleado completo
        if(this != NULL)///Valido que se haya encontrado un elemento
        {
            empleado_mostrar(this); ///Ultima verificacion antes de borrar
            array_getLetras(opcion,2,"\nDesea dar de baja? S/N ","\nError",2);
            if(!strcasecmp("s",opcion))
            {
                indice = ll_indexOf(pArrayListEmpleado,this);
                ll_pop(pArrayListEmpleado,indice);
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
/**
 * \brief Funcion que carga un empleado desde el teclado
 * \param void* pArrayListEmpleado es la lista del array donde se va a cargar
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
int Empleado_nuevoEmpleado(void* pArrayListEmpleado)
{
    int retorno = -1;
    Empleado* this = NULL;
    char bufferNombre[BUFFER];
    char bufferHoras[BUFFER];
    char bufferSueldo[BUFFER];
    char bufferID[BUFFER];
    int auxiliarHoras, auxiliarSueldo = 0;
    int auxiliarID = Empleado_getNextID(pArrayListEmpleado);
    sprintf(bufferID,"%d",auxiliarID);///Funcion para pasar el ID de int a buffer para el newConParamentros
    printf("ID: %s",bufferID);
    if(
        !array_getNombre(bufferNombre,1024,"\nINGRESE EL NOMBRE DEL EMPLEADO: \n","ERROR! NOMBRE INVALIDO!",2)&&
        !utn_getEntero(&auxiliarHoras,2,"\nINGRESE LAS HORAS TRABAJADAS DEL EMPLEADO: \n","ERROR! NUMERO INVALIDO",1,10000000)&&
        !utn_getEntero(&auxiliarSueldo,2,"\nINGRESE EL SUELDO DEL EMPLEADO: \n","ERROR! NUMERO INVALIDO\n",1,10000000)
    )
    {
        sprintf(bufferHoras,"%d",auxiliarHoras);///Funcion para pasar las horas de int a buffer para el newConParamentros
        sprintf(bufferSueldo,"%d",auxiliarSueldo);///Funcion para pasar el sueldo de int a buffer para el newConParamentros
        this = Empleado_newConParametros(bufferID,bufferNombre,bufferHoras,bufferSueldo);
        if(this != NULL)
        {
            retorno = 0;
            ll_add(pArrayListEmpleado,this);
        }
        else
        {
            Empleado_delete(this);
        }
    }
    return retorno;
}
/**
 * \brief Funcion hecha en clase para encontrar automaticamente el proximo ID, se recorre todo el Linked List
 *        guardando en cada iteracion el ID del empleado, al final del FOR devuelvo ultimo ID + 1
 * \param void* pArrayListEmpleado lista a reccorer
 * \return int auxiliarID para asignar - [-1] ERROR
 */
int Empleado_getNextID(void* pArrayListEmpleado)
{
    Empleado* auxiliarEmpleado = NULL;
    int retorno = -1;
    int indice = 0;
    int auxiliarID = 0;

    if(pArrayListEmpleado != NULL)
    {
        for(indice=0; indice<ll_len(pArrayListEmpleado); indice++) ///Recorro todo el LinkedList
        {
            auxiliarEmpleado = ll_get(pArrayListEmpleado,indice);///Obtengo cada empleado
            empleado_getId(auxiliarEmpleado,&auxiliarID);///Obtengo el ID del empleado
        }
        retorno = auxiliarID+1;///Devuelvo el ultimo ID encontrado + 1 para asignarlo al proximo
    }
    return retorno;
}
///--------------------------------------------SETTERS----------------------------------------------------------------------------
/**
 * \brief Funcion que setea el campo ID
 * \param Empleado* this Empleado al que se le va a setear el ID
 * \param char* id string del ID a setear, se realiza un atoi antes del seteo
 * \return [0] EXITO - [-1] ERROR
 */
int empleado_setId(Empleado* this,char* id)
{
    int retorno = -1;
    static int proximoId= -1;
    int idToInt = 0;
    idToInt=atoi(id); ///Casteo para cumplir con el campo int de la estructura Empleado

    if(this!=NULL && idToInt==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(idToInt>proximoId)
    {
        proximoId=idToInt;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}
/**
 * \brief Funcion que setea el campo nombre
 * \param Empleado* this Empleado al que se le va a setear el nombre
 * \param char* nombre string del nombre a setear
 * \return [0] EXITO - [-1] ERROR
 */
int empleado_setNombre(Empleado* this,char* nombre)
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
 * \brief Funcion que setea el campo horasTrabajadas
 * \param Empleado* this Empleado al que se le va a setear el horasTrabajadas
 * \param char* horasTrabajadas string de horasTrabajadas a setear, se realiza un atoi antes del seteo
 * \return [0] EXITO - [-1] ERROR
 */
int empleado_setHorasTrabajadas(Empleado* this,char* horasTrabajadas)
{
    int retorno=-1;
    int horasTrabajadasToInt;
    horasTrabajadasToInt = atoi(horasTrabajadas);///Casteo para cumplir con el campo int de la estructura Empleado

    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadasToInt;
        retorno=0;
    }
    return retorno;
}

/**
 * \brief Funcion que setea el campo sueldo
 * \param Empleado* this Empleado al que se le va a setear el sueldo
 * \param char* sueldo string de sueldo a setear, se realiza un atoi antes del seteo
 * \return [0] EXITO - [-1] ERROR
 */
int empleado_setSueldo(Empleado* this,char* sueldo)
{
    int retorno=-1;
    int sueldoToInt=0;
    sueldoToInt=atoi(sueldo);///Casteo para cumplir con el campo int de la estructura Empleado

    if(this!=NULL)
    {
        this->sueldo=sueldoToInt;
        retorno=0;
    }
    return retorno;
}
///--------------------------------------------GETTERS----------------------------------------------------------------------------
/**
 * \brief Funcion que lee el campo sueldo
 * \param Empleado* this Empleado al que se le va a leer el sueldo
 * \param int* sueldo Puntero auxiliar a int donde se va a almacenar la direccion de memoria del campo sueldo del usuario
 * \return [0] EXITO - [-1] ERROR
 */
int empleado_getSueldo(Empleado* this,int* sueldo)
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
 * \param Empleado* this Empleado al que se le va a leer el nombre
 * \param char* nombre string donde se va a almacenar el campo sueldo del nombre
 * \return [0] EXITO - [-1] ERROR
 */
int empleado_getNombre(Empleado* this,char* nombre)
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
 * \brief Funcion que lee el campo id
 * \param Empleado* this Empleado al que se le va a leer el id
 * \param int* id Puntero auxiliar a int donde se va a almacenar la direccion de memoria del campo id del usuario
 * \return [0] EXITO - [-1] ERROR
 */
int empleado_getId(Empleado* this,int* id)
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
 * \param Empleado* this Empleado al que se le va a leer el horasTrabajadas
 * \param int* horasTrabajadas Puntero auxiliar a int donde se va a almacenar la direccion de memoria del campo horasTrabajadas del usuario
 * \return [0] EXITO - [-1] ERROR
 */
int empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}
