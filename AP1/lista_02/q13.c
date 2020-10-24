
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

/*
    13. Escreva um programa que lê duas cadeias s1 e s2 , e um natural n , e imprime a
    cadeia resultante da inserção de s2 na posição n de s1 . (Inserir s2 na posição 0
    de s1 tem como resultado s2 seguida de s1)
*/

void imprime (char *s1, char *s2, int n);
void inicializa (char *str, int tamanho);

int main (void)
{
    char *s1 = (char *) malloc (TAM * sizeof (char));
    char *s2 = (char *) malloc (TAM * sizeof (char));
    char *s3 = (char *) malloc (TAM * 2 * sizeof (char));;
    int n;

    inicializa(s1, TAM);
    inicializa(s2, TAM);
    inicializa(s3, TAM);

    printf("Por favor digite a primeira string: ");
    scanf("%100[^\n]", s1);
    getchar();
    printf("Por favor digite a segunda string: ");
    scanf("%100[^\n]", s2);
    getchar();
    printf("Por favor digite o n: ");
    scanf("%d", &n);

    imprime(s1, s2, n);
    free(s1);
    free(s2);
    free(s3);
    return 0;
}

void imprime (char *s1, char *s2, int n) {
    if(n > strlen(s1)) {
        printf("Não existe a posição n na primeira string! \n");
        return;
    }
    int index_s1, index_s2;
    for(index_s1 = 0; index_s1 < n ; index_s1++) printf("%c", s1[index_s1]);
    for(index_s2 = 0; index_s2 < strlen(s2) ; index_s2++) printf("%c", s2[index_s2]);
    for(index_s1; index_s1 < strlen(s1) ; index_s1++) printf("%c", s1[index_s1]);
    printf("\n");
}

void inicializa(char *str, int tamanho) {
    for(int i=0; i < tamanho; i++) {
        str[i] = '\0';
    }
}