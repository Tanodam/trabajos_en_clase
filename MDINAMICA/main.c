#include <stdio.h>
#include <stdlib.h>
#define N_ENTEROS 100

int* new_array(int sizeArray);///Funcion que crea el array
int delete_array(int* array, int limite);///Funcion que lo borra
int cargarDatos(int* array, int limite, int valor); ///Funcion que inicializa el array de enteros
void mostrar(int* array, int limite);///Funcion que imprime lo que esta dentro del array
int* reSize_array(int* array, int limite);

int main()
{
    int* arrayEnteros=NULL;
    arrayEnteros=new_array(N_ENTEROS);

    if(!cargarDatos(arrayEnteros,N_ENTEROS,1))
    {
       mostrar(arrayEnteros,N_ENTEROS);
    }
    reSize_array(arrayEnteros,N_ENTEROS);
    cargarDatos(arrayEnteros,N_ENTEROS,36);
    mostrar(arrayEnteros,205);


    return 0;
}


int* new_array(int sizeArray)
{
    int* retorno=NULL;
    int* auxiliar=(int*)malloc(sizeof(int)*sizeArray);
    if(auxiliar!=NULL && sizeArray>0)
    {
        if(auxiliar!=NULL)
        {
            retorno=auxiliar;
        }
    }
    return retorno;
}

int cargarDatos(int* array, int limite,int valor)
{
    int i=0;
    int retorno=-1;
    if(array!=NULL && limite > 0)
    {
        for(i=0; i<limite; i++)
        {
            *(array+i)=valor;
            retorno=0;
        }
    }
    return retorno;
}



void mostrar(int*array, int limite)
{
    int i;
    if(array!=NULL && limite>0)
    {
        for(i=0; i<limite; i++)
        {
            printf("\n%d.Numero: %d",i+1, *array);
        }
    }
}

int delete_array(int* array, int limite)
{
    int retorno=-1;
    if(array!=NULL && limite>0)
    {
        free(array);
        retorno=0;
    }
    return retorno;
}

int* reSize_array(int* array, int limite)
{
    int* retorno=NULL;
    if(array!=NULL && limite>0)
    {
        retorno=(int*)realloc(array,sizeof(int)*limite);
    }
    return retorno;
}
