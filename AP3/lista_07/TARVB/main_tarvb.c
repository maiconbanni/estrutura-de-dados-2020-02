#include "TARVB.h"
#include "limits.h"

TARVB *maior_numero_chaves(TARVB *a){
  if(!a) return NULL;
  TARVB *resp = a, *aux;
  int i = 0;
  while(i <= a->nchaves){
    aux = maior_numero_chaves(a->filho[i]);
    if((aux) && (aux->nchaves > resp->nchaves)) resp = aux;
    i++; 
  }
  return resp;
}

int TARVB_maior(TARVB *a)
{
    if(!a)
        return INT_MIN;
    if(!a->folha)
        return TARVB_maior(a->filho[a->nchaves]); // Numero de filhos é sempre maior que chaves, se tem 1 chave tem 2 filhos.

    return a->chave[a->nchaves - 1];
}

TARVB* TARVB_sucessor_aux(TARVB *a, int ch, TARVB *suc)
{
    if((!a))
        return a;
    int i = 0;
    //Percorre as chaves até chegar no final ou na chave que é maior ou igual a chave buscada
    while((i < a->nchaves) && (ch >= a->chave[i]))
        i++;

    //Nó folha e o i for menor que o número de chaves o sucessor é o próprio nó
    if((a->folha) && (i < a->nchaves))
        return a;

    //Se o nó for folha o
    if((a->folha) && (i == a->nchaves) && (a->chave[i=1] <= ch))
        return suc;

    //Se não for folha
    if((i == a->nchaves) && (a->chave[i-1] <= ch))
        return TARVB_sucessor_aux(a->filho[i], ch, suc);

    return TARVB_sucessor_aux(a->filho[i], ch, a);
}

TARVB* TARVB_sucessor(TARVB *a, int ch)
{
    if((!a) || (ch >= TARVB_maior(a)))
        return NULL;
    return TARVB_sucessor_aux(a, ch, a);
}

int main(int argc, char *argv[]){
  TARVB *arvore = TARVB_Inicializa();
  int t;
  printf("Digite o grau minimo. Se o valor digitado for menor que 2, t sera considerado igual a 2...\n");
  scanf("%d", &t);
  if(t < 2) t = 2;
  int num = 0, from, to;
  while(num != -1){
    printf("Digite um numero para adicionar. 0 para imprimir. -9 para remover e -1 para sair\n");
    scanf("%d", &num);
    if(num == -9){
      scanf("%d", &from);
      arvore = TARVB_Retira(arvore, from, t);
      TARVB_Imprime(arvore);
    }
    else if(num == -1){
      printf("\n");
      TARVB_Imprime(arvore);
      printf("\n");
      TARVB_Imprime(TARVB_sucessor(arvore, 64));
      TARVB_Imprime(maior_numero_chaves(arvore));
      TARVB_Libera(arvore);
      return 0;
    }
    else if(!num){
      printf("\n");
      TARVB_Imprime(arvore);
    } else {
      arvore = TARVB_Insere(arvore, num, t);
      TARVB_Imprime(arvore);
    }

    printf("\n\n");
  }
}