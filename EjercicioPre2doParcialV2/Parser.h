#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "LinkedList.h"

int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados);
int parser_SaveToText(char* fileName, LinkedList* pArrayListEmployee);


#endif // PARSER_H_INCLUDED
