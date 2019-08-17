#include <stdio.h>
#include <string.h>
#include "UnpackPromo.h"


int main(){

    char field61[] = "PROMOCIONES@01|Pag7@02|BMSC@03|BNB";
    char field63[] = "01|Pag7|Numero de Cupon|A\\Monto|N@02|BMS|Campo1|A\\Campo2|A\\Campo3|N@03|BNB|Campo1|A\\Campo2|A\\Campo3|N\\Campo4|N";

    MenuPromocion menu = unpackPromo(field61, field63);

    

    //printf("titulo Promocion: %s", menu.titulo);
    return 0;
}