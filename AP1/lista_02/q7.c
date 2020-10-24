#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 7. Idem, convertendo as letras da cópia para maiúsculas. */

void converte(char *s){
    for(int i = 0; i < strlen(s); i++) {
        if(s[i] >= 97 && s[i] <= 122) {
            s[i] = s[i] - 32;
        }
    }
}

char * copia_transf_maiusculo(char *s){
    int i;
    char *copia = (char *) malloc (strlen(s) * sizeof (char));
    for(i = 0; i < strlen(s); i++) {
        copia[i] = s[i];
    }
    converte(copia);
    return copia;
}

int main(void) {
    char *string = (char *) malloc (100 * sizeof (char));
    printf("Digite a string: ");
    scanf("%100[^\n]", string);
    char* new = copia_transf_maiusculo(string);
    printf("String Original: %s \n", string);
    printf("String Nova: %s \n", new);
    free(string);
    free(new);
    return 0;
}