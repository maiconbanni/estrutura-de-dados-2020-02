#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    Escreva uma função com protótipo
    int contaletra(char *s);
    que calcula o número de letras (maiúsculas e minúsculas) da cadeia s.
*/

int contaletra(char *s){
    int quantidade = 0;
    for(int i = 0; i < strlen(s); i++) {
        if((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122)) {
            quantidade++;
        }
    }
    return quantidade;
}

int main(void) {
    char *string = (char *) malloc (100 * sizeof (char));
    printf("Digite a string: ");
    scanf("%100[^\n]", string);
    printf("Total de Letras: %d \n", contaletra(string));
    free(string);
    return 0;
}

