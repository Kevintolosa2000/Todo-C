#ifndef LISTAALUMNO_H_INCLUDED
#define LISTAALUMNO_H_INCLUDED

#include "notaAlumno.h"

typedef struct _nodo
{
    notaAlumno dato;
    struct _nodo *siguiente;
}nodo;

///==============================================
///FUNCIONES BASICAS PARA EL MANEJO DE LISTAS
///==============================================

///INICIALIZA LA LISTA
nodo * inicListaNotas();
///AGREGA NODO AL PRINCIPIO
nodo * agregarPpioNotas(nodo * lista, nodo * nuevoNodo);
///BUQUEDA DE EL ULTIMO NODO
nodo * buscarUltimoNotas(nodo * lista);
///AGREGA UN NODO AL FINAL
nodo * agregarFinalNotas(nodo * lista, nodo * nuevoNodo);
///AGREGAR UN NODO NUEVO MANTENIENDO EL ORDEN
nodo * agregarEnOrdenNotas(nodo * lista, nodo * nuevoNodo);
///BORRAR UNA LISTA COMPLETA
nodo * borrarTodaLaListaNotas(nodo * lista);
///CREA UN NUEVO NODO
nodo * crearNodoNotas(notaAlumno dato);
///RECORRER Y MOSTRAR UNA LISTA ITERATIVAMENTE
void mostrarListaIterativamente(nodo * lista);
///CONTAR CANTIDAD DE NOTAS
int contarCantidadDeNotas(nodo * lista);

#endif // LISTAALUMNO_H_INCLUDED
