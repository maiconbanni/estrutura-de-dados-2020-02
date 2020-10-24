#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    5. Escreva uma função que converte todas as letras de uma cadeia para maiúsculas.
    O protótipo pode ser
    void converte(char *s);
*/

void converte(char *s){
    for(int i = 0; i < strlen(s); i++) {
        if(s[i] >= 97 && s[i] <= 122) {
            s[i] = s[i] - 32;
        }
    }
}

int main(void) {
    char *string = (char *) malloc (100 * sizeof (char));
    printf("Digite a string: ");
    scanf("%100[^\n]", string);
    converte(string);
    printf("String Convertida para Maiuscula: %s \n", string);
    free(string);
    return 0;
}