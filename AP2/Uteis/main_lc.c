#include "TLC.h"

int main(void) {
  TLC *l = inicializa();

  l = inserir_inicio(l, 1);
  l = inserir_inicio(l, 2);
  l = inserir_inicio(l, 3);
  l = inserir_fim(l, 4);

  l = retira(l,34);

  imprimir(l);
  printf("\n");
  libera(l);
  return 0;
}