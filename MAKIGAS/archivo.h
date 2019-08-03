

#ifndef _ARCHIVO_H_
#define _ARCHIVO_H_


typedef struct Alumno Alumno;

struct Alumno {
    char nombre[20];
    char apellido[20];
    int telefono;
    float nota;
};


void escribir(void);
void leer(void);

#endif // _ARCHIVO_H_