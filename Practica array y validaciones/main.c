#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"
#define STRINGLEN 50
#define LEN 51
#define CANTIDAD 100

 int main()
{
    char miNombre[STRINGLEN];
    char miEdad[STRINGLEN];
    char miCelular[STRINGLEN];
    char miCorreo[STRINGLEN];
    char miApellido [STRINGLEN];
    float edad;


//    if(array_getNombre(miNombre,STRINGLEN,"Ingrese su nombre: ","NOMBRE INVALIDO\n", 3)==0)
//    {
//        printf("El nombre ingresado es %s", miNombre);
//    }
//    if(array_getNombre(miApellido,STRINGLEN,"Ingrese su apellido: ","APELLIDO INVALIDO\n",3)==0)
//    {
//        printf("El apellido ingresado es %s", miApellido);
 //   }
    if(array_getStringFloat(miEdad,STRINGLEN,"Ingrese su edad: ","EDAD INVALIDA\n", 50 )==0)
    {
        edad=atof(miEdad);
        printf("La edad ingresada es %f", edad);
    }
//    if(array_getMail(miCorreo,STRINGLEN,"Ingrese su correo: ","CORREO INVALIDO\n",50 )==0)
//    {
//        printf("El correo ingresado es %s", miCorreo);
//    }
    if(array_getTelefono(miCelular,STRINGLEN,"Ingrese su celular: ","Celular invalido\n", 50 )==0)
    {
        printf("El celular ingresado es %s", miCelular);
    }
}
