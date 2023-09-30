#include "nodoDoble.h"

nodoDoble * inicListaDoble()
{
    return NULL;
}

nodoDoble * cargarElNodoDoble (nodoDoble * listaDoble)
{
    nodoDoble * nuevoNodoDoble;
    char control ='s';

    while (control=='s')
    {
        nuevoNodoDoble = crearNodoDoble(cargarUnProducto());
        listaDoble=agregarEnOrdenDoble(listaDoble,nuevoNodoDoble);

        printf("\nDesea agragar otro producto? (S/N): ");
        fflush(stdin);
        scanf("%c", &control);
        system("cls");
    }
    return listaDoble;
}

nodoDoble * crearNodoDoble (stProducto dato)
{

    nodoDoble* aux = (nodoDoble*) malloc(sizeof(nodoDoble));
    aux->dato = dato;
    aux->anterior = NULL;
    aux->siguiente = NULL;


    return aux;
}

nodoDoble * agregarPpioDoble (nodoDoble * listaDoble, nodoDoble * nuevo)
{
    nuevo->siguiente = listaDoble;
    if(listaDoble != NULL)
    {
        listaDoble->anterior=nuevo;
    }

    return nuevo;
}


nodoDoble* agregarFinalDoblePeroConProductoDeGolpe(nodoDoble* listaDoble, stProducto dato)
{
    return (agregarFinalDoble(listaDoble, crearNodoDoble(dato)));
}


nodoDoble * agregarFinalDoble(nodoDoble  * listaDoble, nodoDoble * nuevo)
{
    if(listaDoble == NULL)
    {
        listaDoble = nuevo;
    }
    else
    {
        nodoDoble * ultimo = buscarUltimoDoble(listaDoble);
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
    }
    return listaDoble;
}

nodoDoble * agregarEnOrdenDoble (nodoDoble  * listaDoble, nodoDoble * nuevo)
{

    if(listaDoble == NULL)
    {
        listaDoble = nuevo;
    }
    else
    {

        if(strcmp(nuevo->dato.nombre,listaDoble->dato.nombre)<0)
        {
            listaDoble = agregarPpioDoble(listaDoble, nuevo);
        }
        else
        {
            nodoDoble * ante = listaDoble;
            nodoDoble * seg = listaDoble->siguiente;
            while((seg != NULL) &&(strcmp(nuevo->dato.nombre,seg->dato.nombre)>0))
            {
                ante = seg;
                seg = seg->siguiente;
            }
            ante->siguiente = nuevo;
            nuevo->anterior = ante;
            nuevo->siguiente = seg;
            if (seg!=NULL)
            {
                seg->anterior=nuevo;
            }
        }
    }
    return listaDoble;
}

///DESPUES AGREGAR LA STRUCT DE NODODOBLE JEJE
nodoDoble * buscarUltimoDoble ( nodoDoble * listaDoble)
{
    nodoDoble * ultimo = listaDoble;
    if (listaDoble)
        while (ultimo->siguiente !=NULL)
        {
            ultimo=ultimo->siguiente;
        }
    return ultimo;
}

nodoDoble * buscarYBorrarNodoDoble (nodoDoble * listaDoble, char nombre [20])
{
    if((listaDoble != NULL) && (strcmp(nombre, listaDoble->dato.nombre)==0 ))
    {
        nodoDoble * aux = listaDoble;
        listaDoble = listaDoble->siguiente;
        listaDoble->anterior=NULL;
        free(aux);
    }
    else
    {
        nodoDoble * aux2= listaDoble;
        nodoDoble * otra=NULL;

        while((aux2 != NULL) && (strcmp(nombre, aux2->dato.nombre)!=0 ))
        {
            otra=aux2;
            aux2 = aux2->siguiente;
        }
        if(aux2!=NULL)
        {
            otra=aux2->anterior;
            otra->siguiente=aux2->siguiente;
            free(aux2);
        }
    }
    return listaDoble;
}

nodoDoble * eliminarPrimerNodoDoble(nodoDoble * listaDoble)
{
    nodoDoble * aBorrar = listaDoble;

    if (listaDoble)
    {
        listaDoble=listaDoble->siguiente;

        if (listaDoble)
        {
            listaDoble->anterior=NULL;
        }

        free(aBorrar);
    }

    return listaDoble;
}

nodoDoble * borrarUltimoNodoDoble (nodoDoble * listaDoble)
{
    nodoDoble * ante;
    nodoDoble * copiaLista= listaDoble;

    while (copiaLista->siguiente!= NULL)
    {
        ante = copiaLista;
        copiaLista=copiaLista->siguiente;
    }
    ante->siguiente = copiaLista->siguiente;

    free(copiaLista);

    return listaDoble;
}


void mostrarListaDoble (nodoDoble*listaDoble)
{
    nodoDoble * aux = listaDoble;

    while (aux != NULL)
    {
        mostrarUnProducto(aux->dato);
        aux=aux->siguiente;
    }
}

int verifacarSiListaDobleEsCapicua (nodoDoble * listaDoble)
{
    int flag=1;
    nodoDoble * inicio = listaDoble;
    nodoDoble * fin = buscarUltimoDoble(listaDoble);
    if (listaDoble != NULL)
    {
        while (flag ==1 && ((inicio->anterior!=fin) && inicio!=fin))
        {
            if (inicio->dato.precio==fin->dato.precio)
            {
                inicio=inicio->siguiente;
                fin=fin->anterior;
            }
            else
            {
                flag=0;
            }
        }
    }
    return flag;
}

float sumaPrecioRecusividadDoble (nodoDoble* listaDoble)
{
    return (listaDoble)?listaDoble->dato.precio+sumaPrecioRecusividadDoble(listaDoble->siguiente):0;
}



nodoDoble * agregarEnORden(nodo*lista,nodoDoble * nuevonodo)
{
   nodo * aux=lista;

   if(lista!=NULL)
   {
       lista=nuevonodo;
   }
   else if (nuevonodo->dato.dni<lista->dato.dni)
   {
       lista=agregarNodoNuevoAlPrincipio(lista,nuevonodo);
   }
   else
   {
       nodoDoble * ante=lista;
       nodoDoble * sig=lista->siguiente;

       while (sig!=NULL && lista->dato.dni<nuevonodo->dato.dni)
       {
          ante=sig;
          sig=sig->siguiente;
       }
       ante->siguiente=nuevonodo;

       nuevonodo->anterior=ante;
   }

