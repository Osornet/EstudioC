#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "UnpackPromo.h"

/**
 * 
 * 
 */
MenuPromocion unpackPromo(char* camp61, char* camp63){

    MenuPromocion menu;

    //variables auxiliares de los campos
    char *bufferf61;
    char *bufferf63;
    int i = 0;
    int j = 0;

    bufferf61 = malloc(sizeof(char) * strlen(camp61));
    bufferf63 = malloc(sizeof(char) * strlen(camp63));

    strcpy(bufferf61, camp61);
    strcpy(bufferf63, camp63);

    
    //punteros del strtok
    char *p, *p2, *p3;

    //tokens
    char *itemTok, *camposTok, *infoCampoTok;
    
    int cantItems = cantTokens(bufferf61, '@') - 1;
    
    menu.cantItems = cantItems;
    menu.items = malloc(sizeof(ItemMenu) * cantItems);

    itemTok = strtok_r(bufferf63, "@", &p);
    while(itemTok != NULL){
            int cantCampos = cantTokens(itemTok, '\\');
            menu.items[i].cantCampos = cantCampos;
            menu.items[i].campos = malloc(sizeof(Campo) * cantCampos);

            camposTok = strtok_r(itemTok, "\\", &p2);
            j = 0;
            while(camposTok != NULL){
                
                infoCampoTok = strtok_r(camposTok, "\\|", &p3);
                if(j == 0){
                    if(infoCampoTok != NULL){
                        menu.items[i].codItem = atoi(infoCampoTok);   
                    }
                    infoCampoTok = strtok_r(NULL, "\\|", &p3);
                    if(infoCampoTok != NULL){
                        strcpy(menu.items[i].textoVoucher, infoCampoTok); 
                    }
                    infoCampoTok = strtok_r(NULL, "\\|", &p3);
                }
                if(infoCampoTok != NULL){
                    strcpy(menu.items[i].campos[j].nombreCampo, infoCampoTok); 
                }
                infoCampoTok = strtok_r(NULL, "\\|", &p3);
                if(infoCampoTok != NULL){
                    menu.items[i].campos[j].tipoCampo = infoCampoTok;
                }
                j++;
                camposTok = strtok_r(NULL, "\\", &p2);
            }
        
        i++;
        itemTok = strtok_r(NULL, "@", &p);
    }


    
    
    free(bufferf61);
    free(bufferf63);

    return menu;
    
}

/**
 * 
 */
int cantTokens(char *str, char c){
    int cant = 0;

    if(strlen(str) == 0){
        return 0;
    }

    for(int i = 0; i < strlen(str); i++){
        if(str[i] == c){
            cant++;
        }
    }

    return cant + 1;
}

