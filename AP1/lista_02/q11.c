#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

/*
    11. Escrever uma função que recebe como argumentos uma cadeia s e um caracter c ,
    e que dá como resultado o número de vezes que c aparece em s .
*/

int count_char (char *str, char c);
void inicializa (char *str, int tamanho);

int main (void)
{
    char *string = (char *) malloc (TAM * sizeof (char));
    char c;
    int resultado;

    inicializa(string, TAM);

    printf("Por favor digite a string: ");
    scanf("%100[^\n]", string);
    getchar();
    printf("Por favor digite o caracter: ");
    scanf("%c", &c);

    resultado = count_char(string, c);
    printf("resultado = %d\n", resultado);
    free(string);
    return 0;
}

int count_char (char *str, char c) {
    int quantidade = 0;
    for(int i = 0; i < strlen(str); i++) if(str[i] == c) quantidade++;
    return quantidade;
}

void inicializa(char *str, int tamanho) {
    for(int i=0; i < tamanho; i++) {
        str[i] = '\0';
    }
}