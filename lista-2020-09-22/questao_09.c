#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#define TAM 100

/*
    Q9) Escreva uma função que dadas duas strings, retorne UM se as strings são
    iguais, ignorando maiúsculas e minúsculas, e ZERO, caso contrário.
    O protótipo da função é o seguinte: int igual (char *str1, char *str2).
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
    __fpurge(stdin);
    printf("Por favor digite a segunda string: ");
    scanf("%100[^\n]", string2);

    resultado = igual(string1, string2);
    printf("resultado = %d\n", resultado);
}

int igual (char *str1, char *str2) {
    int alguem_diferente = 0;
    if(strlen(str1) == strlen(str2)){
        for(int i = 0; i < strlen(str1); i++) {
            str1[i] = str1[i] >= 65 && str1[i] <= 90 ? str1[i] + 32 : str1[i]; 
            str2[i] = str2[i] >= 65 && str2[i] <= 90 ? str2[i] + 32 : str2[i];
            if(str1[i] != str2[i]) {
                alguem_diferente = 1;
                break;
            }
        }
    }
    return alguem_diferente == 0 ? 1 : 0;
}

void inicializa(char *str, int tamanho) {
    for(int i=0; i < tamanho; i++) {
        str[i] = '\0';
    }
}