#ifndef NOTAALUMNO_H_INCLUDED
#define NOTAALUMNO_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int nota;
    int legajo;
    char nombreApe[40];
}notaAlumno;

///MOSTRAR NOTA ALUMNO
void mostrarNotaAlumno(notaAlumno aux);

#endif // NOTAALUMNO_H_INCLUDED
