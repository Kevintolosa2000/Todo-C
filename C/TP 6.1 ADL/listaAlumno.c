#include "listaAlumno.h"
#include <string.h>

///INCIALIZACION DE LA LISTA
nodo * inicListaNotas()
{

    return NULL;

}

///CREA UN NODO
nodo * crearNodoNotas(notaAlumno nuevo)
{
    nodo * nuevoNodo = (nodo*) malloc(sizeof(nodo));
    nuevoNodo->dato=nuevo;
    nuevoNodo->siguiente=NULL;

    return nuevoNodo;
}

///AGREGA EL NODO AL PPCIO DE LA LISTA
nodo * agregarPpioNotas(nodo * lista, nodo * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente=lista;
        lista=nuevoNodo;
    }
    return lista;
}

///BUSCA EL ULTIMO NODO
nodo * buscarUltimoNotas(nodo * lista)
{
    nodo * proximo= lista;
    if(proximo !=NULL)
    {
        while(proximo->siguiente != NULL)
        {
            proximo=proximo->siguiente;
        }
    }

    return proximo;
}

///AGREGA UN NODO AL final
nodo * agregarFinalNotas(nodo * lista, nodo * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodo * ultimo = buscarUltimoNotas(lista);
        ultimo->siguiente=nuevoNodo;
    }

    return lista;
}

///AGREGAR UN NODO NUEVO MANTENIENDO EL ORDEN
nodo * agregarEnOrdenNotas(nodo * lista, nodo * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        if(nuevoNodo->dato.nota <lista->dato.nota)
        {
            lista=agregarPpioNotas(lista,nuevoNodo);
        }
        else
        {
            nodo * ante=lista;
            nodo * seg=lista->siguiente;
            while((seg!=NULL) && (nuevoNodo->dato.nota > seg->dato.nota))
            {
                ante=seg;
                seg=seg->siguiente;
            }

            nuevoNodo->siguiente=seg;
            ante->siguiente=nuevoNodo;
        }
    }

    return lista;
}

///BORRAR UNA LISTA COMPLETA
nodo * borrarTodaLaListaNotas(nodo * lista)
{
    nodo * proximo;
    nodo * seg;
    seg=lista;
    while(seg != NULL)
    {
        proximo=seg->siguiente;
        free(seg);
        seg=proximo;
    }

    return seg;
}

///RECORRER Y MOSTRAR UNA LISTA ITERATIVAMENTE
void mostrarListaIterativamente(nodo * lista)
{
    if(lista)
    {
        while(lista)
        {
            mostrarNotaAlumno(lista->dato);
            lista=lista->siguiente;
        }
    }
}

///CONTAR CANTIDAD DE NOTAS
int contarCantidadDeNotas(nodo * lista)
{
    int contador=0;

    while(lista)
    {
        contador++;
        lista=lista->siguiente;
    }

    return contador;
}
