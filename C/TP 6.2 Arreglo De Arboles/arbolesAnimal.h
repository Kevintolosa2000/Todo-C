#ifndef ARBOLESANIMAL_H_INCLUDED
#define ARBOLESANIMAL_H_INCLUDED

#include "animles.h"

typedef struct
{
   animal dato;
   struct nodoArbol * izq;
   struct nodoArbol * der;
} nodoArbol;

///INIC ARBOL ANIMAL
nodoArbol * inicArbolAnimal();
///CREAR NODO ARBOL ANIMAL
nodoArbol * crearNodoArbolAnimal(registroArchivo nuevo);
///INSERTAR EN ARBOL ANIMAL
nodoArbol * insertarNodoAnimal(nodoArbol * arbol,nodoArbol * nuevoNodo);
///MOSTRAR ARBOL ANIMAL
void mostrarArbolAnimal(nodoArbol * arbol);
///GUARDAR ARBOL EN ARCHIVO
void guardarArbol(FILE * archi,nodoArbol * arbol);
#endif // ARBOLESANIMAL_H_INCLUDED
