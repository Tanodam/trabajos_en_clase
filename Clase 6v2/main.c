#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#define CANTIDAD 10

int main()
{
    char usuario[6];
    char clave[9];
    char auxiliarUsuario[9]="admin\n";
    char auxiliarClave[9]="1234\n";
    int auxtamanio;

    fgets(usuario,, stdin);
    __fpurge(stdin);
    auxtamanio= strlen(usuario);
    printf("El tamaño es %d:", auxtamanio);
   fgets(clave,CANTIDAD, stdin);
    __fpurge(stdin);

    if(strcmp(usuario, auxiliarUsuario)==0 && strcmp(clave, auxiliarClave)==0)
    {
        printf("Ingreso");
    }
    else
    {
        printf("\nUsuario incorrecto");
    }

//    char nombre[CANTIDAD];
//    char apellido[CANTIDAD];
//    char localidad[CANTIDAD];


//    printf("Ingrese su nombre\n");
//    fgets(nombre, CANTIDAD, stdin);
//    printf("El nombre ingresado %s", nombre);

//    fgets(nombre,CANTIDAD, stdin);
//    __fpurge(stdin);
//    fgets(apellido,CANTIDAD, stdin);
//    __fpurge(stdin);
//    fgets(localidad,CANTIDAD, stdin);






    return 0;
}
