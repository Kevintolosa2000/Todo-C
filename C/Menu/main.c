#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

void menuNavegable (int menu,int menuinicio,int menufin, int lineainicio, int eleccion,int opcion);
int sistemanavegable (int menu,int menuinicio,int menufin, int lineainicio, int eleccion);
int siono (int menu,int menuinicio,int menufin, int lineainicio, int eleccion,int opcion);
void puntosParaElegir (int eleccion);
void ejey(int y);

int main()
{
    int menuy=0,elecciony=0,menuinicioy=0,menufiny=0,lineainicioy=0;
    int opciony=0;

    menuNavegable(menuy,menuinicioy,menufiny,lineainicioy,elecciony,opciony);

    return 0;
}

void menuNavegable (int menu,int menuinicio,int menufin, int lineainicio, int eleccion,int opcion)
{
    do
    {
        system("cls");
        eleccion=sistemanavegable(menu,menuinicio,menufin,lineainicio,eleccion);
        puntosParaElegir(eleccion);
///La linea de abajo era el error ahora esta bien
        system("cls");
        fflush(stdin);
        fflush(stdin);
        fflush(stdin);
        opcion=siono(menu,menuinicio,menufin,lineainicio,eleccion,opcion);

    }
    while(opcion==1);

}

int sistemanavegable (int menu,int menuinicio,int menufin, int lineainicio, int eleccion)
{

    printf("\t\t\t*----------------------MENU----------------------*\n");

    printf("\t\t\t\t1-:D\n");
    printf("\t\t\t\t2-:C\n");
    printf("\t\t\t\t3-;S\n");
    printf("\t\t\t\t4-:o\n");
    printf("\t\t\t\t5-UwU\n");

    menu=1;
    menuinicio=1;
    menufin=5;
    lineainicio=1;

    ejey(lineainicio);
    printf("\t\t\t----->");


    while (1)
    {
        Sleep(100);
        if (GetAsyncKeyState(VK_UP))
        {
            menu=menu==menuinicio ? menufin: --menu;
            printf("\r                               ");
            ejey(lineainicio + menu-1);
            printf("\t\t\t----->");
        }
        else if (GetAsyncKeyState(VK_DOWN))
        {
            menu=menu==menufin ? menuinicio: ++menu;
            printf("\r                               ");
            ejey(lineainicio + menu-1);
            printf("\t\t\t----->");
        }
        else if (GetAsyncKeyState(VK_RETURN))
        {
            eleccion=menu;
           return eleccion;
        }
    }

}


int siono (int menu,int menuinicio,int menufin, int lineainicio, int eleccion,int opcion)
{

    printf("\t\t\t*---------Desea volver a cargar un punto?---------*\n");

    printf("\t\t\t\tSI\n");
    printf("\t\t\t\tNO\n");

    menu=1;
    menuinicio=1;
    menufin=2;
    lineainicio=2; ///Aca le puse un 2 en ves de un 1, entonces se ve bien
    opcion=0;

    ejey(lineainicio);

    printf("\t\t\t----->");

    while(1)
    {
        Sleep(100);

        if (GetAsyncKeyState(VK_UP))
        {
            menu=menu==menuinicio ? menufin: --menu;
            printf("\r                               ");
            ejey(lineainicio + menu-1);
            printf("\t\t\t----->");
        }
        else if (GetAsyncKeyState(VK_DOWN))
        {
            menu=menu==menufin ? menuinicio: ++menu;
            printf("\r                               ");
            ejey(lineainicio + menu-1);
            printf("\t\t\t----->");
        }
        else if (GetAsyncKeyState(VK_RETURN))
        {
            fflush(stdin);
            opcion=menu;
            return opcion;
        }

    }
}
void puntosParaElegir (int eleccion)
{
    int numero=0;
    printf("\n\n\n\n");
    switch (eleccion)
    {
    case 1:
        system("cls");
        printf("\t\t\t*---------------------escribi el numero--------------------*\n");
        scanf("%d",&numero);
        printf("%d",numero);
        system("pause");
        break;
    case 2:
        system("cls");
        printf("\t\t\t*---------------------PATACON---------------------*\n");
        break;
    case 3:
        system("cls");
        printf("\t\t\t*--------------------CORRALITO--------------------*\n");

        break;
    case 4:
        system("cls");
        printf("\t\t\t*----------------------MENEM----------------------*\n");

        break;
    case 5:
        system("cls");
        printf("\t\t\t*--------------Son las 2 ya me canse--------------*\n");

        break;
    default:
        printf("\t\t\t*-----------------:C#*#ERROR#*#:D-----------------\n*");

        break;
    }
}

void ejey (int y)
{
    HANDLE hConsole= GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;

    pos.X=0;
    pos.Y=y;

    SetConsoleCursorPosition(hConsole, pos);
}





