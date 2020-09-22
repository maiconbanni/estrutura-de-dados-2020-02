#include <stdio.h>

/*
    Q1) Uma forma simples e eficiente de calcular  todos os números primos até
    um  certo  valor  n  é o método da  Peneira de  Eratosthenes. O processo é 
    simples:  escrevem-se  todos os  valores entre  2  e n (limite máximo). Em 
    seguida, faz-se  um círculo em volta do 2, marcando como primo e riscam-se
    todos os seus  múltiplos. Continua-se  a fazer  círculos em volta do menor 
    inteiro que se   encontra, eliminando todos  os seus múltiplos. Quando não 
    restarem números sem terem círculos à volta ou traços por cima, os números
    com círculos à volta representam todos os  primos até n. A figura seguinte 
    apresenta o método para n = 40.
    Escreva um programa que  implemente a Peneira  de  Eratosthenes. Você deve 
    ler o valor n e mostrar todos os números primos encontrados.
*/

// inicializa vetor com os possiveis valores
void cria_vetor(int *lista, int tamanho) {
    int intervalo = 2;
    for (int i = 0; i <= tamanho; i++) {
        lista[i]=intervalo++;
    }
}

int eh_multiplo(int valor, int base) { return !(valor % base); }

int main(void) {
    int n, tamanho;

    printf("Digite o numero desejado para descobrir todos os numeros primos ate ele: ");
    scanf("%d", &n);
    
    tamanho = n-2;
    int lista_linear[tamanho];
    cria_vetor(lista_linear, tamanho);

    for(int circulo = 0; circulo <= tamanho; circulo++) {
        for(int posicao = circulo + 1; posicao <= tamanho; posicao++) {
            if(lista_linear[circulo] == 0) { continue; }
            if(eh_multiplo(lista_linear[posicao], lista_linear[circulo])) { lista_linear[posicao] = 0; }
        }
    }

    for (int i = 0; i <= tamanho; i++) {
        if(lista_linear[i] != 0) {
            printf("%d ", lista_linear[i]);
        }
    }
    
    printf("\n");
    return 0;
}