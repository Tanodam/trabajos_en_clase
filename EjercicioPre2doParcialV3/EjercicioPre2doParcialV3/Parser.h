#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "LinkedList.h"

int parser_parseCompras(char* fileName, LinkedList* lista);
int parser_SaveToText(FILE* pFile, LinkedList* pArrayListEmployee);


#endif // PARSER_H_INCLUDED
