#include <stdio.h>
#include <stdlib.h>

/*
    Q11) Considere duas matrizes de inteiros de dimensões m1xn1 e m2xn2, onde
    m1 e n1 representam, respectivamente, o número de  linhas e  o número  de
    colunas da primeira  matriz, e  m2 e n2  representam,  respectivamente, o 
    número de linhas e o número de  colunas da  segunda  matriz. Escreva  uma 
    função que realize a multiplicação destas duas matrizes sem alterar nem a
    primeira e nem a segunda matriz:
        int** mult (int m1, int n1, int **mat1, int m2, int n2, int **mat2)
*/

int ** multiplica_matrizes(int l1, int c1, int ** mat1, int l2, int c2, int ** mat2);
void imprime(int l1, int c2, int **resultado);

int main (void) {
    int i, l1, c1, l2, c2, ** mat1, ** mat2, **resultado;

    printf("Digite as dimensoes da matriz um e dois respectivamente: ");
    scanf("%d%d%d%d", &l1, &c1, &l2, &c2);

    if(c1 != l2 ) printf("Não é possível multiplicar essas duas matrizes!\n");

    mat1 = (int **) malloc(sizeof(int *) * l1);
    for(i = 0; i < l1; i++) mat1[i] = (int *) malloc (sizeof(int) * c1);
 
    mat2 = (int **) malloc(sizeof(int *) * l2);
    for(i = 0; i < l1; i++) mat2[i] = (int *) malloc (sizeof(int) * c2);

    for(int linha = 0; linha < l1; linha ++){
        for(int coluna = 0; coluna < c1; coluna ++) {
            scanf("%d", &mat1[linha][coluna]);
        }
    }

    for(int linha = 0; linha < l2; linha ++){
        for(int coluna = 0; coluna < c2; coluna ++) {
            scanf("%d", &mat2[linha][coluna]);
        }
    }

    resultado = multiplica_matrizes(l1, c1, mat1, l2, c2, mat2);

    imprime(l1, c2, resultado);
    return 0;
}

int ** multiplica_matrizes(int l1, int c1, int** mat1, int l2, int c2, int** mat2) {
    int ** resultado, i;
    int auxiliar = 0;
    resultado = (int **) malloc(sizeof(int *) * l1);
    for(i = 0; i < l1; i++) resultado[i] = (int *) malloc (sizeof(int) * c2);

    for(int linha = 0; linha < l1; linha++) {
        for(int coluna = 0; coluna < c2; coluna++){
            auxiliar=0;
            for(i = 0; i < l1; i++) {
                auxiliar += mat1[linha][i] * mat2[i][coluna];
            }
            resultado[linha][coluna] = auxiliar;
        }
    } 
    return resultado;
}

void imprime(int c1, int l2, int **resultado){
    for(int linha = 0; linha < c1; linha ++){
        for(int coluna = 0; coluna < l2; coluna ++) {
            printf("%d ", resultado[linha][coluna]);
        }
        printf("\n");
    }
}