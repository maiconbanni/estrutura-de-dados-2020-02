#include <stdio.h>
int main(void){
    int sair = 0;

    while(!sair) {
        int tamanho;
        scanf("%d", &tamanho);
        if(tamanho <= 0) {
            sair = 1;
        } else if (tamanho == 1) {
            printf("Para o tamanho [%d] nao eh possivel determinar se existe quebra de sequencia\n", tamanho);
        } else {
            int anterior, atual, qtd_quebra_sequencia, indice;
            indice = 1, qtd_quebra_sequencia = 0;
            while(indice <= tamanho) {
                scanf("%d", &atual);
                if(indice == 1 ) {
                    anterior = atual;
                }  else {
                    if(atual < anterior) {
                        qtd_quebra_sequencia++;
                    }
                    anterior = atual;
                }
                indice++;
            }
            printf("Numero de sequencias crescentes interrompidas [%d]\n", qtd_quebra_sequencia);
        }
        if(sair) { break; }
    }
    return 0;
}