#ifndef ANIMLES_H_INCLUDED
#define ANIMLES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct {
   char animal[30];
   int cant;
   int habitat;
   int idEspecie;
   char especie[20];
} registroArchivo;

typedef struct {
    char nombreAnimal [30];
	int cantidad;
	int habitat;
// 1 - selva, 2- savana, 3-bosque, 4-mar
} animal;

///MOSTRAR UN ANIMAL
void mostrarUnAnimal(animal aux);
///MOSTRAR ARCHIVO ANIMALES
void mostrarArchiAnimales(char archivo[]);

#endif // ANIMLES_H_INCLUDED
