#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char dni[9];
    char nombre[30];
    float pesoEquipaje;
    int edad;
    int idAvion;
    int idPasaje;
} registroPasajero;


typedef struct Persona
{
    char nombre[30];
    char dni[9];
    int edad;
} Persona;

typedef struct nodoPasajero
{
    Persona p;
    int idPasaje;
    float pesoEquipaje;
    struct nodoPasajero* sig;
} nodoPasajero;

typedef struct nodoAvion
{
    int idAvion;
    nodoPasajero * pasajeros;
    struct nodoAvion* sig;
} nodoAvion;

nodoAvion * inicListaAvion();
nodoPasajero * inicListaPasajeros();
nodoAvion * pasarDeArchivoALista (nodoAvion * listaAvion, char archi[]);
nodoAvion * altaAvion(nodoAvion * listaAvion,Persona chabon, int idPasaje,float PesoEquipaje, int idAvion);
nodoPasajero * crearNodoPasajero(Persona chabon,int idPasaje,float pesoEquipaje);
nodoPasajero * agregarFinalNodoPasajero(nodoPasajero * listaDePasajeros, nodoPasajero * nuevoPasajero);
nodoAvion * agregarAlFinalAvionR(nodoAvion * listaAvion, nodoAvion * avionBuscado);
nodoAvion * crearNodoAvion(int idAvion);
nodoAvion * buscaPosAvion(nodoAvion * listaAvion,int idAvion);
nodoAvion * buscarUltimoNodoLDL(nodoAvion * listaAvion);
nodoPasajero * buscarUltimoPasajero(nodoPasajero * listaPasajeros);
nodoPasajero * agregarNodoNuevoAlPrincipio (nodoPasajero * listaPasajero, nodoPasajero * nuevoPasajero);
nodoPasajero * agregarEnOrden (nodoPasajero * listaPasajeros, nodoPasajero * nuevoPasajero);
float calcularTotalpeso (nodoPasajero * listaPasajero);
float pesoTotal (nodoAvion * listaAvion, float idAvion);
nodoPasajero * subProgramaBorrarNodoPasajero (nodoPasajero * people);
nodoAvion * eliminarMayores50 (nodoAvion * plane, int idAvion);
nodoPasajero * borrarNodoPasajero(nodoPasajero * people, char nombre[20]);
void pasarTodoAdistintosArchivos (nodoAvion * plane);
void pasarArchiHola (nodoPasajero * people, registroPasajero aux, char nombreArchi[]);

int main()
{
    int eleccion=0,avion=0,cant=0;
    float peso=0;
    nodoAvion * listaAvion=inicListaAvion();

    listaAvion=pasarDeArchivoALista(listaAvion, "avion.bin");
    recorrerYmostrarPasajerosConTodo(listaAvion);
//    system("pause");
//    system("cls");
//
//    avion=retornaIdAvionConMasPasajeros(listaAvion);
//    printf("\nEL AVION CON MAS PASAJEROS ES EL %d\n",avion);
//    system("pause");
//    system("cls");
//
//    cant=cuentaNodosAvion(listaAvion);
//    printf("\nAviones: %d\n",cant);
//    printf("\nEliga el avion\n");
//    scanf("%d",&eleccion);
//    peso=pesoTotal(listaAvion, eleccion);
//    printf("\n\t\t\t\t----------Peso total: %.2f----------\n", peso);
//    system("pause");
//    system("cls");
//
//    cant=cuentaNodosAvion(listaAvion);
//    printf("\nAviones: %d\n",cant);
    printf("\nEliga el avion\n");
    scanf("%d",&eleccion);

    listaAvion=eliminarMayores50(listaAvion,eleccion);

    recorrerYmostrarPasajerosConTodo(listaAvion);

    system("pause");

    return 0;
}

void pasarTodoAdistintosArchivos (nodoAvion * plane)
{
    registroPasajero aux;

    char arEspecie[20];

    arEspecie[0]='\0';
    // char nombreArchi[10];
    while (plane)
    {
//        scanf("&s", nombreArchi);
//         fflush(stdin);
//        strcat (arEspecie,nombreArchi);
        strcat (arEspecie,"pi");
        strcat (arEspecie,".bin");
        aux.idAvion=plane->idAvion;
        pasarArchiHola(plane->pasajeros, aux, arEspecie);
        plane=plane->sig;
    }
}

void pasarArchiHola (nodoPasajero * people, registroPasajero aux, char nombreArchi[])
{
    FILE * archi1=fopen(nombreArchi, "wb");
    if(archi1)
    {
        while (people)
        {
            strcpy(aux.dni, people->p.dni);
            printf("%s\n",aux.dni);
            strcpy(aux.nombre, people->p.nombre);
            aux.edad=people->p.edad;
            aux.idPasaje=people->idPasaje;
            aux.pesoEquipaje=people->pesoEquipaje;
            fwrite(&aux, sizeof(registroPasajero), 1, archi1);
            people=people->sig;
        }
        fclose(archi1);
    }
}

int retornaIdAvionConMasPasajeros (nodoAvion * listaAvion)
{
    int i=0;
    int rta=0;
    int avion=listaAvion->idAvion;

    while (listaAvion != NULL)
    {
        printf("\nAvion: %d",listaAvion->idAvion);

        i=recorrerYcontarPasajeros(listaAvion->pasajeros);

        printf("\nPasajeros= %d",i);

        if (i>=rta)
        {
            rta=i;
            avion=listaAvion->idAvion;
        }

        listaAvion=listaAvion->sig;
    }
//    printf("\nmayor cant de pasaje %d",rta);
    return avion;
}

int cuentaNodosAvion(nodoAvion * listaAvion)
{
    int i=0;

    while(listaAvion != NULL)
    {
        listaAvion=listaAvion->sig;
        i++;
    }
    return i;
}

float pesoTotal (nodoAvion * listaAvion, float idAvion)
{
    float rta=0;
    int aviones=0;

    while(listaAvion)
    {
        if(idAvion==listaAvion->idAvion)
        {
            rta=calcularTotalpeso(listaAvion->pasajeros);
        }
        listaAvion=listaAvion->sig;
    }
    return rta;
}

nodoAvion * eliminarMayores50 (nodoAvion * plane, int idAvion)
{
    nodoAvion * pas=plane;

        pas=buscaPosAvion(plane,idAvion);

        pas->pasajeros = subProgramaBorrarNodoPasajero(pas->pasajeros);


    return plane;
}

nodoPasajero * subProgramaBorrarNodoPasajero (nodoPasajero * people)
{

    if(people)
    {
        if (people->p.edad > 50)
        {
            nodoPasajero * aux = people;
            people = people->sig;
            free(aux);
            people=subProgramaBorrarNodoPasajero(people);
        }
        else
        {
            people->sig = subProgramaBorrarNodoPasajero(people->sig);
        }
    }
    return people;
}

nodoPasajero * borrarNodoPasajero(nodoPasajero * people, char nombre[20])
{
    nodoPasajero * seg=inicListaPasajeros();
    nodoPasajero * ante=inicListaPasajeros();

    if((people != NULL) && (strcmp(nombre, people->p.nombre)==0))
    {
        nodoPasajero * aux = people;
        people = people->sig;
        free(aux);
    }
    else
    {
        seg = people;
        while((seg != NULL) && (strcmp(nombre, seg->p.nombre)!=0))
        {
            ante = seg;
            seg = seg->sig;
        }
        if( seg!= NULL)
        {
            ante->sig = seg->sig;
            free(seg);
        }
    }
    return people;
}

float calcularTotalpeso (nodoPasajero * listaPasajero)
{
    float rta=0;
    if (listaPasajero)
    {
        rta=(listaPasajero->pesoEquipaje)+(calcularTotalpeso(listaPasajero->sig));
    }
    return rta;
}

int recorrerYcontarPasajeros(nodoPasajero * listaPasajeros)
{
    int i=0;

    while(listaPasajeros != NULL)
    {
        listaPasajeros=listaPasajeros->sig;
        i++;
    }
    return i;
}
void recorrerYmostrarPasajerosConTodo(nodoAvion * lista)
{
    nodoAvion * seg = lista;
    while (seg != NULL)
    {
        printf("\n-----------------------\n");
        mostrarNodo(seg);
        recorrerYmostrarClientes(seg->pasajeros);
        printf("\n-----------------------\n");
        seg= seg->sig;
    }
}

void mostrarNodo(nodoAvion * aux)
{
    printf("\n\tID Avion: %d \n", aux->idAvion);
}

void mostrarNodoPersona(nodoPasajero * aux)
{
    printf("\n-----------------------\n");
    printf("ID Pasaje: %d \n", aux->idPasaje);
    mostrarPersona(aux->p);
    printf("Peso Equipaje: %.2f \n", aux->pesoEquipaje);
    printf("-----------------------\n");
}

void mostrarPersona(Persona dato)
{
    printf("Nombre: %s \n", dato.nombre);
    printf("DNI: %s \n", dato.dni);
    printf("Edad: %d \n", dato.edad);
}


void recorrerYmostrarClientes(nodoPasajero * lista)
{
    nodoPasajero * seg = lista;
    while (seg != NULL)
    {
        mostrarNodoPersona(seg);
        seg= seg->sig;
    }
}


nodoAvion * pasarDeArchivoALista (nodoAvion * listaAvion, char archi[])
{
    registroPasajero aux;
    Persona chabon;
    FILE * pasajeros= fopen(archi,"rb");

    if (pasajeros)
    {
        while(fread(&aux,sizeof(registroPasajero),1,pasajeros)>0)
        {
            chabon.edad=aux.edad;
            strcpy(chabon.dni,aux.dni);
            strcpy(chabon.nombre,aux.nombre);
            listaAvion=altaAvion(listaAvion,chabon,aux.idPasaje,aux.pesoEquipaje,aux.idAvion);

        }
        fclose(pasajeros);
    }
    return listaAvion;
}

nodoAvion * altaAvion(nodoAvion * listaAvion,Persona chabon, int idPasaje,float PesoEquipaje, int idAvion)
{
    nodoPasajero * NuevoPasajero=crearNodoPasajero(chabon,idPasaje,PesoEquipaje);
    nodoAvion * avionBuscado=buscaPosAvion(listaAvion,idAvion);

    if(avionBuscado==NULL)
    {
        avionBuscado=crearNodoAvion(idAvion);
        listaAvion=agregarAlFinalAvionR(listaAvion,avionBuscado);
        avionBuscado=buscarUltimoNodoLDL(listaAvion);
    }

    avionBuscado->pasajeros=agregarEnOrden(avionBuscado->pasajeros,NuevoPasajero);

    return listaAvion;
}

nodoPasajero * agregarEnOrden (nodoPasajero * listaPasajeros, nodoPasajero * nuevoPasajero)
{
    if(listaPasajeros == NULL)
    {
        listaPasajeros = nuevoPasajero;
    }
    else
    {
        if (strcmp(nuevoPasajero->p.dni, listaPasajeros->p.dni)<0)
        {
            listaPasajeros=agregarNodoNuevoAlPrincipio(listaPasajeros,nuevoPasajero);
        }
        else
        {
            nodoPasajero * ante = listaPasajeros;
            nodoPasajero * next = listaPasajeros->sig;
            while (next != NULL && strcmp(next->p.dni, nuevoPasajero->p.dni)<0)
            {
                ante=next;
                next=next->sig;
            }
            ante->sig=nuevoPasajero;
            nuevoPasajero->sig=next;
        }
    }
    return listaPasajeros;
}

nodoPasajero * agregarNodoNuevoAlPrincipio (nodoPasajero * listaPasajero, nodoPasajero * nuevoPasajero)
{
    if(listaPasajero == NULL)
    {
        listaPasajero = nuevoPasajero;
    }
    else
    {
        nuevoPasajero->sig = listaPasajero;
        listaPasajero = nuevoPasajero;
    }
    return listaPasajero;
}


nodoPasajero * agregarFinalNodoPasajero(nodoPasajero * listaDePasajeros, nodoPasajero * nuevoPasajero)
{
    if(listaDePasajeros == NULL)
    {
        listaDePasajeros = nuevoPasajero;
    }
    else
    {
        nodoPasajero * ultimoPasajero = buscarUltimoPasajero(listaDePasajeros);
        ultimoPasajero->sig=nuevoPasajero;
    }

    return listaDePasajeros;
}

nodoPasajero * buscarUltimoPasajero(nodoPasajero * listaPasajeros)
{
    nodoPasajero * proximo= listaPasajeros;

    if(proximo != NULL)
    {
        while(proximo->sig != NULL)
        {
            proximo=proximo->sig;
        }
    }

    return proximo;
}

nodoAvion * buscarUltimoNodoLDL(nodoAvion * listaAvion)
{
    nodoAvion * rta= NULL;

    if(listaAvion)
    {
        if(!listaAvion->sig)
        {
            rta=listaAvion;
        }
        else
        {
            rta=buscarUltimoNodoLDL(listaAvion->sig);
        }
    }

    return rta;
}

nodoAvion * agregarAlFinalAvionR(nodoAvion * listaAvion, nodoAvion * avionBuscado)
{
    if(!listaAvion)
    {
        listaAvion=avionBuscado;
    }
    else
    {
        if(!listaAvion->sig)
        {
            listaAvion->sig=avionBuscado;
        }
        else
        {
            listaAvion->sig=agregarAlFinalAvionR(listaAvion->sig,avionBuscado);
        }
    }


    return listaAvion;
}

nodoPasajero * crearNodoPasajero(Persona chabon,int idPasaje,float pesoEquipaje)
{
    nodoPasajero * nuevoNodo = (nodoPasajero*) malloc(sizeof(nodoPasajero));
    nuevoNodo->p=chabon;
    nuevoNodo->sig=NULL;
    nuevoNodo->idPasaje=idPasaje;
    nuevoNodo->pesoEquipaje=pesoEquipaje;

    return nuevoNodo;
}

nodoAvion * crearNodoAvion(int idAvion)
{
    nodoAvion * nuevoNodo = (nodoAvion*) malloc(sizeof(nodoAvion));
    nuevoNodo->idAvion=idAvion;
    nuevoNodo->pasajeros=inicListaPasajeros();
    nuevoNodo->sig=NULL;

    return nuevoNodo;
}

nodoAvion * buscaPosAvion(nodoAvion * listaAvion,int idAvion)
{
    nodoAvion * rta = NULL;

    if(listaAvion)
    {
        if(idAvion == listaAvion->idAvion)
        {
            rta=listaAvion;
        }
        else
        {
            rta=buscaPosAvion(listaAvion->sig,idAvion);
        }
    }

    return rta;
}

nodoAvion * inicListaAvion()
{
    return NULL;
}
nodoPasajero * inicListaPasajeros()
{
    return NULL;
}

