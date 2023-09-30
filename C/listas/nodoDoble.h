#ifndef NODODOBLE_H_INCLUDED
#define NODODOBLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "productos.h"


///#define PilaDoble nodoDoble *

typedef struct _nodoDoble
{
    stProducto dato;
    struct _nodoDoble * anterior;
    struct _nodoDoble * siguiente;
} nodoDoble ;

nodoDoble * agregarEnOrdenDoble (nodoDoble  * listaDoble, nodoDoble * nuevo);
nodoDoble * agregarFinalDoble(nodoDoble  * listaDoble, nodoDoble * nuevo);
nodoDoble * agregarPpioDoble (nodoDoble * listaDoble, nodoDoble * nuevo);
nodoDoble * borrarUltimoNodoDoble (nodoDoble * listaDoble);
nodoDoble * buscarUltimoDoble ( nodoDoble * listaDoble);
nodoDoble * buscarYBorrarNodoDoble (nodoDoble * listaDoble, char nombre [20]);
nodoDoble * cargarElNodoDoble (nodoDoble * listaDoble);
nodoDoble * crearNodoDoble (stProducto dato);
nodoDoble * eliminarPrimerNodoDoble(nodoDoble * listaDoble);
nodoDoble * inicListaDoble();
void mostrarListaDoble (nodoDoble * listaDoble);
int verifacarSiListaDobleEsCapicua (nodoDoble * listaDoble);

float sumaPrecioRecusividadDoble (nodoDoble* listaDoble);
#endif // NODODOBLE_H_INCLUDED
