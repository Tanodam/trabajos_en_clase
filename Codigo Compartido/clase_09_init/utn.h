#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

int utn_getNombre(  char* pNombre, int limite, char* msg,
                    char* msgErr, int reintentos);

int getInt(char mensaje[]);

int utn_getNumeroConComa(float* pResultado,
                char mensaje[],
                char mensajeError[],
                float  minimo,
                float  maximo,
                int  reintentos);

int utn_getDescription(  char* pDescription, int size, char* msg,
                    char* msgErr, int reintentos);

#endif // UTN_H_INCLUDED
