#include <stdio.h>
#include <stdlib.h>

/*
    1. Escreva um programa em C que lê três números reais do teclado, e imprime os
    três números em ordem crescente.
*/

void sort(int n, float *vet){
    int i,j;
    float temp;
    for(i=0; i<n; i++){
        int menor=i;
        for(j=i+1; j<n; j++){
            if(vet[j]<vet[menor])
                menor=j;
            if(menor != i){
                temp = vet[i];
                vet[i]=vet[menor];
                vet[menor]=temp;
            }
        }
    }
}

int main(void) {
    float numeros[3];
    scanf("%f %f %f", &numeros[0], &numeros[1], &numeros[2]);
    sort(3, numeros);
    for(int i = 0; i < 3; i++) printf("%f ", numeros[i]);
    printf("\n");
    return 0;
}