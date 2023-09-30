#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//#include "cosasdepersonas.h" /// para que no te tire bronca la linea 13.
#include "productos.h"

///#define Pila nodo *

typedef struct _nodo
{
    stProducto dato;
    struct _nodo * siguiente;
} nodo;
///---------------------------------------------------------------------------------------
//typedef struct
//{
//    char patente[6];
//    int valor;
//    char marca[10];
//} automovil;
//
//typedef struct _nodoAuto
//{
//    automovil dato;
//    struct _nodoAuto * siguiente;
//} nodoAuto;

///--------------------------------------------------------NODOS--------------------------------------------------------------

nodo * agregarEnOrden (nodo * lista, nodo * nuevoNodo);
nodo * agregarNodoNuevoAlFinal (nodo * lista, nodo * nuevoNodo);
nodo * agregarNodoNuevoAlPrincipio (nodo * lista, nodo * nuevoNodo);
nodo * borrarNodoAEleccion(nodo * lista, char nombre[20]);
nodo * borrarTodaLaLista(nodo * lista);
int buscarNodoPorNombre (nodo * lista, char nombre[20]);
nodo * buscarUltimo (nodo * lista);
nodo * cargarElNodo (nodo* lista);
nodo * crearNodo (stProducto dato);
nodo * deArchivoALista (nodo * lista, char archivo []);
nodo * desvincularNodo (nodo ** lista);
nodo * eliminarPrimero (nodo * lista);
nodo * eliminarUltimo (nodo * lista);
nodo * inicLista();
nodo * invertirLista (nodo * lista);
nodo * intercalarListas(nodo* lista_1,nodo* lista_2);
void mostrarLista (nodo*lista);
nodo * subProgramaAgregarAlFinal(nodo * lista, stProducto dato);
int sumarEdadesLista(nodo * lista);

///------------------------------------------------------NODOS RECURSIVOS----------------------------------------------------

nodo * borrarNodoRecursivoAEleccion (nodo * lista, char flaco []);
nodo * BorrarTodaLaListaRecursivo (nodo * lista);
nodo * invertirListaRecursiva (nodo * lista);
void mostrarNodoParRecursivo (nodo * lista);
void mostrarNodoRecursivo (nodo * lista);
void mostrarNodoRecursivoInvertida (nodo * lista);
void mostrarUnSoloDatoR (nodo*lista);
int sumarListaRecursiva(nodo * lista);

///---------------------------------------------------------Nodos AUTOS-------------------------------------------------------

//void agregarNodoNuevoAlFinalPunteroDoble (nodoAuto ** lista, nodoAuto * nuevoNodo);
//automovil cargarUnAuto ();
//nodoAuto * buscarUltimoAuto (nodoAuto * lista);
//nodoAuto * cargarElNodoDeAutos (nodoAuto * lista);
//nodoAuto * crearNodoAuto (automovil dato);
//void mostrarListaAutos (nodoAuto*lista);
//void mostrarUnAuto(automovil a);

#endif // NODO_H_INCLUDED
