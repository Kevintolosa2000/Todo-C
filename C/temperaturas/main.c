#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <conio.h>
#include <time.h>

int   cargaDeTemperaturasUsu    (int A[], int dim);
void  teMuestroElArreglo        (int A[], int V);
int   cargaDeTemperaturasRand   (int A[], int dim);
void  repartoDeTemperaturas     (int T[], int V, Pila *A, Pila *B, Pila *C);
void  teMuestroLaPila           (Pila p);
int   teCuentoLosMayoresA       (Pila C, int comienzo);
int   SumaTemMax                (Pila C, int comienzo);
float promedioDeTem             (Pila C, int comienzo);
int   buscarMenorTemp           (int A[], int V);
int   teSumoElArreglo           (int A[], int V);
int   teCuentoLosMayoresArr     (int A[], int V, int temp);
int   teSumoLosMayoresArr       (int A[], int V, int temp);
int   porcentajeDeTempsMayoresA (int A[], int V, int dim,int temp);

int main()
{
    Pila tempBajas, tempMedias, tempAltas;
    inicpila(&tempBajas);
    inicpila(&tempMedias);
    inicpila(&tempAltas);

    int validosCU = 0, validosRand = 0, mayoresA = 0, suma = 0, tempMenor = 0, sumaArreglo = 0, tempsMayoresA = 0, sumaDeTempsMayores = 0, porcentajeTempMayores = 0;
    float promedioMax = 0;
    int temperaturasTotales[90];


//    validosCU = cargaDeTemperaturasUsu(temperaturasTotales, 90);
//    teMuestroElArreglo(temperaturasTotales, validosCU);

    printf("\n\tRegistro de temperaturas de los ultimos 90dias: \n");
    validosRand=cargaDeTemperaturasRand(temperaturasTotales, 90);
    teMuestroElArreglo(temperaturasTotales, validosRand);
    repartoDeTemperaturas(temperaturasTotales, validosRand, &tempBajas, &tempMedias, &tempAltas);

    printf("\nA continuacion dividiremos las temperaturas en bajas, medias y altas: \n");
    printf("\n---------------BAJAS------------------\n");
    teMuestroLaPila(tempBajas);
    printf("\n\n---------------MEDIAS-----------------\n");
    teMuestroLaPila(tempMedias);
    printf("\n\n---------------ALTAS------------------\n");
    teMuestroLaPila(tempAltas);
    printf("\n\n--------------------------------------\n");

    mayoresA = teCuentoLosMayoresA(tempAltas, 23);
    printf("\nLa cantidad de temperaturas mayores a 23%c es de: %d\n", 248, mayoresA);

    suma = SumaTemMax(tempAltas, 23);
    printf("La suma de estos valores es igual a %d",suma);

    promedioMax = promedioDeTem(tempAltas, 23);
    printf("\nEn promedio, la temperatura maxima mayor a 23 es de: %.2f\n ", promedioMax);

    tempMenor = buscarMenorTemp(temperaturasTotales, validosRand);
    printf("\nLa temperatura menor del periodo de 90 dias fue de %d%c", tempMenor, 248);

    sumaArreglo = teSumoElArreglo(temperaturasTotales, validosRand);
    printf("\n\nLa suma total de temperaturas es de %d", sumaArreglo);

    tempsMayoresA = teCuentoLosMayoresArr(temperaturasTotales, validosRand, 18);
    printf("\nMayores a 18: %d", tempsMayoresA);

    sumaDeTempsMayores = teSumoLosMayoresArr(temperaturasTotales, validosRand, 18);
    printf("\nLa suma de mayores a 18: %d", sumaDeTempsMayores);

    porcentajeTempMayores = porcentajeDeTempsMayoresA(temperaturasTotales, validosRand, 90, 15);
    printf("\nUn %%%d de las temperaturas totales son mayores a 15", porcentajeTempMayores);


    return 0;
}


int cargaDeTemperaturasUsu (int A[], int dim)
{

    int opcion = 0;
    int i = 0;
    do
    {
        printf("\n Ingrese temperaturas: ");
        scanf("%d", &A[i]);

        i++;

        printf("Si desea dejar de cargar datos precione ESC, de lo contrario cualquier tecla... ");
        opcion = getch();
        system("cls");

    }
    while(opcion != 27 && i<dim);

    return i;
}

void teMuestroElArreglo (int A[], int V)
{

    int i = 0;
    for(i = 0; i<V; i++)
    {
        if(i < 1)
        {
            printf("[%d%c]", A[i], 248);
        }
        else
        {
            printf("\t[%d%c]", A[i], 248);
        }
    }
}

int cargaDeTemperaturasRand (int A[], int dim)
{

    srand(time(NULL));
    int i;
    for(i = 0; i < dim; i++)
    {
        A[i] = rand()%(34)+(-2);
    }

    return i;
}

void repartoDeTemperaturas (int T[], int V, Pila *A, Pila *B, Pila *C)
{

    for(int i = 0; i < V; i++)
    {

        if(T[i]<=10)
        {
            apilar(A, T[i]);
        }
        else if(T[i]>10 && T[i]<=20)
        {
            apilar(B, T[i]);
        }
        else if(T[i]>20)
        {
            apilar(C, T[i]);
        }
    }
}

void teMuestroLaPila (Pila p)
{
    int i = 0;
    while(!pilavacia(&p))
    {
        if (i < 1)
        {
            printf("[%d%c]", tope(&p), 248);
            desapilar(&p);
        }
        else
        {
            printf("\t[%d%c]", tope(&p), 248);
            desapilar(&p);
        }
        i++;
    }
}

int teCuentoLosMayoresA (Pila C, int comienzo){

    int i=0;
    while(!pilavacia(&C)){
      if(tope(&C)<= comienzo){
        desapilar(&C);
      }else if (tope(&C)> comienzo){
        i++;
        desapilar(&C);
      }
    }
    return i;
}

int SumaTemMax (Pila C, int comienzo){

    int suma = 0;
    while(!pilavacia(&C)){
      if(tope(&C)<= comienzo){
        desapilar(&C);
      }else if (tope(&C)> comienzo){
        suma += tope(&C);
        desapilar(&C);
      }
    }
    return suma;
}

float promedioDeTem (Pila C, int comienzo){

    int contador = 0, suma = 0;
    float promedio = 0;

    contador = teCuentoLosMayoresA(C, comienzo);
    suma = SumaTemMax(C, comienzo);

    promedio = suma/contador;

    return promedio;
}

int buscarMenorTemp (int A[], int V){

    int menor = A[0];
    int i = 0;
    while(i < V){

        if(A[i] < menor){
          menor = A[i];
        }else{
            i++;
        }
    }
    return menor;
}

int teSumoElArreglo (int A[], int V)
{

    int suma = 0;
    for(int i = 0; i<V; i++)
    {
        suma += A[i];
    }
    return suma;
}


int teCuentoLosMayoresArr (int A[], int V, int temp)
{

    int j = 0;
    for(int i = 0; i < V; i++)
    {
        if(A[i]>temp){
           j++;
        }
    }
    return j;
}

int teSumoLosMayoresArr (int A[], int V, int temp)
{

    int j = 0;
    for(int i = 0; i < V; i++)
    {
        if(A[i]>temp){
           j += A[i];
        }
    }
    return j;
}


int porcentajeDeTempsMayoresA (int A[], int V, int dim,int temp){

    int contador = 0, porcentaje = 0;
    contador = teCuentoLosMayoresArr( A, V, temp);

    porcentaje = (contador*dim)/100;

    return porcentaje;
}
