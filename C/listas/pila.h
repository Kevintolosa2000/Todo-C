#include <stdio.h>
#include <malloc.h>
#define Pila struct _Pila
#define P_Pila struct _Pila *

#include "productos.h"
#include "nodo.h"

struct _Pila
{
    int *valores;
    int postope;
};

void inicpila(P_Pila p);
void apilar(P_Pila p, int dato);
void apilar(P_Pila p, int dato);
int desapilar(P_Pila p);
int tope(P_Pila p);
int pilavacia(P_Pila p);
void leer (P_Pila p);
void mostrar(P_Pila p);
///--------------------------------------------------------------------
//void inicPilaNuestro (Pila * pila);
//int pilaVaciaNuestro  (Pila * pila);
//void apilarNuestro  (Pila * pila, stProducto dato);
//void mostrarPilaNuestro  (Pila * pila);
//nodo * desapilarNuestro (Pila * pila);

