#include <stdio.h>

/*
    Q3) Um número a é dito permutação de um número b se os dígitos  de a formam
    uma permutação  dos  dígitos de b.  Exemplo:  5412434 é  uma  permutação de 
    4321445, mas não é uma permutação de 4312455. Faça um programa que receba a
    e  b e  responda se a é  permutação de b. Obs.: Considere que  o  dígito  0 
    (zero) não deve aparecer nos números.
*/

void tranforma_numero_em_array(int numero, int *string) {
    int sair = 1, indice = 0;
    int resultado, resto, aux = numero;

    while (sair) {
        resultado = aux / 10;
        resto = aux % 10;
        if(resultado == 0 && resto < 10) {
            sair = 0;
        } else {
            aux = resultado;
        }
        string[indice] = resto;
        indice++;
    }
}

int permutacao (int *v_a, int *v_b) {
    int eh_permutacao = 1;

    for(int i = 0; i < 10; i++) {
        if(v_a[i] < 0 ) {break;}
        for(int j = 0; j < 10; j++) {
            if(v_a[i] == v_b[j]) {
                v_a[i]= v_b[j] = -1; // encontrei correspondencia
                break;
            }
        }
    }

    for(int index = 0; index < 10; index++) {
        if(v_a[index] >= 0 || v_b[index] >=0 ) {
            eh_permutacao = 0;
        }
    }

    return eh_permutacao;
}

int main(void) {
    int a, b, resultado;
    int vetor_a[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int vetor_b[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

    printf("Digite A e B, onde o tamanho máximo é 10: ");
    scanf("%d %d", &a, &b);

    tranforma_numero_em_array(a, vetor_a);
    tranforma_numero_em_array(b, vetor_b);

    resultado = permutacao(vetor_a, vetor_b);

    printf("A é uma permutacao de B ? -> %s\n ", resultado == 0 ? "Não": "Sim");    return 0;
}