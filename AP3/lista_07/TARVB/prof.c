#include "TARVB.h"
#include <limits.h>

int maior(TARVB *a){
  if(!a) return INT_MIN;
  if(!a->folha) return maior(a->filho[a->nchaves]);
  return a->chave[a->nchaves - 1];
}

int menor(TARVB *a){
  if(!a) return INT_MIN;
  if(!a->folha) return menor(a->filho[0]);
  return a->chave[0];
}

TARVB *suc_aux(TARVB *a, int ch, TARVB *suc){
  if(!a) return a;
  int i = 0;
  while((i < a->nchaves) && (ch >= a->chave[i])) i++;
  if((a->folha) && (i < a->nchaves)) return a;
  if((a->folha) && (i == a->nchaves) && (a->chave[i - 1] <= ch)) return suc;
  if((i == a->nchaves) && (a->chave[i - 1] <= ch)) return suc_aux(a->filho[i], ch, suc);
  return suc_aux(a->filho[i], ch, a);
}

TARVB *sucessor(TARVB *a, int ch){
  if((!a) || (ch >= maior(a))) return NULL;
  return suc_aux(a, ch, a);
}
// falta terminar
TARVB *pred_aux(TARVB *a, int ch, TARVB *pred){
  if(!a) return a;
  int i = a->nchaves -1;
  while((i >= 0 ) && (ch >= a->chave[i])) i--;
  if((a->folha) && (i < a->nchaves)) return a;
  if((a->folha) && (i == a->nchaves) && (a->chave[i - 1] <= ch)) return pred;
  if((i == a->nchaves) && (a->chave[i - 1] <= ch)) return pred_aux(a->filho[i], ch, pred);
  return pred_aux(a->filho[i], ch, a);
}

TARVB *predecessor(TARVB *a, int ch){
  if((!a) || (ch <= menor(a))) return NULL;
  return pred_aux(a, ch, a);
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
      scanf("%d", &num);
      TARVB_Imprime(sucessor(arvore, num));
      TARVB_Libera(arvore);
      return 0;
    }
    else if(!num){
      printf("\n");
      printf("Menor elemento %d\n", menor(arvore));
      TARVB_Imprime(arvore);
    }
    else arvore = TARVB_Insere(arvore, num, t);
    printf("\n\n");
  }
}