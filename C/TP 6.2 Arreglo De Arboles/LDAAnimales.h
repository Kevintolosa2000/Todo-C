#ifndef LDAANIMALES_H_INCLUDED
#define LDAANIMALES_H_INCLUDED

#include "arbolesAnimal.h"

typedef struct _nodoEspecie
{
   int idEspecie;
   char especie [20];
 	 // "Mamiferos", "Aves"
       // "Reptiles", "Peces",”Anfibios”
   nodoArbol * arbolDeAnimales;
   struct _nodoEspecie * siguiente;
} nodoEspecie;

///INIC LISTA DE ARBOLES
nodoEspecie * inicListaDeArboles();
///CREAR NODO LISTA DE ARBOLES
nodoEspecie * crearNodoListaDeArboles(registroArchivo dato);
///AGREGAR AL FINAL LISTA DE ARBOLES
nodoEspecie * agregarAlFinalListaDeArboles(nodoEspecie * lista, char especie[],registroArchivo aux);
///BUSCA POS ESPECIE
nodoEspecie * buscaPosicionEspecie(nodoEspecie * lista, char especie[]);
///ALTA LISTA DE ARBOLES
nodoEspecie * altaLDA(nodoEspecie * lista, registroArchivo aux);
///PASAR ARCHIVO TO LDA
nodoEspecie * pasarArchivoToLDA(nodoEspecie * lista, char archivo[]);
///MOSTRAR LDA
void mostrarListaDeArboles(nodoEspecie * lista);
#endif // LDAANIMALES_H_INCLUDED
