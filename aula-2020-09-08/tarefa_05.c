#include <stdio.h>
int main(void){
    int numero, divisor = 1, contador = 1, resto;
    
    printf("Digite o numero desejado para descobrir todos os divisores dele: ");
    scanf("%d", &numero);

    printf("-------------------------- \n");    
    printf("--- Lista de Divisores --- \n");
    printf("-------------------------- \n");    
    while (numero >= divisor ) {
        resto = numero % divisor;
        if( resto == 0) {
            printf("%d. divisor igual a [%d]\n", contador, divisor);
            contador++;
        }
        divisor++;
    }

    return 0;
}