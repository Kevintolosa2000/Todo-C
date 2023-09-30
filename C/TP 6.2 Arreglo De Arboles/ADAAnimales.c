#include "ADAAnimales.h"

///ALTA ADA
int altaADA(celdaEspecie ada[],int validos,registroArchivo nuevo)
{
    int i=-1;

    i=buscaPosEspecieADA(ada,nuevo.especie,validos);
    if(i==-1)
    {
        validos=crearNuevaEspecie(ada,nuevo,validos);
        i=validos-1;
    }
    ada[i].arbolDeAnimales=insertarNodoAnimal(ada[i].arbolDeAnimales,crearNodoArbolAnimal(nuevo));

    return validos;

}

///BUSCA POS ESPECIE
int buscaPosEspecieADA(celdaEspecie ada[], char especie[],int validos)
{
    int flag=0;
    int i=0;

    while(i<validos && flag == 0)
    {
        if(strcmp(ada[i].especie,especie)==0)
        {
            flag=1;
        }else
        {
            i++;
        }
    }

    if(flag == 0)
    {
        i=-1;
    }

    return i;
}

///CREAR NUEVA ESPECIE EN ARREGLO
int  crearNuevaEspecie(celdaEspecie ada[],registroArchivo aux,int validos)
{
    ada[validos].arbolDeAnimales=inicArbolAnimal();
    ada[validos].idEspecie=aux.idEspecie;
    strcpy(ada[validos].especie,aux.especie);

    return validos+1;
}

///PASAR ARCHIVO TO ADA
int pasarArchivoToADA(celdaEspecie ada[],char archivo[])
{
    FILE * archi=fopen(archivo,"rb");
    int validos=0;
    registroArchivo aux;

    if(archi)
    {
        while(fread(&aux,sizeof(registroArchivo),1,archi)>0)
        {
            validos=altaADA(ada,validos,aux);
        }
        fclose(archi);
    }

    return validos;
}

///PASAR ADA TO ARCHIVO
void pasarADAToArchivo(celdaEspecie ada[], int validos)
{
    char arEspecie[20];
    for(int i =0;i<validos; i++)
    {
        arEspecie[0]='\0';
        strcat(arEspecie,ada[i].especie);
        strcat(arEspecie,".dat");

        FILE * pArch=fopen(arEspecie,"ab");
        if(pArch)
        {
            guardarArbol(pArch,ada[i].arbolDeAnimales);
            fclose(pArch);
        }
    }
}

///MOSTRAR ADA
void mostrarADAanimales(celdaEspecie ada[],int validos)
{
    for(int i=0;i<validos;i++)
    {
        printf("\n********************************** \n");
        printf("            %s      \n\n",ada[i].especie);
        printf("********************************** \n\n");
        printf("Nombre Especie: %s \n",ada[i].especie);
        printf("ID especie: %d \n",ada[i].idEspecie);
        mostrarArbolAnimal(ada[i].arbolDeAnimales);
    }
}
