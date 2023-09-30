#include <stdio.h>
#include <stdlib.h>

#include "ADAAnimales.h"
#include "LDAAnimales.h"

#define archiAminal "animales.dat"
#define aves "Aves.dat"
#define mamiferos "Mamiferos.dat"
#define peces "Peces.dat"
#define reptiles "Reptiles.dat"


int main()
{
    //celdaEspecie ada[10];
    nodoArbol * arbolito=inicArbolAnimal();
    //int validos=0;

///PARTE ARREGLO DE ARBOLES
    //validos=pasarArchivoToADA(ada,archiAminal);
    //mostrarADAanimales(ada,validos);

    //pasarADAToArchivo(ada,validos);

    /*
    printf("archi aves \n");
    printf("========================= \n");
    mostrarArchiAnimales(aves);
    printf("========================= \n");
    printf("archi mamiferos \n");
    mostrarArchiAnimales(mamiferos);
    printf("========================= \n");
    printf("archi peces \n");
    mostrarArchiAnimales(peces);
    printf("========================= \n");
    printf("archi reptiles \n");
    mostrarArchiAnimales(reptiles);
    printf("========================= \n");
    */
///PARTE LISTA DE ARBOLES

    nodoEspecie * lista=inicListaDeArboles();
    lista=pasarArchivoToLDA(lista,archiAminal);
    mostrarListaDeArboles(lista);


    return 0;
}
