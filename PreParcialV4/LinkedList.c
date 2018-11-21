#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int i;
    if(this != NULL && ll_len(this) > 0 && nodeIndex >= 0 && nodeIndex < ll_len(this))
    {
        pNode = this->pFirstNode;
        for(i=0; i<nodeIndex; i++)
        {
            pNode = pNode->pNextNode;
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* newNode = (Node*)malloc(sizeof(Node)*1);//variable auxiliar
    Node* currentNode;
    Node* previousNode;

    if(this!= NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this) )
    {
        if((this->pFirstNode == NULL || this->pFirstNode != NULL) &&
                (nodeIndex == 0 ))//Se realiza el add en el primer lugar, estando vacio o no
        {
            //El Tempranero y El Correcto
            previousNode = this->pFirstNode;//Se copia el primer nodo en variable auxiliar
            this->pFirstNode = newNode;//Se enlaza NUEVO NODO al comienzo de la LinkedList

            newNode->pNextNode = previousNode;//Se enlaza el viejo primer nodo al next del nuevo nodo
            newNode->pElement = pElement;

            this->size = ll_len(this) + 1;

            returnAux = 0;
        }
        else if((this->pFirstNode != NULL || this->pFirstNode == NULL)
                && (nodeIndex > 0 && nodeIndex <= ll_len(this)))//Se realiza el add en el index
        {
            //El Sanguchito y El Colado
            currentNode = getNode(this,nodeIndex);//Get del NODO a reemplazar
            previousNode = getNode(this,nodeIndex-1);//Get del NODO anterior al que reemplazo

            newNode->pNextNode = currentNode;//Muevo el NODO del INDICE al siguiente del NUEVO NODO
            newNode->pElement = pElement;//Asigno elemento
            previousNode->pNextNode = newNode;//Asigno al NODO ANTERIOR el NUEVO NODO como siguiente

            this->size = ll_len(this) + 1;

            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
        addNode(this,ll_len(this),pElement);
        returnAux = 0;

    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* auxNode = NULL;

    if(this != NULL && ll_len(this) > 0 && index >= 0 && index < ll_len(this))
    {
        auxNode = getNode(this,index);
        returnAux = auxNode->pElement;
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* auxNode = NULL;
    if(this != NULL && index >= 0 && index < ll_len(this) && ll_len(this) > 0)
    {
        auxNode = getNode(this,index);
        auxNode->pElement = pElement;
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* auxNode;
    Node* currentNode;
    Node* previousNode;

    if(this!= NULL && index >= 0 && index < ll_len(this) )
    {
        if(this->pFirstNode != NULL && index == 0)//Nodo al comienzo
        {
            auxNode = this->pFirstNode;//Se copia el primer nodo
            this->pFirstNode = auxNode->pNextNode;//Se enlaza al next del primer nodo

            free(auxNode);//Se elimina el primer nodo
            this->size = ll_len(this) - 1;

            returnAux = 0;
        }
        else if(this->pFirstNode != NULL && index > 0 && index <= ll_len(this))//Medio
        {
            currentNode = getNode(this,index);//Se copia el nodo del index
            previousNode = getNode(this,index-1);//Se copia el nodo previo al index
            previousNode->pNextNode = currentNode->pNextNode;//Se enlaza el anterior con el next del index

            free(currentNode);//Se elimina el nodo del index
            this->size = ll_len(this) - 1;

            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i = 0;

    if(this != NULL)
    {
        for(i=ll_len(this)-1; i >= 0; i--)
        {
            ll_remove(this,i);
        }
        returnAux = 0;
    }
    return returnAux;
}
/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        free(this);
        this->size = 0;
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i = 0;
    Node* auxNode = NULL;
    if(this != NULL)
    {
        for(i=0; i<ll_len(this); i++)
        {
            auxNode = getNode(this,i);
            if(auxNode->pElement==pElement)
            {
                returnAux=i;
                break;
            }
        }
    }

    return returnAux;
}
/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        if(ll_len(this) == 0)
        {
            returnAux = 1;
        }
        else if(ll_len(this) >= 0)
        {
            returnAux = 0;
        }

    }

    return returnAux;
}
/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
        addNode(this,index,pElement);
        returnAux = 0;
    }


    return returnAux;
}
/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        returnAux = ll_get(this,index);
        ll_remove(this,index);
    }
    return returnAux;
}
/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i = 0;
    Node* auxNode = NULL;
    if(this != NULL)
    {
        returnAux = 0;
        for(i=0; i<ll_len(this); i++)
        {
            auxNode = getNode(this,i);
            if(pElement == auxNode->pElement)
            {
                returnAux = 1;
                break;
            }
        }
    }

    return returnAux;
}
/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i = 0;
    int j = 0;
    if(this != NULL && this2 != NULL)
    {
        returnAux = 1;
        for (i=0; i<ll_len(this); i++)
        {
            if((!ll_contains(this,getNode(this2,j)->pElement)))
            {
                returnAux = 0;
                break;
            }
            j++;
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    Node* auxNode = NULL;
    int i = 0;

    if(this != NULL && from >= 0 && from < ll_len(this) && to >= 0 && to <= ll_len(this))
    {
        cloneArray = ll_newLinkedList();
        for(i=from ; i<=to ; i++)
        {
            auxNode = ll_get(this, i);
            ll_add(cloneArray,auxNode);

        }
    }
    return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    Node* auxNode = NULL;
    int i = 0;
    if(this != NULL)
    {
        cloneArray = ll_newLinkedList();
        for(i=0; i<ll_len(this); i++)
        {
            auxNode = ll_get(this,i);
            ll_add(cloneArray,auxNode);
        }
    }

    return cloneArray;
}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 *         En base al retorno de la funcion criterio y el orden se realiza el swap
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    int i;
    int size=ll_len(this);
    int flagSwap;
    void* thisElementoUno;
    void* thisElementoDos;
    int retornoCriterio;


    if(this != NULL && size > 0 && pFunc != NULL && (order == 1 || order == 0))
    {
        do
        {
            flagSwap = 0;
            for(i=0; i<size; i++)
            {
                thisElementoUno =ll_get(this,i);
                thisElementoDos = ll_get(this,i+1);
                if(thisElementoUno != NULL && thisElementoDos != NULL)
                {
                    retornoCriterio = pFunc(thisElementoUno, thisElementoDos);
                    if((order == 0 && retornoCriterio == -1) || (retornoCriterio == 1 && order == 1))
                    {
                        flagSwap = 1;
                        ll_set(this,i,thisElementoDos);
                        ll_set(this,i+1,thisElementoUno);
                    }
                }
            }


        }
        while(flagSwap == 1);

        returnAux = 0;
    }
    return returnAux;
}
/***
 * \brief Resetea la variable itNode (iterador) setandola en NULL
 * \param this Es el Linkedlist del cual se realiza el set del itNode
 * \return Retorna 0 si this es diferente a NULL sino retorna -1
*/
int resetIterator(LinkedList* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        this->nodoGlobal = NULL;
        retorno = 0;
    }
    return retorno;
}
/***
 * \brief Inicializa la variable itNode (iterador) del LinkedList
 * \param this Es el Linkedlist del cual se realiza el set del itNode
 * \param first Es el Nodo con el cual se inicializa la variable itNode
 * \return Retorna 0 si this y first no son NULL sino retorna -1
*/
void ll_startIter(LinkedList* this)
{
    if(this != NULL)
    {
        this->nodoGlobal = this->pFirstNode;
    }
}
/**
 * \brief Retorna el elemento del itNode (iterador) y mueve un lugar el itNode
 * \param this Es el Linkedlist que recibe para recorrer
 * \return Retorna el elemento si el itNode es diferente a NULL sino retorna NULL
*/
void* ll_getNext(LinkedList* this)
{
    void* retorno;

    if(this != NULL)
    {
        void* pElemento = this->nodoGlobal->pElement;
        this->nodoGlobal = this->nodoGlobal->pNextNode;
        retorno = pElemento;
    }
        return retorno;
}
/**
* \brief Se filtran los elementos de una lista que cumplan con un criterio
* \param this Es el puntero a la LinkedList para filtrar
* \param pFunc Es el puntero a la función para realizar el filtrado
* \return Retorna un nuevo Linkedlist con los elementos filtrados o NULL si la lista y la función son NULL
*
*/
void* ll_filter(void* this,int (*pFunc)(void*))
{
    LinkedList* subList = NULL;
    int i;
    void* pElement;
    if(this != NULL && pFunc != NULL)
    {
        subList = ll_newLinkedList();
        for(i=0; i<ll_len(this)-1; i++)
        {
            pElement = ll_get(this,i);
            if(!pFunc(pElement))
            {
                ll_add(subList,pElement);
            }
        }
    }
    return subList;
}
/**
 * \brief Recibe el LinkedList y ejecuta la funcion recibida con todos los elementos
 * \param this Es el LinkedList que recibe para recorrer
 * \param pFunc Es el puntero a la función para ejecutar dentro del mapping
 * \return Retorna 0 si logra ejecutar la función con todos los elementos sino retorna -1
*/

int ll_map(LinkedList* this, int (*pFunc)(void*))
{
    int retorno = -1;
    int i;
    void* pElement;

    if(this != NULL && pFunc != NULL)
    {
        ll_startIter(this);
        for(i=0;i<ll_len(this);i++)
        {
            pElement = ll_getNext(this);
            if(pElement != NULL)
            {
                if(!pFunc(pElement))
                {
                    retorno = 0;
                }
                else
                {
                    break;
                }
            }
        }
        resetIterator(this);
    }
    return retorno;
}

