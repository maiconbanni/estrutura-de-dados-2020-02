#include <stdio.h>

/*
    Q3) Implemente um programa que, infinitamente, receba, como parâmetro de entrada, um número
    n e um número m, e retorne todas as potências de m, menores que n. Por exemplo, se n = 1000 e
    m = 2, seu programa deve imprimir os seguintes números: 1, 2, 4, 8, 16, 32, 64, 128, 256 e 512.
    Seu programa para quando n for menor que 1 ou quando m for 0, ou 1 ou -1.
*/

int main(void) {
    while(1) {
        int n, m, potencia = 1;
    
        printf("Digite um número N: ");
        scanf("%d", &n);
        printf("Digite um número M: ");
        scanf("%d", &m);
        
        if(n < 1 || m == -1 || m == 0 || m == 1) break;

        printf("Todas as potências de m, menores que n: \n");

        /* Calculo da potencia */
        while (potencia <= n) {
            printf("%d ", potencia);
            potencia *= m;
        }
        printf("\n");
    }
    return 0;

}