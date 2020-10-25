
#include <stdio.h>
#include <stdlib.h>
/*
    9. Faça uma função chamada media que recebe um vetor de double, um inteiro n que indica o tamanho
    do vetor, e um inteiro i passado por referência. A função deve retornar a média dos n elementos no
    vetor e no inteiro i, passado por referência, deve retornar a posição do elemento que tem o valor mais
    próximo da média.
    Cabeçalho: double media(double vet[], int *i);
*/

double media(double vet[], int n, int *i) {
    double media = 0, soma = 0;
    double valor_mais_proximo_da_media = 0, valor = 0, auxiliar = 0;
    int indice;

    for(int p = 0; p < n; p++) soma += vet[p];

    media = soma/n;
    valor_mais_proximo_da_media = media;
    valor = media;
    for(int p = 0; p < n; p++) {
        // considerando a diferença da média com relação a posição sempre de forma positiva para conseguir o resultado esperado
        //printf("p = %d, valor_mais_proximo_da_media = %lf, valor = %lf \n", p, valor_mais_proximo_da_media, valor);
        auxiliar = (media - vet[p]) < 0 ? (media - vet[p]) * -1 : (media - vet[p]);
        if( auxiliar < valor_mais_proximo_da_media){
            valor_mais_proximo_da_media = auxiliar;
            valor = vet[p];
        }
    }

    for(int p = 0; p < n; p++) {
        if(vet[p] == valor){
            *i = p;
            break;
        }
    }

    return media;
}

int main(void) {
    double vetor[10] = {1,3,2,4,5,9,1,6,8,9};
    int tam = 10, indice = -1;
    double m = media(vetor, tam, &indice);
    printf("media = %lf, indice = %d \n", m, indice);
    return 0;
}