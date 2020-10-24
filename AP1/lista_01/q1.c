#include <stdio.h>

/*
    Q1) Escreva um programa que, infinitamente, leia um número inteiro n, que representa o tamanho,
    seguida de uma sequência de n números inteiros, e determine o comprimento máximo de um
    segmento crescente destes n números. Exemplos:
        - Na sequência 5 10 3 2 4 7 9 8 5 o comprimento do segmento crescente máximo é 4.
        - Na sequência 10, 8, 7, 5, 2 o comprimento de um segmento crescente máximo é 1.
    Seu programa para quando n for menor ou igual a zero.
*/

int main(void){
    int sair = 0;

    while(!sair) {
        int tamanho;
        scanf("%d", &tamanho);
        if(tamanho <= 0) {
            sair = 1;
        } else if (tamanho == 1) {
            printf("A maior sequencia possui o tamanho igual a [%d]\n", tamanho);
        } else {
            int anterior, atual, maior_sequencia, contador, indice;
            contador = 1, indice = 1, maior_sequencia = 1;
            while(indice <= tamanho) {
                scanf("%d", &atual);
                if(indice == 1 ) {
                    anterior = atual;
                }  else {
                    if(atual > anterior) {
                        ++contador;
                        if(contador > maior_sequencia) {
                            maior_sequencia = contador;
                        }
                    } else {
                        contador = 1;
                    }
                    anterior = atual;
                }
                indice++;
            }
            printf("A maior sequencia possui o tamanho igual a [%d]\n", maior_sequencia);
        }
        if(sair) { break; }
    }
    return 0;
}