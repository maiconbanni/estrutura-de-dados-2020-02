#include <stdio.h>

/*
    Q4)   Implemente um  programa que, infinitamente, teste se um número é um 
    palíndromo  (Dica:  se  uma  palavra pode ser  lida, indiferentemente, da 
    esquerda para a direita e vice-versa,  ela é  considerada um palíndromo).
    Você deve passar o número a ser testado. O seu programa  deverá  imprimir
    as seguintes mensagens “VERDADEIRO” (caso o número seja um palíndromo) ou
    “FALSO” (caso o número  não seja  um palíndromo) na console. Seu programa 
    para quando o número for negativo.
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

int obtemTamanho(int *vetor_a) {
    for(int index = 0; index < 10; index++) {
        if(vetor_a[index] < 0) { return index; }
    } 
}

int valida_palindromo(int *vetor_a) {
    int eh_palindromo = 1;
    int tamanho_vetor = obtemTamanho(vetor_a);
    int tamanho_inverso = tamanho_vetor -1;

    for(int i = 0; i < tamanho_vetor; i++) {
        if(vetor_a[i] != vetor_a[tamanho_inverso]) { eh_palindromo = 0; }
        tamanho_inverso--;
    }
    return eh_palindromo;
}

int main(void) {
    while(1) {
        int a, resultado;
        int vetor_a[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

        printf("Digite um numero para saber se ele é palíndromo: ");
        scanf("%d", &a);

        if(a < 0) { break; }

        tranforma_numero_em_array(a, vetor_a);

        resultado = valida_palindromo(vetor_a);

        printf("O Número [%d] é um palíndromo? -> %s\n ", a, resultado == 0 ? "FALSO": "VERDADEIRO"); 
    }    
    return 0;
}
