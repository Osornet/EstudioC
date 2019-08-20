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
    char *p, *p2, *p3, *p4;

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
            
                if(j == 0){         //si es el primer campo
                    if(infoCampoTok != NULL){   //codigo de item
                        menu.items[i].codItem = atoi(infoCampoTok);   
                    }
                    infoCampoTok = strtok_r(NULL, "\\|", &p3);
                    if(infoCampoTok != NULL){   //textoVoucher
                        strcpy(menu.items[i].textoVoucher, infoCampoTok); 
                    }
                    infoCampoTok = strtok_r(NULL, "\\|", &p3);
                }
                if(infoCampoTok != NULL){     //nombre del label del campo
                    strcpy(menu.items[i].campos[j].nombreCampo, infoCampoTok); 
                }
                infoCampoTok = strtok_r(NULL, "\\|", &p3);
                if(infoCampoTok != NULL){   //nombr del tipo de campo (N o A)
                    menu.items[i].campos[j].tipoCampo = *infoCampoTok;
                }
                j++;
                camposTok = strtok_r(NULL, "\\", &p2);
            }
        
        i++;
        itemTok = strtok_r(NULL, "@", &p);
    }

    itemTok = NULL;

    itemTok = strtok_r(bufferf61, "@", &p);
    if(itemTok != NULL){
        strcpy(menu.titulo, itemTok);       //titulo del menu de proociones
    }
    itemTok = strtok_r(NULL, "@", &p);
    i = 0;
    while(itemTok != NULL){
        camposTok = NULL;
        camposTok = strtok_r(itemTok, "\\|",&p2);
        j = 0;
        while(camposTok != NULL){
            if(j == 1){
                strcpy(menu.items[i].nomItem, camposTok);   //nombre del item
            }
            j++;
            camposTok = strtok_r(NULL, "\\|",&p2);
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
    int cant = 0,i;

    if(strlen(str) == 0){
        return 0;
    }


    for(i = 0; i < strlen(str); i++){
        if(str[i] == c){
            cant++;
        }
    }

    return cant + 1;
}

void printPromociones(MenuPromocion menu){
    int i, j;
    printf("titulo del menu de promociones: %s\n", menu.titulo);
    printf("canidad de items: %i\n\n", menu.cantItems);
    

    for(i = 0; i<menu.cantItems; i++){
        printf("index del item: %i\n",i);
        printItem(menu.items[i]);
        printf("--------------------------------------------------\n");

        
    }
}

void printItem(ItemMenu item){
    int i;
    printf("codigo: %i\n",item.codItem);
        printf("nombre: %s\n",item.nomItem);
        printf("texto del voucher: %s\n",item.textoVoucher);
        printf("cantidad de campos: %i\n", item.cantCampos);
        printf("+++++++++++++++++CAMPOS++++++++++++++++++++\n");
        for(i = 0; i< item.cantCampos; i++){
            printf("index del campo: %i\n", i);
            printCampo(item.campos[i]);
            printf("++++++++++++++++++++++++++++++++++++++++++\n");
        }
}

void printCampo(Campo campo){
    printf("nombre del campo: %s\n", campo.nombreCampo);
    printf("tipo del campo: %c\n", campo.tipoCampo);
}

char** getListStringPromo(MenuPromocion menu){
    char **listaStr = malloc(sizeof(char*) * menu.cantItems);
    int i;
    for(i = 0; i < menu.cantItems; i++){
        listaStr[i] = malloc(sizeof(char) * DEFAULT_SIZE_STR);
        strcpy(listaStr[i],menu.items[i].nomItem);
    }

    return listaStr;
}

ItemMenu getItemByNomItem(char* nomItem, MenuPromocion menu){
    int i;
    ItemMenu item;
    for(i = 0; i < menu.cantItems; i++){
        if(strcmp(nomItem, menu.items[i].nomItem) == 0){
            return menu.items[i];
        }
    }
    //si no lo encuentra se setea la cantidad de campos a 0 
    item.cantCampos = 0;
    return item;
}

