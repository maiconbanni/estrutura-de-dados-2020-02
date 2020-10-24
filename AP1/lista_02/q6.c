#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    6. Escreva uma função que recebe como entrada uma cadeia, e devolve como saída
    uma cópia da cadeia. Esta função deve alocar o espaço necessário para a cópia.
    O protótipo pode ser
    char *copia(char *s);
*/


char * copia(char *s){
    char *copia = (char *) malloc (strlen(s) * sizeof (char));
    for(int i = 0; i < strlen(s); i++) copia[i] = s[i];
    return copia;
}

int main(void) {
    char *string = (char *) malloc (100 * sizeof (char));
    printf("Digite a string: ");
    scanf("%100[^\n]", string);
    char* new = copia(string);
    printf("String Original: %s \n", string);
    printf("String Nova: %s \n", string);
    free(string);
    free(new);
    return 0;
}