#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"
#include <string.h>

typedef struct
{
    int idMonotrib;
    long int cuit;
// valores entre 2.000.000 y 10.000.000
    char nombreYapellido [30];
} stMonotributista;

typedef struct
{
    int nroFactura;
    int idMonotrib;
    char tipoFactura; // A o B en mayúscula
    float montoTotal; // no más de $ 500.000
    // no puede haber montos negativos
} stFactura;

int main()
{
    char rutaDelArchivo []= {"monotributistas.dat"};
    char rutaDelArchivoFacturaA []= {"facturasA.dat"};
    char rutaDelArchivoFacturaB []= {"facturasB.dat"};
    int validos=0,numero=0;

    stMonotributista monotributista[100];
    stFactura facturas[100];

    puts("1- \n");
    puts("2- \n");
    puts("3- \n");
    puts("4- \n");
    puts("5- \n");
    printf("Que ejercicio queres hacer? ");
    scanf("%d", &numero);
    switch (numero)
    {
    case 1:
        system("cls");
        printf("\n--PUNTO 1--\n");
        validos=cargaArregloMono(monotributista,100);
        break;
    case 2:
        system("cls");
        printf("\n--PUNTO 2--\n");
        cargaArregloFactura(facturas,100);

        break;
    case 3:
        system("cls");
        printf("\n--PUNTO 3--\n");

        break;
    case 4:
        system("cls");
        printf("\n--PUNTO 4--\n");

        break;
    case 5:
        system("cls");
        printf("\n--PUNTO 5--\n");

        break;
    case 6:
        system("cls");
        printf("\n--PUNTO 6--\n");

    default:
        printf("No abarca los puntos del tp");
        break;
    }

    return 0;
}

int cargaArregloMono (stMonotributista A[], int dimension)
{
    int i=0,flag=0;
    long int cuit=0;
    char control = 's';

    while(i<dimension && control=='s')
    {
        do
        {
            printf("\nIngrese Cuit: ");
            scanf("%ld", &cuit);
            flag=verificarCuit(cuit);

        }
        while(flag==0);

        A[i].cuit=cuit;



        printf("\nIngrese nombre: ");
        fflush(stdin);
        scanf("%s", &A[i].nombreYapellido);
        i++;
        printf("\nDesea agregar otro registro?: ");
        fflush(stdin);
        scanf("%c", &control);
    }
    return i;
}

int cargaArregloFactura (stFactura A[], int dimension)
{
    int i=0,flag=0;
    float montototal=0;
    char control = 's';

    while(i<dimension && control=='s')
    {
        do
        {
            printf("\nIngrese monto: ");
            scanf("%f", &montototal);
            if(0<montototal && montototal<500000)
            {
                flag=1;
            }
        }
        while(flag==0);

        A[i].montoTotal=montototal;

        printf("\nIngrese nroFactura: ");
        fflush(stdin);
        scanf("%d", &A[i].nroFactura);
        i++;
        printf("\nDesea agregar otro registro?: ");
        fflush(stdin);
        scanf("%c", &control);
    }
    return i;
}

//float verificarMonto(float montototal)
//{
//    int flag=0;
//
//
//    if(0<montototal && montototal<500000)
//    {
//        flag=1;
//    }
//
//    return flag;
//
//}
int verificarCuit(long int cuit)
{
    int flag=0;


    if(2000000<cuit && cuit<10000000)
    {
        flag=1;
    }

    return flag;

}
///Punto3 A


void pasarArregloAlArchivoMonotributistas (char nombre_archivo[], stMonotributista mono[], int validos)
{
    FILE * monotributistas;
    monotributistas=fopen(nombre_archivo, "ab");
    if(monotributistas!=NULL)
    {
        fwrite(mono,sizeof(stMonotributista), validos, monotributistas);
    }
    fclose(monotributistas);
}
///B

void pasarArregloAlArchivoFacturas (char nombre_archivoA[],char nombre_archivoB[],stFactura F[], int validos)
{
    FILE * FacturaA;
    FILE * FacturaB;
    FacturaA=fopen(nombre_archivoA, "ab");
    FacturaB=fopen(nombre_archivoB, "ab");
    if(FacturaA!=NULL)
    {
        fwrite(F,sizeof(stFactura), validos, FacturaA);
    }
    fclose(FacturaA);

    if(FacturaB!=NULL)
    {
        fwrite(F,sizeof(stFactura), validos, FacturaB);
    }
    fclose(FacturaB);
}
///4
void mostrarMonotribustas(stMonotributista a)
{
    puts("\n---------------");
    printf("\nId Monotributista:%d",a.idMonotrib);
    printf("\nNombreyApellido:%s",a.nombreYapellido);
    printf("\nCuit:%ld",a.cuit);
    puts("\n---------------\n");
}

void mostrarFacturasA (stFactura a)
{
    puts("\n---------------");
    printf("\nNroFactura:%d",a.nroFactura);
    printf("\nId Monotributista:%d",a.idMonotrib);
    printf("\nTipo de factura: A");
    printf("Monto total: %0.2f", a.montoTotal);
    puts("\n---------------\n");
}

void mostrarFacturasB (stFactura a)
{
    puts("\n---------------");
    printf("\nNroFactura:%d",a.nroFactura);
    printf("\nId Monotributista:%d",a.idMonotrib);
    printf("\nTipo de factura: B");
    printf("Monto total: %0.2f", a.montoTotal);
    puts("\n---------------\n");
}

void muestraMonotributistas (char nombre_archivo[])
{
    system("cls");
    stMonotributista a;
    FILE * monotributista= fopen(nombre_archivo, "rb");
    if(monotributista!=NULL)
    {
        while(fread(&a,sizeof(stMonotributista), 1, monotributista)>0)
        {
            mostrarMonotribustas(a);
        }
    }
    fclose(monotributista);
}

void muestraFacturaA (char nombre_archivo[])
{
    system("cls");
    stFactura a;
    FILE * facturaA= fopen(nombre_archivo, "rb");
    if(facturaA!=NULL)
    {
        while(fread(&a,sizeof(stFactura), 1, facturaA)>0)
        {
            mostrarFacturasA(a);
        }
    }
    fclose(facturaA);
}

void muestraFacturaB (char nombre_archivo[])
{
    system("cls");
    stFactura a;
    FILE * facturaB= fopen(nombre_archivo, "rb");
    if(facturaB!=NULL)
    {
        while(fread(&a,sizeof(stFactura), 1, facturaB)>0)
        {
            mostrarFacturasB(a);
        }
    }
    fclose(facturaB);
}
//int cuentaRegistroArchivo(char nombre_archivo[])
//{
//    int cantidad=0;
//    FILE*archivodealumnos;
//    archivodealumnos=fopen(nombre_archivo,"rb");
//    if(archivodealumnos!=NULL)
//    {
//        // me posiciono al final del archiva
//        fseek(archivodealumnos,0,SEEK_END);
//        // divido la cantidad de bytes del archivodealumnos por la cantidad de
//        // bytes de un registro de alumnos
//
//        cantidad= ftell(archivodealumnos)/sizeof(alumnos);
//        fclose(archivodealumnos);
//    }
//    return cantidad+1;
//}
