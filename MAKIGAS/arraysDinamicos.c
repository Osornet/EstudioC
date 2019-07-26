#include <stdio.h>
#include <stdlib.h>

int main(){

    /* char* cadena;
    cadena = malloc(sizeof(char) * 128); //128 caracteres;
    printf("introduzca una cadena: ");
    //scanf("%s", cadena); // scanf detecta un espacio como final de cadena.
    fgets(cadena, 128, stdin); //lee caracteres desde de cualquier origen stdin es una constante que indica que reciba los datos del teclado.
    printf("\nhas ecrito: %s.\n", cadena);
    free(cadena); */

    int* numeros;
    numeros  = malloc(sizeof(int) * 100);

    
    int i = 0;
    for(; i < 100; i++){
        numeros[i] = i*2;
    }

    for(i = 0; i< 100; i++){
        printf("numero: %d\n", numeros[i]);
    }
    free(numeros);

    return 0;
}