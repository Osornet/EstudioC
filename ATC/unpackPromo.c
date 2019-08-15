#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "unpackPromo.h"

MenuPromocion unPackPromo(char* camp61, char* camp63){
    MenuPromocion menuPromo;

    //char camp61[] = "PROMOCIONES@01|Pag7@02|BMSC@03|BNB";
    //char camp63[] = "01|Pag7|Numero de Cupon|A\Monto|N@02|BMSC|Campo1|A\Campo2|A\Campo3|N@03|BNB|Campo1|A\Campo2|A\Campo3|N\Campo4|N";
    
    char buffCamp61[strlen(camp61)],buffCamp63[strlen(camp63)];
    
    char *p, *p2;
    char *promoTok; //token de promocion
    char *promoInfo; //token de campo o de tipo
   
    strcpy(buffCamp61, camp61);
    strcpy(buffCamp63, camp63);
    
    promoTok = strtok_r(buffCamp63, "@", &p);
    int i = 0;
    while (promoTok != NULL){
        
        promoInfo = strtok_r(promoTok, "|", &p2);

        while(promoInfo != NULL){
            promoInfo = strtok_r(NULL, "|", &p2);
        }
        i++;
        promoTok = strtok_r(NULL, "@", &p);
    }

   
    


    return menuPromo;
}