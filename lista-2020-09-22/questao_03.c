
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Q3) Considere que você receba um vetor de inteiros  com  números  ímpares e  
    pares e um número n, sendo n o tamanho do vetor. Implemente uma  função que
    separe os valores inteiros de um  vetor  em ímpares  e pares,  obedecendo a 
    ordem de  entrada  destes  números  no vetor. Implemente os dois protótipos 
    abaixo:
        a) int* transf_i_p (int *vet, int n)
        b) void transf_i_p (int *vet, int n)
*/

int* a_transf_i_p (int *vet, int n);
void b_transf_i_p (int *vet, int n);
void imprime(int *vet, int n);

int main (void) {
    int n;
    printf("Digite o numero de elementos no vetor: ");
    scanf("%d", &n);

    int *lista_original = (int *) malloc (n * sizeof (int));
    int *a;
    
    for(int i = 0; i < n; i++ ){
        scanf("%d", &lista_original[i]);
    }

    a = a_transf_i_p(lista_original, n);
    b_transf_i_p(lista_original, n);
    
    imprime(a, n);
    imprime(lista_original, n);

    free(lista_original);
    
    return 0;
}

int* a_transf_i_p (int *vet, int n) {
    int *valores = (int *) malloc (n * sizeof (int));
    int *pares = (int *) malloc (n * sizeof (int));
    int *impares = (int *) malloc (n * sizeof (int));
    int qtd_par, qtd_impar;
    int par_ou_impar;
    
    qtd_par = qtd_impar = 0;
    par_ou_impar = vet[0] % 2;

    for(int i = 0; i < n; i++ ){
        if(vet[i] % 2 == 0) {
            pares[qtd_par] = vet[i];
            qtd_par++;
        } else {
            impares[qtd_impar] = vet[i];
            qtd_impar++;
        }
    }

    if(par_ou_impar == 0){
        for(int indice = 0; indice < qtd_par; indice++) {
            valores[indice] = pares[indice];
        }

        for(int indice = 0; indice < qtd_impar; indice++) {
            valores[qtd_par + indice] = impares[indice];
        }
    } else {
        for(int indice = 0; indice < qtd_impar; indice++) {
            valores[indice] = impares[indice];
        }

        for(int indice = 0; indice < qtd_par; indice++) {
            valores[qtd_impar + indice] = pares[indice];
        }
    }

    free(pares);
    free(impares);
    
    return valores;
}

void b_transf_i_p (int *vet, int n) {
    int *pares = (int *) malloc (n * sizeof (int));
    int *impares = (int *) malloc (n * sizeof (int));
    int qtd_par, qtd_impar;
    int par_ou_impar;
    
    qtd_par = qtd_impar = 0;
    par_ou_impar = vet[0] % 2;

    for(int i = 0; i < n; i++ ){
        if(vet[i] % 2 == 0) {
            pares[qtd_par] = vet[i];
            qtd_par++;
        } else {
            impares[qtd_impar] = vet[i];
            qtd_impar++;
        }
    }

    if(par_ou_impar == 0){
        for(int indice = 0; indice < qtd_par; indice++) {
            vet[indice] = pares[indice];
        }

        for(int indice = 0; indice < qtd_impar; indice++) {
            vet[qtd_par + indice] = impares[indice];
        }
    } else {
        for(int indice = 0; indice < qtd_impar; indice++) {
            vet[indice] = impares[indice];
        }

        for(int indice = 0; indice < qtd_par; indice++) {
            vet[qtd_impar + indice] = pares[indice];
        }
    }

    free(pares);
    free(impares);
}

void imprime(int *vet, int n){
    for(int i = 0; i < n; i++ ){
        printf("%d ", vet[i]);
    }
    printf("\n");
}