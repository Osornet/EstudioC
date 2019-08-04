#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct unidad
{
    char desc[20];
    struct unidad* next;
} Unidad;

typedef struct unidadList{
    Unidad *primer;
    Unidad *ultimo;
    int size;
}UnidadList;

void add(UnidadList *lista, Unidad* unidad);
void delete(UnidadList *lista, int i);
UnidadList getUnidadList(void);
Unidad get(UnidadList, int i);


int main(){
    UnidadList lista = getUnidadList();
    

    Unidad uni;
    
    add(&lista, &(Unidad){"Unidad 1"});
    add(&lista, &(Unidad){"Unidad 2"});
    add(&lista, &(Unidad){"Unidad 3"});
    add(&lista, &(Unidad){"Unidad 4"});

    Unidad *u;
    for(u = lista.primer; u != NULL; u = u->next){
        printf("%s\n", u->desc);
    }

    printf("el size de la lista es: %d\n", lista.size);

    int i = 1;
    printf("le elemento %d de la lista es: %s\n", i, get(lista, i));

    delete(&lista, 1);

    for(u = lista.primer; u != NULL; u = u->next){
        printf("%s\n", u->desc);
    }
    
    printf("el size de la lista es: %d\n", lista.size);

    return 0;
}

UnidadList getUnidadList(){
    UnidadList lista;
    lista.primer = NULL;
    lista.ultimo = NULL;
    lista.size = 0;
    return lista;
}

void add(UnidadList* lista, Unidad* unidad){
    
    unidad->next = NULL;

    if(lista->primer == NULL){
        lista->primer = unidad;
    }
    if(lista->ultimo != NULL){
        lista->ultimo->next = unidad;
    }
    lista->ultimo = unidad;
    //aumentamos el tamamño
    lista->size++;
}

Unidad get(UnidadList lista, int i){
    if(i >= lista.size){
        return;
    }
    Unidad *u = lista.primer;
    
    while(u != NULL){
        if(i == 0){
            return *u;
        }  
        //printf("%s",u->desc);  
        i--;
        u = u->next;
    }
    
    
}

void delete(UnidadList *lista, int i){
     if(i >= lista->size){
        return;
    }
    Unidad *u = lista->primer;
    
    Unidad *aux = NULL;
    int j = 0;
    while(u != NULL){
        if(j == (i-1) ){
            aux = u->next;
            u->next = aux->next;
            aux->next = NULL;
            aux = NULL;
            lista->size--;
            return;
        }  
        //printf("%s",u->desc);  
        j++;
        u = u->next;
    }
   
}


