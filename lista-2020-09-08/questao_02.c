#include <stdio.h>

/*
    Q2) Implemente um programa que, infinitamente, receba, como parâmetro
        de entrada, um número n e retorne os n primeiros números primos 
        existentes depois de n. Por exemplo, se n = 2, a resposta será os
        primos 3 e 5. É necessário salientar que n não precisa ser primo.
        Seu programa para quando n for menor ou igual a zero.
*/

int eh_primo(int num) {
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int numero, contador, auxiliar;
    
    while(1) {
        printf("Digite um numero n e descobra todos os n primos depois dele: ");
        scanf("%d", &numero);

        if(numero <= 0) { break; }
        contador = 0;
        auxiliar = numero;

        while(contador != numero) {
            if(eh_primo(++auxiliar)){
                ++contador;
                printf("%d. Numero primo [%d]\n", contador, auxiliar);
            }
        }
    }
    return 0;
}