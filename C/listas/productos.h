#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {

   int idProducto;
   char nombre[30];
   char marca[20];
   float precio;
   int eliminado;  /// indica 1 o 0 si el producto fue eliminado
} stProducto;

stProducto cargarUnProducto ();
void mostrarUnProducto(stProducto a);
void estePrinteaEstado(int numero);
#endif // PRODUCTOS_H_INCLUDED
