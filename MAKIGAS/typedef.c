#include <stdio.h>

struct fecha
{
    char dia, mes;
    int anno;
};


typedef struct fecha fecha;
typedef char boolean;
#define TRUE 1
#define FALSE 0



int main(){

    boolean ejemplo = FALSE;

    if(ejemplo){
        printf("Se fue al true");
    }else{
        printf("se fue al false");
    }

    fecha f = {26, 07, 2019};
    prinf("%d, %d, %d", f.dia, f.mes, f.anno);
    return 0;
}