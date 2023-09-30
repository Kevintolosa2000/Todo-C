#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>


typedef struct
{
    int idRegistro;
    int nroCuenta;
    char nombreCliente[30];
    char apellidoCliente[30];
    char fechaMovimiento[11]; // ejemplo “2021-02-15”
    float importe;
} stRegistroCuentaBancaria;

typedef struct
{
    int nroCuenta;
    char nombreCliente[30];
    char apellidoCliente[30];
    float saldo;
} stSaldos;

///registroCuentaBancaria.dat
int main()
{
    stRegistroCuentaBancaria a[300];
    stSaldos b[300];
    int validos=0,validosB=0, cantidad=0,rta=0;

    validos=pasardeArchivoAcuentas(a);///1

    ordenarPorSeleccion(a,validos);///3
    mostrarArreglo(a,validos);
//
//    system("pause");
//    system("cls");
//
//    cantidad=contarArchivo("registroCuentaBancaria.dat");///4
//    printf("%d",cantidad);
printf("-------------------------------------------------------------------------------");
    system("pause");

//    rta=verificaSiExiste(b,validos);
//    printf("%d",rta);
validosB=pasarTodos(a,b,validos,validosB);
mostrarArregloSaldo(b,validosB);
    system("pause");

    guardar(b,validosB);
    mostrarArchivo();
    return 0;
}

int pasarTodos (stRegistroCuentaBancaria a[],stSaldos b[],int validosA,int validosB)
{
    int i=0;

    while (i<validosA)
    {
        validosB=pasarAlArreglo(a[i],b,validosB);
        i++;
    }
    return validosB;
}

int pasarAlArreglo (stRegistroCuentaBancaria a, stSaldos b[],int validossaldo)
{
    int i=0,flag=0;
    while(i<validossaldo && flag==0)
    {
        if (strcmp(a.nombreCliente,b[i].nombreCliente)==0 && strcmp(a.apellidoCliente,b[i].apellidoCliente)==0)
        {
            b[i].saldo=a.importe;
            flag=1;
        }
        i++;
    }
    if (flag==0)
    {
       b[validossaldo].nroCuenta=a.nroCuenta;
       b[validossaldo].saldo=a.importe;
       strcpy(b[validossaldo].nombreCliente,a.nombreCliente);
       strcpy(b[validossaldo].apellidoCliente,a.apellidoCliente);
       validossaldo++;
    }
return validossaldo;
}

void mostrarArchivo()
{
    FILE * archi=fopen("PITO.DAT","rb");
    stSaldos aux;

    if (archi)
    {
        while(fread(&aux,sizeof(stSaldos),1,archi)>0)
        {
            mostrarArregloDeSaldos(aux);
        }
    }
    fclose(archi)
}

void guardar (stSaldos a[],int validos)
{
    FILE * archi=fopen("PITO.DAT","wb");
    stSaldos aux;
    int i=0;

    while (i<validos)
    {
        aux=a[i];
        fwrite(&aux,sizeof(stSaldos),1,archi);
        i++;
    }
    fclose(archi);
}

int verificaSiExiste (stSaldos a[],int validos)
{
    int i=0,cuenta=0,rta=0,flag=0;

    printf("Escriba el numero de cuenta: ");
    scanf("%d",&cuenta);

    if (validos==0)
    {
        rta=-2;
    }

    while (i<validos && flag==0)
    {
        if (cuenta==a[i].nroCuenta)
        {
            rta=i;
            flag==1;
        }
        else
        {
            rta=-1;
        }
        i++;
    }

    return rta;
}

int pasardeArchivoAcuentas(stRegistroCuentaBancaria a[])
{
    FILE * archi=fopen("registroCuentaBancaria.dat","rb");

    stRegistroCuentaBancaria aux;

    int i=0;

    if (archi)
    {
        while(fread(&aux,sizeof(stRegistroCuentaBancaria),1,archi)>0)
        {
            a[i]=aux;
            i++;
        }
    }
    fclose(archi);
    return i;
}

void mostrarArreglo(stRegistroCuentaBancaria a[],int validos)
{
    int i=0;

    while(i<validos)
    {
        mostrarArregloDeCuentas(a[i]);
        i++;
    }
}

void mostrarArregloDeCuentas(stRegistroCuentaBancaria a)
{
    printf("-----------------------------\n");
    printf("ID: %d\n", a.idRegistro);
    printf("NOMBRE: %s\n",a.nombreCliente);
    printf("APELLIDO: %s\n",a.apellidoCliente);
    printf("NRO CUENTA: %d\n",a.nroCuenta);
    printf("FECHA: %s\n",a.fechaMovimiento);
    printf("IMPORTE: %0.2f\n",a.importe);
}

void mostrarArregloSaldo(stSaldos a[],int validos)
{
    int i=0;

    while(i<validos)
    {
        mostrarArregloDeSaldos(a[i]);
        i++;
    }
}

void mostrarArregloDeSaldos(stSaldos a)
{
    printf("-----------------------------\n");
    printf("NOMBRE: %s\n",a.nombreCliente);
    printf("APELLIDO: %s\n",a.apellidoCliente);
    printf("NRO CUENTA: %d\n",a.nroCuenta);
    printf("IMPORTE: %0.2f\n",a.saldo);
}

void ordenarPorSeleccion (stRegistroCuentaBancaria a[],int validos)
{
    int i=0,posMenor=0;
    stRegistroCuentaBancaria aux;

    while (i<validos)
    {
        posMenor=buscarMenorNC(a,validos,i);
        aux=a[posMenor];
        a[posMenor]=a[i];
        a[i]=aux;
        i++;
    }
}
int buscarMenorNC (stRegistroCuentaBancaria a[],int validos,int i)
{
    int menorPosicion=i;
    int numeroMenor=a[i].nroCuenta;

    while(i<validos)
    {
        if(a[i].nroCuenta<numeroMenor)
        {
            numeroMenor=a[i].nroCuenta;
            menorPosicion=i;
        }
        i++;
    }
    mostrarArregloDeCuentas(a[menorPosicion]);
    return menorPosicion;
}

int contarArchivo(char archivo[])
{
    FILE * archi=fopen(archivo,"rb");
    int total=0;
    if (archi)
    {
        fseek(archi,0,SEEK_END);
        total=ftell(archi)/sizeof(stRegistroCuentaBancaria);
    }
    fclose(archi);
    return total;
}
