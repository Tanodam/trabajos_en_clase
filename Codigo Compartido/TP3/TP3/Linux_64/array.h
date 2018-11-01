#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#define false 0
#define true 1
#define DATO_INVALIDO -1

void myFlush();
void limpiarPantalla();
void pausarPantalla();
char array_getNombre(char* pArray, int limiteArray, char* mensaje, char* mensajeError, int reintentos);
char array_getMail(char* pArray, int limiteArray, char* mensaje, char* mensajeError, int reintentos);
int array_getStringFloat(float* pArray, int limiteArray,int minimo, int maximo, char* mensaje, char* mensajeError, int reintentos);
int array_getStringInt(int* pArray, int limiteArray, char* mensaje, char* mensajeError, int reintentos);
int array_getCuilOrCuit(  char *pDocumento, int limite, char *mensaje,
                        char *mensajeError, int reintentos);
int array_getStringAll(char* input,int size);
int array_getLetras(char* pArray,int limiteArray,char* mensaje,char* msjError,int reintentos);
#endif // ARRAY_H_INCLUDED
