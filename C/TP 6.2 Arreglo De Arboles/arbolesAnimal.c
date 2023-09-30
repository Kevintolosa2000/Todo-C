#include "arbolesAnimal.h"

///INIC ARBOL ANIMAL
nodoArbol * inicArbolAnimal()
{
    return NULL;
}

///CREAR NODO ARBOL ANIMAL
nodoArbol * crearNodoArbolAnimal(registroArchivo nuevo)
{
    nodoArbol * nuevoNodo=(nodoArbol*)malloc(sizeof(nodoArbol));
    nuevoNodo->dato.cantidad=nuevo.cant;
    nuevoNodo->dato.habitat=nuevo.habitat;
    strcpy(nuevoNodo->dato.nombreAnimal,nuevo.animal);
    nuevoNodo->der=NULL;
    nuevoNodo->izq=NULL;

    return nuevoNodo;
}

///INSERTAR EN ARBOL ANIMAL
nodoArbol * insertarNodoAnimal(nodoArbol * arbol,nodoArbol * nuevoNodo)
{
    if(arbol==NULL)
        arbol=nuevoNodo;
    else
    {
        if(nuevoNodo->dato.cantidad<arbol->dato.cantidad)
        {
            arbol->izq=insertarNodoAnimal(arbol->izq,nuevoNodo);
        }else
        {
            arbol->der=insertarNodoAnimal(arbol->der,nuevoNodo);
        }
    }

    return arbol;
}

///MOSTRAR ARBOL ANIMAL
void mostrarArbolAnimal(nodoArbol * arbol)
{
    if(arbol)
    {
        mostrarArbolAnimal(arbol->izq);
        mostrarUnAnimal(arbol->dato);
        printf("---------------------------------\n");
        mostrarArbolAnimal(arbol->der);
    }
}

///GUARDAR ARBOL EN ARCHIVO
void guardarArbol(FILE * archi,nodoArbol * arbol)
{
   if(arbol)
   {
       fwrite(&arbol->dato,sizeof(animal),1,archi);
       guardarArbol(archi,arbol->izq);
       guardarArbol(archi,arbol->der);
   }
}
