#include <stdio.h>

int add(int a, int b);

int factorial(int n);

int main(){

    int a = 5, b = 4, resultado, num;

    resultado = add(a, b);
    printf("%d + %d = %d", a, b, resultado);
    //num = 5;
    printf("\ndigite numero: ");
    scanf("%d", &num);
    printf("\n%d! = %d", num, factorial(num));

    return 0;
}

int add(int a, int b){
    return a + b;
}

int factorial(int n){
    if(n == 1){
        return 1;
    }
    return n * factorial(n - 1);
}