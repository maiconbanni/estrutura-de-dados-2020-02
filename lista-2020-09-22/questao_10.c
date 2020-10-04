#include <stdio.h>
#include <stdlib.h>

/*
    Q10) Dada uma matriz quadrada de dimensão 9, com valores de 1 a 9 em suas posições, escreva
    um programa que verifique se esta matriz é uma solução válida para o Sudoku (isto é, uma
    solução é válida no Sudoku se cada linha, cada coluna e cada bloco contém os números de 1 a 9
    somente uma vez).
    Matriz Válida         |     Matriz Inválida
    5 3 4 6 7 8 9 1 2     |     5 3 4 6 7 8 9 1 2
    6 7 2 1 9 5 3 4 8     |     6 7 2 1 9 5 3 4 8
    1 9 8 3 4 2 5 6 7     |     1 9 8 3 4 2 5 6 7
    8 5 9 7 6 1 4 2 3     |     8 5 9 7 6 1 4 2 3
    4 2 6 8 5 3 7 9 1     |     4 2 6 8 5 3 7 9 1
    7 1 3 9 2 4 8 5 6     |     7 1 3 9 2 4 8 5 6
    9 6 1 5 3 7 2 8 4     |     9 6 1 5 3 7 2 8 4
    2 8 7 4 1 9 6 3 5     |     2 8 7 4 1 9 6 3 5
    3 4 5 2 8 6 1 7 9     |     3 4 5 2 8 6 1 9 7
*/

int valida_linha(int **vet, int linha);
int valida_couna(int **vet, int coluna);
int valida_quadrante(int **vet, int quadrante);
int valida_sudoku(int **vet);
int compare (const void * a, const void * b);

int main (void) {
    int i, j, lin, col, **sudoku;
    lin = col = 9;
    sudoku = (int **) malloc(sizeof(int *) * lin);

    for(i = 0; i < lin; i++) sudoku[i] = (int *) malloc (sizeof(int) * col);
 
    for(i = 0; i < lin; i++)
        for(j = 0; j < col; j++) scanf("%d", &sudoku[i][j]);

    int resultado = valida_sudoku(sudoku);

    printf("Este Sudoku é Válido? [%s]\n", resultado == 1 ? "Sim" : "Não");
    return 0;
}

int valida_linha(int **sudoku, int linha){
    int linha_sudoku[9];
    for(int l = linha; l <= linha; l++) {
        for(int c = 0; c < 9; c++) {
            if(sudoku[l][c] < 1 || sudoku[l][c] > 9) return 0;
            linha_sudoku[c] = sudoku[l][c];
        }
    }
    qsort(linha_sudoku, 9, sizeof(int), compare);
    for(int i = 0; i < 9; i++) if(linha_sudoku[i] != (i + 1)) return 0;

    return 1;
}

int valida_coluna(int **sudoku, int coluna){
    int coluna_sudoku[9];
    for(int c = coluna; c <= coluna; c++) {
        for(int l = 0; l < 9; l++) { 
            if(sudoku[l][c] < 1 || sudoku[l][c] > 9) return 0;
            coluna_sudoku[l] = sudoku[l][c];
        }
    }
    qsort(coluna_sudoku, 9, sizeof(int), compare);

    for(int i = 0; i < 9; i++) if(coluna_sudoku[i] != (i + 1)) return 0;

    return 1;
}

int valida_quadrante(int **sudoku, int quadrante){
    int quadrante_sudoku[9];
    int linha, coluna, indice;
    linha = coluna = indice = 0;

    switch (quadrante){
        case 1: linha = 0; coluna = 0; break;
        case 2: linha = 0; coluna = 3; break;
        case 3: linha = 0; coluna = 6; break;
        case 4: linha = 3; coluna = 0; break;
        case 5: linha = 3; coluna = 3; break;
        case 6: linha = 3; coluna = 6; break;
        case 7: linha = 6; coluna = 0; break;
        case 8: linha = 6; coluna = 3; break;
        case 9: linha = 6; coluna = 6; break;
        default: return 0;
    }

    for(int l = linha; l <= linha + 2; l++) {
        for(int c = coluna; c <= coluna + 2; c++) {
            quadrante_sudoku[indice] = sudoku[l][c];
            indice++;
        }
    }
    
    qsort(quadrante_sudoku, 9, sizeof(int), compare);

    for(int i = 0; i < 9; i++) if(quadrante_sudoku[i] != (i + 1)) return 0;

    return 1;
}

int valida_sudoku(int **sudoku){
    for(int i = 0; i < 9; i++) {
        if(!valida_linha(sudoku,i)) return 0;
        if(!valida_coluna(sudoku,i)) return 0;
        if(!valida_quadrante(sudoku,i+1)) return 0;
    }
    return 1;
}

int compare (const void * a, const void * b) {
   return *(int*)a - *(int*)b;
}