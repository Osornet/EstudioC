#include <stdio.h>

struct fecha{
    int dia, mes, anno;
};    

struct fecha getFecha(char dia, char mes, int anno);
int printFecha(struct fecha f);


int main(int argc, char** argv){

    struct fecha f;
    f = getFecha(26, 7,2019);
    int resp = printFecha(f);
    
    return 0;
}
struct fecha getFecha(char dia, char mes, int anno){
    //struct fecha f = { dia, mes, anno }; //incializacion inline

    struct fecha f;
   /*  f.dia = dia;
    f.mes = mes;
    f.anno = anno; */

    f = (struct fecha) { dia, mes, anno };
    
    return f;
}
int printFecha(struct fecha f){
    printf("%d/%d/%d", f.dia, f.mes, f.anno);
    return 0;
}


