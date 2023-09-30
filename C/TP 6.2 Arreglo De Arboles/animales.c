#include "animles.h"

///MOSTRAR UN ANIMAL
void mostrarUnAnimal(animal aux)
{
    printf("Nombre: %s \n",aux.nombreAnimal);
    printf("Habitat: %d \n",aux.habitat);
    printf("cantidad: %d \n",aux.cantidad);
}

///mostrarregistroanimal
void mostrarRegistroAnimal(registroArchivo aux)
{
    printf("Nombre: %s \n",aux.animal);
    printf("Habitat: %d \n",aux.habitat);
    printf("cantidad: %d \n",aux.cant);
    printf("especie: %s \n",aux.especie);
    printf("idEspecie: %d \n",aux.idEspecie);
}

///MOSTRAR ARCHIVO ANIMALES
void mostrarArchiAnimales(char archivo[])
{
    FILE * archi=fopen(archivo,"rb");
    animal aux;

    if(archi)
    {
        while(fread(&aux,sizeof(animal),1,archi)>0)
        {
            mostrarUnAnimal(aux);
        }
    }
}
