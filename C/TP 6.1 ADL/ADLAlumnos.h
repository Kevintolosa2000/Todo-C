#ifndef ADLALUMNOS_H_INCLUDED
#define ADLALUMNOS_H_INCLUDED
#include "listaAlumno.h"
#include "notaAlumno.h"
#include <string.h>

typedef struct
{
    int idMateria;
    char materia[40];
    nodo * lista;
}celda;

typedef struct
{
    int nota;
    int legajo;
    char nombreApe[40];
    char materia[40];
    int idMateria;
}registroArchivo;

///ALTA DE ARREGLO DE LISTAS
int alta(celda adl[],char materia[],int idMateria,notaAlumno nuevo,int validos);
///BUSCAR POS MATERIA
int buscaPosMateria(celda adl[],int idMateria,int validos);
///AGREGAR MATERIA
int agregarMateria(celda adl[],char materia[],int idMateria,int validos);
///PASAR ARCHIVO TO ADL
int pasarArchivoToADL(celda ald[], int dimension, char archivo[]);
///MOSTRAR ADL
void mostrarADL(celda adl[],int validos);
///GUARDAR ADL EN ARCHIVO
void pasarADLtoArchivo(celda adl[],int validos,char archivo[]);

#endif // ADLALUMNOS_H_INCLUDED
