#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "nodoDoble.h"
#include "productos.h"


typedef struct _Fila
{
    struct _nodoDoble* inicio;
    struct _nodoDoble* fin;
}Fila;

void inicFila (Fila* fila);
void agregarDatoFila (Fila* fila, stProducto dato);
void muestraFila (Fila* fila);

#endif // FILA_H_INCLUDED
