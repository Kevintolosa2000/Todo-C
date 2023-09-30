#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"
#include <string.h>
typedef struct
{
    int matricula;
    char nombre[20];
    char genero;

} alumnos;

typedef struct
{
    int matricula;
    char nombre[20];
    char genero;

} alumnosb;
int cargaArregloStruct (alumnos A[], int dimension);
void mostrarStEstudiantes (alumnos  A[], int validos);
void mostrarUnEstudiantes (alumnos  A[], int x);
int buscarAlumno (alumnos A[], int validos, int matriculaext);
int buscaPosicionMenorIntSt(alumnos a[], int v, int pos);
void ordenaArregloSeleccionSt(alumnos a[], int validos);
void buscarAlumnoPorGenre (alumnos A[], int validos, char genero);
//int compararAlumnos (stalumnos alumnos[],int dim, char nombre[]);
//int compararAlumnosRetrnoI (stalumnos alumnos[],int dim, char nombre[]);




int main()
{
    srand(time(NULL));
    char nombre [20];
    int numero=0,validos=0,matriculaext=0, x=0, alumno;
    int unArreglo[50];
    char genero, p;
    char control='s';
    alumnos a[100];

    while (control == 's')
    {
        system("cls");

        puts("1-Hacer una funcion que cargue un arreglo de alumnos, hasta que el usuario lo decida. \n");
        puts("2-Hacer una funcion que muestre un arreglo de alumnos por pantalla. Modularizar.\n");
        puts("3-Hacer una funcion que muestre por pantalla los datos de un alumno, conociendo su matricula. Modularizar.\n");
        puts("4-Hacer una funcion que ordene el arreglo de alumnos por medio del metodo de seleccion. El criterio de ordenacion es el numero de matricula.\n");
        puts("5-Hacer una funcion que muestre por pantalla los datos de los estudiantes de un genero determinado (se envia por parametro).\n");
        puts("6-Hacer una funcion que inserte en un arreglo ordenado por matricula un nuevo dato, conservando el orden.\n");
        printf("Que ejercicio queres hacer? ");
        scanf("%d", &numero);
        switch (numero)
        {
        case 1:

            printf("\n--PUNTO 1--\n");

            validos=cargaArregloStruct(a, 50);
            printf("%d", validos);

            break;
        case 2:
            printf("\n--PUNTO 2--\n");
            mostrarStEstudiantes(a, validos);

            system("pause");
            break;
        case 3:
            printf("\n--PUNTO 3--\n");
            printf("De que alumno deseas saber los datos?: ");
            scanf("%d", &matriculaext);
            x=buscarAlumno(a, validos, matriculaext);
            mostrarUnEstudiantes(a, x);
            system("pause");
            break;
        case 4:
            printf("\n--PUNTO 4--\n");
            ordenaArregloSeleccionSt(a, validos);
            mostrarStEstudiantes(a, validos);
            system("pause");
            break;
        case 5:
            printf("\n--PUNTO 5--\n");
            printf("De que genero prefiere saber los datos? (M/F): ");
            fflush(stdin);
            scanf("%c", &genero);
            buscarAlumnoPorGenre(a, validos, genero);
            system("pause");
            break;
        case 6:
            printf("\n--PUNTO 6--\n");
            ordenaArregloSeleccionSt(a, validos);
            mostrarStEstudiantes(a, validos);
            system("pause");
            break;
        case 7:
            ordenarporseleccion(a,validos);
            printf("Ingrese los datos del alumno");
            cargaArregloStruct(a,100);
            insertarOrdenado(a,validos,a);
            mostrarStEstudiantes(a,validos);
            system("pause");
            break;
        case 8:
            printf("\n--PRUEBA--\n");
            printf("Escriba el nombre del alumno que desea encontrar");
            fflush(stdin);
            scanf("%s",&nombre);
            alumno=buscarAlumnopornombre(a,validos,nombre);
            mostrarUnEstudiantes(a,alumno);
            system("pause");

        default:
            printf("No abarca los puntos del tp");
            break;
        }
        system("cls");
        printf("\nDESEA CARGAR continuar -[S]-[N]-: ");
        fflush(stdin);
        scanf("%c", &control);
    }
    return 0;
}

void buscarAlumnoPorGenre (alumnos A[], int validos, char genero)
{
    for (int i=0; i< validos; i++)
    {
        if(A[i].genero==genero)
        {
            mostrarUnEstudiantes(A,i);
        }

    }
}

int cargaArregloStruct (alumnos A[], int dimension)
{
    int i=0;
    char control = 's';
    while(i<dimension && control=='s')
    {

        printf("\nIngrese matricula: ");
        scanf("%d", &A[i].matricula);
        printf("\nIngrese nombre: ");
        fflush(stdin);
        scanf("%s", &A[i].nombre);
        printf("\nIngrese genero: ");
        fflush(stdin);
        scanf("%c",&A[i].genero);
        i++;
        printf("\nDesea agregar otro registro?: ");
        fflush(stdin);
        scanf("%c", &control);
    }
    return i;
}

void mostrarStEstudiantes (alumnos  A[], int validos)
{
    system("cls");
    int i=0;
    while(i<validos)
    {
        puts("Estos son los datos de los estudiantes");
        printf("Matricula:%d\n", A[i].matricula);
        printf("nombre:%s\n", A[i].nombre);
        printf("genero:%c\n", A[i].genero);
        i++;
    }
}
void mostrarUnEstudiantes (alumnos  A[], int x)
{
    puts("Estos son los datos de los estudiantes");
    printf("Matricula:%d\n", A[x].matricula);
    printf("Nombre:%s\n", A[x].nombre);
    printf("genero:%c\n", A[x].genero);
}

int buscarAlumno (alumnos A[], int validos, int matriculaext)
{
    int i=0, posicion=0;
    int flag=0;


    while (i<validos && flag==0)
    {
        if(A[i].matricula==matriculaext)
        {
            flag=1;
            posicion=i;
        }
        i++;
    }
    return posicion;
}

int buscaPosicionMenorIntSt(alumnos a[], int v, int pos)
{
    int i=pos;
    int menor = a[i].matricula;
    int posMenor = i;

    while(i<v)
    {
        if(a[i].matricula < menor)
        {
            menor = a[i].matricula;
            posMenor = i;
        }
        i++;
    }

    return posMenor;
}
int buscarmenor (alumnos a[], int validos, int pos)
{

    int i =pos;
    int menor= a[i].matricula;
    int posmenor = i;

    while (i<validos)
    {
        if(a[i].matricula < menor)
        {

            menor= a[i].matricula;
            posmenor=i;

        }
        i++;
    }
    return posmenor;

}
void ordenarporseleccion (alumnos a[], int validos)
{
    int posmenor;
    alumnos b;
    int i=0;
    while(i<validos-1)
    {
        posmenor=buscarmenor(a,validos,i);
        b=a[posmenor];
        a[posmenor]=a[i];
        a[i]=b;
        i++;
    }
}

///------------------.........................................
void ordenaArregloSeleccionSt(alumnos a[], int validos)
{
    int posMenor;
    alumnos aux;
    int i = 0;
    while(i<validos-1)
    {
        posMenor=buscaPosicionMenorIntSt(a, validos, i);
        aux = a[posMenor];
        a[posMenor] = a[i];
        a[i] = aux;
        i++;
    }
}


int buscarAlumnopornombre (alumnos A[], int validos, char nombre [])
{
    int i=0, posicion=0;
    int flag=0;


    while (i<validos && flag==0)
    {
        if(strcmp(A[i].nombre, nombre)==0)
        {
            flag=1;
            posicion=i;
        }
        i++;
    }
    return posicion;
}

//int compararAlumnosRetrnoI (stalumnos alumnos[],int dim, char nombre[])
//{
//    int i=0;
//    int flag=0;
//
//    while (i<dim && flag==0)
//    {
//        if(strcmp(alumnos[i].nombre, nombre)==0)
//        {
//            flag=1;
//        }
//        i++;
//    }
//    return i-1;
//}

void alumnoIgual (int flag)
{
    if (flag==1)
    {
        printf("\nUsuario ya registrado, por favor vuelva a intentarlo\n");

    }
}

int insertarOrdenado(alumnos A[], int validos, alumnos dato)
{
    int i = validos - 1;

    while (i >= 0 && A[i].matricula > dato.matricula)
    {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = dato;

    return validos + 1;
}

