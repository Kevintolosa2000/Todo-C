#include "fila.h"


void inicFila (Fila* fila)
{
    fila->inicio=inicListaDoble();
    fila->fin=inicListaDoble();
}



void agregarDatoFila (Fila* fila, stProducto dato)
{
    nodoDoble * nuevo = crearNodoDoble(dato);
    fila->fin= agregarFinalDoble(fila->fin, nuevo);
    if (!fila->inicio)
    {
        fila->inicio=fila->fin;
    }
    fila->fin=nuevo;
}


void muestraFila (Fila* fila)
{
      mostrarListaDoble(fila->inicio);
}

stProducto verPrimeroFila (Fila * fila)
{
    stProducto p;

    if (fila->inicio)
    {
     ///     p=verPrimerDatoListaDoble(fila->inicio);
    }
    return p;
}

stProducto extraerDeFila (Fila* fila)
{
    stProducto p;
    if (fila->inicio)
    {
        p=verPrimeroFila(fila->inicio);
        fila->inicio=eliminarPrimerNodoDoble(fila->inicio);
        if (!fila->inicio)
        {
            fila->fin=inicListaDoble();
        }
    }
    return p;
}


int filaVacia (Fila* fila)
{
    return (!fila->inicio)?0:1;
}



