#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    char str[] = "a|e@i|o";
    char strAux[strlen(str)];
    strcpy(strAux, str); 
    printf("%s\n\n",strAux);

    char *p = NULL;

    char *tok1 = strtok_r(strAux, "@",&p);
   
    while(tok1 != NULL){

        char strAux2[strlen(tok1)];
        strcpy(strAux2, tok1);

        printf("%s\n",strAux2);

        char *auxp;

        char *tok2 = strtok_r(strAux2, "\\|", &auxp);

        while(tok2 != NULL){
            printf("%s\n",tok2);
            tok2 = strtok_r(NULL, "\\|", &auxp);
        }
    

        tok1 = strtok_r(NULL, "@", &p);
        
    }

    return 0;
}