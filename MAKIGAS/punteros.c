#include <stdio.h>

int main(){
    /* int i;
    int *p;

    i //int
    &i //int *
    p // int *
    *p // int*/

    int i = 5;
    int *p;

    p = &i;

    printf("%p\n", p);
    printf("%p\n", &i);
    printf("%d\n", i);
    printf("%d\n", *p);


    return 0;
}