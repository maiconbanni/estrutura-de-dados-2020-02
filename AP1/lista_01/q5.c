#include <stdio.h>
/*
    Q5) Implemente um programa  que, i nfinitamente, receba, como parâmetro de
    entrada, um número n e retorne a representação  binária de n. Por exemplo,
    se n é igual a 12, a resposta deste programa deve ser “1100”. Seu programa
    para quando n for menor que zero.
*/

void tranforma_decimal_em_binario(int numero, int *string) {
    int sair = 1, indice = 0;
    int resultado, resto, aux = numero;

    while (sair) {
        resultado = aux / 2;
        resto = aux % 2;
        if(resultado == 0 && resto < 2) {
            sair = 0;
        } else {
            aux = resultado;
        }
        string[indice] = resto;
        indice++;
    }
}

void inicializa(int *vetor, int tamanho) {
    for(int i=0; i < tamanho; i++) {
        vetor[i] = -1;
    }
}

void imprime_binario (int *numero, int tamanho) {
    for(int i = tamanho -1; i >= 0; i--) {
        if(numero[i] >= 0) {
            printf("%d", numero[i]);
        }
    }
    printf("\n");
}

int main(void) {
    int tamanho = 256;
    while(1) {
        int entrada, resultado;
        int *vetor;

        inicializa(vetor, tamanho);

        printf("Digite um numero inteiro em decimal e veja sua representação binária: ");
        scanf("%d", &entrada);

        if(entrada < 0) { break; }

        tranforma_decimal_em_binario(entrada, vetor);
        imprime_binario(vetor, tamanho);
    }    
    return 0;
}
