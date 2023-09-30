#ifndef ADL_H_INCLUDED
#define ADL_H_INCLUDED

#include "nodo.h"

typedef struct
{
    char categoria[50];
    nodo * lista;
} celda;

int alta (celda adl[], char categoria, stProducto x, int validos);
int buscaPosCategoriaCelda (celda adl[], char categoria[],int validos);
int agregarCategoriaCelda (celda adl[], char categoria [], int validos);

#endif // ADL_H_INCLUDED
