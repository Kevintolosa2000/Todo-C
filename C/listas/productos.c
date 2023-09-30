#include "productos.h"

stProducto cargarUnProducto ()
{
    stProducto a;
    printf("ID:");
    scanf("%d",&a.idProducto);///autopincrementalll!!!!!!!!!
    printf("\nIngrese nombre del producto: ");
    fflush(stdin);
    gets(a.nombre);
    printf("\nIngrese la marca del producto: ");
    fflush(stdin);
    gets(a.marca);
    printf("\nIngrese el precio del producto: ");
    scanf("%f", &a.precio);
    a.eliminado=0;
    return a;
}
void mostrarMuchosProductos (stProducto a[], int validos)
{
    int i=0;
    while (i<validos)
    {
        mostrarUnProducto(a[i]);
        i++;
    }
}
void mostrarUnProducto(stProducto a)
{
    puts("\n---------------");
    printf("\n Id: %d",a.idProducto);
    printf("\n Nombre del producto:%s",a.nombre);
    printf("\n La marca del producto:%s",a.marca);
    printf("\n El precio del producto:%0.02f", a.precio);
    estePrinteaEstado(a.eliminado);
    puts("\n---------------");
}

void estePrinteaEstado(int numero)
{
    if (numero==1)
    {
        printf("\n El producto se encuentra eliminado: %d", numero);
    }
    else if (numero==0)
    {
        printf("\n El producto no se encuentra eliminado: %d", numero);
    }
    else
    {
        printf("\n Se puso cualquier cosa xd: %d", numero);
    }
}
