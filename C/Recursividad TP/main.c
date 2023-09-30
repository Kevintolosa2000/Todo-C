#include <stdio.h>
#include <stdlib.h>

int factorial (int x);
int potenciaRecursiva (int base, int exponente);
void arregloRecursivo (int A[], int validos, int i);
void arregloRecursivoInvertida (int A[], int validos, int i);
int arregloRecursivoCapicua (int A[], int validos, int i);
int sumaArregloRecursivo (int A[],int validos, int i);
int buscaMenorArray(int A[], int validos, int i);
int main()
{
    int prueba = 0;
    int A[5]= {5,8,4,3,1};

    //prueba = potenciaRecursiva(5,2);
    //arregloRecursivo(A,10,0);
    prueba = buscaMenorArray(A,5,0);
    printf("\n dasdasda: %d", prueba);
}
/*///punto 1 Calcular el factorial de un número en forma recursiva.
int factorial (int x)
{
    int rta;

    if (x == 0)
    {
        rta = 1;
    }
    else
    {
        rta = x * factorial(x-1);
    }

    return rta;
}*/

///punto 2 Calcular la potencia de un número en forma recursiva.

int potenciaRecursiva (int base, int exponente)
{
    int rta;

    if (exponente == 0)
    {
        rta = 1;
    }
    else
    {
        rta = base * potenciaRecursiva(base, exponente - 1);
    }
    printf("\n La potencia es: %d \n", rta);
    return rta;
}

///punto 3 Recorrer un arreglo y mostrar sus elementos en forma recursiva.

void arregloRecursivo (int A[], int validos, int i)
{

    if (i == validos - 1)
    {
        printf("\n %d \n",A[i]);
    }
    else
    {
        printf("\n %d \n", A[i]);
        arregloRecursivo(A,validos, i+1);
    }
}

///punto 4 Recorrer un arreglo comenzando desde la posición 0 y mostrar sus elementos en forma invertida (recursivo).

void arregloRecursivoInvertida (int A[], int validos, int i)
{

    if (i == validos - 1)
    {
        printf("\n %d \n",A[i]);
    }
    else
    {
        arregloRecursivo(A,validos, i+1);
        printf("\n %d \n", A[i]);

    }
}

///punto 5 Determinar en forma recursiva si un arreglo es capicúa.

int arregloRecursivoCapicua (int A[], int validos, int i)
{
    int flag = 0;
    if (i == validos - 1 )
    {
        printf("\n El numero es capicua: %d", A[i]);
    }
    else
    {
        if (A[i] == A [validos - 1])
        {
            flag = arregloRecursivoCapicua(A,validos - 1, i + 1);

        }
        else
            flag = 1;
    }
    return flag;
}

///punto 6 Sumar en forma recursiva los elementos de un arreglo de enteros y retornar el total de la suma.

int sumaArregloRecursivo (int A[],int validos, int i)
{
    int suma = 0;

    if (i < validos )
    {
        suma = A[i] + sumaArregloRecursivo(A, validos, i +1);
    }
    printf("\n La Suma es: %d \n", suma);

    return suma;
}

///punto 7 Buscar el menor elemento de un arreglo en forma recursiva.

int buscaMenorArray(int A[], int validos, int i)
{
    int menor;

    if(i == validos - 1)
    {
        menor = A[i];
    }
    else
    {
        menor = buscaMenorArray(A, validos, i+1);  ///int A[5]= {5,8,4,3,1};

        if(A[i] < menor)
        {
            menor = A[i];
        }
    }

    return menor;
}
