#include "TAVL.h"
#include "string.h"

void intToString(int number, char *string) {
    memset(string,'\n',12);
    sprintf(string, "%d", number);
}

char* tree2str(TAVL *t) {
  char *number = (char *) malloc (12 * sizeof (char));
  char *str = (char *) malloc (100 * sizeof (char));
  if(t == NULL) return strcat(str,"");
  if(t->esq == NULL && t->dir == NULL) {
    intToString(t->info, number);
    strcat(str, number);
    strcat(str,"");
    return str;
  }
  if(t->dir==NULL) {
    intToString(t->info, number);
    strcat(str, number);
    strcat(str,"(");
    strcat(str,tree2str(t->esq));
    strcat(str,")");
    return str;
  }
  intToString(t->info, number);
  strcat(str, number);
  strcat(str,"(");
  strcat(str,tree2str(t->esq));
  strcat(str,")(");
  strcat(str,tree2str(t->dir));
  strcat(str,")");

  return str;
}

TAVL* str2Tree(char *s, TAVL *arvore, int idx){
  if (idx >= strlen(s)) return NULL;
  char *number = (char *) malloc (12 * sizeof (char));
  memset(number, '\0', 12);
  int n = 0;
  while (idx < strlen(s) && s[idx] != '(' && s[idx] != ')') {
    number[n++] = s[idx++];
  }
  if(atoi(number) > 0 ) arvore = TAVL_insere(atoi(number),arvore);
  if (idx < strlen(s) && s[idx] == '(') {
      idx++; 
      arvore->esq = str2Tree(s, arvore->esq, idx);
      idx++; idx++; 
      if (idx < strlen(s) && s[idx] == '(') {
        idx++; idx++;
        arvore->dir = str2Tree(s, arvore->dir, idx);
        idx++; idx++;
      }
  }
  return arvore;
}

int main(void){
  TAVL* arvbin = NULL;

  arvbin = TAVL_insere(1,arvbin);
  arvbin = TAVL_insere(2,arvbin);
  arvbin = TAVL_insere(3,arvbin);
  arvbin = TAVL_insere(4,arvbin);
  arvbin = TAVL_insere(5,arvbin);
  arvbin = TAVL_insere(6,arvbin);
  arvbin = TAVL_insere(7,arvbin);
  arvbin = TAVL_insere(8,arvbin);

  char *treeStr = (char *) malloc (100 * sizeof (char));
  treeStr = tree2str(arvbin);
  treeStr[strlen(treeStr)] = '\0';
  printf("tree2str = %s \n", treeStr);
  printf("Imprimindo árvore Original! \n");
  TAVL_imprime(str2Tree(treeStr,arvbin,0));
  printf("\n");
  TAVL_libera(arvbin);
  free(treeStr);
}