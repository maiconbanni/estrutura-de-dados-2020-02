#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

/*
    10. Escreva uma função
    int igual(char *s1, char *s2);
    para descobrir se as cadeias s1 e s2 são iguais.
    Sugestão: comece descobrindo porque a solução abaixo não é aceitável.

    int igual(char *s1, char *s2) {
        return s1==s2;
    }
*/

int igual (char *str1, char *str2);
void inicializa (char *str, int tamanho);

int main (void)
{
    char *string1 = (char *) malloc (TAM * sizeof (char));
    char *string2 = (char *) malloc (TAM * sizeof (char));
    int resultado;

    inicializa(string1, TAM);
    inicializa(string2, TAM);

    printf("Por favor digite a primeira string: ");
    scanf("%100[^\n]", string1);
    getchar();
    printf("Por favor digite a segunda string: ");
    scanf("%100[^\n]", string2);

    resultado = igual(string1, string2);
    printf("resultado = %d\n", resultado);
    free(string1);
    free(string2);
    return 0;
}

int igual (char *str1, char *str2) {
    if(strlen(str1) != strlen(str2)) return 0;
    for(int i = 0; i < strlen(str1); i++) if(str1[i] != str2[i]) return 0;
    return 1;
}

void inicializa(char *str, int tamanho) {
    for(int i=0; i < tamanho; i++) {
        str[i] = '\0';
    }
}