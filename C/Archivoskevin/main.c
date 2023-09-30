#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "pila.h"

typedef struct
{
    int legajo;
    char nombreYapellido[30];
    int edad;
    int anio;
} alumnos;

typedef struct
{
    char producto [100];
    int precio;
} productos;

void agregarAlFinal (char nombre_archivo[], int dato);
void mostrarArchivo (char nombre_archivo[], int dato);
int cocaretornable (char nombre_archivo[], int dato);

int main()
{
    int numero=0, dato, x=0, edad=0, i=0, p=0, validos=0;
    srand(time(NULL));
    alumnos outOfTouch;
    productos outOfTouchs;
    char rutaDelArchivo []= {"archivoDeEnteros.dat"};
    char rutaDelArchivoAlumnos []= {"archivoDeAlumnos.dat"};
    char rutaDelArchivoProductos []= {"archivoDeProductos.dat"};
    Pila mayor;
    inicpila(&mayor);



    puts("1- Hacer una funcion que agregue un elemento al final de un archivo.\n");
    puts("2- Hacer una funcin que muestre por pantalla el contenido de un archivo.\n");
    puts("3- Hacer una funcion que retorne la cantidad de registros que contiene un archivo.\n");
    puts("4- Crear una funcion que cargue un archivo de alumnos. Abrirlo de manera tal de verificar si el archivo ya esta creado previamente. Cargar el archivo con 5 datos. Cerrarlo dentro de la funcion.\n");
    puts("5- Crear una funcion que muestre por pantalla los registros de un archivo de alumnos. Modularizar\n");
    puts("6- Crear una funcion que permita agregar de a un elemento al final del archivo. O sea, se debe abrir el archivo, se piden los datos, se escribe en el archivo y se cierra.\n");
    puts("7- Crear una funcion que pase a una pila los numeros de legajo de los alumnos mayores de edad.\n");
    puts("8- Dado un archivo de alumnos, hacer una funcion que cuente la cantidad de alumnos mayores a edad especifica que se envia por parametro.\n");
    puts("9- Dado un archivo de alumnos, mostrar por pantalla el nombre de todos los alumnos entre un rango de edades especifico (por ejemplo, entre 17 y 25 años).\n");
    puts("10- Dado un archivo de alumnos, mostrar los datos del alumno de mayor edad.\n");
    puts("11- Crear una funcion que retorne la cantidad de alumnos que cursan de la edad de 6 años en adelante.\n");
    puts("12- Crear una funcion que reciba como parametro un arreglo de tipo alumno y lo copie en el archivo. Asimismo, realice otra funcion que pase los elementos del archivo a un arreglo de alumnos, filtrando los estudiantes de un año en particular.\n");
    puts("13- Crear una funcion que retorne la cantidad de registros que tiene el archivo. Usar fseek y ftell\n");
    printf("Que ejercicio queres hacer? ");
    scanf("%d", &numero);
    switch (numero)
    {
//    case 0:
//        cargarProductos(rutaDelArchivoProductos);
//        mostrarProductos(rutaDelArchivoProductos);
//        system("cls");
//        pasarArregloAlArchivo(rutaDelArchivoProductos,productos)
//        break;
    case 1:
        printf("\n--PUNTO 1--\n");
        printf ("que dato? ");
        scanf("%d", &dato);
        agregarAlFinal(rutaDelArchivo, dato);
        break;
    case 2:
        printf("\n--PUNTO 2--\n");
        printf ("que dato? ");
        scanf("%d", &dato);
        agregarAlFinal(rutaDelArchivo, dato);
        mostrarArchivo(rutaDelArchivo, dato);
        break;
    case 3:
        printf("\n--PUNTO 3--\n");
        printf ("Que dato?: ");
        scanf("%d", &dato);
        agregarAlFinal(rutaDelArchivo, dato);
        mostrarArchivo(rutaDelArchivo, dato);
        x=cocaretornable(rutaDelArchivo,dato);
        printf("\nEsta es la cantidad: %d", x);
        break;
    case 4:
        printf("\n--PUNTO 4--\n");
        cargaAlumnos(rutaDelArchivoAlumnos);
        mostrarStEstudiantes(rutaDelArchivoAlumnos);
        break;
    case 5:
        printf("\n--PUNTO 5--\n");
        cargaAlumnos(rutaDelArchivoAlumnos);
        mostrarStEstudiantes(rutaDelArchivoAlumnos);
        break;
    case 6:
        printf("\n--PUNTO 6--\n");
        cargaUnAlumno(rutaDelArchivoAlumnos);
        mostrarStEstudiantes(rutaDelArchivoAlumnos);
        break;
    case 7:
        printf("\n--PUNTO 7--\n");
        mostrarStEstudiantes(rutaDelArchivoAlumnos);
        buscarLegajo(rutaDelArchivoAlumnos, &mayor);
        mostrar(&mayor);
        break;
    case 8:
        printf("\n--PUNTO 8--\n");
        printf("desde que edad? ");
        scanf("%d", &edad);
        mostrarStEstudiantes(rutaDelArchivoAlumnos);
        p=contadorEdad(rutaDelArchivoAlumnos, edad);
        printf("estos son los alumnos mayores a %d: %d", edad, p);
        break;
    case 9:
        printf("\n--PUNTO 9--\n");
        mostrarStEstudiantes(rutaDelArchivoAlumnos);
        mostrarNombrePorEdad(rutaDelArchivoAlumnos);
        break;
    case 10:
        printf("\n--PUNTO 10--\n");
        mostrarStEstudiantes(rutaDelArchivoAlumnos);
        alumnoMayorDeEdad(rutaDelArchivoAlumnos);
        break;
    case 11:
        printf("\n--PUNTO 11--\n");
        printf("Que edad varon?: ");
        scanf("%d", &edad);
        mostrarStEstudiantes(rutaDelArchivoAlumnos);
        i=contadorPorEdad(rutaDelArchivoAlumnos,edad);
        printf("La cantidad de alumnos que cursan de %d son: %d", edad,i);
        break;
    case 12:
        printf("\n--PUNTO 12--\n");
        validos=cargaArregloStruct(&outOfTouch, 10);
        pasarArregloAlArchivo(rutaDelArchivoAlumnos, &outOfTouch, validos);
        mostrarStEstudiantes(rutaDelArchivoAlumnos);
        break;
    case 13:
        printf("\n--PUNTO 13--\n");
        x=cuentaRegistroArchivo(rutaDelArchivoAlumnos);
        printf("\n\n\n\t\t\t\t esta es la cantidad de alumnos registrados: %d\n\n\n\t\t\t\t", x);
        break;
    default:
        printf("No abarca los puntos del tp");
        break;
    }
    return 0;
}

void agregarAlFinal (char nombre_archivo[],int dato)
{
    FILE * archivoDeEnteros;
    archivoDeEnteros=fopen(nombre_archivo, "ab");

    if (archivoDeEnteros!=NULL)
    {
        fwrite(&dato, sizeof(int), 1, archivoDeEnteros);
        fclose(archivoDeEnteros);
    }
}

void mostrarArchivo (char nombre_archivo[], int dato)
{
    FILE * archivoDeEnteros;
    archivoDeEnteros=fopen(nombre_archivo, "rb");

    if (archivoDeEnteros!=NULL)
    {
        while (fread(&dato,sizeof (int), 1, archivoDeEnteros)>0)
        {
            printf(" /%d/ ", dato);
        }
        fclose(archivoDeEnteros);
    }
}

int cocaretornable (char nombre_archivo[], int dato)
{
    int i=0;
    FILE * archivoDeEnteros;
    archivoDeEnteros=fopen(nombre_archivo, "rb");

    if (archivoDeEnteros!=NULL)
    {
        fseek(archivoDeEnteros,sizeof(int)*0,SEEK_SET);

        while(fread(&dato,sizeof(int),1,archivoDeEnteros)>0)
        {
            i++;
        }
        fclose(archivoDeEnteros);
    }
    return i;
}

int contadorEdad(char nombre_archivo[],int edad)
{
    int i=0;
    alumnos a;
    FILE * archivoDeAlumnos;
    archivoDeAlumnos=fopen(nombre_archivo,"rb");

    if(archivoDeAlumnos!=NULL)
    {

        while(!feof(archivoDeAlumnos))
        {
            fread(&a,sizeof(alumnos), 1, archivoDeAlumnos);

            if(!feof(archivoDeAlumnos))
            {
                if(a.edad>edad)
                {
                    i++;
                    printf("%d\n", i);

                }
            }

        }
        fclose(archivoDeAlumnos);
    }
    return i;
}

void mostrarNombrePorEdad(char nombre_archivo[])
{
    FILE * archivoDeAlumnos;
    alumnos a;
    archivoDeAlumnos=fopen(nombre_archivo,"rb");

    if(archivoDeAlumnos!=NULL)
    {

        while(fread(&a,sizeof(alumnos), 1, archivoDeAlumnos)>0)
        {
            ///fread(&a,sizeof(alumnos), 1, archivoDeAlumnos);

            if((a.edad>17) && (a.edad<25))
            {

                printf("Nombre:%s\n", a.nombreYapellido);
            }


        }
        fclose(archivoDeAlumnos);
    }
}

int cargarProductos (char nombre_archivo[])
{
   int i=0;
    char control = 's';
    productos a;
    FILE * archivoDeProductos;

    archivoDeProductos=fopen(nombre_archivo,"ab");
    if(archivoDeProductos!=NULL)
    {
        printf("Ingreso de alumnos: \n");
        do
        {
            printf("\n Ingrese producto: ");
            fflush(stdin);
            gets(a.producto);
            printf("\n Ingrese precio: ");
            scanf("%d", &a.precio);
            fwrite(&a,sizeof(productos),1,archivoDeProductos);
            i++;
            fflush(stdin);
            printf("Desea continuar: ");
            scanf("%c", &control);
        }while (control=='s');

        fclose(archivoDeProductos);
    }
    return i;
}

void mostrarProductos (char nombre_archivo[])
{
    productos a;
    FILE * archivoDeProductos;
    archivoDeProductos = fopen(nombre_archivo, "rb");

    if (archivoDeProductos !=NULL)
    {
        while (fread(&a,sizeof(productos),1,archivoDeProductos)>0)
        {
            printf("Producto:%s\n", a.producto);
            printf("Precio:%d\n", a.precio);
        }
    }
     fclose(archivoDeProductos);
}
int cargaAlumnos(char nombre_archivo[])
{
    int i=0;
    char control = 's';
    alumnos a;


    FILE * archivoDeAlumnos;

    archivoDeAlumnos=fopen(nombre_archivo,"ab");

    if(archivoDeAlumnos!=NULL)
    {
        printf("Ingreso de alumnos: \n");
        while(control=='s')
        {
            printf("\n Ingrese legajo: ");
            scanf("%d", &a.legajo);
            printf("\n Ingrese nombre y apellido: ");
            fflush(stdin);
            gets(a.nombreYapellido);
            printf("\n Ingrese edad: ");
            scanf("%d",&a.edad);
            fwrite(&a,sizeof(alumnos),1,archivoDeAlumnos);
            i++;
            printf("\nDesea agregar otro registro?: ");
            fflush(stdin);
            scanf("%c", &control);
        }
        fclose(archivoDeAlumnos);
    }
    return i;
}

int cargaUnAlumno(char nombre_archivo[])
{
    int i=0;
    char control = 's';
    alumnos a;


    FILE * archivoDeAlumnos;

    archivoDeAlumnos=fopen(nombre_archivo,"ab");

    if(archivoDeAlumnos!=NULL)
    {
        printf("Ingreso de alumnos: \n");
        printf("\n Ingrese legajo: ");
        scanf("%d", &a.legajo);
        printf("\n Ingrese nombre y apellido: ");
        fflush(stdin);
        gets(a.nombreYapellido);
        printf("\n Ingrese edad: ");
        scanf("%d",&a.edad);
        fwrite(&a,sizeof(alumnos),1,archivoDeAlumnos);
        i++;
        fclose(archivoDeAlumnos);
    }
    return i;
}

void mostrarStEstudiantes (char nombre_archivo[])
{
    alumnos a;
    FILE * archivoDeAlumnos= fopen(nombre_archivo, "rb");
    if( archivoDeAlumnos!=NULL)
    {
        while(fread(&a,sizeof(alumnos), 1, archivoDeAlumnos)>0)
        {
            puts("Estos son los datos de los estudiantes");
            printf("Matricula:%d\n", a.legajo);
            printf("Nombre:%s\n", a.nombreYapellido);
            printf("Edad:%d\n", a.edad);
        }
    }
    fclose(archivoDeAlumnos);
}

void buscarLegajo (char nombre_archivo [],Pila * m)
{

    FILE * archivoDeAlumnos;
    int i=0;
    alumnos a;
    alumnos mayor;
    archivoDeAlumnos=fopen(nombre_archivo, "rb");
    if( archivoDeAlumnos!=NULL)
    {
        while(!feof(archivoDeAlumnos))
        {
            fread(&a,sizeof(alumnos),1, archivoDeAlumnos);

            if(!feof(archivoDeAlumnos))
            {
                if (a.edad>=18)
                {
                    apilar(m, a.legajo);
                }
            }
        }
        fclose(archivoDeAlumnos);
    }
}

int alumnoMayorDeEdad (char nombre_archivo[])
{
    FILE * archivoDeAlumnos;
    alumnos a, mayor;
    archivoDeAlumnos=fopen(nombre_archivo, "rb");

    if( archivoDeAlumnos!=NULL)
    {
        fread(&mayor,sizeof(alumnos),1, archivoDeAlumnos);

        while(fread(&a,sizeof(alumnos),1, archivoDeAlumnos)>0)
        {

            if(a.edad > mayor.edad)
            {
                mayor=a;
            }
        }
        printf("aca esta el alumno mas mayor: \n");
        mostrarAlumno(mayor);
        fclose(archivoDeAlumnos);
    }
}


void mostrarAlumno (alumnos x)
{
    printf("Matricula:%d\n", x.legajo);
    printf("Nombre:%s\n", x.nombreYapellido);
    printf("Edad:%d\n", x.edad);
}


int contadorPorEdad (char nombre_archivo[], int edad)
{
    FILE * archivoDeAlumnos;
    alumnos a;
    int i=0;
    archivoDeAlumnos=fopen(nombre_archivo, "rb");
    if(archivoDeAlumnos!=NULL)
    {
        while(!feof(archivoDeAlumnos))
        {
            fread(&a,sizeof(alumnos), 1, archivoDeAlumnos);

            if(!feof(archivoDeAlumnos))
            {
                if (a.edad>=edad)
                {
//                    mostrarAlumno(a);
//                    puts("Estos son los datos de los estudiantes");
                    i++;
                }
            }

        }
        fclose(archivoDeAlumnos);
    }
    return i;
}

int pasarAlArchivoNuevo (char nombre_archivo2[])
{

    FILE * archivoDePrecios;
    archivoDePrecios=fopen(nombre_archivo2, "rb");


}
char **Insertion_sort(char** words, int Max_lines)
{
    int i, j;
    char *temp;

    for( i = 1 ; i < Max_lines; i++)
    {
        strcpy(temp, words[i]);
        j = i-1;
        while ( j >= 0 && strcmp(words[j], temp)>0)
        {
            strcpy(words[j+1], words[j]);
            j=j-1;
        }
        strcpy(words[j+1],temp);
    }
    return words;
}

void pasarArregloAlArchivo (char nombre_archivo[], productos outOfTouch[], int validos)
{
    productos a;
    FILE * archivoDeProductos;
    archivoDeProductos=fopen(nombre_archivo, "ab");
    if(archivoDeProductos!=NULL)
    {
        outOfTouch=fwrite(&a,sizeof(productos), validos, archivoDeProductos);
    }
    fclose(archivoDeProductos);
}

//void pasarArregloAlArchivo (char nombre_archivo[], alumnos outOfTouch[], int validos)
//{
//    FILE * archivoDeAlumnos;
//    archivoDeAlumnos=fopen(nombre_archivo, "ab");
//    if(archivoDeAlumnos!=NULL)
//    {
//        fwrite(outOfTouch,sizeof(alumnos), validos, archivoDeAlumnos);
//    }
//    fclose(archivoDeAlumnos);
//}

int cargaArregloStruct (alumnos A[], int dimension)
{
    int i=0;
    char control = 's';
    while(i<dimension && control=='s')
    {

        printf("\nIngrese legajo: ");
        fflush(stdin);
        scanf("%d", &A[i].legajo);
        printf("\nIngrese nombre apellido: ");
        fflush(stdin);
        gets(A[i].nombreYapellido);
        printf("\nIngrese edad: ");
        fflush(stdin);
        scanf("%d",&A[i].edad);
        i++;
        printf("\nDesea agregar otro registro?: ");
        fflush(stdin);
        scanf("%c", &control);
    }
    return i;
}

int cuentaRegistroArchivo(char nombre_archivo[])
{
    int cantidad=0;
    FILE*archivodealumnos;
    archivodealumnos=fopen(nombre_archivo,"rb");
    if(archivodealumnos!=NULL)
    {
        // me posiciono al final del archiva
        fseek(archivodealumnos,0,SEEK_END);
        // divido la cantidad de bytes del archivodealumnos por la cantidad de
        // bytes de un registro de alumnos

        cantidad= ftell(archivodealumnos)/sizeof(alumnos);
        fclose(archivodealumnos);
    }
    return cantidad;
}






