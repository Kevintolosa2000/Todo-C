#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>




///ESTRUCTURA EQUIPO
typedef struct
{
    int idEquipo;
    char nombre [30];
    int zona; /// las zonas pueden ser 1,2,3

} stEquipo;

///ESTRUCTURA JUGADOR
typedef struct
{
    int idJugador;
    char nombre[30];
    int edad;
    int idEquipo;
} stJugador;

///PUNTO 1 CARGAR JUGADORES EN UN ARREGLO, VALIDANDO SU ID DE EQUIPO Y MOSTRARLOS POR PANTALLA
//int contarJugadores(char aContar[]);
//int validarIdEquipo(int id);
//int cargarArregloJugadores(stJugador a[],int dim);
//void mostrarArregloJugadores(stJugador a[], int validos);
//void mostrarUnJugador(stJugador a);
/////PUNTO 2 CATEGORIZACION SENIOR - JUNIOR
//void categorizarEnJuniorYSenior(stJugador jugadores[], int validos);
//int mostrarArchivoDeJugadores(char aMostrar[]);
//void cargarTotalDeJugadoresAArchivo(stJugador a[], int validos);
/////PUNTO 3 CALCULAR PORCENTAJE MAYOR A UNA EDAD INGRESADA POR CONSOLA
//void calcularPorcentajeMayoresACiertaEdad(int edad);
//float calcularPorcenaje(int edad,int cantJugadores, char archivoJug[]);
/////PUNTO 4 MOSTRAR EQUIPOS POR ZONA
//int pedirYVerificarZona();
//void mostrarEquiposPorZonas(int f, int c, char equiposZona[f][c], int zona);
//int cargarArregloStringEquipos(int f, int j,char equiposZona[f][j], int zona);
//void mostrarArregloStrings(int f,int c, char equiposZona [f][c],int validos, int zona);




int main()
{
    stJugador nuevosJugadoeres[100];
    int validos=0, cantJunior=0, cantSenior=0, cantJugadores=0,edadBase=0;
    int zonaEquipos=0;
    int opc=0;
    char equiposPorZona[14][30];
    char control;
    char  jugJunior [] = {"jugadoresJunior.dat"};
    char jugSenior[] = {"jugadoresSenior.dat"};
    char equipos[] = {"equipos.dat"};
    char jugadoresTotal[] = {"jugadores.dat"};
    do
    {
        opc=menu();

        switch(opc)
        {
        case 1:
            ///PUNTO 1 CARGAR JUGADORES EN UN ARREGLO, VALIDANDO SU ID DE EQUIPO Y MOSTRARLOS POR PANTALLA
            system("cls");
            printf("------------------------------------------ \n");
            printf("1 - CARGAR JUGADORES Y MOSTRARLOS POR PANTALLA \n");
            printf("------------------------------------------ \n");

            validos=cargarArregloJugadores(nuevosJugadoeres,100, equipos, jugadoresTotal);
            mostrarArregloJugadores(nuevosJugadoeres,validos);
            cargarTotalDeJugadoresAArchivo(nuevosJugadoeres,validos,jugadoresTotal);

            printf("La cantidad de jugadores cargados es de %d \n", validos);
            break;

        case 2:
            ///PUNTO 2 CATEGORIZACION SENIOR - JUNIOR
            system("cls");
            printf("------------------------------------------ \n");
            printf("2 - CATEGORIZAR JUGADORES EN SENIOR (+30) O JUNIOR (-30) \n");
            printf("------------------------------------------ \n");

            categorizarEnJuniorYSenior(nuevosJugadoeres,validos,jugJunior,jugSenior);

            printf("JUGADORES JUNIOR \n");
            cantJunior=mostrarArchivoDeJugadores(jugJunior);
            printf("La cantidad de jugadores Junior es de %d \n", cantJunior);
            printf("JUGADORES SENIOR \n");
            cantSenior=mostrarArchivoDeJugadores(jugSenior);
            printf("La cantidad de jugadores senior es de %d \n", cantSenior);
            printf("TOTAL DE JUGADORES \n");
            break;

        case 3:
            ///CALCUAR PORCENTAJE DE JUGADORES MAYORES A CIERTA EDAD EN EL ARCHIVO DE CATEGORIA CORRESPONDIENTE
            system("cls");
            printf("------------------------------------------ \n");
            printf("3 - PROCENTAJE DE JUGADORES MAYORES A UNA TEMPERATURA SEGUN CATEGORIA \n");
            printf("------------------------------------------ \n");

            printf("Por favor ingrese la edad base para calcular el porcentaje de jugadores mayores \n");
            scanf("%d", &edadBase);

           calcularPorcentajeMayoresACiertaEdad(edadBase, jugJunior, jugSenior);
            break;

        case 4:
            ///PUNTO 4 MOSTRAR EQUIPOS POR ZONA SOLICITADA
            system("cls");
            printf("------------------------------------------ \n");
            printf("4 -Zonas jugadores \n");
            printf("------------------------------------------ \n");

            zonaEquipos=pedirYVerificarZona();
            mostrarEquiposPorZonas(14,30,equiposPorZona,zonaEquipos,equipos);
            break;


        }

        printf("Desea realizar otra operacion? -----> S/N \n");
        fflush(stdin);
        control=getch();


    }
    while(control=='s');


    return 0;
}

int menu()
{
    int opc=0;

    system("cls");
    printf("\t\t\t\t SISTEMA DE ADMINISTRACION DE TORNEO BARRIAL DE FUTBOL  \n");
    printf("\t\t\t\t                  (matricula pendiente)");
    printf("\n");
    printf("\n");
    printf("1 - CARGAR JUGADORES Y MOSTRARLOS POR PANTALLA \n");
    printf("2 - CATEGORIZAR JUGADORES EN SENIOR (+30) O JUNIOR (-30) \n");
    printf("3 - PROCENTAJE DE JUGADORES MAYORES A UNA EDAD DETERMINADA SEGUN CATEGORIA \n");
    printf("4 - MOSTRAR EQUIPOS POR ZONA \n");
    printf("=== PRESIONE CUALQUIER TECLA PARA SALIR DEL SISTEMA ===\n");
    scanf("%d", &opc);

    return opc;
}

///CONTAR JUGADORES

int contarJugadores(char aContar[])
{
    FILE * archivin=NULL;

    int cantJug=0;
    stJugador aux;
    archivin=fopen(aContar,"rb");

    if(archivin!=NULL)
    {
        while(fread(&aux,sizeof(stJugador),1,archivin) > 0)
        {
            cantJug++;
        }

        fclose(archivin);
    }
    else
    {
        // printf("AUN NO SE HAN CARGADO JUGADORES EN EL ARCHIVO \n");
    }

    return cantJug;
}

///CARGAR JUGADORES EN UN ARREGLO DE JUGADORES

int validarIdEquipo(int id, char equip[])
{
    FILE * archivin=NULL;

    stEquipo aux;
    int flag=0;

    archivin=fopen(equip,"rb");

    if(archivin!=NULL)
    {
        while(flag==0 && !feof(archivin))
        {
            fread(&aux,sizeof(stEquipo),1,archivin);
            if(!feof(archivin))
            {
                if(aux.idEquipo == id)
                {
                    flag=1;
                }
            }
        }
        fclose(archivin);
    }
    else
    {
        printf("ERROR DE DATOS - El archivo no pudo ser abierto \n");
    }

    return flag;

}


int cargarArregloJugadores(stJugador a[],int dim, char equiposNo[], char jugadoresTotal[])
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

///CARGAR TOTAL DE JUGADORES AL ARCHIVO

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

///PUNTO 2 CATEGORIZACION SENIOR - JUNIOR

void categorizarEnJuniorYSenior(stJugador jugadores[], int validos, char jugJunior[], char jugSenior[])
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

///PUNTO 3 MOSTRAR PORCENTAJE DE JUGADORES MAYORES A CIERTA EDAD

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

void mostrarEquiposPorZonas(int f, int c, char equiposZona[f][c], int zona,char equipos[])
{
    int equiposValidos=0;

    equiposValidos=cargarArregloStringEquipos(f,c,equiposZona,zona,equipos);
    mostrarArregloStrings(f,c,equiposZona,equiposValidos,zona);
}

int cargarArregloStringEquipos(int f, int j,char equiposZona[f][j], int zona,char equipos[])
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

int pedirYVerificarZona()
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
