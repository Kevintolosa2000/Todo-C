#include "ADL.h"


int alta (celda adl[], char categoria, stProducto x, int validos)
{
    nodo * aux = crearNodo(x);
    ///Te pide otra cosas nuesra funcion
    int pos = buscaPosCategoriaCelda(adl,categoria, validos);
    if(pos==-1)
    {
        validos=agregarCategoriaCelda(adl,categoria, validos);
        pos=validos-1;

    }
    adl[pos].lista=agregarNodoNuevoAlPrincipio((adl[pos].lista), aux);
    ///ROMPE, no se por que
    return validos;
}

int buscaPosCategoriaCelda (celda adl[], char categoria[],int validos)
{
    int rta=-1;
    int i=0;
    while((i<validos) && (rta==-1))
    {
        if (strcmp(adl[i].categoria,categoria)==0)
        {
            rta=i;
        }
        i++;

    }
    return rta;
}

int agregarCategoriaCelda (celda adl[], char categoria [], int validos)
{
    strcpy(adl[validos].categoria, categoria);
    adl[validos].lista = inicLista();
    validos++;
    return validos;
}
