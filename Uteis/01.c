#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    Considere a implementação de uma lista encadeada para armazenar
    as notas dos alunos de uma turma dada pelo tipo abaixo:

    struct lista{
        char nome[81];
        int mat;
        float p1, p2, p3;
        struct lista *prox;
    };
    typedef struct lista Lista;

    Considere que a lista está ORDENADA crescentemente por matrícula do aluno (camo mat).
    Implemente uma função que, dados uma lista encadeada e o número de matrícula de um aluno,
    tenha como valor de retorno 1, se o aluno pertence á lista e 0, caso contrário. A Função
    deve OBRIGATORIAMENTE aproveitar a ordenação, para não percorrer toda a lista
    desnecessáriamente. Essa função deve obedecer ao seguinte protótipo:
        int busca(Lista *l, int matric)
*/

struct lista{
    char nome[81];
    int mat;
    float p1, p2, p3;
    struct lista *prox;
};
typedef struct lista Lista;

Lista* insere_no_inicio(Lista *l, int mat, char *nome, float p1, float p2, float p3 ){
  Lista *novo = (Lista *) malloc(sizeof(Lista));
  // Preenchendo o conteúdo do novo nó na lista
  memset(novo->nome, '\0', 81); // zerando a string
  strcpy(novo->nome, nome); // copiando a string para o novo nó da lista
  novo->mat = mat;
  novo->p1 = p1;
  novo->p2 = p2;
  novo->p3 = p3;
  // Incluindo o novo nó no inicio da lista
  novo->prox = l;
  return novo;
}

void imprime(Lista *l){
  Lista *p = l;
  while(p){
    printf("Matricula[%d], Nome[%s], p1 [%f], p2 [%f], p3 [%f] \n", p->mat, p->nome, p->p1, p->p2, p->p3);
    p = p->prox;
  } 
}

int busca(Lista *l, int matric){
  Lista *p = l;
  while(p){
    if(p->mat == matric) return 1;
    p = p->prox;
  }
  return 0; 
}

int main (void) {
    Lista *l = NULL;
    int matricula = 0;
    printf("Digite o numero da matrícula que deseja buscar na Lista: ");
    scanf("%d", &matricula);

    l = insere_no_inicio(l, 6, "Benjamim Banni" , 5.0, 4.0, 3.0);
    l = insere_no_inicio(l, 5, "Jorge Banni"    , 6.0, 5.0, 4.0);
    l = insere_no_inicio(l, 4, "Ana Maria Banni", 7.0, 6.0, 5.0);
    l = insere_no_inicio(l, 3, "Álan Banni"     , 8.0, 7.0, 6.0);
    l = insere_no_inicio(l, 2, "Thais Banni"    , 9.0, 8.0, 7.0);
    l = insere_no_inicio(l, 1, "Maicon Banni"   , 10.0, 9.0, 8.0 );

    printf("############################\n");
    printf("#####  Lista Original  #####\n");
    printf("############################\n");
    imprime(l);

    printf("O Aluno com matricula [%d] foi encontrado? [%s] \n", matricula,  busca(l, matricula) ? "Sim": "Não"); 

    return 0;
}