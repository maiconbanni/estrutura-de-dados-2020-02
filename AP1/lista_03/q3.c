
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    2.  Suponha que criamos uma estrutura para armazenar dados de pessoas e 
    um vetor para armazenardados de várias pessoas:
    struct Pessoa{
        int rg;
        int cpf;
        char nome[80];
    }
    struct Pessoa cadastro[100];
    Suponha que o vetor esteja ordenado em ordem crescente por valor de RG.
    Implemente uma funçãode busca por RG, que opera como a busca binária,
    e que caso exista uma pessoa no cadastro com o RG a ser buscado, devolve o índice
    deste cadastro e caso não exista o RG a ser buscado, devolve -1.
 */

typedef struct Pessoa{
    int rg;
    int cpf;
    char nome[80];
} Pessoa;

int busca_binaria(Pessoa pessoa[], int inicio, int fim, int valor) {
    int indice;
    if (inicio > fim){
        return -1;
    } else {
        indice = (inicio + fim)/2;
        if (pessoa[indice].rg == valor)
            return indice;
        else if (valor < pessoa[indice].rg)
        return busca_binaria(pessoa, inicio, indice - 1, valor);
    else
        return busca_binaria(pessoa, indice + 1 , fim, valor);
    }
}

void adicionar(Pessoa *Pessoa, int index, char *nome, int rg, int cpf) {
    memset(Pessoa[index].nome, '\0', 80);
    Pessoa[index].rg = rg;
    Pessoa[index].cpf = cpf;
    strcpy(Pessoa[index].nome, nome);
}

int main(void) {
    Pessoa *pessoas = (Pessoa *) malloc(sizeof(Pessoa) * 5);
    adicionar(pessoas, 0, "Maicon Banni", 1001, 1101);
    adicionar(pessoas, 1, "Thais Banni" , 1002, 1102);
    adicionar(pessoas, 2, "Ana Banni"   , 1003, 1103);
    adicionar(pessoas, 3, "Jorge Banni" , 1004, 1104);
    adicionar(pessoas, 4, "Alan Banni"  , 1005, 1105);
    printf("Lista Original\n");
    for(int i = 0; i < 5; i++) printf("%d. Pessoa Nome[%s], RG [%d], CPF [%d]\n", i, pessoas[i].nome, pessoas[i].rg, pessoas[i].cpf);
    int resultado;
    printf("Resultado [%d] para Busca do RG 1001\n", busca_binaria(pessoas, 0, 4, 1001));
    printf("Resultado [%d] para Busca do RG 1002\n", busca_binaria(pessoas, 0, 4, 1002));    
    printf("Resultado [%d] para Busca do RG 1003\n", busca_binaria(pessoas, 0, 4, 1003));
    printf("Resultado [%d] para Busca do RG 1004\n", busca_binaria(pessoas, 0, 4, 1004));    
    printf("Resultado [%d] para Busca do RG 1005\n", busca_binaria(pessoas, 0, 4, 1005));
    printf("Resultado [%d] para Busca do RG 1006\n", busca_binaria(pessoas, 0, 4, 1006));    
    free(pessoas);
    return 0;
}