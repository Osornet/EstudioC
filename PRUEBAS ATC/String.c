#include <stdio.h>
#include <string.h>


int main(){

    char cadena[] = "1.2|2.3|3.4";
    char *p = NULL;

    char bufferCad[strlen(cadena)];
    strcpy(bufferCad, cadena);

    printf("%s\n\n", bufferCad);
    char* tok1 = strtok_r(bufferCad, "|", &p);

    while(tok1 != NULL){

        printf("%s\n", tok1);
        char *p2;
        char* tok2 = strtok_r(tok1, ".", &p2);

        while(tok2 != NULL){
             printf("%s\n", tok2);
            tok2 = strtok_r(NULL, ".", &p2);
        }


        tok1 = strtok_r(NULL, "|", &p);
    }

    return 0;
}