#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#define TAM 100

/*
    Q8) Escreva uma função que dadas duas strings, retorne UM se a primeira
    contém a segunda, ignorando maiúsculas e minúsculas, e ZERO, caso 
    contrário. O protótipo da função é o seguinte:
    int cic (char *str1, char *str2).
*/

int cic (char *str1, char *str2);
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
    __fpurge(stdin);
    printf("Por favor digite a segunda string: ");
    scanf("%100[^\n]", string2);

    resultado = cic(string1, string2);
    printf("resultado = %d\n", resultado);

    free(string1);
    free(string2);
    
    return 0;
}

int cic (char *str1, char *str2) {
    int achei = 0;
    if(strlen(str1) < strlen(str2)) return 0;
    if(strlen(str1) == strlen(str2)) {
        if(strcasecmp(str2, str1) == 0) {
            return 1;
        } else {
            return 0;
        }
    }

    char *substring = (char *) malloc (strlen(str2) * sizeof (char));
    int iteracoes = strlen(str1) - strlen(str2) + 1;
    for(int i = 0; i <= iteracoes + 1; i++) {
        strncpy(substring, str1++, strlen(str2));
        if(strcasecmp(substring,str2) == 0) {
            achei = 1;
            break;
        }
    }

    free(substring);
    return achei;
}

void inicializa(char *str, int tamanho) {
    for(int i=0; i < tamanho; i++) {
        str[i] = '\0';
    }
}