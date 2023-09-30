#include "registroArchivo.h"


/// Se muestra un dato de tipo stRegistroCuentaBancaria
void mostrarUnRegistro(stRegistroCuentaBancaria r){
    printf("\n Id Registro.....................: %d",r.idRegistro);
    printf("\n Nro de Cuenta...................: %d",r.nroCuenta);
    printf("\n Nombre Cliente..................: %s",r.nombreCliente);
    printf("\n Apellido Cliente................: %s",r.apellidoCliente);
    printf("\n Fecha Movimiento................: %s",r.fechaMovimiento);
    printf("\n Importe.........................: %.2f\n",r.importe);

    printf("-----------------------------------------------------------------------------------");
}

/// Se recorre el archivo y usando la funcion mostrarUnRegistro() se muestran los datos del archivo
void mostrarRegistros(char archivo[]){
    stRegistroCuentaBancaria r;
    FILE* pArchRegistro = fopen(archivo,"rb");
    if(pArchRegistro){
        while(fread(&r,sizeof(stRegistroCuentaBancaria),1,pArchRegistro)>0){
            mostrarUnRegistro(r);
        }
        fclose(pArchRegistro);
    }
}
