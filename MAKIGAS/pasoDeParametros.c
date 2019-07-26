#include <stdio.h>

int main(int argc, char** argv){

    //un array en relidad, es un puntero cuya direccion es la del primer elemento del puntero

   /*  int prueba[10] = {1,2,3,4,5,6,7,8,9,10};

    printf("%d\n", *(prueba + 1));

    return 0; */

    // imprimimos el número de parametros
    printf("%d\n", argc);

    // imprimo los parametros
    int i;
    for(i = 0; i< argc; i++){
        printf("%s ", argv[i]);
    }

    return 0;
}