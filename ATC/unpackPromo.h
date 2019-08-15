#ifndef _UNPACK_PROMO_H_
#define _UNPACK_PROMO_H_

typedef struct Campo{
    char nombreCampo[30];
    char tipo;
}Campo;
typedef struct ItemMenu{
    int codItem;
    char nomItem[30];
    Campo campos[10];
    char textoVoucher[30];
}ItemMenu;
typedef struct MenuPromocion{
    char titulo[30];
    ItemMenu items[50];
    char activated[30];
}MenuPromocion;


MenuPromocion unPackPromo(char* camp61, char* camp63);



#endif //_UNPACK_PROMO_H_
