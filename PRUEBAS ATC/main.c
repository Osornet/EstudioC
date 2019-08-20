#include <stdio.h>
#include <string.h>
#include "UnpackPromo.h"


int main(){
    int i,j;
    char field61[] = "PROMOCIONES@01|Pag7@02|BMSC@03|BNB";
    char field63[] = "01|Pag7|Numero de Cupon|A\\Monto|N@02|BMS|Campo1|A\\Campo2|A\\Campo3|N@03|BNB|Campo1|A\\Campo2|A\\Campo3|N\\Campo4|N";

    MenuPromocion menu = unpackPromo(field61, field63);
    //printPromociones(menu);
    //printItem(menu.items[2]);
    //printCampo(menu.items[0].campos[0]);
    char **listString = getListStringPromo(menu);
    /* for(i = 0; i < menu.cantItems; i++){
        printf("item[%i]: %s\n", i, listString[i]);
    } */
    ItemMenu item = getItemByNomItem(listString[2], menu);

    if(item.cantCampos != 0){
        printItem(item);
    }
    return 0;
}