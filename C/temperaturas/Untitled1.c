//#include <stdio.h>
//#include <stdlib.h>
// libreria de pilas
//#include "pila.h"
// libreria del tiempo para usar semillas del rand
//#include <time.h>
//
///12.	Dada la pila ORIGEN ordenarla en forma ascendente por método de inserción dejando el resultado en la pila ORIGEN.
///     Para este ejercicio usar lo aprendido para el ejercicio 5.
//
//salida base mayor a tope menor de lista ordenada.
//
////int main()
////{
//    //definir variables Pilas Pila, descarte, mayor, ordenada
//    Pila pila, ordenada, aux;
//    //definir int cont i cantA
//    int  i, cantA, valor;
//    // INICIALIZO las pilas
//    inicpila(&pila);
//    inicpila(&aux);
//    inicpila(&ordenada);
//    valor=0;
//
//    /*//inicio la semilla del randificación
//    srand(time(NULL));
//    //ingreso de datos cantA=rand 3
//    cantA=rand()%8+5;
//    //ingreso de valores en For pila cantA
//    for(i=0; i<cantA; i++)
//    {
//        apilar(&pila, rand()%9);
//    }
//    */
//    apilar(&pila, 5);
//    apilar(&pila, 6);
//    apilar(&pila, 1);
//    apilar(&pila, 9);
//    apilar(&pila, 1);
//    apilar(&pila, 9);
//    apilar(&pila, 11);
//    apilar(&pila, 0);
//
//    // COMPROBACION DE QUE TODO ESTA CORRECTO EN LAS PILAS
//    printf("\n Cant de elementos en pila: %i\n", cantA);
//    mostrar(&pila);
//
//
//    printf("\n :::::::::::::::::::::::::Ordenamiento de la lista:::::::::::::::::::::::::\n" );
//
//    // 1º desapilo el primer valor PROBLEMA EL PRIMER VALOR DEBE SER MENOR
//    apilar(&ordenada, desapilar(&pila));
//
//
//    while(!pilavacia(&pila))
//    {
//        // desapilo un valor
//        valor=tope(&pila);
//        desapilar(&pila);
//
//
//        if(valor>tope(&ordenada) )
//        {
//            //si es menor
//            while(valor>tope(&ordenada) || pilavacia(&ordenada))
//            {
//                apilar(&aux, desapilar(&ordenada));
//            }
//            apilar((&ordenada), valor);
//            //termino de vaciar la pila
//            while(!pilavacia(&ordenada))
//            {
//                apilar(&aux, desapilar(&ordenada));
//            }
//            //armo denuevo ordenada
//            while(!pilavacia(&aux))
//            {
//                apilar(&ordenada, desapilar(&aux));
//
//            }
//        }
//        //Si es mayor lo apilo en el tope
//        else
//        {
//            apilar(&ordenada, valor);
//        }
//
//    }
//
//
//    //ORDENO LA PILA NUEVAMENTE E IMPRIMO
//
//    printf("\n Pila de ordenada: \n" );
//    mostrar(&ordenada);
//
//    return 0;
//}
