
#include "ADLAlumnos.h"

///ALTA DE ARREGLO DE LISTAS
int alta(celda adl[],char materia[],int idMateria,notaAlumno nuevo,int validos)
{
    nodo * aux=crearNodoNotas(nuevo);
    int pos=buscaPosMateria(adl,idMateria,validos);
    if(pos==(-1))
    {
        validos=agregarMateria(adl,materia,idMateria,validos);
        pos=validos-1;
        ///setea la posicion de la nueva  materia
    }

    adl[pos].lista=agregarPpioNotas(adl[pos].lista,aux);
    return validos;
}

///BUSCAR POS MATERIA
int buscaPosMateria(celda adl[],int idMateria,int validos)
{
    int rta=(-1);
    int i=0;

    while((i<validos) && (rta == (-1)))
    {
        if(adl[i].idMateria == idMateria)
        {
            rta=i;
        }
        i++;
    }

    return rta;
}

///AGREGAR MATERIA
int agregarMateria(celda adl[],char materia[],int idMateria,int validos)
{
    strcpy(adl[validos].materia,materia);
    ///copia el nombre de la materia
    adl[validos].idMateria=idMateria;
    ///copia el id de la materia
    adl[validos].lista=inicListaNotas();
    ///inicializa la lista asociada a la materia
    validos++;
    ///incrementa la cantidad de materias
    return validos;
}

///PASAR ARCHIVO TO ADL
int pasarArchivoToADL(celda ald[], int dimension, char archivo[])
{
    FILE * archi=fopen(archivo,"rb");

    int validos=0;

    registroArchivo aux;
    notaAlumno nuevo;

    if(archi)
    {
        while(fread(&aux,sizeof(registroArchivo),1,archi)>0)
        {
            nuevo.legajo=aux.legajo;
            strcpy(nuevo.nombreApe,aux.nombreApe);
            nuevo.nota=aux.nota;

            validos=alta(ald,aux.materia,aux.idMateria,nuevo,validos);
        }

        fclose(archi);
    }

    return validos;
}

///MOSTRAR ADL
void mostrarADL(celda adl[],int validos)
{
    int i=0;

    for(i=0;i<validos;i++)
    {
        printf("=================================\n");
        printf("*********************************\n");
        printf("Materia: %s \n", adl[i].materia);
        printf("ID Materia: %d \n", adl[i].idMateria);
        mostrarListaIterativamente(adl[i].lista);

    }
}

///GUARDAR ADL EN ARCHIVO
void pasarADLtoArchivo(celda adl[],int validos,char archivo[])
{
    FILE * archi=fopen(archivo,"wb");
    int i=0;
    registroArchivo aux;

    if(archi)
    {
        for(i=0;i<validos;i++)
        {
            while(adl[i].lista)
            {
               aux.idMateria=adl[i].idMateria;
               strcpy(aux.materia,adl[i].materia);
               aux.legajo=adl[i].lista->dato.legajo;
               strcpy(aux.nombreApe,adl[i].lista->dato.nombreApe);
               aux.nota=adl[i].lista->dato.nota;

               fwrite(&aux,sizeof(registroArchivo),1,archi);
               adl[i].lista=adl[i].lista->siguiente;
            }
        }
        fclose(archi);
    }
}



