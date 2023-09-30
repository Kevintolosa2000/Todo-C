#include "pila.h"


void inicpila(P_Pila p)
{
       int *aux;
       aux = (int *)malloc(50*sizeof(int));
       p->valores = aux;
       p->postope=0;
}

void apilar(P_Pila p, int dato)
{
    int index = (*p).postope;
    (*p).valores[index]=dato;
    (*p).postope = (*p).postope + 1;
}

int desapilar(P_Pila p)
{
       int z = p->valores[p->postope -1];
       p->postope--;
       return z;
}

int tope(P_Pila p)
{
       return p->valores[p->postope - 1];
}

int pilavacia(P_Pila p)
{
       return (p->postope == 0);
}

void leer (P_Pila p)
{
    int aux = 0;
    if (p->postope < 50)
    {
        printf("Ingrese un valor entero: ");
        fflush(stdin);
        scanf("%d", &aux);
        apilar(p, aux);
    }
    else
        printf("Error: la pila esta llena");
}

void mostrar(P_Pila p)
{
    int i;
    printf("\nBase .............................................. Tope\n\n");
    for(i=0; i < p->postope; i++)
        printf("| %d ", p->valores[i]);
    printf("\n\nBase .............................................. Tope\n\n");
}


///-----------------------------------------------------------------------------------------------------
//void inicPilaNuestro(Pila * pila)
//{
//    (*pila)=inicLista();
//}
//
//int pilaVacia (Pila * pila)
//{
//    int flag=0;
//    if ((*pila)!=NULL)
//    {
//        flag =1;
//    }
//    return flag;
//}
//
//void apilarNuestro (Pila * pila, stProducto dato)
//{
//    nodo * nuevo = crearNodo(dato);
//    (*pila) = agregarNodoNuevoAlPrincipio((*pila), nuevo);
//}
//
//nodo * desapilarNuestro (Pila * pila)
//{
//    nodo * primerNodo;
//    nodo * nodoABorrar;
//    inicPilaNuestro(&primerNodo);
//
//    if (*pila!=NULL)
//    {
//        primerNodo=(*pila);
//        nodoABorrar=primerNodo;
//        (*pila)=(*pila)->siguiente;
//        free(nodoABorrar);
//    }
//    return primerNodo;
//}
//
//void mostrarPilaNuestro (Pila * pila)
//{
//    printf("Tope");
//    mostrarLista(*pila);
//    printf("Base");
//}
