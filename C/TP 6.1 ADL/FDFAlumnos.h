#ifndef FDFALUMNOS_H_INCLUDED
#define FDFALUMNOS_H_INCLUDED

#include "listaAlumno.h"
#include "notaAlumno.h"
#include <string.h>

typedef struct _nodoLDL
{
    int idMateria;
    char materia[40];
    nodo * listaNotas;
    struct _nodoLDL * siguiente;

}nodoLDL;

typedef struct
{
    int nota;
    int legajo;
    char nombreApe[40];
    char materia[40];
    int idMateria;
}registroArchivo;

///INICLISTALDL
nodoLDL * inicListaLDL();
///CREAR NUEVO NODO LDL
nodoLDL * crearNodoLDL(int idMateria, char materia[]);
///AGREGAR MATERIA
nodoLDL * subProgramaAgregarMateriaLDL(nodoLDL * listaMaterias,char materia[],int idMateria);
///AGREGAR AL FINAL MATERIA
nodoLDL * agregarAlFinalMateriaLDLRecur(nodoLDL * lista, nodoLDL * nuevoNodo);
///ALTA DE DE LISTA DE LISTAS
nodoLDL * altaLDL(nodoLDL * listaMaterias,char materia[],int idMateria,notaAlumno nuevo);
///BUSCAR POS MATERIA
nodoLDL * buscaPosMateriaLDL(nodoLDL * listaMaterias,int idMateria);
///PASAR ARCHIVO TO LDL
nodoLDL * pasarArchivoToLDL(nodoLDL* listaMaterias, char archivo[]);
///MOSTRAR LDL
void mostrarLDL(nodoLDL * listaMaterias);
///GUARDAR ADL EN ARCHIVO
void pasarLDLtoArchivo(nodoLDL * listaMaterias,char archivo[]);
///BUSCAR ULTIMO NODO
nodoLDL * buscarUltimoNodoLDL(nodoLDL * lista);


#endif // FDFALUMNOS_H_INCLUDED
