#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "pila.h"

int buscaCapicua(int A[], int validos);
int buscaArreglo(int A[], int validos, int elemento);
void muestraArreglos (int A[], int validos);
int sumaArreglos (int A[], int validos);
int cargaRand(int A[], int  dim);
int cargaManual( int  A[ ], int dimension);


void transfierePila(int A[],int validos, Pila * p);

void cargaManualFloat( float  A[ ], int dimension);
int CargaRandFloat(float A[], int  dim);
void muestraArreglosFloat (float A[], int validos);
float sumaFloat(float A[], int validos);


int buscaArregloChar(char A[], int validos, char elemento);
int cargaManualChar(char A[], int dimension);
void muestraArreglosChar (char A[], int validos);

int menu()
{
    int seleccion=0;
    printf("\n\nBienvenido a ejercicios con arreglos!\n\n");
    printf("\nIngrese el numero del ejercicio que desea realizar:\n");
    printf("\n---------------------------------------------------\n");
    printf("Hacer una función que reciba como parámetro un arreglo de números enteros y permita que el usuario ingrese valores al mismo por teclado.\n");
    printf("La función debe retornar la cantidad de elementos cargados en el arreglo (o pueden utilizar como puntero válidos).\n");
    printf("Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y los muestre por pantalla.\n");
    printf("Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y calcule la suma de sus elementos.\n");
    printf("Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos) cargados en él y una Pila. La función debe copiar los elementos del arreglo en la pila.\n");
    printf("Realizar una función que sume los elementos de un arreglo de números reales (float) de dimensión 100. \n");
    printf("Realizar una función que indique si un elemento dado se encuentra en un arreglo de caracteres.\n");
    printf("Realizar una función que inserte un carácter en un arreglo ordenado alfabéticamente, conservando el orden.\n");
    printf("Realizar una función que obtenga el máximo carácter de un arreglo dado.\n");
    printf("Realizar una función que determine si un arreglo es capicúa.\n");
    printf("Realizar una función que invierta los elementos de un arreglo.  (sin utilizar un arreglo auxiliar)\n");

    printf("Ordenar un arreglo según los siguientes métodos: Selección / Inserción\n");
    printf("Dados dos arreglos ordenados alfabéticamente, crear un tercer arreglo con los elementos de los dos primeros intercalados, de manera que quede un arreglo también ordenado alfabéticamente.\n");
    printf("Dado un el vector {1,5,6,7,8} escribir un programa que genere otro vector con la suma del contenido de todo los elementos anteriores al índice actual: {1,6,12,19,27}.\n");
    fflush(stdin);
    scanf("%d", &seleccion);
    return seleccion;

}





int main()
{
    Pila Principal;
    inicpila(&Principal);

    int Arreglo[100];
    int  dimension=100,validos=0,flag=0,posicion=0, seleccion=0;
    float  suma=0.0;
    char elemento;


    printf("\nHello arreglos!\n");
    validos=cargaManual(Arreglo, dimension);
    printf("\nValidos: %d\n", validos);
    muestraArreglos(Arreglo, validos);
    flag=buscaCapicua(Arreglo,validos);
    printf("\n flag %d\n", flag);
    system("pause");
    if(flag==0)
    {
        printf("\nEl arreglo no es capicua");
    }
    else
    {
        printf("\nEl arreglo es capicua");
    }
    //validos=CargaRandFloat(Arreglo, dimension);
    // MuestraArreglosFloat(Arreglo, validos);

    /* do
     {
         system("cls");

         switch(seleccion)
         {
         case 1:

             {
                 break;
             }
         case 2:

             {
                 break;
             }
         default
         {
             printf("El numero ingresado no pertenece a ninguno de los ejercicios.");
         }

         }


     }
     while(seleccion!=27);

         posicion=BuscaArregloChar(Arreglo,validos, elemento);
         if(posicion==0)
         {
             printf("No se encontro el elemento dentro del array, este esta en la posicion: %d",posicion );
         }else{
              printf("Se encontro el elemento dentro del array, este esta en la posicion: %d",posicion );
         }
     //suma=SumaFloat(Arreglo, validos);
     //printf("\nResultado de la suma de los elementos: %.1f\n", suma);



     */
    return 0;
}




int cargaArregloVali(int A[], int validos, int dimension)
{

    char opcion=0;
//probar si no sobrescribe el ultimo elemento
    while(validos<dimension && opcion != 27)
    {
        do
        {
            system("cls");
            printf("\n Ingresa un dato: ");
            scanf("%d", &A[validos]);
            if(A[validos]>100)
            {
                printf("\n Dato invalido, ingrese un numero menor a 100");
                getch();
            }
        }
        while(A[validos]>100);

        printf("\n ESC para salir o cualquier tecla para continuar");
        opcion=getch();
        validos++;
    }

    return validos;
}

void invierteArreglo(int A[], int validos)
{

    int i=0,fin=0,inversor=0;
    fin=validos-1;
    while(i<fin)
    {
        inversor=A[i];
        A[i]=A[fin];
        A[fin]=inversor;
        i++;
        fin--;
    }

}


int buscaMaximoChar(char A[], int validos, char * elemento)
{
    int i=0, posicion=0;
    char mayor=0;
    while(i<validos)
    {
        if(A[i]>mayor)
        {
            mayor=A[i];
        }
        i++;
    }
//despues del primer ciclo while tengo el "mayor" elemento del array de chars en la variable mayor, pero no la posicion.
    *elemento=mayor;
    for (i=0; i<validos; i++)
    {
        if(A[i]==mayor)
        {
            posicion=A[i];
        }
    }
    return posicion;
    //retorna la posicion por la funcion y modifica por puntero un char para indicar cual es el valor de esa posicion.
}

int insertaElementoChar(char A[], int validos, char elemento)
{
    int i=0;
    i=validos-1;

    while(i<=0 && elemento<A[i])
    {

        A[i+1]=A[i];
        i--;
    }
    A[i+1]= elemento;
    return validos+1;
}


int buscaElementoChar(char A[], int validos, char elemento)
{
    int flag=0, i=0;

    while(i<validos && flag==0)
    {
        if(elemento==A[i])
        {
            flag=1;
        }
        else
        {
            i++;
        }
    }
//Retorna 1 si el elemento esta presente y 0 si no.
    return flag;
}





int retornaMenor( int A[], int validos, int posicion)

{
    int menorval=0, menorpos=0;

    menorval=A[posicion];
    menorpos=posicion;


    while(posicion<validos)
    {

        if(menorval<A[posicion])
        {
            menorpos=posicion;
            menorval=A[posicion];

        }
        posicion++;

    }



    return menorpos;
}


void ordenaArregloSeleccion(int A[], int validos)
{
    int i=0,menor=0, j=0, posicion=0, buffer=0;

    while(j<validos)
    {

        menor=A[i];
        while(i<validos)
        {
            if(A[i]<menor)
            {
                menor=A[i];
                posicion=i;
            }
            i++;
        }
        //despues del primer while queda guardado en menor el menor valor absoluto
        buffer=A[j];
        A[j]=menor;
        A[posicion]=buffer;
//se intercambia la posicion del menor elemento y el que estuviera ocupando su lugar en el orden, para despues ser ordenado
        j++;
        i=j;
    }



}

void transfierePila(int A[],int validos, Pila * p)
{
    int i=0,aux=0;
    Pila Pilaux;
    inicpila(&Pilaux);

    for(i=0; i<validos; i++)
    {
        aux=A[i];
        apilar(p, aux);

    }

}


int cargaManual( int  A[ ], int dimension)
{

    int opcioncarga=0,i=0;
    char seguir;

    for(i=0; i<dimension && seguir!=27; i++)
    {

        printf("\nIngrese un valor para cargar al arreglo:");
        fflush(stdin);
        scanf("%d", &opcioncarga);
        A[i]=opcioncarga;

        printf("\nDesea seguir cargando datos? cualquier tecla para continuar, ESC para salir\n");
        fflush(stdin);
        seguir=getch();
    }
    return i;
}

int cargaRand(int A[], int  dim)
{
    int cantidad=0, i=0;
    printf("\nIngrese la cantidad de elementos para agregar al array, se cargaran numeros aleatorios del 1 al 100, siendo el maximo %d", dim-1);
    fflush(stdin);
    scanf("%d",&cantidad);
    printf("\nCargando %d elementos random en el array\n", cantidad);

    for(i=0; i<cantidad; i++)
    {
        A[i]=rand()%100+1;
    }

    return cantidad;

}

void muestraArreglos (int A[], int validos)
{
    int i=0;
    printf("\nContenido del arreglo\n");
    for(i=0; i<validos; i++)
    {

        printf(" %i ",A[i]);
    }

}

int sumaArreglos (int A[], int validos)
{
    int suma=0, i=0;
    for(i=0; i<validos; i++)
    {
        suma= suma+A[i];

    }
    return suma;
}


int buscaArreglo(int A[], int validos, int elemento)
{
    int i=0, flag=0,posicion=0;

    for(i=0; flag==0 && i<validos; i++)
    {

        if(A[i]== elemento)
        {
            flag=1;
            posicion=A[i];
        }

    }
    if(flag==0)
    {
        posicion=0;
    }


    return posicion;
}

void cargaManualFloat( float  A[ ], int dimension)
{

    int opcioncarga=0,cantidad=0;

    for(cantidad=0; cantidad<dimension; cantidad++)
    {

        printf("\nIngrese un valor para cargar al arreglo:");
        fflush(stdin);
        scanf("%d", &opcioncarga);
        A[cantidad]=opcioncarga;
    }

}

int cargaRandFloat(float A[], int  dim)
{
    int cantidad=0, i=0;
    printf("\nIngrese la cantidad de elementos para agregar al array, se cargaran numeros aleatorios del 1 al 100, siendo el maximo %d", dim-1);
    fflush(stdin);
    scanf("%d",&cantidad);
    printf("\nCargando %d elementos random en el array\n", cantidad);

    for(i=0; i<cantidad; i++)
    {
        A[i]=rand()%100+1;
    }
    return cantidad;
}

void muestraArreglosFloat (float A[], int validos)
{
    int i=0;
    printf("\nContenido del arreglo\n");
    for(i=0; i<validos; i++)
    {

        printf(" %.2f ",A[i]);
    }

}

float sumaFloat(float A[], int validos)
{
    float suma=0;
    int i=0;
    for(i=0; i<validos && i<99; i++)
    {
        suma= suma+A[i];
    }
    return suma;
}


void muestraArreglosChar (char A[], int validos)
{
    int i=0;
    printf("\nContenido del arreglo:");
    for(i=0; i<validos; i++)
    {

        printf(" %c ",A[i]);
    }

}


int cargaManualChar(char A[], int dimension)
{

    int i=0,flag=0;
    char opcioncarga, continuar;

    for(i=0; i<dimension && flag==0; i++)
    {

        printf("\nIngrese un caracter para cargar al arreglo:");
        fflush(stdin);
        scanf("%c", &opcioncarga);
        A[i]=opcioncarga;
        printf("Desea continuar? Presione cualquier tecla o ESC para salir");
        fflush(stdin);
        scanf("%c", &continuar);
        if(continuar==27)
        {
            flag=1;
        }
    }
    return i;
}


int buscaArregloChar(char A[], int validos, char elemento)
{
    int i=0, flag=0,posicion=0;

    for(i=0; flag==0 && i<validos; i++)
    {

        if(A[i]== elemento)
        {
            flag=1;
            posicion=A[i];
        }
        else
        {
            i++;
        }
    }
    if(flag==0)
    {
        posicion=0;
    }


    return posicion;
}



int buscaCapicua(int A[], int validos)
{
    int flag=0, i=0, j=0, capicua=0;
    j=validos-1;


    while(flag==0)
    {
        if(A[i]==A[j])
        {
            i++;
            j--;
        }
        else
        {
            flag=1;
        }
        if(i==j || j==i+1)
        {
            capicua=1;
            flag=1;
        }
    }
    return capicua;
}



