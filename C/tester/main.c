#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <wchar.h>      /// Incluye un soporte para amplios tipos de caracteres.
#include <locale.h>     /// Incluye el soporte para distintos tipos de formatos de fecha, moneda, texto, etc.
#define ESC 27

typedef struct          /// Estructura PRODUCTOS.
{
    int codProducto;
    char producto[100];
    float costo;
} stProductos;
typedef struct              /// Estructura CLIENTES.
{
    int idCliente;
    char nombre[30];
    char apellido[30];
    char userName[20];
    char password[20];
    char mail[100];
    char genero;
    int rol;
    int activo;
} stCliente;
typedef struct              /// Estructura PEDIDOS.
{
    int idPedido;
    int idCliente;
    int codProducto;
    int cantidad;
    char producto[100];
    char fecha[12];
    char descripcion[300];
    float costoPedido;

} stPedidos;

/// ***********************************     PROTOTIPADO     **************************************

int registrarse (char C[]);
int ultimoIdCliente(char C[]);
int compararUsuarios (char C[],char usuario[]);
void usuarioRepetido (int flag);
void asteriscos (char contra[]);
int iniciarSesion(char C[]);
int compararPassword (char C[], char password[]);
int verificarSiEstaActivo (char C[],int idUser);
int buscaIdCliente (char C[],char usuario[]);
void altaPedido(char pD[],char pR[],char C[],int idUser,char F[],int dimensionFecha);
int ultimoCodProducto(char P[]);
int ultimoIdPedido (char R[]);
void altaProductos(char P[]);
void mostrarProductos(char P[]);
float obtenerCosto(char P[],int seleccion);
void  obtenerFecha(char F[],int dimension);
void seleccionarProductos(char pD[],char pR[],int idUser);

void mostrarPedidos (char pD[],int idUser);
void modificarPedido(char pD[],char pR[],int idUser);

int main()
{
    int validos=0,menu=0,salir,idUser,i;
    int dimensionFecha = 80;
    char fecha[dimensionFecha];

    char rutaArchiPedidos[]= {"pedidos.dat"};
    char rutaArchiProductos[]= {"productos.dat"};
    char rutaArchiClientes[]= {"clientes.dat"};

    do
    {

        printf("\n\t\t\t    ****    MENU    ****\n");
        printf("\n 1.   REGISTRARSE.");
        printf("\n 2.   INICIAR SESION.");
        printf("\n 3.   HACER PEDIDO.");
        printf("\n 4.   MOSTRAR PEDIDOS.");
        printf("\n 5.   ALTA PRODUCTOS.");
        printf("\n 6.   MOSTRAR PRODUCTOS.\n");
        printf("\n 7.   MOODIFICAR PEDIDOS.\n");


        printf("\n Ingrese una opcion: ");
        scanf("%d",&menu);
        switch(menu)
        {
        case 1:
            system("cls");
            printf("\n\t\t\t REGISTRARSE.\n");
            i=registrarse(rutaArchiClientes);  ///es un int, devuelve i por lo que le puse i provisorio para que no de error.
            break;
        case 2:
            system("cls");
            printf("\n\t\t\t INICIAR SESION.\n");
            idUser=iniciarSesion(rutaArchiClientes);
            break;
        case 3:
            system("cls");
            printf("\n\t\t\t HACER PEDIDO.\n");
            altaPedido(rutaArchiPedidos,rutaArchiProductos, rutaArchiClientes,idUser,fecha,dimensionFecha);
            break;
        case 4:
            system("cls");
            printf("\n\t\t\t MOSTRAR PEDIDOS.\n");
            mostrarPedidos (rutaArchiPedidos,idUser);
            break;
        case 5:
            system("cls");
            printf("\n\t\t\t ALTA PRODUCTOS.\n");
            altaProductos(rutaArchiProductos);
            system("pause");
            break;
        case 6:
            system("cls");
            printf("\n\t\t\t MOSTRAR PRODUCTOS.\n");
            mostrarProductos(rutaArchiProductos);
            break;
        case 7:
            system("cls");
            printf("\n\t\t\t MODIFICAR PEDIDOS.\n");
            modificarPedido(rutaArchiPedidos,rutaArchiProductos,idUser);
            system("pause");
            break;
//        case NN:
//            system("cls");
//            printf("\n\t\t\t ALTA DE PEDIDO.\n\n");
//            validos=cargarPedido(rutaArchiPedidos);
//            break;
        }
        printf("\n\t\t\t ESC para salir. Cualquier tecla para continuar.");
        printf("\n\t\t\t\t Desea continuar?.  ");
        salir=getch();
        system("cls");
    }
    while(salir!=ESC);
//    obtenerFecha(fecha,dimensionFecha);

    return 0;

}
///   *******************       FUNCIONES       *******************
///     ------------------     REGISTRARSE.    ------------------
int registrarse(char C[])
{
    setlocale(LC_ALL, "");
    int i=0, flag=0;
    int idCliente;
    char nombreUsuario [20];
    stCliente cl;

    idCliente = ultimoIdCliente(C);

    FILE *archivoDeCliente = fopen(C,"ab");

    cl.idCliente = idCliente + 1;
    cl.rol = 0;

    if(archivoDeCliente!= NULL)
    {
        printf("\nIngrese su nombre: ");
        fflush(stdin);
        gets(cl.nombre);

        printf("\nIngrese su apellido: ");
        fflush(stdin);
        gets(cl.apellido);

        do
        {
            printf("\nIngrese su nombre se usuario: ");
            fflush(stdin);
            gets(nombreUsuario);
            //scanf("%s", &nombreUsuario);
            flag=compararUsuarios(C,nombreUsuario);
            usuarioRepetido(flag);

        }
        while (flag!=0);
        strcpy(cl.userName, nombreUsuario);

        printf("\nIngrese su genero (M/F/O): ");
        fflush(stdin);
        scanf("%c",&cl.genero);

        printf("\nIngrese su email: ");
        fflush(stdin);
        gets(cl.mail);

        printf("\nIngrese su contraseña (No mas de 10 caracteres): ");
        fflush(stdin);
        asteriscos(cl.password);

        cl.activo = 1;

        fwrite(&cl,sizeof(stCliente),1,archivoDeCliente);
        i++;
    }
    fclose(archivoDeCliente);
    return i;
}
///     ------------------     ULTIMO ID CLIENTE.    ------------------
int ultimoIdCliente(char C[])
{
    int a = 99;
    stCliente cl;
    FILE *archivoClientes = fopen(C,"rb");
    if(archivoClientes != NULL)
    {
        while(fread(&cl,sizeof(stCliente),1,archivoClientes)>0)
        {
            a = cl.idCliente;
        }
    }
    fclose(archivoClientes);
    return a;
}
///     ------------------     COMPARAR NOMBRE DE USUARIO.    ------------------
int compararUsuarios (char C[],char usuario[])
{
    int flag=0;
    stCliente cl;
    FILE *archivoDeCliente = fopen(C,"rb");
    if(archivoDeCliente!= NULL)
    {
        while ( fread (&cl, sizeof (stCliente), 1, archivoDeCliente) > 0)
        {
            if (strcmp (cl.userName, usuario) == 0)
            {
                flag=1;
            }
        }

    }
    fclose(archivoDeCliente);
    return flag;
}
///     ------------------     USUARIO REPETIDO.    ------------------
void usuarioRepetido (int flag)
{
    if (flag==1)
    {
        printf("\nUsuario ya registrado, por favor vuelva a intentarlo\n");

    }
}
///     ------------------     ASTERISCOS.    ------------------
void asteriscos (char contra[])
{
    char caracter;
    int x=0;
    do
    {
        caracter=getch();
        if(caracter==13)
        {
            contra [x]='\0';

        }
        else if(caracter==8)
        {
            if(x>0)
            {
                x--;
                printf("\b \b");
            }
        }
        else if (x<10)
        {
            printf("*");
            contra[x]=caracter;
            x++;
        }
    }
    while(caracter!=13);
}
///     ------------------    INICIO SESION.    ------------------
int iniciarSesion(char C[])
{
    setlocale(LC_ALL, "");
    int idUser=0,flag1=0,flag2=0, intentos=0;
    char nombreUsuario []="NULL", password []="NULL";
    printf("\n\t\t\t Por favor ingrese su usuario y contraseña\n");

    do
    {
        printf("\n\t\t\t Usuario: ");
        fflush(stdin);
        gets(nombreUsuario);

        flag1=compararUsuarios(C,nombreUsuario);

        if(flag1==1)
        {
            idUser=buscaIdCliente (C,nombreUsuario);
        }
        else
        {
            system("cls");
            printf("\n\t\t\t Usuario inexistente. Intentelo nuevamente.");
        }
    }
    while (flag1!=1);

    do
    {
        printf("\n\t\t\t Contraseña: ");
        fflush(stdin);
        asteriscos(password);
        flag2=compararPassword (C,password);
        if (flag2==0)
        {
            system("cls");
            printf("\n\t\t\t Contraseña incorrecta, por favor vuelva a intentarlo\n");
        }

        intentos++;

        if (intentos==3)
        {
            system("cls");
            printf("\n\t\t\t Has sobrepasado el limite de intentos. ");
            system("\t\t\t pause");
            idUser=0;
        }

        idUser=verificarSiEstaActivo(C,idUser);
    }
    while (flag2==0 && intentos!=3);

    return idUser;
}
///     ------------------    COMPARAR PASSWORD.    ------------------
int compararPassword (char C[], char password[])
{
    int flag=0;
    stCliente cl;
    FILE *archivoDeCliente = fopen(C,"rb");

    if(archivoDeCliente!= NULL)
    {
        while ( fread (&cl, sizeof (stCliente), 1, archivoDeCliente) > 0)
        {
            if (strcmp (cl.password, password) == 0)
            {
                flag=1;
            }
        }

    }
    fclose(archivoDeCliente);
    return flag;
}
///     ------------------    VERIFICAR ASTERISCOS.    ------------------
int verificarSiEstaActivo (char C[],int idUser)
{
    stCliente cl;
    FILE *archivoDeCliente = fopen(C,"rb");

    if(archivoDeCliente!= NULL)
    {
        while ( fread (&cl, sizeof (stCliente), 1, archivoDeCliente) > 0)
        {
            if (cl.idCliente==idUser)
            {
                if (cl.activo==1)
                {
                    idUser=cl.idCliente;
                }

                else
                {
                    printf("\n\n\t\t\tEste usuario ya no se encuentra activo.\n\t\t\tSi desea activarla informe al admin. Por favor, ");
                    system("pause");
                    idUser=0;
                }
            }
        }

    }
    fclose(archivoDeCliente);
    return idUser;
}
///     ------------------    BUSCAR ID CLIENTE.    ------------------
int buscaIdCliente (char C[],char usuario[])
{
    int idUser;
    stCliente cl;
    FILE *archivoDeCliente = fopen(C,"rb");

    if(archivoDeCliente!= NULL)
    {
        while ( fread (&cl, sizeof (stCliente), 1, archivoDeCliente) > 0)
        {
            if (strcmp (cl.userName, usuario) == 0)
            {
                idUser=cl.idCliente;
            }
        }

    }
    fclose(archivoDeCliente);
    return idUser;
}
///     ------------------    ALTA DE PEDIDO.    ------------------
void altaPedido(char pD[],char pR[],char C[],int idUser,char F[],int dimensionFecha)
{
    char control = 's';
    char nomUser[30];
    int ultimoPedido,codProd=0,pdCant=0;
    float costo=0, calc=0,acumulador=0;

    stCliente cl;
    stPedidos pd;
    stProductos pr;

    FILE *archivoDeCliente = fopen(C,"rb");

    if (archivoDeCliente!=NULL)
    {
        while(fread(&cl,sizeof(stCliente),1,archivoDeCliente)>0)
        {
            if(cl.idCliente == idUser)
            {
                strcpy(nomUser,cl.userName);
            }
        }
    }

    ultimoPedido=ultimoIdPedido (pD);
    pd.idPedido =  ultimoPedido + 1;

    FILE *archivoPedidos = fopen(pD,"ab");

    if(archivoPedidos != NULL)
    {
        pd.idCliente=idUser;
        obtenerFecha(F,dimensionFecha);
        strcpy(pd.fecha,F);
        printf("\n*********************************************************");
        printf("\nUsuario: %s\t\t\t\t FECHA: %s\n\t\t\tNUMERO DE PEDIDO: %d \n",cl.nombre,pd.fecha,pd.idPedido);
        FILE *archivoProductos = fopen(pR,"rb");
        do
        {

            mostrarProductos(pR);
            printf("< --- SELECCIONE EL CODIGO DEL PRODUCTO --- >  \n");
            scanf("%d",&codProd);
            printf("\n\nCodigoProducto del scanf: %d",codProd);

            rewind(archivoProductos);

            while(fread(&pr,sizeof(stProductos),1,archivoProductos) > 0)
            {
                printf("\nCONTROL WHIL\n");
                if(codProd==pr.codProducto)
                {
                    printf("\nCONTROL IF\n");
                    strcpy(pd.producto, pr.producto);
                    costo = pr.costo;
                    printf("\nproducto: %s\n",pd.producto);
                    printf("\ncosto: %0.2f\n",costo);
                }
            }

            printf("INGRESE LA CANTIDAD DE UNIDADES A COMPRAR: \n");
            scanf("%d",&pdCant);
            pd.cantidad=pdCant;
            calc = (costo * pdCant);

            acumulador =  acumulador + calc;
            printf("\nUsted va gastando: %0.2f \n",acumulador);
            pd.costoPedido=acumulador;

            printf("\nDESEA AGREGAR MAS PRODUCTOS AL CARRO?? (S/N)\n");
            fflush(stdin);
            control = getch();
//            printf("INGRESE UNA DESCRIPCION SI LO DESEA: \n");
//            fflush(stdin);
//            gets(pd.descripcion);

            printf("EL VALOR FINAL DEL PEDIDO ES: %0.2f \n",pd.costoPedido);

            fwrite(&pd,sizeof(stPedidos),1,archivoPedidos);


        }
        while(control != 'n');
        pd.idPedido++;
        fclose(archivoPedidos);
        fclose(archivoDeCliente);
    }
}
///     ------------------      ULTIMO ID PEDIDO.    ------------------
int ultimoIdPedido (char R[])
{
    int a = 999;
    stPedidos l;
    FILE *archpedidos = fopen(R,"rb");
    if(archpedidos != NULL)
    {
        while(fread(&l,sizeof(stPedidos),1,archpedidos)>0)
        {
            a = l.idPedido;
        }
    }

    fclose(archpedidos);
    return a;
}
///     ------------------     OBTENER FECHA.    ------------------
void  obtenerFecha(char F[],int dimension)
{
    time_t t;
    struct tm *tm;
    t = time(NULL);
    tm = localtime(&t);
    strftime(F,dimension,"%d-%m-%Y %I:%M%p",tm);
}

///     ------------------     MODIFICAR PEDIDOS.    ------------------
void modificarPedido(char pD[],char pR[],int idUser)
{
    int flag=0,flag2=0,pedido,codProd,pdCant;
    float costo=0,calc, acumulador;
    char control='s';
    stPedidos pd;
    stProductos pr;
    mostrarPedidos(pD,idUser);
    FILE *archivoPedidos=fopen(pD,"r+b");
    printf("\nIngrese el numero de pedido a modificar: ");
    scanf("%d",&pedido);

    if(archivoPedidos!=NULL)
    {
        while(!feof(archivoPedidos)&& flag ==0)
        {
            if(fread(&pd,sizeof(stPedidos),1,archivoPedidos)>0)
            {
                if(pd.idPedido == pedido)
                {
                    flag=1;
                }
            }
        }
    }
    if(flag ==1)
    {

        if(archivoPedidos!=NULL)
        {
            do
            {
                mostrarProductos(pR);
                printf("< --- SELECCIONE EL CODIGO DEL PRODUCTO --- >  \n");
                scanf("%d",&codProd);

                FILE *archivoProductos=fopen(pR,"rb");
                while(!feof(archivoProductos) && flag2==0)
                {
                    if(fread(&pd,sizeof(stPedidos),1,archivoPedidos)>0)
                    {
                        if(pd.idPedido==codProd)
                        {
                            flag2=1;
                        }
                    }
                }

                if(flag2==1)
                {
                    printf("INGRESE LA CANTIDAD DE UNIDADES A COMPRAR: \n");
                    scanf("%d",&pdCant);
                    pd.cantidad=pdCant;

                    strcpy(pd.producto, pr.producto);
                    costo = pr.costo;
                    calc = (costo * pdCant);
                    acumulador =  acumulador + calc;
                    printf("\nUsted va gastando: %0.2f \n",acumulador);
                    pd.costoPedido=acumulador;
                    ///***********************************
                    fseek(archivoPedidos, -1*sizeof(stPedidos),SEEK_CUR);
                    fwrite(&pd,sizeof(stPedidos),1,archivoPedidos);

                }
                printf("\nDESEA AGREGAR MAS PRODUCTOS AL CARRO?? (S/N)\n");
                fflush(stdin);
                control = getch();
                fclose(archivoProductos);
            }
            while(control != 'n');
        }


    }


    fclose(archivoPedidos);

}
///     ------------------     MOSTRAR PEDIDOS.    ------------------
void mostrarPedidos (char pD[],int idUser)
{
    stPedidos pd;
    FILE *archpedidos=fopen(pD,"rb");

    if(archpedidos!=NULL)
    {
        printf("============== TUS PEDIDOS SON ================== \n");
        while(fread(&pd,sizeof(stPedidos),1,archpedidos)>0 && idUser==pd.idCliente)
        {
            printf("ID PEDIDO: %d\t\t FECHA: %s \n",pd.idPedido,pd.fecha);
            printf("PRODUCTO: %s\n",pd.producto);
            printf("CANTIDAD: %d\n",pd.cantidad);
            printf("COSTO PEDIDO: %0.2f \n",pd.costoPedido);
            printf("=============================================== \n");
        }
    }
    fclose(archpedidos);
}
///     ------------------     ALTA PRODUCTOS.    ------------------
void altaProductos(char P[])
{
    char control = 's';
    int codProducto = 0;
    stProductos a;
    codProducto = ultimoCodProducto(P);
    FILE *archivoProductos = fopen(P,"ab");
    a.codProducto = codProducto + 1;
    do
    {
        printf("CODIGO DE PRODUCTO: %d \n",a.codProducto);
        printf("INGRESE EL PRODUCTO A AGREGAR: \n");
        fflush(stdin);
        gets(a.producto);
        printf("INGRESE EL PRECIO DEL PRODUCTO: \n");
        scanf("%f",&a.costo);
        fwrite(&a,sizeof(stProductos),1,archivoProductos);
        a.codProducto ++;
        printf("< --- DESEA CARGAR OTRO PRODUCTO? --- >  S/N\n");
        fflush(stdin);
        control = getch();

        system("cls");
    }
    while(control == 's');
    fclose(archivoProductos);
}
///     ------------------     ULTIMO CODIGO DE PRODUCTO.    ------------------
int ultimoCodProducto(char P[])
{
    int a = 0;
    stProductos pr;
    FILE *archivoProductos = fopen(P,"rb");
    if(archivoProductos != NULL)
    {
        while(fread(&pr,sizeof(stProductos),1,archivoProductos)>0)
        {
            a = pr.codProducto;
        }
    }
    fclose(archivoProductos);
    return a;
}
///     ------------------     OBTENER COSTO.    ------------------
//float obtenerCosto(char P[],int seleccion)
//{
//    stProductos p;
//    float costo;
//
//    FILE *archivoProductos = fopen(P,"rb");
//    if(archivoProductos != NULL)
//    {
//        while(fread(&p,sizeof(stProductos),1,archivoProductos)>0)
//        {
//            if(p.codProducto == seleccion)
//            {
//                costo = p.costo;
//            }
//        }
//
////       rewind(archivoProductos);
//    }
//
//    fclose(archivoProductos);
//
//    return costo;
//}
///     ------------------     MOSTRAR PRODUCTOS.    ------------------
void mostrarProductos(char P[])
{
    stProductos a;
    FILE *archivoProductos = fopen(P,"rb");
    if(archivoProductos != NULL)
    {
        printf("INICIANDO MUESTREO DE PRODUCTOS .....\n");
        printf(" ========================== \n");
        while(fread(&a,sizeof(stProductos),1,archivoProductos) > 0)
        {
            printf("CODIGO: %d \n",a.codProducto);
            printf("PRODUCTO: %s \n",a.producto);
            printf("PRECIO: %.2f \n",a.costo);
            printf(" ========================== \n");
        }
        printf("FINALIZANDO MUESTREO DE PRODUCTOS....\n");
    }
    else
    {
        printf("ERROR AL LISTAR LOS PRODUCTOS: ERROR \"ARCHIVO PRODUCTOS VACIO\" \n");
    }
    fclose(archivoProductos);
}
/////     ------------------     SELECCIONAR PRODUCTOS.    ------------------
//float seleccionarProductos(char P[],int seleccion[],int cantidad[],int *validos)
//{
//    float costo;
//    int  sel;
//    int cant;
//    int i = 0;
//    float calc = 0;
//    float acumulador = 0;
//    char control = 's';
//
//    stProductos p;
//    mostrarProductos(P);
//
//    FILE *archivoProductos = fopen(P,"rb");
//
//    printf("\n");
//
//    do
//    {
//        printf("< --- SELECCIONE EL CODIGO DEL PRODUCTO --- >  \n");
//        scanf("%d",&sel);
//
//        seleccion[i] = sel;
//
//        costo = obtenerCosto(P,sel);
//
//        printf("INGRESE LA CANTIDAD DE UNIDADES A COMPRAR: \n");
//        scanf("%d",&cant);
//
//        cantidad[i] = cant;
//
//        calc = (costo * cant);
//
//        acumulador =  acumulador + calc;
//
//        printf("DESEA AGREGAR MAS PRODUCTOS AL CARRO?? \n");
//        fflush(stdin);
//        control = getch();
//
//        printf("VA GASTANDO: %0.2f \n",acumulador);
//
//        i++;
//    }
//    while(control == 's');
//
//    *validos = i;
//
//    fclose(archivoProductos);
//
//    return acumulador;
//}
/////     ------------------     OBTENER COSTO.    ------------------
//float obtenerCosto(char P[],int seleccion)
//{
//    stProductos p;
//    float costo = 0;
//    FILE *archivoProductos = fopen(P,"rb");
//    if(archivoProductos != NULL)
//    {
//        while(fread(&p,sizeof(stProductos),1,archivoProductos)>0)
//        {
//            if(p.codProducto == seleccion)
//            {
//                costo = p.costo;
//            }
//        }
//        rewind(archivoProductos);
//    }
//    fclose(archivoProductos);
//    return costo;
//}
/// FIN ***********************************************************************************************************








//void modificarPedido(char pD[],char pR[],int idUser)
//{
//
//    int pedido,codProd,pdCant,posicion;
//    float costo,acumulador, calc;
//    char control='s';
//    stPedidos pd;
//    stProductos pr;
//
//    mostrarPedidos (pD,idUser);
//
//
//    FILE *archivoPedidos=fopen(pD,"rb");
//
//    if(archivoPedidos!=NULL)
//    {
//
//        printf("\nSeleccione pedido a modificar: ");
//        scanf("%d",&pedido);
//        printf("\n\nCONTROL 1\n");
//
//        while(fread(&pd,sizeof(stPedidos),1,archivoPedidos)>0)
//        {
//            printf("\n\nCONTROL While\n");
//            if (pedido==pd.idPedido)
//            {
//                posicion=ftell(archivoPedidos);
//
//                fclose(archivoPedidos);
//                FILE *archivoPedidos=fopen(pD,"ab");
//                fseek(archivoPedidos,posicion-1,SEEK_SET);
//                do
//                {
//                    FILE *archivoProductos=fopen(pR,"rb");
//                    if(archivoProductos!=NULL)
//                    {
//                        mostrarProductos(pR);
//                        printf("< --- SELECCIONE EL CODIGO DEL PRODUCTO --- >  \n");
//                        scanf("%d",&codProd);
//                        printf("\n\nCodigoProducto del scanf: %d",codProd);
//
//                        while(fread(&pr,sizeof(stProductos),1,archivoProductos) > 0)
//                        {
//                            if(codProd==pr.codProducto)
//                            {
//                                printf("\nCONTROL IF PRODUCTOS\n");
//                                strcpy(pd.producto, pr.producto);
//                                costo = pr.costo;
//                                printf("\nproducto: %s\n",pd.producto);
//                                printf("\ncosto: %0.2f\n",costo);
//                            }
//                        }
//                    }
//                    fclose(archivoProductos);
//                    printf("INGRESE LA CANTIDAD DE UNIDADES A COMPRAR: \n");
//                    scanf("%d",&pdCant);
//                    pd.cantidad=pdCant;
//                    calc = (costo * pdCant);
//
//                    acumulador =  acumulador + calc;
//                    printf("\nUsted va gastando: %0.2f \n",acumulador);
//                    pd.costoPedido=acumulador;
//
//                    printf("\nDESEA AGREGAR MAS PRODUCTOS AL CARRO?? (S/N)\n");
//                    fflush(stdin);
//                    control = getch();
//
//                    fwrite(&pd,sizeof(stPedidos),1,archivoPedidos);
//
//
//                }
//                while(control != 'n');
//                printf("EL VALOR FINAL DEL PEDIDO ES: %0.2f \n",pd.costoPedido);
//            }
//
//        }
//
//
//    }
//    fclose(archivoPedidos);
//
//}


//
//void seleccionarProductos(char pD[],char pR[],int idUser)
//{
//    int  costoPedido,pdCant,codProd;
//    int i = 0;
//    float calc = 0;
//    float acumulador = 0;
//    char control = 's';
//
//    stPedidos pd;
//    stProductos pr;
//    mostrarProductos(pR);
//
//    FILE *archivoProductos = fopen(pR,"rb");
//    FILE *archivoPedidos = fopen(pD,"ab");
//    pd.idCliente=idUser;
//    if(archivoProductos!=NULL && archivoPedidos!=NULL)
//    {
//        do
//        {
//            printf("< --- SELECCIONE EL CODIGO DEL PRODUCTO --- >  \n");
//            scanf("%d",&codProd);
//
//            pd.codProducto=codProd;
//
//            while(fread(&pr,sizeof(stProductos),1,archivoProductos) > 0)
//            {
//                if(pr.codProducto == codProd)
//                {
//                    strcpy(pd.producto, pr.producto);
//                }
//            }
//            costoPedido = obtenerCosto(pR,codProd);
//
//            printf("INGRESE LA CANTIDAD DE UNIDADES A COMPRAR: \n");
//            scanf("%d",&pdCant);
//            calc = (costoPedido * pdCant);
//
//            acumulador =  acumulador + calc;
//            printf("VA GASTANDO: %0.2f \n",acumulador);
//            pd.costoPedido=acumulador;
//            fwrite(&pd,sizeof(stPedidos),1,archivoPedidos);
//
//
//            printf("\nDESEA AGREGAR MAS PRODUCTOS AL CARRO?? \n");
//            fflush(stdin);
//            control = getch();
//            i++;
//        }
//        while(control == 's');
//    printf("INGRESE UNA DESCRIPCION SI LO DESEA: \n");
//    fflush(stdin);
//    gets(pd.descripcion);
//     printf("EL VALOR DEL PEDIDO SELECCIONADO ES: %0.2f \n",pd.costoPedido);
//
//    fwrite(&pd,sizeof(stPedidos),1,archivoPedidos);
//
//    }
//    fclose(archivoProductos);
//    fclose(archivoPedidos);
//
//}











//
//typedef struct          /// STRUCTURA MATRICULA ALUMNOS.
//{
//    int matricula;
//    char nombre[30];
//    char genero;
//} stAlumno;
//Estructura de Pedido
//
//int cargaStAlumnos(char rutaArchivo[]);
//void mostraEstructuraAlumnos(char rutaArchivo[]);
////void buscaStAlumno(stAlumno A[],int v);
//int main()
//{
//    setlocale(LC_ALL,"");
//
//    int validos=0, menu;
//    char rutaArchivo[]=("datosDeAlumnos.dat");
//
//    do
//    {
//
//        printf("\t\tTRABAJO PRACTICO N°6 - ESTRUCTURAS\n");
//        printf("\n1.	Cargue arreglo de alumnos, hasta que el usuario lo decida.");
//        printf("\n2.	Mostrar arreglo de alumnos.");
//
//        printf("\n\t\t---Engrese el número del ejercicio: ");
//        scanf("%d",&menu);
//        switch(menu)
//        {
//        case 1:
//            system("cls");
//            printf("\n********  CARGA DE MATRICULAS. *********");
//            validos=cargaStAlumnos(rutaArchivo);
//            printf("\nSe cargaron %d matriculas.", validos);
//            break;
//        case 2:
//            system("cls");
//            printf("\n********  MOSTRAR MATRICULAS. *********\n");
//            mostraEstructuraAlumnos(rutaArchivo);
//            break;
//
//            printf("\n\n\t\t---Desea continuar?---");
//            printf("\n\tESC para salir. cualquier tecla para continuar.");
//            menu=getch();
//
//        }
//    }
//    while(menu!=ESC);
//
//    return 0;
//}
/////         **********      FUNCIONES       **********
//int cargaStAlumnos(char rutaArchivo[])
//{
//    int i=0;
//    char salir='s';
//
//    stAlumno A;
//    FILE *archivo=fopen(rutaArchivo,"ab");
//
//    if(archivo==NULL)
//    {
//        printf("\nEl archivo no existe.\n");
//    }
//    else
//    {
//        while(salir=='s')
//        {
//            printf("\nIngrese numero Matricula: ");
//            scanf("%d",&A.matricula);
//            printf("\nIngrese Nombre y Apellido: ");
//            fflush(stdin);
//            gets(A.nombre);
//            printf("\nIngrese el Genero: ");
//            fflush(stdin);
//            scanf("%c",&A.genero);
//            // A[i].genero=getch();
//
//            fwrite(&A,sizeof(stAlumno),1,archivo);
//            i++;
//
//            printf("\n\n\tDesea continuar con la carga de datos? (s/n): \n");
//            fflush(stdin);
//            salir=getch();
//        }
//    }
//    fclose(archivo);
//
//    return i;
//}
//void mostraEstructuraAlumnos(char rutaArchivo[])
//{
//    int i=0;
//    stAlumno a;
//    FILE *archivo=fopen(rutaArchivo,"rb");
//    if(archivo!=NULL)
//    {
//        while(fread(&a,sizeof(stAlumno),1,archivo)>0)
//        {
//            printf("\nNumero de Matricula: %d",a.matricula);
//            printf("\nNombre y Apellido: %s",a.nombre);
//            printf("\nGenero : %c",a.genero);
//            i++;
//            printf("\n****************************************\n");
//        }
//    }
//    system("pause");
//    fclose(archivo);
//}
