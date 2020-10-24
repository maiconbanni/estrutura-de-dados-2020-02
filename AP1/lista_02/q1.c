#include <stdio.h>
#include <stdlib.h>

/*
    1. Escreva um programa em C que lê três números inteiros do teclado, e imprime os
    três números em ordem crescente.
*/

int compare (const void * a, const void * b) {
   return *(int*)a - *(int*)b;
}

int main(void) {
    int numeros[3];
    scanf("%d %d %d", &numeros[0], &numeros[1], &numeros[2]);
    qsort(numeros, 3, sizeof(int), compare);
    for(int i = 0; i < 3; i++) printf("%d ", numeros[i]);
    printf("\n");
    return 0;
}