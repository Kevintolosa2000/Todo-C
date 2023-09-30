#ifndef ARBOLES_H_INCLUDED
#define ARBOLES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "productos.h"


typedef struct _nodoArbol
{
    stProducto dato;
    struct _nodoArbol *izq;
    struct _nodoArbol *der;
} nodoArbol;

nodoArbol * inicArbol();
nodoArbol * cargarElArbol (nodoArbol * arbol);
nodoArbol * crearNodoArbol(stProducto dato);
nodoArbol * insertarPorId(nodoArbol * arbol, stProducto dato);
nodoArbol * buscarPorIdArbol(nodoArbol * arbol, stProducto dato);
nodoArbol * buscarPorNombreArbol (nodoArbol * arbol, char dato[]);

int arbolEsHoja (nodoArbol * arbol);
int contarNodosArbol (nodoArbol * arbol);


void preorder(nodoArbol * arbol);
//void inorder(nodoArbol * arbol);
void postorder(nodoArbol * arbol);
#endif // ARBOLES_H_INCLUDED
