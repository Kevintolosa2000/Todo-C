#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int idRegistro;
    int idPaciente;
    int idEspecialidad;///
    char nombrePaciente[30];
    char apellidoPaciente[30];
    char diagnostico[100];
    char fechaAtencion[11];   /// formato: AAAA-mm-DD
    char especialidadMedica[30];
    char nombreDoctor[30];
} stRegistroMedico;

typedef struct
{
    int idRegistro;
    int idPaciente;
    char nombrePaciente[30];
    char apellidoPaciente[30];
    char diagnostico[100];
    char fechaAtencion[11];   /// formato: AAAA-mm-DD
} pacientes;

typedef struct _nodo
{
    pacientes dato;
    struct _nodo *siguiente;
} nodo;

typedef struct _nodoLDL
{
    int idEspecialidad;
    char especialidadMedica[30];
    char nombreDoctor[30];
    nodo * listaPacientes;
    struct _nodoLDL * siguiente;

} nodoLDL;

///----------------------------------Punto 2-------------------------------------
nodoLDL * inicListaLDL();
nodoLDL * pasarArchivoToLDL(nodoLDL* listaPacientes, char archivo[]);
nodoLDL * altaLDL (nodoLDL * lista,char nombreDoctor[], char especialidadMedica[],int idEspecialidad,pacientes nuevoPaciente);
nodo * crearNodoPaciente(pacientes nuevo);
nodoLDL * buscaPosEspecialidad(nodoLDL * lista,int idEspecialidad);
nodoLDL * subProgramaAgregarEspecialidad(nodoLDL * lista,char nombreDoctor[],char especialidad[],int idEspecialidad);
nodoLDL * crearNodoLDL(char nombreDoctor [],int idEspecialidad, char especialidad[]);
nodoLDL * buscarUltimoNodoLDL(nodoLDL * lista);
nodo * agregarFinal(nodo * lista, nodo * nuevoNodo);
nodo * buscarUltimoPaciente(nodo * lista);
nodoLDL * agregarAlFinalEspecialidadR(nodoLDL * lista, nodoLDL * nuevoNodo);
///----------------------------------Punto 3-------------------------------------
void mostrarPaciente(pacientes aux);
void mostrarListaI(nodo * lista);
void mostrarLDL(nodoLDL * listaLDL);
///----------------------------------Punto 4-------------------------------------
nodoLDL * cargarPaciente(nodoLDL * listaLDL);
///----------------------------------Punto 5-------------------------------------
int buscarPaciente(nodoLDL * lista,char nombre[],char apellido[]);
///----------------------------------Punto 6-------------------------------------
int IdEspecialidad(nodoLDL * lista);
int recorrerYcontar(nodo * listaPacientes);
///----------------------------------Punto 7-------------------------------------
///ABAJO DEL TODO NO LLEGUE

int main()
{

///1-ELEGI LDL DEBIDO A QUE AUNQUE SOLO HAY 10 ESPECIALIDADES SE PUEDEN AGREGAR MAS POR LO QUE LA LISTA VENDRIA BIEN YA QUE SE
///PUEDEN AGREGAR TANATAS COMO QUIERAS DEBIDO A QUE ES DINAMICA DE IGUAL FORMA CON LOS PANCIENTES.
    int busca=0;
    char nombre[30];
    char apellido[30];

    nodoLDL * listaLDL=inicListaLDL();

    listaLDL=pasarArchivoToLDL(listaLDL,"registroMedico.dat"); ///2

    mostrarLDL(listaLDL);///3

    system("pause");
    system("cls");

    listaLDL=cargarPaciente(listaLDL);///4

    mostrarLDL(listaLDL);
    system("pause");
    system("cls");

    printf("\t\t\t\nIngres el nombre del paciente a buscar: ");
    gets(nombre);
    printf("\t\t\t\nIngres el apellido del paciente a buscar: ");
    gets(apellido);
    busca=buscarPaciente(listaLDL,nombre,apellido);///5

    printf("%d",busca);
     system("cls");
    system("pause");

    IdEspecialidad(listaLDL);
    mostrarLDL(listaLDL);
    system("pause");
    system("cls");
    return 0;
}

nodoLDL * inicListaLDL()
{
    return NULL;
}

nodo * inicListaPaciente()
{

    return NULL;

}

nodoLDL * pasarArchivoToLDL(nodoLDL* lista, char archivo[])
{
    FILE * archi=fopen(archivo,"rb");
    stRegistroMedico aux;
    pacientes nuevoPaciente;

    if(archi)
    {
        while(fread(&aux,sizeof(stRegistroMedico),1,archi)>0)
        {

            nuevoPaciente.idPaciente=aux.idPaciente;
            nuevoPaciente.idRegistro=aux.idRegistro;
            strcpy(nuevoPaciente.nombrePaciente,aux.nombrePaciente);
            strcpy(nuevoPaciente.apellidoPaciente,aux.apellidoPaciente);
            strcpy(nuevoPaciente.diagnostico,aux.diagnostico);
            strcpy(nuevoPaciente.fechaAtencion,aux.fechaAtencion);

            lista=altaLDL(lista,aux.nombreDoctor,aux.especialidadMedica,aux.idEspecialidad,nuevoPaciente);
        }
        fclose(archi);
    }

    return lista;
}

nodoLDL * altaLDL (nodoLDL * lista,char nombreDoctor [], char especialidadMedica[],int idEspecialidad,pacientes nuevoPaciente)
{
    nodo * nuevo=crearNodoPaciente(nuevoPaciente);

    nodoLDL * aux=buscaPosEspecialidad(lista,idEspecialidad);

    if(!aux)
    {
        lista=subProgramaAgregarEspecialidad(lista,nombreDoctor,especialidadMedica,idEspecialidad);
        aux=buscarUltimoNodoLDL(lista);
    }

    aux->listaPacientes=agregarFinal(aux->listaPacientes,nuevo);

    return lista;
}

nodo * crearNodoPaciente(pacientes nuevo)
{
    nodo * nuevoNodo = (nodo*) malloc(sizeof(nodo));
    nuevoNodo->dato=nuevo;
    nuevoNodo->siguiente=NULL;

    return nuevoNodo;
}

nodoLDL * buscaPosEspecialidad(nodoLDL * lista,int idEspecialidad)
{
    nodoLDL * rta=NULL;

    if(lista)
    {
        if(idEspecialidad == lista->idEspecialidad)
        {
            rta=lista;
        }
        else
        {
            rta=buscaPosEspecialidad(lista->siguiente,idEspecialidad);
        }
    }

    return rta;
}

nodoLDL * subProgramaAgregarEspecialidad(nodoLDL * lista,char nombreDoctor [],char especialidad[],int idEspecialidad)
{
    nodoLDL * nuevoNodo=crearNodoLDL(nombreDoctor,idEspecialidad,especialidad);

    lista=agregarAlFinalEspecialidadR(lista,nuevoNodo);

    return lista;
}

nodoLDL * crearNodoLDL(char nombreDoctor [],int idEspecialidad, char especialidadMedica[])
{
    nodoLDL * nuevoNodo=(nodoLDL *) malloc(sizeof(nodoLDL));
    nuevoNodo->idEspecialidad=idEspecialidad;
    strcpy(nuevoNodo->especialidadMedica,especialidadMedica);
    strcpy(nuevoNodo->nombreDoctor,nombreDoctor);
    nuevoNodo->listaPacientes=inicListaPaciente();
    nuevoNodo->siguiente=NULL;

    return nuevoNodo;
}

nodoLDL * buscarUltimoNodoLDL(nodoLDL * lista)
{
    nodoLDL * rta=NULL;

    if(lista)
    {
        if(!lista->siguiente)
        {
            rta=lista;
        }
        else
        {
            rta=buscarUltimoNodoLDL(lista->siguiente);
        }
    }

    return rta;
}

nodo * agregarFinal(nodo * lista, nodo * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodo * ultimo = buscarUltimoPaciente(lista);
        ultimo->siguiente=nuevoNodo;
    }

    return lista;
}

nodo * buscarUltimoPaciente(nodo * lista)
{
    nodo * proximo= lista;

    if(proximo !=NULL)
    {
        while(proximo->siguiente != NULL)
        {
            proximo=proximo->siguiente;
        }
    }

    return proximo;
}

nodoLDL * agregarAlFinalEspecialidadR(nodoLDL * lista, nodoLDL * nuevoNodo)
{
    if(!lista)
    {
        lista=nuevoNodo;
    }
    else
    {
        if(!lista->siguiente)
        {
            lista->siguiente=nuevoNodo;
        }
        else
        {
            lista->siguiente=agregarAlFinalEspecialidadR(lista->siguiente,nuevoNodo);
        }
    }

    return lista;
}
///--------------------------------------------------------------------------------------------------------------

void mostrarLDL(nodoLDL * listaLDL)
{
    while(listaLDL)
    {
        printf("======================ESPECIALIDAD=============================== \n");
        printf("ID especialidad: %d \n",listaLDL->idEspecialidad);
        printf("Especialida: %s \n",listaLDL->especialidadMedica);
        printf("Doctor: %s \n",listaLDL->nombreDoctor);
        printf("================================================================= \n");

        mostrarListaI(listaLDL->listaPacientes);
        listaLDL=listaLDL->siguiente;
    }
}

void mostrarListaI(nodo * lista)
{
    if(lista)
    {
        while(lista)
        {
            mostrarPaciente(lista->dato);
            lista=lista->siguiente;
        }
    }
}

void mostrarPaciente(pacientes aux)
{
    printf("--------------------------------\n");
    printf("Id: %d \n",aux.idPaciente);
    printf("Nombre Paciente: %s \n",aux.nombrePaciente);
    printf("Apellido Paciente: %s \n",aux.apellidoPaciente);
    printf("Fecha de atencion: %s \n",aux.fechaAtencion);
    printf("Diagnostico: %s \n",aux.diagnostico);
}
///--------------------------------------------------------------------------------------------------------------
nodoLDL * cargarPaciente(nodoLDL * listaLDL)
{
    stRegistroMedico aux;
    pacientes nuevo;

    char continuar;

    do
    {

        printf("Por favor ingrese la id de la especialidad \n");
        scanf("%d", &aux.idEspecialidad);

        printf("Ingrese la especialidad medica \n");
        fflush(stdin);
        gets(aux.especialidadMedica);

        printf("Ingrese el nombre del doctor \n");
        fflush(stdin);
        gets(aux.nombreDoctor);


        printf("ingrese el ID del paciente \n");
        scanf("%d",&nuevo.idPaciente);

        printf("ingrese el ID de registro \n");
        scanf("%d",&nuevo.idRegistro);

        printf("Ingrese el nombre del paciente: \n");
        fflush(stdin);
        gets(nuevo.nombrePaciente);

        printf("Ingrese el apellido del paciente: \n");
        fflush(stdin);
        gets(nuevo.apellidoPaciente);

        printf("Ingrese el diagnostico \n");
        fflush(stdin);
        gets(nuevo.diagnostico);

        printf("Ingrese el la fecha de atencion  \n");
        fflush(stdin);
        gets(nuevo.fechaAtencion);

        listaLDL=altaLDL(listaLDL,aux.nombreDoctor,aux.especialidadMedica,aux.idEspecialidad,nuevo);

        printf("Desea seguir cargando pacientes? -> s/n \n");

        continuar=getch();

    }
    while(continuar == 's');

    return listaLDL;
}
///--------------------------------------------------------------------------------------------------------------
int buscarPaciente(nodoLDL * lista,char nombre[],char apellido[])
{
    int flag=0;

    while (lista != NULL && flag==0)
    {
        while(lista->listaPacientes != NULL && flag==0)
        {
            if (strcmp(nombre, lista->listaPacientes->dato.nombrePaciente)==0 && strcmp(apellido, lista->listaPacientes->dato.apellidoPaciente)==0)
            {
                flag=1;
            }
            lista->listaPacientes=lista->listaPacientes->siguiente;
        }
        lista=lista->siguiente;

    }
    return flag;
}
///--------------------------------------------------------------------------------------------------------------
int IdEspecialidad(nodoLDL * lista)
{
    int i=0;
    int rta=0;
    int id=lista->idEspecialidad;

    while (lista != NULL)
    {
        i=recorrerYcontar(lista->listaPacientes);

        if (i>=rta)
        {
            rta=i;
            id=lista->idEspecialidad;
        }

        lista=lista->siguiente;
    }
    printf("La especialidad con mas atenciones fue la nro: %d \nCon %d pacientes\n",id,rta);
    system("pause");
    return id;
}

int recorrerYcontar(nodo * listaPacientes)
{
    int i=0;

    while(listaPacientes != NULL)
    {
        listaPacientes=listaPacientes->siguiente;
        i++;
    }
    return i;
}

///-------------------------------------------------------------------------------------------------------------- no llegue

//void pasarListaToArchivo(nodoLDL * lista)
//{
//    char especialidadMedica[20];
//    nodoLDL * especialidad=inicListaLDL();
//
//    while (lista)
//    {
//        printf("Que especialidad deseas guardar?");
//        gets(especialidadMedica);
//        especialidad=buscaEspecialidad(lista,especialidadMedica);
//
//        especialidadMedica[0]='\0';
//        strcat(especialidadMedica,lista->especialidadMedica);
//        strcat(especialidadMedica,".dat");
//
//        FILE * archi=fopen(especialidadMedica,"ab");
//
//        if(archi)
//        {
//            guardarLista(archi,especialidad);
//            fclose(archi);
//        }
//    }
//
//}
//
//nodoLDL * buscaEspecialidad(nodoLDL * lista,char especialidadMedica[])
//{
//    nodoLDL * rta=inicListaLDL();
//
//    if(lista)
//    {
//        if(strcmp(especialidadMedica, lista->especialidadMedica)==0)
//        {
//            rta=lista;
//        }
//        else
//        {
//            rta=buscaEspecialidad(lista->siguiente,especialidadMedica);
//        }
//    }
//
//    return rta;
//}
//void guardarLista(FILE * archi,nodoLDL * especialidad)
//{
//   if(especialida)
//   {
//       fwrite(&especialidad->listaPacientes->dato,sizeof(especialidad),1,archi);
//     especialidad->siguiente;
//   }
//}
