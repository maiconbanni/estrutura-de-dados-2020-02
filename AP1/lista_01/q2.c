#include <stdio.h>

/*
    Q2) Implemente um programa que, infinitamente, receba, como parâmetro de entrada, um número
    n e retorne os n primeiros números primos existentes. Seu programa para quando n for menor ou
    igual a zero.
*/

int main(void) {
    int numero, divisor = 1, resto;
    int flg_n_primo = 1;
    
    printf("Digite o numero desejado para descobrir todos os numeros primos ate ele: ");
    scanf("%d", &numero);
    
    while(1) {
        if(numero <= 0) { break; }

        if(numero > 1) {
            int i, j;
            for (i = 2; i <= numero; i++) {
                for (j = 2; j <= i; j++) {
                    resto = i % j;
                    if( resto == 0 && j != i ) { flg_n_primo = 0; }
                }
                if(flg_n_primo == 1) { printf("Numero Primo [%d]\n", i); }
                flg_n_primo = 1; 
            }
        }
        printf("Digite o numero desejado para descobrir todos os numeros primos ate ele: ");
        scanf("%d", &numero);
    }
    return 0;
}