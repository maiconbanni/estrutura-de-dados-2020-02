
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    1.  Suponha que criamos uma estrutura para armazenar produtos de um supermercado:
    struct Produto{
        char nome[80];
        double preco;
        int quantidade;
    };
    Implemente duas funções, uma que devolve o vetor ordenado por preços
    e outra que devolve o vetor ordenado pela quantidade de itens no estoque.
    Funções void ordenaPreco(struct Produto vet[], int n)
    e 
    void ordenaQuant(struct Produto vet[], int n).
 */
typedef struct Produto {
    char nome[80];
    double preco;
    int quantidade;
} Produto;

int compara_preco(const void *x, const void *y){
    Produto *px = (Produto *) x, *py = (Produto *) y;
    if(px->preco > py->preco) return 1;
    if(px->preco < py->preco) return -1;
    return 0;
}

int compara_quantidade(const void *x, const void *y){
    Produto *px = (Produto *) x, *py = (Produto *) y;
    if(px->quantidade > py->quantidade) return 1;
    if(px->quantidade < py->quantidade) return -1;
    return 0;
}

void adicionar(Produto *produto, int index, char *nome, double preco, int quantidade) {
    memset(produto[index].nome, '\0', 80);
    produto[index].preco = preco;
    produto[index].quantidade = quantidade;
    strcpy(produto[index].nome, nome);
}

void ordena_preco(Produto vet[], int n) {
    qsort(vet, n, sizeof(Produto), compara_preco);
}

void ordena_quantidade(Produto vet[], int n) {
    qsort(vet, n, sizeof(Produto), compara_quantidade);
}

int main(void) {
    Produto *produtos = (Produto *) malloc(sizeof(Produto) * 5);
    adicionar(produtos, 0, "Banana"   , 5, 101);
    adicionar(produtos, 1, "Maça"     , 4, 102);
    adicionar(produtos, 2, "Laranja"  , 3, 103);
    adicionar(produtos, 3, "Limão"    , 2, 104);
    adicionar(produtos, 4, "Melancia" , 1, 105);
    ordena_preco(produtos, 5);
    printf("Ordenação por preço\n");
    for(int i = 0; i < 5; i++) printf("%d. Produto Nome[%s], preco[%lf], quantidade[%d]\n", i, produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
    ordena_quantidade(produtos, 5);
    printf("Ordenação por quantidade\n");
    for(int i = 0; i < 5; i++) printf("%d. Produto Nome[%s], preco[%lf], quantidade[%d]\n", i, produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
    free(produtos);
    return 0;
}