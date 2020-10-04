#include <stdio.h>
#include <stdlib.h>

/*
    Q10) Dada uma matriz quadrada de dimensão 9, com valores de 1 a 9 em suas posições, escreva
    um programa que verifique se esta matriz é uma solução válida para o Sudoku (isto é, uma
    solução é válida no Sudoku se cada linha, cada coluna e cada bloco contém os números de 1 a 9
    somente uma vez).
        5 3 4 6 7 8 9 1 2
        6 7 2 1 9 5 3 4 8
        1 9 8 3 4 2 5 6 7
        8 5 9 7 6 1 4 2 3
        4 2 6 8 5 3 7 9 1
        7 1 3 9 2 4 8 5 6
        9 6 1 5 3 7 2 8 4
        2 8 7 4 1 9 6 3 5
        3 4 5 2 8 6 1 7 9
*/

int main (void) {
    int i, j, lin, col, **mat;
    lin = col = 9;
    mat = (int **) malloc(sizeof(int *) * lin);

    int auxiliar = 0;

    for(i = 0; i < lin; i++) mat[i] = (int *) malloc (sizeof(int) * col);
 
    for(i = 0; i < lin; i++)
        for(j = 0; j < col; j++) scanf("%d", &mat[i][j]);

    for(int guia = 0; guia < lin; guia++) {
        for(j = 0; j < col; j++) {
            auxiliar = mat[i][j];
        }
    }
    return 0;
}
