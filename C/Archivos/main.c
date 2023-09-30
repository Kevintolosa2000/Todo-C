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


void agregarAlFinal (char nombre_archivo[], int dato);
void mostrarArchivo (char nombre_archivo[], int dato);
int cocaretornable (char nombre_archivo[]);

int main()
{
    int numero=0, dato, x=0, edad=0, edad2=0, p=0, i=0, validos=0;
    srand(time(NULL));
    alumnos outOfTouch;
    char rutaDelArchivo []= {"archivoDeEnteros.dat"};
    char rutaDelArchivoAlumnos []= {"archivoDeAlumnos.dat"};
    Pila P;
    inicpila(&P);
    char control='s';

    while (control=='s')
    {
        system("cls");
        puts("1- Agregar un alumno\n");
        puts("2- Mostrar alumno\n");
        puts("3-Pasar legajo a una pila \n");
        puts("4- Retorna cantidad de alumnos mayores a \n");
        puts("5-Nombre por rango de edad \n");
        puts("6-info alumno mayor de edad \n");

        printf("Que ejercicio queres hacer? ");
        scanf("%d", &numero);
        switch (numero)
        {
        case 1:
            system("cls");
            printf("\n--PUNTO 1--\n");
            agregarUnAlumno(rutaDelArchivoAlumnos);
            break;
        case 2:
            system("cls");
            printf("\n--PUNTO 2--\n");
            mostrarAlumnos(rutaDelArchivoAlumnos);

            break;
        case 3:
            system("cls");
            printf("\n--PUNTO 3--\n");
            pasarAlumnosMayoresDeEdad(rutaDelArchivoAlumnos,&P);
            mostrarPila(&P);

            break;
        case 4:
            system("cls");
            printf("\n--PUNTO 4--\n");
            printf("indique la edad de los alumnos: ");
            scanf("%d", &edad);
            int cantdealumnos=contadoDeEdad(rutaDelArchivoAlumnos,edad);
            printf("La cantidad de alumnos mayores a %d es de: %d\n", edad, cantdealumnos);

            break;
        case 5:
            system("cls");
            printf("indique entre que edad desea saber los nombres");
            printf("Mayores a: ");
            scanf("%d", &edad);
            printf("Menores a: ");
            scanf("%d", &edad2);
            mostrarPorRangoDeEdad(rutaDelArchivoAlumnos, edad,edad2);
            break;
        case 6:
            alumnoMayor(rutaDelArchivoAlumnos);

            break;
        default:
            printf("No abarca los puntos del tp");
            break;
        }

        printf("\nDeseas Realizar otro ejercicio? (S/N)");
        fflush(stdin);
        scanf("%c",&control);
    }
    return 0;
}




int agregarUnAlumno (char nombre_archivo[])
{
    FILE * archivoDeAlumnos = fopen(nombre_archivo,"ab");
    alumnos a;
    int i=0;
    char control='s';
    int legajo;
    legajo= ultimolegajo(nombre_archivo);
    a.legajo= legajo+1;

    if (archivoDeAlumnos!=NULL)
    {

        while (i<2)
        {
            printf("\nIngrese nombre y apellido: ");
            fflush(stdin);
            gets(a.nombreYapellido);
            printf("\nIngrese la edad: ");
            scanf("%d", &a.edad);
            printf("\nIngrese el anio que cursa: ");
            scanf("%d", &a.anio);
            fwrite(&a,sizeof(alumnos),1,archivoDeAlumnos);
            i++;
            system("cls");
            printf("\nDesea agragar otro alumno? (S/N): ");
            fflush(stdin);
            scanf("%c", &control);
        }
        fclose(archivoDeAlumnos);
    }
    return i;
}
void mostrarAlumnos (char nombre_archivo[])
{
    alumnos a;
    FILE * archivoDeAlumnos = fopen(nombre_archivo,"rb");

    if (archivoDeAlumnos!=NULL)
    {
        while (fread(&a,sizeof(alumnos),1,archivoDeAlumnos)>0)
        {
            mostrarAlumnoX(a);
        }
    }
    fclose(archivoDeAlumnos);
}

void mostrarAlumnoX(alumnos a)
{
    puts("\n---------------");
    printf("\n Legajo:%d",a.legajo);
    printf("\n NombreyApellido:%s",a.nombreYapellido);
    printf("\n Edad:%d",a.edad);
    printf("\n Anio:%d", a.anio);
    puts("\n---------------");
}

int ultimolegajo(char nombre_archivo[])
{
    int al = 0;
    alumnos a;

    FILE *archivoDeAlumnos = fopen(nombre_archivo,"rb");

    if(archivoDeAlumnos != NULL)
    {
        while(fread(&a,sizeof(alumnos),1,archivoDeAlumnos)>0)
        {
            al = a.legajo;
        }

    }

    fclose(archivoDeAlumnos);

    return al;
}

int pasarAlumnosMayoresDeEdad (char nombre_archivo[],Pila *P)
{
    alumnos a;
    FILE * archivoDeAlumnos = fopen(nombre_archivo,"rb");

    if (archivoDeAlumnos!=NULL)
    {
        while (!feof(archivoDeAlumnos))
        {
            fread(&a,sizeof(alumnos),1,archivoDeAlumnos);

            if (!feof(archivoDeAlumnos))
            {
                if (a.edad<18)
                {
                    apilar(P, a.legajo);
                }
            }
        }
        fclose(archivoDeAlumnos);
    }

}

void mostrarPila (Pila *p)
{
    mostrar(p);
}

int contadoDeEdad (char nombre_archivo [], int edad)
{
    int i=0;
    alumnos a;
    FILE *archivoDealUMNOS=fopen(nombre_archivo,"rb");

    if(archivoDealUMNOS!=NULL)
    {
        while (!feof(archivoDealUMNOS))
        {
            fread(&a,sizeof(alumnos),1,archivoDealUMNOS);

            if(!feof(archivoDealUMNOS))
            {
                if (a.edad > edad)
                {
                    i++;
                }
            }
        }
        fclose(archivoDealUMNOS);
    }
    return i;
}

int mostrarPorRangoDeEdad (char nombre_archivo [], int edad, int edad2)
{
    int i=0;
    alumnos a;
    FILE *archivoDealUMNOS=fopen(nombre_archivo,"rb");

    if(archivoDealUMNOS!=NULL)
    {
        while (!feof(archivoDealUMNOS))
        {
            fread(&a,sizeof(alumnos),1,archivoDealUMNOS);

            if(!feof(archivoDealUMNOS))
            {
                if ((a.edad > edad) && (a.edad < edad2))
                {
                    printf("\n Alumno:%s ", a.nombreYapellido);
                }
            }
        }
        fclose(archivoDealUMNOS);
    }
    return i;
}


int alumnoMayor (char nombre_archivo [])
{
    alumnos a, mayor,i;
    FILE *archivoDealUMNOS=fopen(nombre_archivo,"rb");

    if(archivoDealUMNOS!=NULL)

        fread(&i,sizeof(alumnos),1,archivoDealUMNOS);
    {
        while (!feof(archivoDealUMNOS))
        {
            fread(&a,sizeof(alumnos),1,archivoDealUMNOS);

            if( fread(&mayor,sizeof(alumnos),1,archivoDealUMNOS)>0)
            {
                if (a.edad < mayor.edad)
                {
                    a=i;


                }
            }
        }
        mostrarAlumnoX(a);
        fclose(archivoDealUMNOS);
    }
}
void mostrarAlumno(alumnos a)
{
    puts("\n---------------");
    printf("Legajo:%d",a.legajo);
    printf("\nNombreyApellido:%s",a.nombreYapellido);
    printf("\nEdad:%d",a.edad);
    puts("\n---------------\n");
}


void muestraAlumnoFalopa (char nombre_archivo[])
{
    system("cls");
    alumnos a;
    FILE * archivoDeAlumnos= fopen(nombre_archivo, "rb");
    if(archivoDeAlumnos!=NULL)
    {
        while(fread(&a,sizeof(alumnos), 1, archivoDeAlumnos)>0)
        {
            mostrarAlumno(a);
        }
    }
    fclose(archivoDeAlumnos);
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

int cocaretornable (char nombre_archivo[])
{
    int i=0, dato=0;
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
                }
            }

        }
        fclose(archivoDeAlumnos);
    }
    return i;
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
    system("cls");
    alumnos a;
    FILE * archivoDeAlumnos= fopen(nombre_archivo, "rb");
    if(archivoDeAlumnos!=NULL)
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
    archivoDeAlumnos=fopen(nombre_archivo, "rb");
    if(archivoDeAlumnos!=NULL)
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

void verNombresRangoEdad (char nombre_archivo[], int edad, int edad2)
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
                if ((a.edad>=edad) && (a.edad<=edad2))
                {
                    mostrarAlumno(a);
                    puts("Estos son los datos de los estudiantes");
                }
            }

        }
        fclose(archivoDeAlumnos);
    }
}
void mostrarUnEstudiante (char nombre_archivo[])
{
    FILE * archivoDeAlumnos;
    alumnos a;
    archivoDeAlumnos=fopen(nombre_archivo, "rb");
    if(archivoDeAlumnos!=NULL)
    {
        fread(&a,sizeof(alumnos),1, archivoDeAlumnos);
        puts("Estos son los datos de los estudiantes");
        printf("Nombre:%s\n", a.nombreYapellido);
    }
    fclose(archivoDeAlumnos);
}

void buscaAlumnoMayorEdad(char nombreArchivo[])
{
    FILE * archivoDeAlumnos;
    alumnos mayor,aux;
    archivoDeAlumnos=fopen(nombreArchivo,"rb");
    if(archivoDeAlumnos!=NULL)
    {
        fread(&mayor,sizeof(alumnos),1,archivoDeAlumnos);
        while(fread(&aux,sizeof(alumnos),1,archivoDeAlumnos)>0)
        {
            if(aux.edad>mayor.edad)
            {
                mayor=aux;
            }
//            printf("El alumno de mayor edad en el archivo es:\n");
//            mostrarAlumno(mayor);
            //fclose(archivoDeAlumnos);
        }
        printf("El alumno de mayor edad en el archivo es:\n");
        mostrarAlumno(mayor);
        fclose(archivoDeAlumnos);
    }
}



void mostrarAlumno(alumnos a)
{
    puts("\n---------------");
    printf("Legajo:%d",a.legajo);
    printf("\nNombreyApellido:%s",a.nombreYapellido);
    printf("\nEdad:%d",a.edad);
    puts("\n---------------\n");
}


void muestraAlumnoFalopa (char nombre_archivo[])
{
    system("cls");
    alumnos a;
    FILE * archivoDeAlumnos= fopen(nombre_archivo, "rb");
    if(archivoDeAlumnos!=NULL)
    {
        while(fread(&a,sizeof(alumnos), 1, archivoDeAlumnos)>0)
        {
            mostrarAlumno(a);
        }
    }
    fclose(archivoDeAlumnos);
}

int buscaPosicionMenorIntSt(alumnos a[], int v, int pos)
{
    int i=pos;
    int menor = a[i].legajo;
    int posMenor = i;
    i++;
    while(i<v)
    {
        if(a[i].legajo < menor)
        {
            menor = a[i].legajo;
            posMenor = i;
        }
        i++;
    }

    return posMenor;
}

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

void pasarArregloAlArchivo (char nombre_archivo[], alumnos outOfTouch[], int validos)
{
    FILE * archivoDeAlumnos;
    archivoDeAlumnos=fopen(nombre_archivo, "ab");
    if(archivoDeAlumnos!=NULL)
    {
        fwrite(outOfTouch,sizeof(alumnos), validos, archivoDeAlumnos);
    }
    fclose(archivoDeAlumnos);
}

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
    return cantidad+1;
}

///Dado un archivo de alumnos, que tenga al menos 10 registros,
///hacer una funcion que muestre el contenido de un registro, cuyo numero (entre 0 y 9)
///se pase por parametro. Controlar no sobrepasar los limites del archivo



void mostrarAlumnoArchivo(char nombre_archivo[], int i)
{
    FILE * archivodealumnos;
    alumnos a;
    archivodealumnos=fopen(nombre_archivo,"rb");
    if (i<10)
    {
        if(archivodealumnos!=NULL)
        {
            fseek(archivodealumnos,sizeof(alumnos)*(i-1), SEEK_SET);
            fread(&a, sizeof(alumnos), 1, archivodealumnos);
            fclose(archivodealumnos);
            mostrarAlumno(a);
        }
    }
    else
    {
        printf("flaco ?????");
    }
}

void modificarUnRegistro(char nombreArchivo[],int legajo)
{
    FILE*archi=fopen(nombreArchivo,"r+b");
    alumnos aux;
    char nuevoNombreYApellido[30];
    int flag=0;
    if(archi!=NULL)
    {
        while(!feof(archi)&& flag ==0)
        {
            if(fread(&aux,sizeof(alumnos),1,archi)>0)
            {
                if(aux.legajo == legajo)
                {
                    flag=1;
                }
            }
        }
    }
    if(flag ==1)
    {
        /// modificar el registro o darle de baja
        printf("\n\n\n\t\rLo encontreeeee!! \nque nombre queres ponerle brother?? ");

        ///PORQUE NO ME DEJAAAA :(
        fflush(stdin);
        gets(nuevoNombreYApellido);
        ///scanf("%s", nuevoNombreYApellido);
        strcpy(aux.nombreYapellido,nuevoNombreYApellido);
        /// me muevo un registro para atras
        fseek(archi, -1*sizeof(alumnos),SEEK_CUR);
        /// sobre escribe el registro
        fwrite(&aux,sizeof(alumnos),1,archi);
        mostrarAlumno(aux);
    }
    fclose(archi);
}

int validaridEquipo(int id, char equipos[])
{
    FILE * archivin=NULL;
    stEquipo aux;
    int flag=0;
    archivin=fopen(equipos,"rb");

    if(archivin!=NULL)
    {
        while(flag==0 && !feof(archivin))
        {
            fread(&aux,sizeof(stEquipo),1,archivin);
            if(!feof(archivin))
            {
                if(aux.idEquipo==id)
                {
                    flag=1;
                }

            }

        }
        fclose(archivin);
    }
    else
    {
        printf("ERROR DE DATOS-El archivo no pudo sex abierto\n");
    }
    return flag;
}


int cargaArregloJugador (stJugador A[], int dimension, char nombre_archivo[], char name [])
{
    int i=0, flag=0, equipo=0;
    FILE * archiDejugador;
    FILE * archiDeEquipo;
    archiDejugador=fopen(nombre_archivo, "rb");
    archiDeEquipo=fopen(name, "rb");
    char control = 's';
    while(i<dimension && control=='s')
    {
        A[i].idJugador=cuentaRegistroArchivo(archiDejugador)+1;
        do
        {
            printf("\nIngrese Equipo: ");
            scanf("%d", &equipo);
            flag=validaridEquipo(equipo, name);
            if(flag==0)
            {
                printf("No existe el id");
            }
        }
        while(flag==0);

        A[i].idEquipo=equipo;

        printf("\nIngrese nombre: ");
        fflush(stdin);
        gets(A[i].nombre);
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

void pasarArregloAlArchivoJugador (char nombre_archivo[], stJugador jugador[], int validos)
{
    FILE * archiDejugador;
    archiDejugador=fopen(nombre_archivo, "wb");
    if(archiDejugador!=NULL)
    {
        fwrite(jugador,sizeof(stJugador), validos, archiDejugador);
    }
    fclose(archiDejugador);
}

int cuentaRegistroArchivoJugador(char nombre_archivo[])
{
    int cantidad=0;
    FILE*archiJugador;
    archiJugador=fopen(nombre_archivo,"rb");
    if(archiJugador!=NULL)
    {
        // me posiciono al final del archiva
        fseek(archiJugador,0,SEEK_END);
        // divido la cantidad de bytes del archiJugador por la cantidad de
        // bytes de un registro de alumnos

        cantidad= ftell(archiJugador)/sizeof(stJugador);
        fclose(archiJugador);
    }
    return cantidad;
}












int cargarArchivo(char nombre_archivo[])
{
    int i=0;
    char control = 's';
    stAlgo a;


    FILE * archi;

    archi=fopen(nombre_archivo,"wb");

    if(archiJugador!=NULL)
    {
        printf("Ingreso de : \n");
        while(control=='s')
        {
            printf("\n Ingrese numero: ");
            scanf("%d", &a.);
            fwrite(&a,sizeof(stAlgo),1,archi);
            i++;
            printf("\nDesea agregar otro registro?: ");
            fflush(stdin);
            scanf("%c", &control);
        }
        fclose(archi);
    }
    return i;
}

void muestraAlgoFalopa (char nombre_archivo[])
{
    system("cls");
    stAlgo a;
    FILE * archi= fopen(nombre_archivo, "rb");
    if(archi!=NULL)
    {
        while(fread(&a,sizeof(stAlgo), 1, archi)>0)
        {
            mostrarJugador(a);
        }
    }
    fclose(archi);
}


void mostrarAlgo(stAlgo a)
{
    puts("\n---------------");
    printf("NOMBRE:%s",a.nombre);
    printf("\n:%d",a.);
    printf("\n:%d",a.);
    printf("\nEDAD:%d",a.edad);
    puts("\n---------------\n");
}

void mostrarStAlumnos (char nombre_archivo[])
{

    stAlumnos a;
    FILE * archivoDeAlumnos= fopen(nombre_archivo, "rb");
    if(archivoDeAlumnos!=NULL)
    {
        while(fread(&a,sizeof(stAlumnos), 1, archivoDeAlumnos)>0)
        {
            puts("Estos son los datos de los estudiantes");
            printf("Matricula:%d\n", a.matricula);
        }
    }
    fclose(archivoDeAlumnos);
}


int contarAlumnos(char aContar[])
{
    FILE * archivin=NULL;

    int cantAlumnos=0;
    stAlumnos aux;
    archivin=fopen(aContar,"rb");

    if(archivin!=NULL)
    {
        while(fread(&aux,sizeof(stAlumnos),1,archivin) > 0)
        {
            cantAlumnos++;
        }

        fclose(archivin);
    }
    else
    {
        // printf("AUN NO SE HAN CARGADO JUGADORES EN EL ARCHIVO \n");
    }

    return cantAlumnos;
}


int validarAlgo(int id, char nombre_archivo[])
{
    FILE * archi=NULL;

    stAlgo aux;
    int flag=0;

    archi=fopen(nombre_archivo,"rb");

    if(archi!=NULL)
    {
        while(flag==0 && !feof(archi))
        {
            fread(&aux,sizeof(stAlgo),1,archi);
            if(!feof(archi))
            {
                if(aux.idEquipo == id)
                {
                    flag=1;
                }
            }
        }
        fclose(archi);
    }
    else
    {
        printf("ERROR DE DATOS - El archivo no pudo ser abierto \n");
    }

    return flag;

}


int cargarArregloAlgo(stJugador a[],int dim, char equiposNo[], char jugadoresTotal[])
{
    FILE * nazi;
    nazi=fopen(equiposNo, "rb");
    int i=0;
    int aux=0, verificacionId=0;
    char control='s';

    printf("Ingresemos sus Jugadores \n");

    while(control=='s' && i<dim)
    {
        system("cls");
        printf("Por favor ingrese el nombre del jugador: \n");
        fflush(stdin);
        gets(a[i].nombre);

        printf("Por favor ingrese la edad del mismo: \n");
        scanf("%d", &a[i].edad);

        do
        {
            printf("Ingrese ID del equipo al cual pertenece el jugador: \n");
            scanf("%d", &aux);
            verificacionId=validarIdEquipo(aux,equiposNo);

            if(verificacionId == 0)
            {
                printf("ID de equipo invalido por favor ingrese un ID existente \n");
            }
            else
            {
                printf("ID de equipo valido, jugador cargado correctamente \n");
                a[i].idEquipo=aux;
            }

        }
        while(verificacionId == 0);

        a[i].idJugador=contarJugadores(jugadoresTotal)+(1+i);

        printf("Desea ingresar otro jugador? --> s/n \n");
        control=getch();

        i++;

    }

    return i;

}


void cargarTotalDeJugadoresAArchivo(stJugador a[], int validos, char jugTot[])
{
    FILE * archivin=NULL;

    archivin=fopen(jugTot,"ab");
    int i=0;

    if(archivin!=NULL)
    {
        fwrite(a,sizeof(stJugador),validos,archivin);
        fclose(archivin);
    }
    else
    {
        printf("ERROR DE DATOS - El archivo no pudo ser abierto \n");
    }


}

void mostrarArregloJugadores(stJugador a[], int validos)
{
    int i=0;

    for(i=0; i<validos; i++)
    {
        mostrarUnJugador(a[i]);
    }

}


void categorizarEnJovenesYAdultos(stJugador jugadores[], int validos, char jugJunior[], char jugSenior[])
{
    FILE * junior=NULL;
    FILE * senior=NULL;

    int i=0;
    junior=fopen(jugJunior,"wb");
    senior=fopen(jugSenior,"wb");

    if(junior!= NULL && senior !=NULL)
    {
        for(i=0; i<validos; i++)
        {
            if(jugadores[i].edad>=30)
            {
                fwrite(&jugadores[i],sizeof(stJugador),1,senior);
            }
            else
            {
                fwrite(&jugadores[i],sizeof(stJugador),1,junior);
            }
        }
        fclose(junior);
        fclose(senior);
    }
    else
    {
        printf("ERROR DE DATOS - El archivo no pudo ser abierto \n");
    }

}

void mostrarArchivoDeJugadores(char aMostrar[])
{
    FILE * archi=NULL;
    archi=fopen(aMostrar,"rb");

    stJugador aux;

    if(archi!=NULL)
    {
        while(fread(&aux,sizeof(stJugador),1,archi) > 0)
        {
            mostrarUnJugador(aux);
        }
        fclose(archi);
    }
    else
    {
        printf("ERROR DE DATOS - El archivo no pudo ser abierto \n");
    }

}

void mostrarUnJugador(stJugador a)
{
    printf("------------------------------------------------\n");
    printf("                ID de jugador : %d \n", a.idJugador);
    printf("            Nombre del Jugador: %s \n", a.nombre);
    printf("                          Edad: %d \n", a.edad);
    printf("ID del equipo al que pertenece: %d \n",a.idEquipo);
    printf("------------------------------------------------\n");
}

void calcularPorcentajeMayoresACiertaEdad(int edad,char jugJunior[],char jugSenior [])
{
    float porcentaje=0;
    int cantJugadores=0;

    if(edad<30)
    {
        cantJugadores=contarJugadores(jugJunior);
        porcentaje=calcularPorcenaje(edad,cantJugadores,jugJunior);
        printf("El porcentaje de jugadores Juniors mayores a %d es de %.2f porciento \n", edad,porcentaje);
    }
    else
    {
        cantJugadores=contarJugadores(jugSenior);
        printf("cant jug senior %d \n", cantJugadores);
        porcentaje=calcularPorcenaje(edad,cantJugadores,jugSenior);
        printf("El porcentaje de jugadores Senior mayores a %d es de %.2f porciento \n", edad,porcentaje);
    }
}

void calcularPorcenaje(int edad,int cantJugadores, char archivoJug[])
{
    FILE * archivin=NULL;

    float porcentaje=0;
    stJugador aux;
    int mayores=0;

    archivin=fopen(archivoJug,"rb");

    if(archivin!=NULL)
    {
        while(fread(&aux,sizeof(stJugador),1,archivin)>0)
        {
            if(aux.edad > edad)
            {
                mayores++;
            }

        }
        porcentaje=(float)mayores*100/cantJugadores;
    }
    else
    {
        printf("ERROR DE DATOS - El archivo no pudo ser abierto \n");
    }

    printf("Este es el de la funcion %.2f", porcentaje);///acordate de que aca esta el error raro
}

void mostrarPorZonas(int f, int c, char equiposZona[f][c], int zona,char equipos[])
{
    int equiposValidos=0;

    equiposValidos=cargarArregloStringEquipos(f,c,equiposZona,zona,equipos);
    mostrarArregloStrings(f,c,equiposZona,equiposValidos,zona);
}

int cargarArregloStrings(int f, int j,char equiposZona[f][j], int zona,char equipos[])
{
    FILE * archivin=NULL;

    archivin=fopen(equipos,"rb");
    int i=0;
    stEquipo aux;

    if(archivin!=NULL)
    {
        while(fread(&aux,sizeof(stEquipo),1,archivin)>0)
        {
            if(aux.zona == zona)
            {
                strcpy(equiposZona[i],aux.nombre);
                i++;
            }
        }
        fclose(archivin);
    }
    else
    {
        printf("ERROR DE DATOS - El archivo no pudo ser abierto \n");
    }

    return i;
}

void mostrarArregloStrings(int f,int c, char equiposZona [f][c],int validos,int zona)
{
    int i=0;
    int j=1;

    printf("Equipos de la Zona %d : \n", zona);

    for(i=0; i<validos; i++)
    {
        printf(" > Equipo nro %d : %s \n",j, equiposZona[i]);
        j++;
    }
}

int VerificarEntreyEntre()
{
    int zona=0;

    do
    {
        printf("Por favor ingrese la zona de equipos que desea mostrar: \n");
        scanf("%d", &zona);

        if(zona<=3 && zona>=1)
        {
            printf("Zona ingresada correctamente \n");
        }
        else
        {
            printf("Zona de equipos invalida \n");
        }

    }
    while(zona > 3 || zona < 1);

    return zona;

}
