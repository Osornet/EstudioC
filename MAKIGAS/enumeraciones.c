#include <stdio.h>
enum DIASSEM {
    LUNES,
    MARTES,
    MIERCOLES,
    JUEVES,
    VIERNES,
    SABADO,
    DOMINGO
};

struct fecha{
    int dia, mes, anno;
    enum DIASSEM diasem;
};


int main(){
    struct fecha f;
    f.dia = 26;
    f.mes = 7;
    f.anno = 2019;

    f.diasem = MARTES;

    printf("%d/%d/%d\n", f.dia, f.mes, f.anno);

    switch(f.diasem){
        case LUNES: 
            printf("lunes\n");
            break;
        case MARTES: 
            printf("martes\n");
            break;
        case MIERCOLES: 
            printf("miercoles\n");
            break;
        case JUEVES: 
            printf("jueves\n");
            break;
        case VIERNES: 
            printf("viernes\n");
            break;
        case SABADO: 
            printf("sabado\n");
            break;
        case DOMINGO: 
            printf("domingo\n");
            break;
        default:
            printf("dia no encontrado\n");
    }
   

    return 0;
}