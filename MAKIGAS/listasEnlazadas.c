#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IVA 0.19

typedef struct Producto{
    int codigo;
    char descripcion[20];
    float precioUnitario;
    struct Producto* next;  //siguiente elemento de la lista
} t_producto;

float aplicarIva(float precioBase);
void emitirSaludo(void);
void imprimirProducto(t_producto);
t_producto* leerProducto(void);
char desicionValida(char desicion);
char validarDesicion(char desicion);
void mostrarTicket(int cantidad, t_producto* primer, float* total);
void inputProducto(char* entrada, int lengt, char *msg);
void eliminarTodo(t_producto*);

int main()
{
    t_producto *primer = NULL, *ultimo = NULL, *producto;
    int i, cantidad = 0;
    char desicion;
    float total = 0.0;

    emitirSaludo();

    //-------------------------------AGREGAMOS LOS PRODUCTOS---------------------------//
    while(1){
        do{
            printf("hay %d productos, agregar? [s/n]", cantidad);
            desicion = getchar(); //leemos un caracter
            while(getchar() == EOF);
        }while(!desicionValida(desicion));
        if(!validarDesicion(desicion)){ // si la desicion es negativa se cierra del ciclo
            break;
        }
        producto = leerProducto(); 
        if(primer == NULL){
            primer = producto;
        }
        if(ultimo !=NULL){
            ultimo->next = producto;
        }
        ultimo = producto;
        cantidad++;

    }
    //--------------------------------IMPRIMIMOS EL TICKET-----------------------------//
    mostrarTicket(cantidad, primer, &total);
    eliminarTodo(primer);
    total = 0;

    return 0;
}
/**
 * Genera un saludos
 */
void emitirSaludo(){
    printf("*********************************************\n");
    printf("**         MENSAJE DE SUPERMERCADO         **\n");
    printf("**        Subtitulo de supermercado        **\n");
    printf("*********************************************\n");
}
/**
 * valida que el char obtenido sea un char valido
 * params: desicion - char que se obtuvo
 * return: 0 si no es valido, 1 si es valido
 */
char desicionValida(char desicion){
    char esValido = 0;
    switch(desicion){
        case 's':
        case 'S':
        case 'n':
        case 'N':
            esValido = 1;
            break;
        default:
            esValido = 0;
    }
    return esValido;
}

/**
 * valida que la desicion sea positiva o negativa de acuerdo al char obtenido;
 * param: desicion - char que se obtuvo
 * return 1 si es s o S, 0 si es n o N; 
 */
char validarDesicion(char desicion){
    char esPositiva;
     switch(desicion){
        case 's':
        case 'S':
            esPositiva = 1;
            break;
        case 'n':
        case 'N':
            esPositiva = 0;
            break;
        default:
            esPositiva = 0;
    }
    return esPositiva;
}
/**
 * muestra el ticket en la pantalla
 */
void mostrarTicket(int cantidad, t_producto* primer, float* total){
    printf("\n\n");
    t_producto *producto;
    for(producto = primer; producto != NULL; producto = producto->next){
        imprimirProducto(*producto);
        *total += producto->precioUnitario; //se acumula el total
    }
    printf("Total de productos: %d\n", cantidad);
    printf("Precio total (sin IVA): %.2f\n", *total);
    printf("Precio total (con IVA): %.2f\n", aplicarIva(*total));
    printf("\n\nBuenos Dias\n");
}

float aplicarIva(float precioBase){
    return precioBase * (1.0 + IVA);
}

void imprimirProducto(t_producto producto){
    printf("%10d %-20s %.2f\n", producto.codigo, producto.descripcion, producto.precioUnitario);
}

t_producto* leerProducto(void){
    t_producto *p = malloc(sizeof(t_producto));

    char entrada[80];

    //leer el codigo del producto
    inputProducto(entrada, 10, "codigo: ");
    /*strtol conierte de una cadena de caracteres a un long int
    su primer parametro es la cadena
    su segundo parametro por el momento no nos interesa
    su tercer parametro es la base numerica, como es decimal, entonces sera 10*/
    p->codigo = (int) strtol(entrada, NULL, 10);
    //lectura de la descripcion
    inputProducto(entrada,20, "Descripcion: ");
    strcpy(p->descripcion, entrada);
    //leer el precio del producto 
    inputProducto(entrada, 10, "Precio: ");
    p->precioUnitario = strtof(entrada, NULL);

    p->next = NULL;
    return p;
}


void inputProducto(char* entrada, int lengt, char *msg){
    printf("%s", msg);
    // lee el dato
    fgets(entrada, lengt, stdin);

    if(entrada[strlen(entrada) - 1] == '\n'){
        entrada[strlen(entrada) - 1] = '\0'; 
    }
}

void eliminarTodo(t_producto* primer){
   t_producto *actual= primer, *next;

    while(actual != NULL){
        next = actual->next;
        actual->next = NULL;
        free(actual);
        actual = next;
    }
}