#include <stdio.h>
#include <stdlib.h>

#include "nodo.h"
#include "productos.h"
#include "nodoDoble.h"
#include "arboles.h"



typedef struct
{
   int nota;
   int legajo;
   char nombreApe[40];
   char materia[40];
   int idMateria;
} registroArchivo;

typedef struct
{
   int nota;
   int legajo;
   char nombreApe[40];
} notaAlumno;

typedef struct
{
    int idMateria;
    char materia[40];
    nodo * listaDeNotas;
} celda;

typedef struct _nodoalumno
{
   notaAlumno dato;
   struct _nodoalumno *siguiente;
} nodoalumno;

nodoDoble * deNodoSimpleADoble (nodo * lista, nodoDoble * listaDoble);
nodo * arbolToLista(nodoArbol * arbol, nodo * lista);
///lista->dato.nombre[0]== letra  Encontras la primer letra del string
///strlen (lista->dato.nombre)-1 Encontras la ultima letra del string, esta buenisimo

int main()
{




    return 0;
}


nodoDoble * deNodoSimpleADoble (nodo * lista, nodoDoble * listaDoble)
{
    while(lista)
    {
        listaDoble=agregarEnOrdenDoble(listaDoble, crearNodoDoble(lista->dato));
        lista=lista->siguiente;
    }
    return listaDoble;

}



nodo * arbolToLista(nodoArbol * arbol, nodo * lista)
{
    nodo * aux =NULL;
        if(arbol != NULL)
    {

        lista=arbolToLista(arbol->izq, lista);
        aux=crearNodo(arbol->dato);
        lista=agregarNodoNuevoAlFinal(lista, aux);
        lista=arbolToLista(arbol->der,lista);
        insertarEnOrdenRecursivaPunteroDoble((*lista),crearNodo(arbol->dato));
    }
    return lista;
}
