
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    4. Refaça as funções de busca sequencial e busca binária vistas em aula assumindo que o vetor possui
    chaves que podem aparecer repetidas. Neste caso, você deve retornar em um outro vetor todas as
    posições onde a chave foi encontrada.
    Protótipo da função: void busca(int vet[], int tam, int chave, int posicoes[], int *n)
    • Você deve devolver em posicoes[] as posições de vet que possuem a chave, e devolver em *n o
    número de ocorrências da chave.
    – OBS: Na chamada desta função, o vetor posições deve ter espaço suficiente (por exemplo,
    tam) para guardar todas as possíveis ocorrências da chave.
*/
void busca(int vet[], int tam, int chave, int posicoes[], int *n) {
    int qtd_key = 0;
    int i_pos = 0;
    for(int i = 0; i < tam; i++) {
        if(vet[i] == chave) posicoes[i_pos++] = i;
    }
    *n = i_pos;
}

void imprime(int pos[], int tam){
    for(int i = 0; i < tam; i++) {
        printf("%d \n", pos[i]);
    }
}

int main(void) {
    int vetor[10] = {1,3,2,4,3,5,2,7,8,9};
    int posicoes[10];
    int qtd_encontrada = 0;
    printf("Buscando chave = %d\n", 1);
    busca(vetor, 10, 1, posicoes, &qtd_encontrada);
    imprime(posicoes, qtd_encontrada);
    printf("Buscando chave = %d\n", 3);
    busca(vetor, 10, 3, posicoes, &qtd_encontrada);
    imprime(posicoes, qtd_encontrada);
    printf("Buscando chave = %d\n", 9);
    busca(vetor, 10, 9, posicoes, &qtd_encontrada);
    imprime(posicoes, qtd_encontrada);
    printf("Buscando chave = %d\n", 7);
    busca(vetor, 10, 7, posicoes, &qtd_encontrada);
    imprime(posicoes, qtd_encontrada);
    printf("Buscando chave = %d\n", 0);
    busca(vetor, 10, 0, posicoes, &qtd_encontrada);
    imprime(posicoes, qtd_encontrada);
    return 0;
}