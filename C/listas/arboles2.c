#include "arboles.h"


nodoArbol * inicArbol()
{
    return NULL;
}

nodoArbol * crearNodoArbol(stProducto dato)
{
    nodoArbol * aux = (nodoArbol*) malloc(sizeof(nodoArbol));
    aux->dato=dato;
    aux->der=NULL;
    aux->izq=NULL;
    return aux;
}
nodoArbol * cargarElArbol (nodoArbol * arbol)
{
    nodoArbol * nuevoNodoArbol;
    char control ='s';

    while (control=='s')
    {
        nuevoNodoArbol = crearNodoArbol(cargarUnProducto());
        arbol=insertarPorId(arbol,nuevoNodoArbol->dato);

        printf("\nDesea agragar otro producto? (S/N): ");
        fflush(stdin);
        scanf("%c", &control);
        system("cls");
    }
    return arbol;
}
nodoArbol * insertarPorId(nodoArbol * arbol, stProducto dato)
{
    if(arbol==NULL)
        arbol = crearNodoArbol(dato);
    else
    {
        if( dato.idProducto > (arbol->dato.idProducto))
            arbol->der = insertarPorId(arbol->der, dato);
        else
            arbol->izq = insertarPorId(arbol->izq, dato);
    }
    return arbol;
}

void preorder(nodoArbol * arbol)
{
    if(arbol != NULL)
    {
        mostrarUnProducto(arbol->dato);
        preorder(arbol->izq);
        preorder(arbol->der);
    }
}

void inorder(nodoArbol * arbol)
{
    if(arbol != NULL)
    {
        inorder(arbol->izq);
        mostrarUnProducto(arbol->dato);
        inorder(arbol->der);
    }
}

void deArbolToArchivoInOrder (char archivo[],nodoArbol * arbol)
{
    ///insercionbalanceadaenunarbol
}
void postorder(nodoArbol * arbol)
{
    if(arbol != NULL)
    {
        postorder(arbol->izq);
        postorder(arbol->der);
        mostrarUnProducto(arbol->dato);
    }
}

nodoArbol * buscarPorIdArbol(nodoArbol * arbol, stProducto dato)
{
    nodoArbol * rta=NULL;
    if(arbol!=NULL)
    {
        if(dato.idProducto == arbol->dato.idProducto)
            rta = arbol;
        else if(dato.idProducto > arbol->dato.idProducto)
            rta = buscarPorIdArbol(arbol->der, dato);
        else
            rta = buscarPorIdArbol(arbol->izq, dato);
    }
    return rta;
}

nodoArbol * buscarPorNombreArbol (nodoArbol * arbol, char dato[])
{
    nodoArbol * rta =NULL;
    if (arbol!=NULL)
    {
        if (strcmp(arbol->dato.nombre, dato)==0)
        {
            rta=arbol;
        }
        else
        {
            rta=buscarPorNombreArbol(arbol->izq,dato);
            if (!rta)
            {
                rta=buscarPorNombreArbol(arbol, dato);
            }
        }
    }
    return rta;
}

int contarNodosArbol (nodoArbol * arbol)
{
    int rta=NULL;

    if (!arbol)
    {
        rta=0;
    }
    else
    {
        if(arbolEsHoja(arbol))
        {
            rta=1;
        }
        else
        {
            rta= 1 +contarNodosArbol(arbol->der)+contarNodosArbol(arbol->izq);
        }
    }
    return rta;

///Forma condensada
//    int rta=0;
//
//    if(arbol)
//    {
//        rta=1+contarNodosArbol(arbol->der)+contarNodosArbol(arbol->izq);
//    }
//    return rta;
}

int arbolEsHoja (nodoArbol * arbol)
{
    int rta=0;
    if (arbol->izq==NULL && arbol->der==NULL)
    {
        rta =1;
    }
    return rta;
//    return (!arbol->izq && !arbol->der)?1:0;
}

nodoArbol * deArrayToArbol(stProducto dato[], int principio, int fin)
{
    if (principio > fin)
    {
        return NULL;
    }

    int mitad = (principio + fin)/2;

    nodoArbol * raiz = crearNodoArbol(dato[mitad]);

    raiz->izq =  deArrayToArbol(dato, principio, mitad-1);

    raiz->der = deArrayToArbol(dato, mitad+1, fin);

    return raiz;
}
///hace id auto incremental
///Se necesita un archivo con productos
///un contar arrchivo productos
///y saber recorrer el archivo

int contarProductos(char archivoProductos[])
{
    int cantidad=0;

    FILE*productos;

    productos=fopen(archivoProductos,"rb");

    if(productos!=NULL)
    {
        fseek(productos,0,SEEK_END);

        cantidad= ftell(productos)/sizeof(stProducto);
        fclose(productos);
    }
    return cantidad;
}


int deArchivoToArrayProductos (stProducto prods[], char archivo [])
{
    FILE * produtos=fopen(archivo,"rb");
    stProducto aux;
    int i=0;

    if (produtos)
    {
        while(fread(&aux,sizeof(stProducto),1,produtos)>0)
        {
            prods[i]=aux;
            i++;
        }
    }
    fclose(produtos);
    return i;
}

void deArrayAArchivo(char archivoAPasar[], stProducto prods[], int validos)
{
    FILE * archi=fopen(archivoAPasar,"wb");

    int i=0;
    if (archi!=NULL)
    {
        while (i<validos)
        {
            fwrite(&prods[i],sizeof(stProducto),1,archi);
            i++;
        }
    }
    fclose(archi);
}

void agregarDeArrayAArchivo(char archivoAPasar[], stProducto prods)
{
    FILE * archi=fopen(archivoAPasar,"ab");
    if (archi!=NULL)
    {
        fwrite(&prods,sizeof(stProducto),1,archi);
    }
    fclose(archi);
}

nodoArbol * nodoMasDerecho (nodoArbol* arbol)
{
    nodoArbol * resp;

    if (arbol)
    {
        if (arbol->der)
        {
            resp=nodoMasDerecho(arbol->der);
        }
        else
        {
            resp=arbol;
        }
    }
    return resp;
}

nodoArbol * nodoMasIzquierdo (nodoArbol* arbol)
{
    nodoArbol * resp;

    if (arbol)
    {
        if (arbol->izq)
        {
            resp=nodoMasIzquierdo(arbol->izq);
        }
        else
        {
            resp=arbol;
        }
    }
    return resp;
}

nodoArbol * borrarNodoArbol (nodoArbol * osvaldo, stProducto dato)
{
    if (osvaldo)
    {
        if (osvaldo->dato.idProducto==dato.idProducto)
        {
            if (osvaldo->izq)
            {
                nodoArbol * masDer = nodoMasDerecho(osvaldo->izq);
                osvaldo->dato = masDer->dato;
                osvaldo->izq = borrarNodoArbol(osvaldo->izq, masDer->dato);
            }
            else if (osvaldo->der)
            {
                nodoArbol * masIzq = nodoMasIzquierdo(osvaldo->der);
                osvaldo->dato = masIzq->dato;
                osvaldo->der = borrarNodoArbol(osvaldo->der, masIzq->dato);
            }
            else
            {
                free(osvaldo);
                osvaldo=NULL;
            }
        }
        else if (dato.idProducto>osvaldo->dato.idProducto)
        {
            osvaldo->der=borrarNodoArbol(osvaldo->der, dato);
        }
        else
        {
            osvaldo->izq=borrarNodoArbol(osvaldo->izq, dato);
        }
    }

    return osvaldo;
}

int deArchivoToArrayProductos (stProducto prods[], char archivo [])
{
    FILE * produtos=fopen(archivo,"rb");
    stProducto aux;
    int i=0;

    if (produtos)
    {
        while(fread(&aux,sizeof(stProducto),1,produtos)>0)
        {
            if(aux.productoAnulado==0)
            {
                prods[i]=aux;
                i++;
            }
        }
    }
    fclose(produtos);
    return i;
}

nodoArbol * deArrayToArbol(stProducto dato[], int principio, int fin)
{
    int mitad=0;
    nodoArbol * raiz=inicArbol();

    if (principio > fin)
    {
        raiz=NULL;
    }
    else
    {
        mitad = (principio + fin)/2;

        raiz = insertarPorId(raiz,dato[mitad]);

        raiz->izq =  deArrayToArbol(dato, principio, mitad-1);

        raiz->der = deArrayToArbol(dato, mitad+1, fin);
    }

    return raiz;
}
