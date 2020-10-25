
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
    7. Escreva uma função chamada teste que recebe um valor n passado por valor e dois inteiros b e k
    passados por “referência". Sua função deve retornar em b e k valores tal que b^k = n e b seja o menor
    possível.
*/

void teste(int valor, int *b, int *k) {
    int base = 1;
    int potencia = 1;
    int resultado = 0;

    if(valor >=0 && valor<= 3) {
        *b = valor;
        *k = potencia;
    } else {
        for(base = 2; base <= valor; base++){
            for(potencia = 1; potencia <= valor; potencia++){
                resultado = pow(base, potencia);
                if(resultado == valor){
                    *b = base;
                    *k = potencia;
                    return;
                } else if(resultado > valor ){
                    potencia = 1;
                    break;
                }
            }
        }
    }
}

int main(void) {
    int n, b, k;
    n = b = k = 0;
    printf("Digite o valor de N: ");
    scanf("%d", &n);
    teste(n, &b, &k);
    printf("n = %d, b = %d, k = %d \n", n, b, k);
    return 0;
}