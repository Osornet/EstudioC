#include <stdio.h>

int llenar(int *array, int count);
int imprimir(int *array, int count);
int buscar(int *array, int valor);

int main(){

    int count = 10;
    int a [count];

    int resp = llenar(a, count);
    
    resp = buscar(a, 5);
    return 0;
}

int llenar(int *array, int count){

    for(int i = 0; i< count; i++){
        array[i] = i;
    }
    return 0;

}
int imprimir(int *array, int count){
    for(int i = 0 ; i < count; i++){
        printf("%d\n", array[i]);
    }
    return 0;
}
int buscar(int *array, int valor){
    int count;
    count = sizeof(array);
    printf("la cantidad de numeros es : %d", count);
    /* for(int i = 0; i<count; i++){
        if(valor == array[i]){
            return 1;
        }
    } */
    return 0;
}

