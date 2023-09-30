#ifndef REGISTROARCHIVO_H_INCLUDED
#define REGISTROARCHIVO_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>

#define arRegistro "registroCuentaBancaria.dat"

typedef struct{
    int idRegistro;

    int nroCuenta;
    char nombreCliente[30];
    char apellidoCliente[30];
    char fechaMovimiento[11];
    float importe;
} stRegistroCuentaBancaria;

void mostrarUnRegistro(stRegistroCuentaBancaria r);
void mostrarRegistros(char archivo[]);

#endif // REGISTROARCHIVO_H_INCLUDED
