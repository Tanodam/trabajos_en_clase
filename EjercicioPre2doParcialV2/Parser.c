#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#include "LinkedList.h"
#include "Parser.h"
#define BUFFERSTR 2000

int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados)
{
    FILE* pFile;
    pFile = fopen(fileName, "r");
    Empleado *pEmpleado;
    char string[2000];
    char bufferNombre[1024];
    char bufferHoras[1024];
    char bufferId[1024];
    char bufferSueldo[1024];


    if(pFile != NULL)
    {
    fgets(string,sizeof(string),pFile);
        while(!feof(pFile))
        {
            fgets(string,sizeof(string),pFile);
            if(strlen(string) > 5)
            {
                strncpy(bufferId,strtok(string, ","),1024);
                strncpy(bufferNombre,strtok(NULL,","),1024);
                strncpy(bufferHoras,strtok(NULL,"\n"),1024);
                pEmpleado = Empleado_newConParametros(bufferId,bufferNombre,bufferHoras,"0");
                //printf("%s - %s - %s - %s\n", bufferId,bufferNombre,bufferHoras,bufferSueldo);

                if(pEmpleado != NULL)
                {
                    ll_add(listaEmpleados,pEmpleado);
                }
            }
        }


    }
    fclose(pFile);



    return 1; // OK
}

