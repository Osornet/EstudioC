#include <stdio.h>

#define PI 3.14159

int main(int argc , char** argv){
    
    /*
        primer parametro, ruta del archivo
        segundo parametro modo, que indica como se abre el archivo

        modos:
        r: abre el archivo para leerlo, debe existir
        w: escribir un archivo para leerlo, si ya existe el archivo lo borra y lo vuelve a crear
        a: funciona como w, pero en caso de que ya exista el archivo lo que se agrege lo guarda al final
        r+: lectura y escritura, el archivo tiene que existir
        w+: lectura y escritura, sobreescribe el archivo

    */

   char buffer[80];

    FILE* fp = fopen("ejemplo.txt", "r");
    FILE* fp2 = fopen("destino.txt", "w");
    /*
    primer parametro: cadena a guardar el contenido
    segundo parametro: tamaño de caracteres que queremos guardar del archivo a la cadena
    tercer parametro: entrada de origen, puede ser entrada de texto pero en este caso es un archivo.
     */
    //fgets(buffer, 80, fp);

    //fprintf(fp,"\nHola este es el valor de pi: %f", PI);

     int caracter, a = 0;
    /* 
    while((caracter = fgetc(fp))!= EOF){
        if(caracter == 'a'){
            a++;
        }
    }
    printf("se han encontrado %d ases", a);
    printf("\n");
     */

    char caracteres[80];
    //solo lee una linea del archivo, si queremos leer mas de un alinea tenemos que utilizarlo varias veces.
    //fgets(caracteres, 80, fp);


    //leer varias lineas
    /* while(fgets(caracteres, 80, fp) != NULL){
        printf("%s", caracteres);
    }
 */


    /* for (caracter = 0; caracter < 10; caracter++){
        fputc(caracter, fp);
    } */

    while(fgets(caracteres, 80, fp) != NULL){
        fputs(caracteres, fp2);
    }
  


    fclose(fp);
    



    //printf("contenido del archivo: %s\n", buffer);
    
    return 0;
}






