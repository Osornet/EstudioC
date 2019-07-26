#include <stdio.h>

struct fecha {
    int dia, mes, anno;
};

struct fecha getFecha(int dia, int mes, int anno);
void printFecha(struct fecha*);
void incrementarFecha(struct fecha*);

int main(){
    struct fecha f;
    f = getFecha(26,07,2019);
    printFecha(&f);
    incrementarFecha(&f);
    printFecha(&f);
    return 0;
}

struct fecha getFecha(int dia, int mes, int anno){
    return (struct fecha) {dia, mes, anno};
}

void printFecha(struct fecha* f){
    printf("%d/%d/%d\n", f->dia, f->mes, f->anno);
}

void incrementarFecha(struct fecha* f){
    f->dia++;
    if(f->dia > 30){
        f->dia = 1;
        f->mes++;
        if(f->mes > 12){
            f->mes = 1;
            f->anno++;
        }
    }
}
