#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct
{
    int caloriasQuemadas;
    char nombreCiclista[30];
    char apellidoCiclista[30];
    int edad;
    int tipoEntrenamiento; // 1 adentro - 2 afuera
    int peso;
    int kilometros;
} stEntrenamiento;

int main()
{
    stEntrenamiento people[200];
    int validos=0;
    int a=0,b=0;

    mostrarArchivos("entrenamiento2.dat");

    modificarCalorias("entrenamiento2.dat");
    mostrarArchivos("entrenamiento2.dat");
    system("pause");
//
//    validos=pasarDeAarchivos("entrenamiento1.dat","entrenamiento2.dat",people);
//    mostrarArreglo(people,validos);

//    validos=cargarArreglo(people,200);
//    ordenarPorSeleccion(people,validos);
//
//    pasarAdosrchivos(people,validos);

//    mostrarArchivos("entrenamiento1.dat");
//    system("pause");
//    mostrarArchivos("entrenamiento2.dat");
//     system("pause");
//    modificarCalorias("entrenamiento2.dat");
//    mostrarArchivos("entrenamiento1.dat");
//    system("pause");

    return 0;
}


int pasarDeAarchivos (char archivo1[],char archivo2[], stEntrenamiento people[])
{
    FILE * archi1=fopen(archivo1,"rb");
    FILE * archi2=fopen(archivo2,"rb");
    stEntrenamiento aux;
    int i=0;
    if (archi1)
    {
        while(fread(&aux,sizeof(stEntrenamiento),1,archi1))
        {
            people[i]=aux;
            i++;
        }
    }
    fclose(archi1);

    if (archi2)
    {
        while(fread(&aux,sizeof(stEntrenamiento),1,archi2))
        {
            people[i]=aux;
            i++;
        }
    }
    fclose(archi2);

    return i;
}



void modificarCalorias (char archivo[])
{
    int total=0,numero=0,flag=0;
    total=cuentaArchivo(archivo);
    do
    {

        printf("\nQue posicion desea modificar: ");
        scanf("%d",&numero);

        if (numero>total)
        {
            printf("vuelva a ingresar posicion erronea");

        }
        else
        {
            flag=1;
            FILE * archi=fopen(archivo,"r+b");
            stEntrenamiento aux;

            int calorias=0;
            char nombre[20];

            if (archi)
            {
                numero=numero-1;

                printf("\nnuevas calorias: ");
                fflush(stdin);
                gets(nombre);
                strcpy(aux.nombreCiclista, nombre);

//                aux.caloriasQuemadas=calorias;

                fseek(archi,sizeof(stEntrenamiento)*numero,SEEK_CUR);
                fwrite(&aux,sizeof(stEntrenamiento),1,archi);

            }
            fclose(archi);
        }
    }
    while(flag==0);

}

int cuentaArchivo(char archivo[])
{
    FILE * ARCHI=fopen(archivo,"rb");
    int total=0;

    if (ARCHI)
    {
        fseek(ARCHI,0,SEEK_END);
        total=ftell(ARCHI)/sizeof(stEntrenamiento);
    }
    fclose(ARCHI);

    return total;
}


int cargarArreglo (stEntrenamiento people[], int dimension)
{
    char control='s';
    int i=0,numero=0,edad=0,flag=0;
    do
    {
        printf("\nIngrese su nombre: ");
        fflush(stdin);
        gets(people[i].nombreCiclista);

        printf("\nIngrese su apellido: ");
        fflush(stdin);
        gets(people[i].apellidoCiclista);

        do
        {
            printf("\nIngrese su edad: ");
            scanf("%d", &edad);
            flag=validarEdad(edad);
        }
        while(flag==0);

        people[i].edad=edad;

        do
        {
            printf("\nIngrese su entrenamiento (1adentro/2afuera): ");
            scanf("%d", &numero);
            flag=validarentrenamiento(numero);
        }
        while(flag==0);

        people[i].tipoEntrenamiento=numero;

        printf("\nIngrese su peso: ");
        scanf("%d", &people[i].peso);

        printf("\nIngrese sus calorias quemadas: ");
        scanf("%d", &people[i].caloriasQuemadas);

        printf("\nIngrese sus kilometros recorridos: ");
        scanf("%d", &people[i].kilometros);

        i++;

        printf("\nDesea cargar otro usuario? (s/n): ");
        fflush(stdin);
        scanf("%c",&control);
    }
    while(i<dimension && control=='s');

    return i;
}


void mostrarArchivos (char archivo[])
{
    FILE * archi=fopen(archivo,"rb");

    stEntrenamiento aux;

    if (archi)
    {
        while(fread(&aux,sizeof(stEntrenamiento),1,archi)>0)
        {
            mostrarEspecifico(aux);
        }
    }
    fclose(archi);
}

void pasarAdosrchivos(stEntrenamiento people[],int validos)
{
    FILE * archi=fopen("entrenamiento1.dat","wb");
    FILE * archi2=fopen("entrenamiento2.dat","wb");

    stEntrenamiento aux;
    int i=0;
    while (i<validos)
    {
        aux=people[i];

        if (people[i].tipoEntrenamiento==1)
        {
            fwrite(&aux,sizeof(stEntrenamiento),1,archi);
        }
        else
        {
            fwrite(&aux,sizeof(stEntrenamiento),1,archi2);
        }
        i++;
    }
    fclose(archi);
    fclose(archi2);
}

int buscarMenor(stEntrenamiento people[],int validos,int i)
{
    int menorNumero=people[i].edad;
    int menorPos=i;

    while(i<validos)
    {
        if(menorNumero>people[i].edad)
        {
            menorNumero=people[i].edad;
            menorPos=i;
        }
        i++;
    }

    return menorPos;
}

void ordenarPorSeleccion(stEntrenamiento people[],int validos)
{
    int i=0;
    int menorPos=0;
    stEntrenamiento aux;
    while(i<validos)
    {
        menorPos=buscarMenor(people,validos,i);
        aux=people[menorPos];
        people[menorPos]=people[i];
        people[i]=aux;
        i++;
    }
}


int validarentrenamiento(int numero)
{
    int flag=0;

    if (numero>0 && numero<=2)
    {
        flag=1;
    }
    else
    {
        printf("No existe es tipo de entrenamiento");
        system("pause");
    }
    return flag;
}

int validarEdad(int edad)
{
    int flag=0;

    if (edad>=18)
    {
        flag=1;
    }
    else
    {
        printf("Edad no autorizada");
        system("pause");
    }
    return flag;
}

void mostrarArreglo(stEntrenamiento people[],int validos)
{
    int i=0;

    while(i<validos)
    {
        mostrarEspecifico(people[i]);
        i++;
    }
}

void mostrarEspecifico(stEntrenamiento people)
{
    printf("\n nombre: %s",people.nombreCiclista);
    printf("\n apellido: %s",people.apellidoCiclista);
    printf("\n edad: %d",people.edad);
    printf("\n tipo de entrenamiento: %d",people.tipoEntrenamiento);
    printf("\n peso: %d",people.peso);
    printf("\n calorias quemadas: %d",people.caloriasQuemadas);
    printf("\n kilometros: %d\n",people.kilometros);
}













