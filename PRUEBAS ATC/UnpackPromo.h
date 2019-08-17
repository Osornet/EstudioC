
#ifndef _UNPACK_PROMO_H_

#define _UNPACK_PROMO_H_

#define CANT_ITEMS 50

#define DELIMITADOR_1 = "@";
#define DELIMITADOR_2 = "|";
#define DELIMITADOR_3 = "\\";


typedef struct Campo{
    char nombreCampo[30];
    char tipoCampo;
}Campo;

typedef struct ItemMenu{
    int codItem;
    char nomItem[30];
    int cantCampos;
    Campo *campos;
    char textoVoucher[30];
}ItemMenu;


typedef struct MenuPromocion{
    char titulo[30];
    int cantItems;
    ItemMenu *items;
    char activated[30];
}MenuPromocion;


MenuPromocion unpackPromo(char* camp61, char* camp63);
int cantTokens(char *str, char c);




#endif //_UNPACK_PROMO_H_