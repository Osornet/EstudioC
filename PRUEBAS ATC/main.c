#include <stdio.h>
#include <string.h>
#include "UnpackPromo.h"


int main(){
    int i,j;
    char field61[] = "PROMOCIONES@01|Pag7@02|BMSC@03|BNB";
    char field63[] = "01|Pag7|Numero de Cupon|A\\Monto|N@02|BMS|Campo1|A\\Campo2|A\\Campo3|N@03|BNB|Campo1|A\\Campo2|A\\Campo3|N\\Campo4|N";

    unsigned char Nii_aux[2];
	char Niifin[2+1];  //apuntador de apuntadores
    char NiiOriginal[5] = "0255";

   	//cambio en el nii del TPDU
    compress((unsigned char *)Niifin,(unsigned char *)NiiOriginal, 2);
	sprintf((char *)Nii_aux,"%s%s",(char *)Niifin,(char *)&Niifin[1]);

    printf("NiiOriginal: %s\n", NiiOriginal);
    printf("niifin: %X\n", Niifin);
    printf("Nii_aux: %X\n", Nii_aux);
    

    

    /* char value = 'A';
    unsigned char valueHex = hex_value(value);
    printf("valir hexa de %c es %d", value, valueHex); */
	//CopyNii((char*) Nii_aux);




    return 0;
}