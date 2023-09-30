#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "pila.h"

typedef struct
{
    int id;
    int codigo;
    int rubro; // 1 – Televisores / 2 – Lavarropas / 3 – Cocinas / 4 - Calefactores
    char marca[30];
    char modelo[30];
    float precio;
} stArticulo;

///articulos.dat

int main()
{
    int validos=0,id=0,totalRegistros=0;
    stArticulo electro[300];
///------------------------------------------------1------------------------------------------------------------
    printf("Ingrese id del rubro que desea pasar(1: Televisores  2: Lavarropas  3: Cocinas  4: Calefactores):  ");
    scanf("%d",&id);
    validos=pasarArticulos(electro,300,id);
///------------------------------------------------2------------------------------------------------------------
    mostrarArreglo(electro,validos);
///------------------------------------------------3------------------------------------------------------------
//    system("pause");
//    system("cls");
//    ordenarPorSeleccion(electro,validos);
//    mostrarArreglo(electro,validos);
///------------------------------------------------4------------------------------------------------------------
//    system("pause");
//    system("cls");
//    totalRegistros=contarRegistros();
//    printf("%d",totalRegistros);
///------------------------------------------------5------------------------------------------------------------
//    mostrarArticuloDelArchivo(5);
///------------------------------------------------6------------------------------------------------------------
//    system("pause");
//    system("cls");
//    pasarAUnNuevoArchivo(electro,validos);
///------------------------------------------------7------------------------------------------------------------
//    mostrarArchivo();
///------------------------------------------------8------------------------------------------------------------
//
//    Pila pilita;
//    inicpila(&pilita);
//    int rubro=0;
//
//    printf("Que rubro desea pasar: ");
//    scanf("%d",&rubro);
//
//    pasarRubroAUnaPila(rubro,&pilita);
//    mostrar(&pilita);
///------------------------------------------------9------------------------------------------------------------
//    eliminarPares(&pilita);
    return 0;
}

int pasarRubroAUnaPila(int rubro, Pila * pilita)
{
    FILE * archi=fopen("articulos.dat","rb");
    stArticulo aux;
    int i=0;

    if(archi)
    {
        while(fread(&aux,sizeof(stArticulo),1,archi)>0 || i<50)
        {
            if (aux.rubro==rubro)
            {
                apilar(pilita,aux.codigo);
            }
            i++;
        }
    }
    fclose(archi);
}

void eliminarPares(Pila * pilita)
{
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(pilita))
    {
        if(!(tope(pilita)%2))
        {
            desapilar(pilita);
        }
        else
        {
            apilar(&aux, desapilar(pilita));
        }
    }
    while(!pilavacia(&aux))
    {
        apilar(pilita, desapilar(&aux));
    }
    mostrar(pilita);
}

int pasarArticulos (stArticulo electro[], int dimension, int idRubro)
{

    FILE * archi=fopen("articulos.dat","rb");
    stArticulo aux;
    int i=0;
    if (archi)
    {

        while(fread(&aux,sizeof(stArticulo),1,archi)>0)
        {

            if (aux.rubro==idRubro)
            {

                electro[i]=aux;
                i++;
            }

        }
    }
    fclose(archi);
    return i;
}

void mostrarArreglo (stArticulo electro[],int validos)
{
    int i=0;

    while(i<validos)
    {
        muestraElArticulo(electro[i]);
        i++;
    }

}

void muestraElArticulo (stArticulo electro)
{

    printf("\n------------------------------------");
    printf("\nID: %d", electro.id);
    printf("\nCODIGO: %d", electro.codigo);
    printf("\nRUBRO: %d", electro.rubro);
    printf("\nMARCA: %s", electro.marca);
    printf("\nMODELO: %s", electro.modelo);
    printf("\nPRECIO: %0.2f", electro.precio);
    printf("\n------------------------------------");

}

int buscarMenor (stArticulo electro[],int validos,int i)
{

    int menorValor=electro[i].codigo;
    int menorPosicion=i;

    while (i<validos)
    {
        if(menorValor>electro[i].codigo)
        {
            menorValor=electro[i].codigo;
            menorPosicion=i;
        }
        i++;
    }
    return menorPosicion;
}


void ordenarPorSeleccion (stArticulo electro[],int validos)
{
    int i=0,posMenor=0;
    stArticulo aux;

    while(i<validos)
    {
        posMenor=buscarMenor(electro,validos,i);
        aux=electro[posMenor];
        electro[posMenor]=electro[i];
        electro[i]=aux;
        i++;
    }

}

int contarRegistros()
{
    FILE *  archi=fopen("articulos.dat","rb");

    int total=0;
    if (archi)
    {
        fseek(archi,0,SEEK_END);
        total=ftell(archi)/sizeof(stArticulo);

    }
    else
    {
        printf("No hay datos en archivo");
    }
    fclose(archi);
    return total;
}


void mostrarArticuloDelArchivo(int numero)
{
    FILE *  archi=fopen("articulos.dat","rb");

    int total=0;

    total=contarRegistros();

    stArticulo aux;
    if (archi)
    {

        if (numero>total || numero<0)
        {
            printf("No existe ese articulo en el archivo");
        }
        else
        {
            numero=numero-1;
            fseek(archi,sizeof(stArticulo)*numero,SEEK_SET);
            fread(&aux,sizeof(stArticulo),1,archi);
            muestraElArticulo(aux);
        }

    }
    fclose(archi);

}


void pasarAUnNuevoArchivo(stArticulo electro [],int validos)
{
    FILE * archi=fopen("articulosEconomicos.dat","wb");
    int i=0;
    int precioElegido=0;

    stArticulo aux;

    printf("Eliga los articulos menores a que precio desea guardar: ");
    scanf("%d",&precioElegido);

    while (i<validos)
    {
        if (electro[i].precio<=precioElegido)
        {
            aux=electro[i];
            fwrite(&aux,sizeof(stArticulo),1,archi);

        }
        i++;
    }
    fclose(archi);

}


void mostrarArchivo()
{
    FILE * archi=fopen("articulosEconomicos.dat","rb");
    stArticulo aux;
    while (fread(&aux,sizeof(stArticulo),1,archi)>0)
    {
        muestraElArticulo(aux);
    }
    fclose(archi);
}










