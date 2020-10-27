#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void to_array(int numero, int *string) {
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

int teste (int n){
    int numero[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int saida[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int tamanho = 0;
    to_array(n, numero); // converte o numero de traz pra frente
    for(int i = 0; i < 10; i++) {
        if(numero[i] >= 0) tamanho++;
    }
    int primeiros_dig = numero[tamanho -1] * 10 + numero[tamanho -2];  // calcula o inteiro com os 2 primeiros digitos 
    int ultimos_dig = numero[0] + numero[1] * 10;  // calcula o inteiro com os 2 ultimos digitos

    int resultado = (primeiros_dig + ultimos_dig) * (primeiros_dig + ultimos_dig);  // calcula a potencia de 2
    to_array(resultado, saida);  // converte o numero de traz pra frente
    
    if( numero[0] == saida[0] &&
        numero[1] == saida[1] &&
        numero[tamanho -2] == saida[2] &&
        numero[tamanho -1] == saida[3]
    ) {
        return 1;
    }
    return 0;
}

int main(void){
  while(1){
    int n;
    scanf("%d", &n);
    if(n < 0) return 0;
    printf("%d\n", teste(n));
  }
}