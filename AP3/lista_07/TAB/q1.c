#include "TAB.h"

int main(void){
  TAB* arvbin = NULL;
  TAB* newbin = NULL;
  TAB* pai, *no_encontrado;

  arvbin = TAB_insere(arvbin,10);
  arvbin = TAB_insere(arvbin,20);
  arvbin = TAB_insere(arvbin,5);
  arvbin = TAB_insere(arvbin,3);
  arvbin = TAB_insere(arvbin,4);
  arvbin = TAB_insere(arvbin,15);
  arvbin = TAB_insere(arvbin,21);
  arvbin = TAB_insere(arvbin,16);
  arvbin = TAB_insere(arvbin,25);
  arvbin = TAB_insere(arvbin,2);

  newbin = TAB_insere(newbin,15);
  newbin = TAB_insere(newbin,25);
  newbin = TAB_insere(newbin,10);
  newbin = TAB_insere(newbin,11);
  newbin = TAB_insere(newbin,3);
  newbin = TAB_insere(newbin,6);
  newbin = TAB_insere(newbin,1);

  printf("Imprimindo predecessor! \n");
  no_encontrado = predecessor(TAB_busca(arvbin, 15));
  TAB_imprime(no_encontrado);
  printf("\n");

  printf("Imprimindo no_encontrado! \n");
  no_encontrado = buscaSetPai(newbin, 6, &pai);
  TAB_imprime(no_encontrado);
  printf("\n");
  printf("Imprimindo pai de 6! \n");
  TAB_imprime(pai);
  printf("\n");

  printf("Imprimindo Folhas! \n");
  imprime_folhas(arvbin);
  printf("\n");

  printf("Imprimindo Nivel 0! \n");
  imprime_nivel(arvbin, 0, 0);
  printf("\n");

  printf("Imprimindo Nivel 1! \n");
  imprime_nivel(arvbin, 0, 1);
  printf("\n");

  printf("Imprimindo Nivel 2! \n");
  imprime_nivel(arvbin, 0, 2);
  printf("\n");
  
  printf("Imprimindo Nivel 3! \n");
  imprime_nivel(arvbin, 0, 3);
  printf("\n");

  printf("Imprimindo Nivel 4! \n");
  imprime_nivel(arvbin, 0, 4);
  printf("\n");

  printf("Imprimindo árvore Original! \n");
  TAB_imprime(arvbin);

  printf("Imprimindo árvore Original! \n");
  TAB_imprime(newbin);

  TAB *replica = copia(arvbin);
  printf("Imprimindo réplica da árvore! \n");
  TAB_imprime(replica);
  
  TAB *reflexo = espelho(arvbin);
  printf("Imprimindo espelho da árvore! \n");
  TAB_imprime(reflexo);

  TAB *max = maior(arvbin);
  printf("Imprimindo maior elemento da árvore! \n");
  TAB_imprime(max);

  TAB *min = menor(arvbin);
  printf("Imprimindo menor elemento da árvore! \n");
  TAB_imprime(min);

  printf("As árvores arvbin e replica são iguais? %s \n", igual(arvbin, replica) ? "SIM" : "NÃO");
  printf("As árvores arvbin e reflexo são iguais? %s \n", igual(arvbin, reflexo) ? "SIM" : "NÃO");
  printf("As árvores arvbin é zigzag? %s \n", zigzag(newbin) ? "SIM" : "NÃO");
  printf("As árvores arvbin e replica tem os mesmos nós? %s \n", mesmos_nos(arvbin, replica) ? "SIM" : "NÃO");
  printf("As árvores arvbin e reflexo tem os mesmos nós? %s \n", mesmos_nos(arvbin, reflexo) ? "SIM" : "NÃO");
  printf("As árvores arvbin e newbin tem os mesmos nós? %s \n", mesmos_nos(arvbin, newbin) ? "SIM" : "NÃO");
  printf("A árvore arvbin é estritamente binária!? %s \n", estbin(arvbin) ? "SIM" : "NÃO");
  printf("A árvore arvbin é estritamente binária!? %s \n", estritamente_bin(arvbin) ? "SIM" : "NÃO");
  printf("A árvore newbin é estritamente binária!? %s \n", estbin(newbin) ? "SIM" : "NÃO");
  printf("A árvore newbin é estritamente binária!? %s \n", estritamente_bin(newbin) ? "SIM" : "NÃO");
  printf("As árvores max e min são iguais? %s \n", igual(max, min) ? "SIM" : "NÃO");
  printf("Imprimindo Quantidade de Nós Internos da árvore! %d \n", ni(arvbin));
  printf("Imprimindo Quantidade de Nós Folha da árvore! %d \n", nf(arvbin));
  printf("Imprimindo Altura da árvore! %d \n", altura(arvbin));
  printf("Imprimindo Quantidade de Elementos da árvore! %d \n", count(arvbin));
  printf("Imprimindo a Soma dos Elementos da árvore! %d \n", soma_nos(arvbin));
  printf("Imprimindo Pré-Ordem! \n");
  TAB_imprime_preorder(arvbin);
  printf("\n");
  printf("Imprimindo Em-Ordem - SIMETRIA! \n");
  TAB_imprime_inorder(arvbin);
  printf("\n");
  printf("Imprimindo Pós-Ordem! \n");
  TAB_imprime_postorder(arvbin);
  printf("\n");
  printf("Imprimindo Largura! \n");
  TAB* colorida = colore (arvbin);
  TAB_imprime_largura(colorida);
  printf("\n");
  
  TAB *impares = retira_pares(arvbin);
  printf("Imprimindo árvore sem os pares! \n");
  TAB_imprime(impares);

  TAB *pares = retira_impares(replica);
  printf("Imprimindo árvore sem os impares! \n");
  TAB_imprime(pares);
  
  TAB_libera(arvbin);
  TAB_libera(newbin);
  TAB_libera(replica);
  TAB_libera(reflexo);
  return 0;
}