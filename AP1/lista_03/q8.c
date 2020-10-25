
#include <stdio.h>
#include <stdlib.h>
/*
    8. Faça uma função chamada primo que recebe como parâmetro um inteiro m e dois outros inteiros p1
    e p2 passados por referência. A função deve retornar em p1 o maior número primo que é menor do
    que m e deve retornar em p2 o menor número primo que é maior do que m.
*/

int eh_primo(int num) {
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void primo(int m, int *p1, int *p2){
    int maior_primo_menor_m = 0;
    int menor_primo_maior_m = 0;
    if(m <= 1){
        printf("Não tem primos antes!\n");
    } else {
        for(int i = 1; i < (m * 2); i++) {
            if(eh_primo(i) && i < m) {
                maior_primo_menor_m = i;
            } if(eh_primo(i) && i > m) {
                menor_primo_maior_m = i;
                break;
            }
        }
        *p1 = maior_primo_menor_m;
        *p2 = menor_primo_maior_m;
    }
}

int main(void) {
    int m, p1, p2;
    m = p1 = p2 = 0;
    printf("Digite o valor de M: ");
    scanf("%d", &m);
    primo(m, &p1, &p2);
    printf("m = %d, p1 = %d, p2 = %d \n", m, p1, p2);
    return 0;
}