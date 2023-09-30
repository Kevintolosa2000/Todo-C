#ifndef ADAANIMALES_H_INCLUDED
#define ADAANIMALES_H_INCLUDED

#include "arbolesAnimal.h"
#include <string.h>

typedef struct
{
   int idEspecie;
   char especie [20];
 	 // "Mamiferos", "Aves"
       // "Reptiles", "Peces",”Anfibios”
   nodoArbol * arbolDeAnimales;
} celdaEspecie;

///ALTA ADA
int altaADA(celdaEspecie ada[],int validos,registroArchivo nuevo);

///BUSCA POS ESPECIE
int buscaPosEspecieADA(celdaEspecie ada[], char especie[],int validos);

///CREAR NUEVA ESPECIE EN ARREGLO
int  crearNuevaEspecie(celdaEspecie ada[],registroArchivo aux,int validos);

///PASAR ARCHIVO TO ADA
int pasarArchivoToADA(celdaEspecie ada[],char archivo[]);

///MOSTRAR ADA
void mostrarADAanimales(celdaEspecie ada[],int validos);

///PASAR ADA TO ARCHIVO
void pasarADAToArchivo(celdaEspecie ada[], int validos);

#endif // ADAANIMALES_H_INCLUDED
