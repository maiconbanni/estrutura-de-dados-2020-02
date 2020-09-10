#include <stdio.h>
#include <time.h>

/* Funcao que calcula recursivamente a serie de fibonacci */
int fibonacci(int n) {
    if(n <=2 ) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main(void){
    int numero;
    float tempo_recursivo, tempo_linear;
    time_t inicio, fim; 

    
    printf("Digite o numero desejado para saber a sequencia de fibonacci: ");
    scanf("%d", &numero);

    if(numero < 0){
        printf("O numero precisa ser um inteiro positivo!\n");
    }
    
    inicio = time(NULL); // registrando o momento em que o processo iniciou
    printf("fibonacci de [%d] com recursividade igual a [%d]\n", numero, fibonacci(numero));
    fim = time(NULL); // registrando o momento em que o processo encerrou

    printf("Tempo gasto com recurividade [%.2f]\n", difftime(fim, inicio));
    
    inicio = time(NULL); // registrando o momento em que o processo iniciou

    int i, anterior = 1, pos_atual = 1, soma;
    for (i = 3; i <= numero; i = i + 1)
    {
        soma = anterior + pos_atual;
        anterior = pos_atual;
        pos_atual = soma;
    }
    
    printf("fibonacci de [%d] sem recursividade igual a [%d]\n", numero, pos_atual);
    fim = time(NULL); // registrando o momento em que o processo terminou

    printf("Tempo gasto sem recursividade [%.2f]\n", difftime(fim, inicio));

    return 0;
}