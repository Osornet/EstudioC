#include <stdio.h>
#include "archivo.h"

int main(int argc , char** argv){
    
    //escribir();
    leer();
    return 0;
}


void escribir(){

    Alumno a = {"Manuel", "Osorio", 3125632621, 5.0};
    Alumno b = {"Omar", "ape2", 3125632621, 3.8};
    Alumno c = {"Silvia", "ape2", 3125632621, 4.5};

    Alumno alumnos[] = {a, b, c};

    FILE* archivo = fopen("expedientes.bin","w");

    fwrite(alumnos, sizeof(Alumno), 3, archivo);

    fclose(archivo);
}

/* void leer(){
    Alumno alumnos[3];
    FILE* archivo = fopen("expedientes.bin","r");

    //mover el puntero de de tal forma que leamos desde cierta posicion de memoria.
    
    fread(alumnos, sizeof(alumnos), 3, archivo);

    for(int i = 0; i< 3; i++){
        printf("%s\n", alumnos[i].nombre);
    }
    

    fclose(archivo);
} */


void leer(){
    Alumno alumno;

    FILE* archivo = fopen("expedientes.bin", "r");

    /*
        mueve el puntero de lectura del archivo
        primer parametro: puntero a mover
        segundo parametro: cuantos bytes se va a mover en este caso que remo que se mueva el tamaño de la estructura y si queremos que se mueva
        cierta cantidad lo multiplicamos la cantidad de veces que sea necesaria
        tercer parametros es el modo de como vamos a leer:

        SEEK_SET : mueve el puntero al principio del documento y lo mueve la cantidad de bytes colocados en el segundo parametro
        SEEK_CUR : desde el puntero donde se encuentra actualmente mueve la cantidad de bytes colocadoa en el segundo parametro
        SEEK_END : meuve el puntero al final del documento y lo mueve la cantidad de bytes colocados en el segundo parametro. ( deberos usar numeos negativos)

     */
    //posicion a moverse
    int pos = 2;

    //fseek(archivo, sizeof(Alumno) * pos, SEEK_SET);

    //tiene la equivalencia de mover el cursor del lectura al comienzo, es decir, es colo colocar fseek(archivo, 0, SEEK_SET);
    rewind(archivo);

    fread(&alumno, sizeof(Alumno), 1, archivo);
    printf("%s\nposicion del puntero: %ld", alumno.nombre, ftell(archivo));

    fclose(archivo);


}









