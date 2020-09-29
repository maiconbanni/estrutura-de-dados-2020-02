#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct prior{
  int p_user, id;
  char narq[31];
}TP;

typedef struct ei{
  int tam, ult_pos_ocup;
  TP **vet;
}TEI;

TEI * inicializa(int tam){
  TEI *resp = (TEI *) malloc(sizeof(TEI));
  resp->vet = (TP **) malloc(sizeof(TP *) * tam);
  int i;
  for(i = 0; i < tam; i++) resp->vet[i] = NULL;
  resp->tam = tam;
  resp->ult_pos_ocup = -1;
  return resp; 
}

void imprime(TEI *resp){
  int i;
  for(i = 0; i <= resp->ult_pos_ocup; i++)
   printf("%d: %d %s\n", resp->vet[i]->p_user, resp->vet[i]->id, resp->vet[i]->narq); 
}

void retira(TEI *resp){
  if(resp->ult_pos_ocup == -1) return;
  TP *temp = resp->vet[0];
  int i;
  for(i = 0; i < resp->ult_pos_ocup; i++) resp->vet[i] = resp->vet[i + 1];
  resp->ult_pos_ocup--;
  free(temp);
}

void insere_no_final_da_lista(TEI *resp, int p_user, int id, char *narq) {
    // printf("insere_no_final_da_lista\n");
    if(resp->tam > (resp->ult_pos_ocup -1)) {
        resp->ult_pos_ocup += 1;
        resp->vet[resp->ult_pos_ocup] = (TP *) malloc(sizeof(TP *));
        resp->vet[resp->ult_pos_ocup]->p_user = p_user;
        resp->vet[resp->ult_pos_ocup]->id = id;
        memcpy(resp->vet[resp->ult_pos_ocup]->narq, narq, strlen(narq));
    }
}

void insere_posicao_da_lista(TEI *resp, int p_user, int id, char *narq, int posicao_a_inserir) {
    // printf("insere_posicao_da_lista = %d \n", posicao_a_inserir);
    // Nada a fazer a lista ja esta cheia
    if((posicao_a_inserir < (resp->tam)) && ( resp->ult_pos_ocup < (resp->tam - 1)) ){
        // printf("shiftar pra direita\n");
        for(int i = resp->ult_pos_ocup + 1; i > posicao_a_inserir; i--){
            //printf("i = %d \n", i);
            //printf("i - 1 = %d \n", i - 1);
            resp->vet[i] = (TP *) malloc(sizeof(TP *));
            resp->vet[i]->p_user = resp->vet[i-1]->p_user;
            resp->vet[i]->id     = resp->vet[i-1]->id;
            memcpy(resp->vet[i]->narq, resp->vet[i-1]->narq, strlen(resp->vet[i-1]->narq));
        }
        // printf("Mapear informacao no lugar certo\n");
        resp->vet[posicao_a_inserir]->p_user = p_user;
        resp->vet[posicao_a_inserir]->id = id;
        memset(resp->vet[posicao_a_inserir]->narq, '\0', strlen(resp->vet[posicao_a_inserir]->narq));
        memcpy(resp->vet[posicao_a_inserir]->narq, narq, strlen(narq));
        resp->ult_pos_ocup += 1;
        // printf("resp->ult_pos_ocup = %d \n", resp->ult_pos_ocup);
    }
}

int find_by_user(TEI *resp, int p_user) {
    // printf("find_by_user = %d\n", p_user);
    if(p_user > resp->vet[0]->p_user) {return 0;}

    int posicao_a_inserir = 0;
    for(int indice = 0; indice <= resp->ult_pos_ocup; indice++){
        if(p_user > resp->vet[indice]->p_user ) {
            break; 
        } else {
          posicao_a_inserir = indice + 1;
        }
    }

    // for(int indice = 0; indice <= resp->ult_pos_ocup; indice++){
    //     if(resp->vet[indice]->p_user == p_user) {
    //         posicao_a_inserir = indice + 1; 
    //     }
    // }
    // printf("posicao_a_inserir = %d\n", posicao_a_inserir);
    return posicao_a_inserir;
}

/* Passos
    (a)aloca espaço para esse novo elemento
    (b) esse novo elemento de impressão será inserido depois do último elemento com p_user igual ao seu.
        Isto quer dizer que,  em alguns casos, você terá que remanejar elementos.
*/
void insere(TEI *resp, int p_user, int id, char *narq){
    //primeiro elemento
    if(resp->ult_pos_ocup == -1){
        insere_no_final_da_lista(resp, p_user, id, narq);
    } else {
        int posicao_a_inserir = find_by_user(resp, p_user);
        // printf("resp->ult_pos_ocup = %d\n", resp->ult_pos_ocup);
        if(posicao_a_inserir > resp->ult_pos_ocup) {
            insere_no_final_da_lista(resp, p_user, id, narq);
        } else {
            insere_posicao_da_lista(resp, p_user, id, narq, posicao_a_inserir);
        }
    }
}

int main(void){
  int tam;
  scanf("%d", &tam);
  if(tam <= 0) return 0;
  TEI *fila = inicializa(tam);
  int i, n;
  do{
    scanf("%d", &n);
  }while((n <= 0) || (n > tam));
  for(i = 0; i < n; i++){
    TP aux;
    scanf("%d%d", &aux.p_user, &aux.id);
    scanf(" %30[^\n]", aux.narq);
    insere(fila, aux.p_user, aux.id, aux.narq);
  }
  imprime(fila);
  for(i = 0; i < n; i++) retira(fila);
  free(fila);
  return 0;
}