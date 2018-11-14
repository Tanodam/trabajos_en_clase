#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#include "LinkedList.h"
#include "Parser.h"

int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados)
{
    FILE* pFile;
    pFile = fopen(fileName, "r");
    Empleado *pEmpleado;
    char string[4096];
    int retorno = -1;
    char* token;
    char bufferNombre[1024];
    char bufferHoras[1024];
    char bufferId[1024];
    char bufferSueldo[1024];


    fgets(string, 4096,fileName);
    do
        {
        fgets(string, 4096,fileName);
        token = strtok(string,",");
        strncpy(bufferId,token,1024);
        token = strtok(NULL,",");
        strncpy(bufferNombre,token,1024);
        token = strtok(NULL,",");
        strncpy(bufferHoras,token,1024);
        token = strtok(NULL,"\n");
        }while(!feof(fileName));

        em_calcularSueldo()
    printf("%s - %s - %s", bufferId,bufferHoras,bufferNombre);
    pEmpleado=empleado_newConParametros(bufferId,bufferNombre,bufferHoras,bufferSueldo);

    fclose(pFile);

    return 1; // OK
}

