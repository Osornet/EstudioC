#include <stdio.h>
#include <stdlib.h>


typedef struct Producto{
    int codigo;
    char descripcion[20];
    float precioUnitario;
} t_producto;

float aplicarIva(float precioBase);
void emitirSaludo(void);
void imprimirProducto(t_producto);
t_producto leerProducto(char* saludo);

int main()
{
    t_producto productos[4];
    t_producto producto;
    char decision;
    int i, cantidad = 0;
    float total = 0.0;

    emitirSaludo();

    while(cantidad < 4){
        do{
            printf("Hay %d productos en el carrito. ¿Pasamos otro? [s/n] ", cantidad);
            decision = getchar();
            while(getchar() == EOF); // esta linea se usa para que se coma el salto de linea \n
        }while(decision !='s' && decision != 'S' && decision != 'n' && decision != 'N');
        if(decision == 'n' || decision == 'N'){
            break;
        }
        producto = leerProducto();
        productos[cantidad++] = producto;
    }

    for(i = 0; i < cantidad; i++){
        imprimirProducto(productos[i]);
        total += productos[i].precioUnitario;
    }

    printf("Total productos: %d\n", cantidad);
    printf("Precio total sin IVA %2f\n", total);
    printf("Precio total con IVA %2f\n", aplicarIva(total));
    printf("\n\nBuenos Dias.\n");

    return 0;
}



