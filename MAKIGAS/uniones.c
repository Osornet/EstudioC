#include <stdio.h>

union numero{
    int entero;
    float flotante;
};

union conversor{
    int valor;
    struct {
        char byte3, byte2, byte1, byte0;
    }bytes;
};

int main(){
    /* union numero num;
    num.flotante = 5.5;
    num.entero = 12432143214;

    printf("%f\n %d\n", num.flotante, num.entero);
    return 0; */

    union conversor num;
    num.valor = 10;
    printf("%x %x %x %x\n", num.bytes.byte3, num.bytes.byte2, num.bytes.byte1, num.bytes.byte0);
}