#include <stdio.h>


int main(){

    int i,j = 1;
    int v[10];

    
    for(i = 0; i<10; i++){
        v[i] = j;
        j *= 3;
    }

    for(i = 0; i<10; i++){
        printf("\nv[%d] = %.5d", i, v[i]);
    }

    return 0;
}