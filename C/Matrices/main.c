#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"
#include <string.h>
void mostrarUnaMatriz (int filas, int columnas, int unaMatriz[filas][columnas]);
void cargarUnaMatrizrandom(int filas, int columnas, int M[filas][columnas]);
void cargaManual(int f, int c, int M[f][c]);
int sumarUnaMatriz (int filas, int columnas, int M[filas][columnas]);
int contarUnaMatriz (int filas, int columnas, int M[filas][columnas]);
float promedioMatriz (int filas, int columnas, int M[filas][columnas]);
int encuentraDatoMatriz(int f,int c, int M[f][c], int dato);
int cargarMatrizdePalabras(int filas, int columnas, int M[filas][columnas]);
void mostrarMatrizdePalabras(int filas, int columnas, int M[filas][columnas]);

int main()
{
    srand(time(NULL));
    int unaMatriz [10][10];
    char unaMatrizChar [10][10], unArregloC[10];
    int numero=0;
    int validos=0;
    int flag=2;
    puts("1-Hacer una funcion que reciba como parametro una matriz de numeros enteros y permita que el usuario ingrese valores al mismo por teclado. La funcion debe cargar la matriz por completo\n");
    puts("2-Hacer una funcion que reciba como parametro una matriz de numeros enteros y la muestre por pantalla (en formato matricial)\n");
    puts("3-Hacer una funcion que reciba como parametro una matriz de numeros enteros y que cargue la misma con numeros aleatorios (sin intervencion del usuario). La funcion debe cargar la matriz por completo\n");
    puts("4-Hacer una funcion tipo int que sume el contenido total de una matriz de numeros enteros\n");
    puts("5-Hacer una funcion tipo float que calcule el promedio de una matriz de numeros enteros\n");
    puts("6-Hacer una funcion que determine si un elemento se encuentra dentro de una matriz de numeros enteros. La funcion recibe la matriz y el dato a buscar.\n");
    puts("7-Hacer una funcion que cargue un arreglo de palabras (strings). La funcion debe retornar cuantas palabras se cargaron.  (puede ser a traves del parametro como puntero)");
    puts("8-Hacer una funcion que muestre un arreglo de palabras.\n");
    printf("Elija el caso a realizar\n");
    scanf("%d", &numero);

    switch (numero)
    {
    case 1:
        printf("\n--PUNTO 1--\n");
        cargaManual(2, 2, unaMatriz);
        mostrarUnaMatriz(2, 2, unaMatriz);
        break;
    case 2:
        printf("\n--PUNTO 2--\n");
        cargarUnaMatrizrandom(10, 10, unaMatriz);
        mostrarUnaMatriz(10, 10, unaMatriz);
        break;
    case 3:
        printf("\n--PUNTO 3--\n");
        cargarUnaMatrizrandom(10, 10, unaMatriz);
        mostrarUnaMatriz(10, 10, unaMatriz);
        break;
    case 4:
        printf("\n--PUNTO 4--\n");
        int suma=0;
        cargarUnaMatrizrandom(10, 10, unaMatriz);
        mostrarUnaMatriz(10, 10, unaMatriz);
        suma=sumarUnaMatriz(10, 10, unaMatriz);
        printf("La suma es %d", suma);
        break;
    case 5:
        printf("\n--PUNTO 5--\n");
        float promedio=0;
        cargarUnaMatrizrandom(10, 10, unaMatriz);
        mostrarUnaMatriz(10, 10, unaMatriz);
        promedio=promedioMatriz(10, 10, unaMatriz);
        printf("El promedio es es %0.02f", promedio);
        break;
    case 6:
        printf("\n--PUNTO 6--\n");
        int dato=0, band=0;
        cargarUnaMatrizrandom(3, 3, unaMatriz);
        mostrarUnaMatriz(3, 3, unaMatriz);
        printf("\nIngrese el dato a buscar: ");
        scanf("%d", &dato);
        band=encuentraDatoMatriz(3, 3, unaMatriz, dato);
        if(band==1)
        {
            printf("\n Su valor se encontro.");
        }
        else
        {
            printf("\nNo se encontro el elemento.");
        }
        break;
    case 7:
        printf("\n--PUNTO 7--\n");
        cargarMatrizdePalabras(10, 10, unaMatrizChar);
        break;
    case 8:
        printf("\n--PUNTO 8--\n");
        validos=cargarMatrizdePalabras(10,10,unaMatrizChar);
        mostrarMatrizdePalabras(validos,10,unaMatrizChar);
        break;
    case 9:
        printf("\n--PUNTO 9--\n");
        char palabra[30];
        validos=cargarMatrizdePalabras(3,3,unaMatrizChar);
        mostrarMatrizdePalabras(validos,3,unaMatrizChar);
        printf("que palabra varon?: ");
        fflush(stdin);
        scanf("%s", &palabra);
        flag=encuentraString(3, 3, unaMatrizChar, palabra);
        respuesta(flag);
        break;
    default:
        printf("No abarca los puntos del tp");
        break;
    }
    return 0;
}

//int che(char palabra[],int filas,int columnas,char arregloPalabras[filas][columnas])
//(
//    int value=0;
//    while(i<filas && value ==0)
//        value=strcmp(array,matriz[i]);
//          i++;
//}
int encuentraString (int filas, int columnas, char M[filas][columnas], char palabra[])
{
    int f=0;
    int flag=0;
    printf("[%d]", flag);
    while(f<filas && flag==0)
    {
        if(strcmp(palabra, M[f])==0)
        {
            flag=1;
            printf("[%d]", flag);
        }
        f++;
    }

    return flag;
}

void respuesta (int flag)
{
    if (flag==1)
    {
        printf("La Enconte gil de goma");
    }
    else
    {
        printf("no");
    }
}
void cargaManual(int f, int c, int M[f][c])
{
    int i=0;
    int co=0;
    for(i=0; i<f; i++)
    {
        for(co=0; co<c; co++)
        {
            printf("Ingrese valor Fila[%d]Columna[%d]: ", i, co);
            scanf("%d", &M[i][co]);
            printf("\n");
        }

    }
}
void cargarUnaMatrizrandom(int filas, int columnas, int M[filas][columnas])
{
    int f, c;
    for (f=0; f<filas; f++)
    {
        for (c=0; c<columnas; c++)
        {
            M[f][c]=rand()%100;
        }
    }
}

void mostrarUnaMatriz (int filas, int columnas, int M[filas][columnas])
{
    int f=0, c=0;
    for (f=0; f<filas; f++)
    {
        for (c=0; c<columnas; c++)
        {
            printf("(%0.2d)", M[f][c]);
        }
        printf("\n");
    }
}

int sumarUnaMatriz (int filas, int columnas, int M[filas][columnas])
{
    int f, c, suma=0;
    for (f=0; f<filas; f++)
    {
        for (c=0; c<columnas; c++)
        {
            suma+=M[f][c];
        }
    }
    return suma;
}

float promedioMatriz (int filas, int columnas, int M[filas][columnas])
{
    float promedio=0;
    int suma=0, cont=0;
    suma=sumarUnaMatriz(10,10,M);
    cont=contarUnaMatriz(10,10, M);
    promedio= (float) suma/cont;
    return promedio;
}
int contarUnaMatriz (int filas, int columnas, int M[filas][columnas])
{
    int cont=0;
    cont=filas * columnas;
    return cont;
}
int encuentraDatoMatriz(int f,int c, int M[f][c], int dato)
{
    int i=0;
    int j=0;
    int b=0;
    for(i=0; i<f; i++)
    {
        for(j=0; j<c; j++)
        {
            if(dato==M[i][j])
                b=1;
        }
    }
    return b;
}
int cargarMatrizdePalabras(int filas, int columnas, int M[filas][columnas])
{
    int i=0;
    char control='s';

    while (i<filas && control=='s')
    {
        printf("Ingrese una palabra\n");
        fflush(stdin);
        scanf("%s", &M[i]);
        printf("Desea continuar? s/n \n\t");
        fflush(stdin);
        scanf("%c", &control);

        i++;
    }
    return i;
}

void mostrarMatrizdePalabras(int filas, int columnas, int M[filas][columnas])
{
    printf("Esto es lo que escribiste\n");

    for(int i=0; i<filas; i++)
    {
        printf("%s\n", M[i]);
    }
}

///Hacer una función que determine si un string se encuentra dentro de un arreglo de strings.
///La función recibe el arreglo, la cantidad de palabras que contiene y la palabra a buscar.
///devuelve el índice de la fila en que se encuentra, de lo contrario -1










