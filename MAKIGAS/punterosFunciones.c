#include <stdio.h>


struct obj
{
    int campo1, campo2;
    struct obj *x;
    void (*func1)(int, char, int);    
};



void impresionPrueba();
void impresionPrueba2(int);
int impresionPrueba3(int);
int sumar(int a, int b, void(*callback)(int));
void imprimir(int valor);

int main(){
   /*  void(*funcion)(void);
    funcion = &impresionPrueba;
    (*funcion)(); */

   /*  void (*funcion)(int);
    funcion = &impresionPrueba2;
    (*funcion)(5);
    return 0; */

    /* int (*funcion)(int);

    funcion = &impresionPrueba3;
    int resp = (*funcion)(3);
    if(resp){
        printf("impresion correcta");
    } */

    sumar(4, 5, &imprimir);



}

void impresionPrueba(){
    printf("esto es una imprescion de prueba\n");
}

void impresionPrueba2(int x){
    printf("parametro: %d\n", x);
}
int impresionPrueba3(int x){
     printf("parametro: %d\n", x);
     return 1;
}


//ejemplo de callback
int sumar(int a, int b, void(*callback)(int)){
    int suma = a + b;
    (*callback)(suma);
    return suma;
}

void imprimir(int valor){
    printf("el resultado es: %d", valor);
}



