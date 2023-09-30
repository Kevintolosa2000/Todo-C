//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//
//typedef struct
//{
//    int dni;
//    char nombre_apellido[30];
//    int edad;
//    char equipo[30];
//
//} player;
//
//typedef struct _nodoPlayer
//{
//    player p;
//    struct _nodoPlayer * sig;
//} nodoPlayer;
//
//nodoPlayer * arrayALista(nodoPlayer * lista, player Players[], int val);
//int loadPlayers(player A[]);
//player playerCargar ();
//void playerAgregarEnOrden (nodoPlayer ** lista, nodoPlayer * nuevoNodo);
//nodoPlayer * playerAgregarEnOrdenPorNombre (nodoPlayer * lista, nodoPlayer * nuevoNodo);
//nodoPlayer * playerAgregarNodoNuevoAlPrincipio (nodoPlayer * lista, nodoPlayer * nuevoNodo);
//int playerBuscarNodoPorEdad (nodoPlayer * lista);
//nodoPlayer * playerCargarElNodo (nodoPlayer * lista);
//int playerContarNodosRecursivo(nodoPlayer * lista);///RECURSIVA
//nodoPlayer * playerCrearNodo (player p);
//nodoPlayer * playerDesvincularNodo (nodoPlayer ** lista);
//void playerInicLista (nodoPlayer ** lista);
//void playerMostrarArreglo (player A[],int i);
//void playerMostrarArregloRecursivo (player A[], int validos, int i);///RECURSIVA
//void playerMostrarLista (nodoPlayer*lista);
//void playerMostrarNodoRecursivoMayoresEdad(nodoPlayer * lista);///RECURSIVA
//void playerMostrarUnico (player A);
//void playerMostrarUnSoloDatoR (nodoPlayer*lista);///RECURSIVA
//nodoPlayer * playerpasarDeListaToLista (nodoPlayer * listaVieja, nodoPlayer * listaNueva,char equipo []);
//nodoPlayer * PlayerEliminarPrimero (nodoPlayer * lista);
//nodoPlayer * playerEliminarUltimo (nodoPlayer * lista);
//nodoPlayer * playerBorrarNodoEnPosicion (nodoPlayer * lista, int posicion);
//int subProgramaVerficarCantidad (int cant, int x);
//nodoPlayer * playerBorrarTodaLaListaRecursivo (nodoPlayer * lista);///RECURSIVA
//
//
////int main()
////{
////    nodoPlayer * lista;
////    playerInicLista(&lista);
//////    nodoPlayer * listanueva;
//////    playerInicLista(&listanueva);
//////
////////    lista=playerCargarElNodo(lista);
////////    playerMostrarLista(lista);
//////
////    player Players[15];
////
////    int valid=loadPlayers(Players);
////
////    lista=arrayALista(lista,Players,valid);
////
////    lista=playerBorrarTodaLaListaRecursivo(lista);
////
////    if (!lista)
////    {
////        printf("no hay nada");
////    }
////playerMostrarNodoRecursivoMayoresEdad(lista);
//
//
////    int x=0,cant=0,flag=0;
////
////    do
////    {
////        system("cls");
////
////        cant=playerContarNodosRecursivo(lista);
////
////        printf("\nQue nodo deseas borrar: ");
////        scanf("%d",&x);
////
////        flag=subProgramaVerficarCantidad(cant,x);
////
////    }while(flag==0);
////
////    playerMostrarLista(lista);
////    lista= playerBorrarNodoEnPosicion(lista,x);
////    printf("\n--------------------------------------------------------------------------------------------");
////    playerMostrarLista(lista);
////
//////    printf(": %d",x);
////
//////    char equipo [50];
//////    printf("Que equipo varon: ");
//////    fflush(stdin);
//////    gets(equipo);
//////
//////    listanueva=playerpasarDeListaToLista(lista,listanueva,equipo);
//////
//////    playerMostrarLista(listanueva);
////    return 0;
////}
//
//nodoPlayer * playerBorrarNodoEnPosicion (nodoPlayer * lista, int posicion)
//{
//
//    nodoPlayer * seg;
//    nodoPlayer * ante;
//    int i=1;
//
//    if((lista != NULL) && i==posicion)
//    {
//        lista=PlayerEliminarPrimero(lista);
//    }
//    else
//    {
//        seg = lista;
//
//        while((seg!= NULL) && i!=posicion)
//        {
//            ante = seg;
//            seg = seg->sig;
//            i++;
//        }
//        if(seg!=NULL && i==posicion)
//        {
//            ante->sig = seg->sig;
//            free(seg);
//        }
//
//        return lista;
//    }
//}
//
//nodoPlayer * PlayerEliminarPrimero (nodoPlayer * lista)
//{
//    nodoPlayer * primerNodo = lista;
//
//    if (lista != NULL)
//    {
//
//        lista=lista->sig;
//        free(primerNodo);
//    }
//
//    return lista;
//}
//
//nodoPlayer * playerEliminarUltimo (nodoPlayer * lista)
//{
//    nodoPlayer * ante;
//    nodoPlayer * copiaLista= lista;
//
//    while (copiaLista->sig!= NULL)
//    {
//        ante = copiaLista;
//        copiaLista=copiaLista->sig;
//    }
//
//    ante->sig = copiaLista->sig;
//
//    free(copiaLista);
//
//    return lista;
//}
//
//nodoPlayer * playerBorrarTodaLaListaRecursivo (nodoPlayer * lista)
//{
//
//    if(lista != NULL)
//    {
//        lista=playerBorrarTodaLaListaRecursivo(lista->sig);
//
//        PlayerEliminarPrimero(lista);
//
//    }
//
//    return lista;
//}
//
//int subProgramaVerficarCantidad (int cant, int x)
//{
//    int flag=0;
//
//    if (x<=cant && x>0)
//    {
//        flag=1;
//    }
//    else
//    {
//        printf("Flasheaste, pone otro numero\n");
//        system("pause");
//    }
//    return flag;
//}
//
//int playerContarNodosRecursivo(nodoPlayer * lista)
//{
//    int rta=0;
//
//    if(lista == NULL)
//    {
//        rta=0;
//    }
//    else
//    {
//        rta= 1 + (playerContarNodosRecursivo(lista->sig));
//    }
//    return rta;
//}
//
//
//nodoPlayer * playerCrearNodo (player p)
//{
//    nodoPlayer * aux = (nodoPlayer*) malloc(sizeof (nodoPlayer));
//    aux ->p = p;
//    aux -> sig = NULL;
//    return aux;
//}
//
//nodoPlayer * arrayALista(nodoPlayer * lista, player Players[], int val)
//{
//    int i=0;
//
//    while(i < val)
//    {
//        playerAgregarEnOrden(&lista, playerCrearNodo(Players[i]));
////        lista=playerAgregarEnOrden(lista, playerCrearNodo(Players[i]));
//
//        i++;
//    }
//    return lista;
//}
//
//nodoPlayer * playerpasarDeListaToLista (nodoPlayer * listaVieja, nodoPlayer * listaNueva, char equipo [])
//{
//    nodoPlayer * auxViejo=listaVieja;
// //   nodoPlayer * auxNuevo=NULL;
//
//    while (auxViejo != NULL)
//    {
//        if (auxViejo != NULL && strcmp(equipo, auxViejo->p.equipo)==0)
//        {
//            playerAgregarEnOrden(&listaNueva,playerCrearNodo(auxViejo->p));
//        }
//        auxViejo=auxViejo->sig;
//    }
//    return listaNueva;
//}
//
//nodoPlayer * playerDesvincularNodo (nodoPlayer ** lista)
//{
//    nodoPlayer * aux;
//    if (*lista!=NULL)
//    {
//        aux =(*lista);
//        (*lista)=(*lista)->sig;
//        aux->sig=NULL;
//    }
//    return aux;
//}
//
//
//nodoPlayer * playerCargarElNodo (nodoPlayer * lista)
//{
//    nodoPlayer * nuevoNodo;
//    char control ='s';
//    while (control=='s')
//    {
//        nuevoNodo = playerCrearNodo(playerCargar());
//        playerAgregarEnOrden(&lista,nuevoNodo);
//
//        printf("\nDesea agragar otro producto? (S/N): ");
//        fflush(stdin);
//        scanf("%c", &control);
//        system("cls");
//    }
//    return lista;
//}
//
//player playerCargar ()
//{
//    player a;
//
//    printf("\n NOMBRE Y APELLIDO: ");
//    fflush(stdin);
//    gets(a.nombre_apellido);
//
//    printf("\n DNI: ");
//    scanf("%d",&a.dni);
//
//    printf("\n EDAD: ");
//    scanf("%d",&a.edad);
//
//    printf("\n EQUIPO: ");
//    fflush(stdin);
//    gets(a.equipo);
//
//    return a;
//}
//
//void playerAgregarEnOrden (nodoPlayer ** lista, nodoPlayer * nuevoNodo)
//{
//    if((*lista) == NULL)
//    {
//        (*lista) = nuevoNodo;
//    }
//    else
//    {
//        if ((*lista)->p.dni > nuevoNodo->p.dni)
//        {
//            *lista=playerAgregarNodoNuevoAlPrincipio(*lista,nuevoNodo);
//        }
//        else
//        {
//            nodoPlayer * ante = (*lista);
//            nodoPlayer * next = (*lista)->sig;
//
//            while (next != NULL && (nuevoNodo->p.dni > next->p.dni))
//            {
//                ante=next;
//                next=next->sig;
//            }
//            nuevoNodo->sig=next;
//            ante->sig=nuevoNodo;
//        }
//    }
//}
//
//nodoPlayer * playerAgregarEnOrdenPorNombre (nodoPlayer * lista, nodoPlayer * nuevoNodo)
//{
//    if(lista == NULL)
//    {
//        lista = nuevoNodo;
//    }
//    else
//    {
//        if (strcmp(nuevoNodo->p.nombre_apellido, lista->p.nombre_apellido)<0)
//        {
//            lista=playerAgregarNodoNuevoAlPrincipio(lista,nuevoNodo);
//        }
//        else
//        {
//            nodoPlayer * ante = lista;
//            nodoPlayer * next = lista->sig;
//            while (next != NULL && strcmp(next->p.nombre_apellido, nuevoNodo->p.nombre_apellido)<0)
//            {
//                ante=next;
//                next=next->sig;
//            }
//            ante->sig=nuevoNodo;
//            nuevoNodo->sig=next;
//        }
//    }
//    return lista;
//}
//
//nodoPlayer * playerAgregarNodoNuevoAlPrincipio (nodoPlayer * lista, nodoPlayer * nuevoNodo)
//{
//    if(lista == NULL)
//    {
//        lista = nuevoNodo;
//    }
//    else
//    {
//        nuevoNodo->sig= lista;
//        lista = nuevoNodo;
//    }
//    return lista;
//}
//
//void playerMostrarArregloRecursivo (player A[], int validos, int i)
//{
//
//    if (i == validos - 1)
//    {
//        playerMostrarArreglo(A,i);
//    }
//    else
//    {
//        playerMostrarArreglo(A,i);
//        playerMostrarArregloRecursivo(A,validos, i+1);
//    }
//}
//
//void playerMostrarLista (nodoPlayer*lista)
//{
//    nodoPlayer * aux = lista;
//
//    while (aux != NULL)
//    {
//        playerMostrarUnico(aux->p);
//        aux=aux->sig;
//    }
//}
//
//void playerMostrarUnico (player A)
//{
//    printf("\n NOMBRE Y APELLIDO: %s \n",A.nombre_apellido);
//    printf("\n DNI: %d \n",A.dni);
//    printf("\n EDAD: %d \n",A.edad);
//    printf("\n EQUIPO: %s \n",A.equipo);
//
//}
//
//void playerMostrarNodoRecursivoMayoresEdad (nodoPlayer * lista)
//{
//    if(lista != NULL)
//    {
//
//        playerMostrarNodoRecursivoMayoresEdad (lista->sig);
//
//        if (lista->p.edad>25)
//        {
//            playerMostrarUnSoloDatoR(lista);//Se puede escribir el printf pero asi es mas rapido.
//        }
//
//    }
//}
//
//void playerMostrarUnSoloDatoR (nodoPlayer*lista)
//{
//    nodoPlayer * aux = lista;
//
//    playerMostrarUnico(aux->p);
//    aux=aux->sig;
//}
//
//
//void playerMostrarArreglo (player A[],int i)
//{
//    printf("\n NOMBRE Y APELLIDO: %s \n",A[i].nombre_apellido);
//    printf("\n DNI: %d \n",A[i].dni);
//    printf("\n EDAD: %d \n",A[i].edad);
//    printf("\n EQUIPO: %s \n",A[i].equipo);
//
//}
//
//void playerInicLista (nodoPlayer ** lista)
//{
//
//    *lista = NULL;
//
//}
//
//int playerBuscarNodoPorEdad (nodoPlayer * lista)
//{
//    int f=0,auxDni=0;
//
//    if (lista)
//    {
//        f= lista->p.edad;
//    }
//    while (lista != NULL )
//    {
//        if (lista->p.edad > f)
//        {
//            auxDni=lista->p.dni;
//            f=lista->p.edad;
//        }
//        lista=lista->sig;
//    }
//    return auxDni;
//}
//
//int loadPlayers(player A[])
//{
//    int i=0;
//
//    A[i].dni=1234;
//    A[i].edad=23;
//    strcpy(A[i].nombre_apellido,"JuanFer Quintero");
//    strcpy(A[i].equipo,"River Plate");
//    i++;
//
//    A[i].dni=9876;
//    A[i].edad=33;
//    strcpy(A[i].nombre_apellido,"Nacho Scocco");
//    strcpy(A[i].equipo,"River Plate");
//    i++;
//
//    A[i].dni=2341;
//    A[i].edad=28;
//    strcpy(A[i].nombre_apellido,"Pity Martinez");
//    strcpy(A[i].equipo,"River Plate");
//    i++;
//
//    A[i].dni=9999;
//    A[i].edad=45;
//    strcpy(A[i].nombre_apellido,"Juan Roman Riquelme");
//    strcpy(A[i].equipo,"Boca Juniors");
//    i++;
//
//    A[i].dni=1213;
//    A[i].edad=50;
//    strcpy(A[i].nombre_apellido,"Guillermo Barros Schelotto");
//    strcpy(A[i].equipo,"Gimnasia de La Plata");
//    i++;
//
//    A[i].dni=1927;
//    A[i].edad=48;
//    strcpy(A[i].nombre_apellido,"Marcelo Gallardo");
//    strcpy(A[i].equipo,"River Plate");
//    i++;
//
//    A[i].dni=8362;
//    A[i].edad=28;
//    strcpy(A[i].nombre_apellido,"Franco Armani");
//    strcpy(A[i].equipo,"River Plate");
//    i++;
//
//    A[i].dni=2415;
//    A[i].edad=23;
//    strcpy(A[i].nombre_apellido,"Cristian Pavon");
//    strcpy(A[i].equipo,"Boca Juniors");
//    i++;
//
//    A[i].dni=9642;
//    A[i].edad=36;
//    strcpy(A[i].nombre_apellido,"Fernando Gago");
//    strcpy(A[i].equipo,"Boca Juniors");
//    i++;
//
//    A[i].dni=9642;
//    A[i].edad=46;
//    strcpy(A[i].nombre_apellido,"Carlitos Tevez");
//    strcpy(A[i].equipo,"Boca Juniors");
//    i++;
//
//    A[i].dni=2643;
//    A[i].edad=34;
//    strcpy(A[i].nombre_apellido,"Ariel Rojas");
//    strcpy(A[i].equipo,"San Lorenzo");
//    i++;
//
//    A[i].dni=2647;
//    A[i].edad=30;
//    strcpy(A[i].nombre_apellido,"Sebastian Torrico");
//    strcpy(A[i].equipo,"San Lorenzo");
//    i++;
//
//    A[i].dni=3426;
//    A[i].edad=26;
//    strcpy(A[i].nombre_apellido,"Maximiliano Meza");
//    strcpy(A[i].equipo,"Independiente");
//    i++;
//
//    A[i].dni=3827;
//    A[i].edad=36;
//    strcpy(A[i].nombre_apellido,"Martin Campania");
//    strcpy(A[i].equipo,"Independiente");
//    i++;
//
//    A[i].dni=1673;
//    A[i].edad=20;
//    strcpy(A[i].nombre_apellido,"Emmanuel Gigliotti");
//    strcpy(A[i].equipo,"Chongqing Lifan");
//    i++;
//
//    return i;
//}
