
#include "LDAAnimales.h"
///INIC LISTA DE ARBOLES
nodoEspecie * inicListaDeArboles()
{
    return NULL;
}

///CREAR NODO LISTA DE ARBOLES
nodoEspecie * crearNodoListaDeArboles(registroArchivo dato)
{
    nodoEspecie * nuevoNodo=(nodoEspecie*)malloc(sizeof(nodoEspecie));
    nuevoNodo->arbolDeAnimales=inicArbolAnimal();
    nuevoNodo->idEspecie=dato.idEspecie;
    strcpy(nuevoNodo->especie,dato.especie);
    nuevoNodo->siguiente=NULL;
    return nuevoNodo;
}

///AGREGAR AL FINAL LISTA DE ARBOLES
nodoEspecie * agregarAlFinalListaDeArboles(nodoEspecie * lista, char especie[],registroArchivo aux)
{
    if(!lista)
    {
        lista=crearNodoListaDeArboles(aux);
    }else
    {
        lista->siguiente=agregarAlFinalListaDeArboles(lista->siguiente,especie,aux);
    }

    return lista;
}

///BUSCA POS ESPECIE
nodoEspecie * buscaPosicionEspecie(nodoEspecie * lista, char especie[])
{
    nodoEspecie * rta=NULL;

    if(lista)
    {
        if(strcmp(lista->especie,especie)==0)
        {
            rta=lista;
        }else
        {
            rta=buscaPosicionEspecie(lista->siguiente,especie);
        }
    }

    return rta;

}
///ALTA LISTA DE ARBOLES
nodoEspecie * altaLDA(nodoEspecie * lista, registroArchivo aux)
{
    nodoEspecie * especie=NULL;
    especie=buscaPosicionEspecie(lista,aux.especie);

    if(!especie)
    {
        especie=crearNodoListaDeArboles(aux);
        lista=agregarAlFinalListaDeArboles(lista,aux.especie,aux);
        especie=buscaPosicionEspecie(lista,aux.especie);
    }

    especie->arbolDeAnimales=insertarNodoAnimal(especie->arbolDeAnimales,crearNodoArbolAnimal(aux));

    return lista;

}

///PASAR ARCHIVO TO LDA
nodoEspecie * pasarArchivoToLDA(nodoEspecie * lista, char archivo[])
{
    FILE * archi=fopen(archivo,"rb");

    registroArchivo aux;

    if(archi)
    {
        while(fread(&aux,sizeof(registroArchivo),1,archi)>0)
        {
            lista=altaLDA(lista,aux);
        }

        fclose(archi);
    }

    return lista;
}

///MOSTRAR LDA
void mostrarListaDeArboles(nodoEspecie * lista)
{
    if(lista)
    {
        printf("\n\n\n============================================= \n");
        printf("Especie: %s \n",lista->especie);
        printf("ID Especie: %d \n",lista->idEspecie);
        printf("============================================= \n\n");
        mostrarArbolAnimal(lista->arbolDeAnimales);
        mostrarListaDeArboles(lista->siguiente);
    }
}
