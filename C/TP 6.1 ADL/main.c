#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//#include "ADLAlumnos.h"
#include "FDFAlumnos.h"

#define archiR "archivoRegistros.dat"
#define archiR2 "archivoRegistros2.dat"


///CARGAR ARREGLO DE REGISTROS
int cargarArregloDeRegistros(registroArchivo a[],int dim);
///MOSTRAR REGISTROS
void mostrarRegistros(registroArchivo a[], int validos);
///MOSTRAR UN REGISTRO
void mostrarUnRegistro(registroArchivo a);
///CARGAR ARREGLO A ARCHIVO
void cargarArregloRegistrosAArchivo(registroArchivo a[], int validos, char archivo[]);
///MOSTRAR ARCHIVO DE REGISTROS
void mostrarArchivoDeRegistros(char archivo[]);

int main()
{
    registroArchivo arreglo[9];
    nodoLDL * listaLDL=inicListaLDL();

//    int validos=0;
//celda adl [10];

    //validos=cargarArregloDeRegistros(arreglo,9);
    //mostrarRegistros(arreglo,validos);
    //printf("ahora cargamos al archivo \n");
    //cargarArregloRegistrosAArchivo(arreglo,validos,archiR);
    //printf("cargando ... \n");
    //printf("Finalizado \n");

    mostrarArchivoDeRegistros(archiR);
    printf("Archivo mostrado funciono? \n");
//
//    validos=pasarArchivoToADL(adl,10,archiR);
//    printf("cargo el adl \n");
//    printf("AHORA MUESTRA EL ADL \n");
//    mostrarADL(adl,validos);
//    printf("AHORA GUARDAMOS EL ADL AL ARCHIVO \n");
//    pasarADLtoArchivo(adl,validos,archiR2);
//    printf("Chequeamos si cargo los datos bien en el archivo \n");
//    mostrarArchivoDeRegistros(archiR2);


    printf("AHORA PROBAMOS CON LISTA DE LISTA \n");
    listaLDL=pasarArchivoToLDL(listaLDL,archiR);
    printf("supuestamente cargamos el LDL \n");
    printf("\t\t\tahora deberia mostrar el LDL \n\n\n");
    mostrarLDL(listaLDL);
///Pasar LDL a archivo

    return 0;
}

///CARGAR ARREGLO DE REGISTROS
int cargarArregloDeRegistros(registroArchivo a[],int dim)
{
    int i=0;
    char continuar;

    do
    {
        printf("Por favor ingrese la nota \n");
        scanf("%d",&a[i].nota);

        printf("ingrese el ID de la materia \n");
        scanf("%d",&a[i].idMateria);

        printf("Ingrese el nombre y apellido del alumno \n");
        fflush(stdin);
        gets(a[i].nombreApe);

        printf("Ingrese el legajo del estudiante \n");
        scanf("%d", &a[i].legajo);

        printf("Ingrese el nombre de la materia \n");
        fflush(stdin);
        gets(a[i].materia);

        printf("Desea seguir cargando estudiantes? -> s/n \n");
        continuar=getch();

        i++;

    }
    while(i<dim && continuar == 's');

    return i;
}

///MOSTRAR REGISTROS
void mostrarRegistros(registroArchivo a[], int validos)
{
    int i=0;

    for(i=0; i<validos; i++)
    {
        mostrarUnRegistro(a[i]);
    }
}

///MOSTRAR UN REGISTRO
void mostrarUnRegistro(registroArchivo a)
{
    printf("========================= \n");
    printf("Nota :             %d \n",a.nota);
    printf("Nro de legajo:     %d \n", a.legajo);
    printf("Nombre Y Apellido: %s \n", a.nombreApe);
    printf("Materia:           %s \n", a.materia);
    printf("ID de materia:     %d \n", a.idMateria);
}

///CARGAR ARREGLO A ARCHIVO
void cargarArregloRegistrosAArchivo(registroArchivo a[], int validos, char archivo[])
{
    FILE * archi=fopen(archivo,"ab");

    if(archi)
    {
        fwrite(a,sizeof(registroArchivo),validos,archi);
        fclose(archi);
    }
}

///MOSTRAR ARCHIVO DE REGISTROS
void mostrarArchivoDeRegistros(char archivo[])
{
    FILE * archi=fopen(archivo,"rb");

    registroArchivo aux;

    if(archi)
    {
        while(fread(&aux,sizeof(registroArchivo),1,archi)>0)
        {
            mostrarUnRegistro(aux);
        }

        fclose(archi);
    }
}

