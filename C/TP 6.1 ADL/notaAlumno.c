#include "notaAlumno.h"


///MOSTRAR NOTA ALUMNO
void mostrarNotaAlumno(notaAlumno aux)
{
    printf("---------------------------------\n");
    printf("Alumno:        %s \n",aux.nombreApe);
    printf("Nro de legajo: %d \n",aux.legajo);
    printf("Nota:          %d \n",aux.nota);
}
