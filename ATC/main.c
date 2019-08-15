#include <stdio.h>
#include <string.h>
#include "unpackPromo.h"


int main(){
    
    char camp61[] = "PROMOCIONES@01|Pag7@02|BMSC@03|BNB";
    char camp63[] = "01|Pag7|Numero de Cupon|A\\Monto|N@02|BMSC|Campo1|A\\Campo2|A\\Campo3|N@03|BNB|Campo1|A\\Campo2|A\\Campo3|N\\Campo4|N";
    unPackPromo(camp61, camp63);
    return 0;
}