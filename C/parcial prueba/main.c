//#include <stdio.h>
//#include <stdlib.h>
//#include "pila.h"
//#include <time.h>
//#include <conio.h>
//
//#include<string.h>
//#include <wchar.h>      /// Incluye un soporte para amplios tipos de caracteres.
//#include <locale.h>     /// Incluye el soporte para distintos tipos de formatos de fecha, moneda, texto, etc.
//
//#include <windows.h>
//
//#define DEBUG 1
//
//#define FIN_ANIMACION 0
//
//#define FPS 10 // Si no fuera TAN cutre dibujando (O mas bien borrando) Windows, la tasa de frames seria real
//
////char CIRC0[] = " _";
////char CIRC1[] = " _\n  \\";
////char CIRC2[] = " _\n  \\\n  |";
////char CIRC3[] = " _\n  \\\n  |\n  /";
////char CIRC4[] = " _\n  \\\n  |\n _/";
////char CIRC5[] = " _\n  \\\n  |\n\\_/";
////char CIRC6[] = " _\n  \\\n| |\n\\_/";
////char CIRC7[] = " _\n/ \\\n| |\n\\_/";
////char CIRC8[] = "\n/ \\\n| |\n\\_/";
////char CIRC9[] = "\n/\n| |\n\\_/";
////char CIRC10[] = "\n/\n|\n\\_/";
////char CIRC11[] = "\n/\n|\n\\_";
////char CIRC12[] = "\n/\n|\n\\";
////char CIRC13[] = "\n/\n|";
////char CIRC14[] = "\n/";
//
//
////char CIRC0[] = " B \n";
////char CIRC1[] = "\t i \n";
////char CIRC2[] = "\t\t e \n";
////char CIRC3[] = "\t\t\t n \n";
////char CIRC4[] = "\t\t\t\t b \n";
////char CIRC5[] = "\t\t\t\t\t e \n";
////char CIRC6[] = "\t\t\t\t\t\t n \n";
////char CIRC7[] = "\t\t\t\t\t\t\t i \n";
////char CIRC8[] = "\t\t\t\t\t\t\t\t d \n";
////char CIRC9[] = "\t\t\t\t\t\t\t\t\t o \n";
////char CIRC10[] ="\t\t\t\t\t\t\t\t\t \n";
////char CIRC11[] ="\t\t\t\t\t\t\t\t\t\t A \n";
////char CIRC12[] ="\t\t\t\t\t\t\t\t\t\t\t App Patacones :D \n";
////char CIRC13[] = "\n\t\t\t\t\t\t\t\t\t\t\t\t p \n";
////char CIRC14[] = "\n\t\t\t\t\t\t\t\t\t\t\t\t\t Patacones \n";
//
//char CIRC0[] ="____Sexy?Sex\n";
//char CIRC1[] ="____?Sexy?Sexy\n";
//char CIRC2[] ="___y?Sexy?Sexy?\n";
//char CIRC3[] ="___?Sexy?Sexy?S\n";
//char CIRC4[] ="___?Sexy?Sexy?S\n";
//char CIRC5[] ="__?Sexy?Sexy?Se\n";
//char CIRC6[] ="_?Sexy?Sexy?Se\n";
//char CIRC7[] ="_?Sexy?Sexy?Se\n";
//char CIRC8[] ="_?Sexy?Sexy?Sexy?\n";
//char CIRC9[] ="?Sexy?Sexy?Sexy?Sexy\n";
//char CIRC10[] ="?Sexy?Sexy?Sexy?Sexy?Se\n";
//char CIRC11[] ="?Sexy?Sexy?Sexy?Sexy?Sex\n";
//char CIRC12[] ="_?Sexy?__?Sexy?Sexy?Sex\n";
//char CIRC13[] ="___?Sex____?Sexy?Sexy?\n";
//char CIRC14[] ="___?Sex_____?Sexy?Sexy\n";
//char CIRC15[] ="___?Sex_____?Sexy?Sexy\n";
//char CIRC16[] ="____?Sex____?Sexy?Sexy\n";
//char CIRC17[] ="_____?Se____?Sexy?Sex\n";
//char CIRC18[] ="______?Se__?Sexy?Sexy\n";
//char CIRC19[] ="_______?Sexy?Sexy?Sex\n";
//char CIRC20[] ="________?Sexy?Sexy?sex\n";
//char CIRC21[] ="_______?Sexy?Sexy?Sexy?Se\n";
//char CIRC22[] ="_______?Sexy?Sexy?Sexy?Sexy?\n";
//char CIRC23[] ="_______?Sexy?Sexy?Sexy?Sexy?Sexy\n";
//char CIRC24[] ="_______?Sexy?Sexy?Sexy?Sexy?Sexy?S\n";
//char CIRC25[] ="________?Sexy?Sexy____?Sexy?Sexy?se\n";
//char CIRC26[] ="_________?Sexy?Se_______?Sexy?Sexy?\n";
//char CIRC27[] ="_________?Sexy?Se_____?Sexy?Sexy?\n";
//char CIRC28[] ="_________?Sexy?S____?Sexy?Sexy\n";
//char CIRC29[] ="_________?Sexy?S_?Sexy?Sexy\n";
//char CIRC30[] ="________?Sexy?Sexy?Sexy\n";
//char CIRC31[] ="________?Sexy?Sexy?S\n";
//char CIRC32[] ="________?Sexy?Sexy\n";
//char CIRC33[] ="_______?Sexy?Se\n";
//char CIRC34[] ="_______?Sexy?\n";
//char CIRC35[] ="______?Sexy?\n";
//char CIRC36[] ="______?Sexy?\n";
//char CIRC37[] ="______?Sexy?\n";
//char CIRC38[] ="______?Sexy\n";
//
//
//
//
//
//
//
//
//
//
//
////char CIRC13[] = "\n\t\t\t\t\t\t\t\t\t\t p \n";
////char CIRC14[] = "\n\t\t\t\t\t\t\t\t\t\t\t\t\t Patacones \n";
//
////char *CIRCULO[] = {CIRC0, CIRC1, CIRC2, CIRC3, CIRC4, CIRC5, CIRC6, CIRC7,
////                   CIRC8, CIRC9, CIRC10, CIRC11, CIRC12, CIRC13, CIRC14, FIN_ANIMACION
////                  };
////
//char *CIRCULO[] = {CIRC0, CIRC1, CIRC2, CIRC3, CIRC4, CIRC5, CIRC6, CIRC7,
//                   CIRC8, CIRC9, CIRC10, CIRC11, CIRC12,CIRC13,CIRC14,CIRC15,CIRC16,CIRC17,CIRC18,CIRC19,CIRC20,
//                   CIRC21,CIRC22,CIRC23,CIRC24,CIRC25,CIRC26,CIRC27,CIRC28,CIRC29,CIRC30,CIRC31,CIRC32,CIRC33,
//                   CIRC34,CIRC35,CIRC36,CIRC37,CIRC38, FIN_ANIMACION
//                  };
//
//void dibujar_anim(char *animacion[], int repeticiones)
//{
//    setlocale(LC_ALL, "");
//    int i;
//    int frame = 0;
//printf("+\n!   !   !   !\n");
//    for (i=0; i<repeticiones; i++)
//    {
//        while (animacion[frame] != FIN_ANIMACION)
//        {
//            //system ("cls");
//            if (DEBUG)
//                //printf ("⢀⡴⠑⡄⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣤⣀⡀");
//                printf (animacion[frame]);
//
//            Sleep (1000/FPS);
//            frame++;
//        }
//
//        frame = 0;
//    }
//    printf("\t\t\t\t\t\t\t\t\t\t\t\t+!   !   !   !\n");
//}
//
//int main (void)
//{
//setlocale(LC_ALL, "");
//    dibujar_anim(CIRCULO, 1);
//
//    return 0;
//}
//
//
//
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
HANDLE wHnd;

int main (){


   for (int i=0 )
   {

   }
}
