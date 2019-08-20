
#ifndef _UNPACK_PROMO_H_

#define _UNPACK_PROMO_H_

#define DEFAULT_SIZE_STR 30

#define DELIMITADOR_1 = "@";
#define DELIMITADOR_2 = "|";
#define DELIMITADOR_3 = "\\";


typedef struct Campo{
    char nombreCampo[DEFAULT_SIZE_STR];
    char tipoCampo;
}Campo;

typedef struct ItemMenu{
    int codItem;
    char nomItem[DEFAULT_SIZE_STR];
    int cantCampos;
    Campo *campos;
    char textoVoucher[DEFAULT_SIZE_STR];
}ItemMenu;


typedef struct MenuPromocion{
    char titulo[DEFAULT_SIZE_STR];
    int cantItems;
    ItemMenu *items;
    char activated[DEFAULT_SIZE_STR];
}MenuPromocion;


MenuPromocion unpackPromo(char* camp61, char* camp63);
int cantTokens(char *str, char c);
void printPromociones(MenuPromocion menu);
void printItem(ItemMenu item);
void printCampo(Campo campo);
char** getListStringPromo(MenuPromocion menu);
ItemMenu getItemByNomItem(char* nomItem, MenuPromocion menu);



#endif //_UNPACK_PROMO_H_