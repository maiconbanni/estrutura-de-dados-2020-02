#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#define TAM 100
/*
    Q12) Escreva uma função que dada uma string composta por substrings
    separadas por “/”, retorne todas as suas substrings da string original.
    Por exemplo, a string /Fla/Flu/Bota/ será decomposta em:
    Fla
    Flu
    Bota
    Esta função não deve modificar a string original. O protótipo da função é
    o seguinte: char** s2ss (char *str). Isto é, a resposta desta função será
    uma matriz de caracteres alocada dinamicamente.
*/

void inicializa (char *str, int tamanho);
char** s2ss(char *str);

int main (void) {
    char *string = (char *) malloc (TAM * sizeof (char));

    inicializa(string, TAM);

    printf("Por favor digite a primeira string: ");
    scanf("%100[^\n]", string);

    char **matriz = s2ss(string);

    int i = 0;
    while ( i >= 0 ) {
        if(matriz[i] != NULL) {
            for(int col = 0; col < strlen(matriz[i]); col++) {
                printf("%c", matriz[i][col]);
            }
            printf("\n");
            i++;
        } else {
            i = -1;
        }
    }
    
    return 0;    
}

char** s2ss(char *str) {
    int linhas = 0, colunas = 0, l = 0, texto_copiado = 0;

    for(int i = 0; i < strlen(str); i++) {
        if(str[i] == '/') linhas++;
    }

    if (str[strlen(str)-1] != '/') linhas++;

    char **mat;
    mat = (char **) malloc(sizeof(char *) * linhas + 1);
    mat[linhas] = NULL;
    
    for(int i = 0; i < strlen(str); i++){
        if(str[i] != '/') {
            colunas++;
        } else {
            mat[l] = (char *) malloc (sizeof(char) * (colunas + 1));
            memset(mat[l], '-', colunas);
            mat[l][colunas] = '\0';
            colunas = 0;
            l++;
        }
    }
    mat[l] = (char *) malloc (sizeof(char) * (colunas + 1));
    memset(mat[l], '-', colunas);
    mat[l][colunas] = '\0';

    for(int i = 0; i < linhas; i++){
        for(int c = 0; c < strlen(mat[i]); c++){
            mat[i][c] = str[texto_copiado];
            texto_copiado++;
        }
        texto_copiado++;
    }
    return mat;
}

void inicializa(char *str, int tamanho) {
    for(int i=0; i < tamanho; i++) {
        str[i] = '\0';
    }
}