#include <stdio.h>
int main(void){
    int sair = 0;

    while(!sair) {
        int tamanho;
        scanf("%d", &tamanho);
        if(tamanho <= 0) {
            sair = 1;
        } else if (tamanho == 1) {
            printf("A maior sequencia possui o tamanho igual a [%d]\n", tamanho);
        } else {
            int anterior, atual, maior_sequencia, contador, indice;
            contador = 1, indice = 1, maior_sequencia = 1;
            while(indice <= tamanho) {
                scanf("%d", &atual);
                if(indice == 1 ) {
                    anterior = atual;
                }  else {
                    if(atual > anterior) {
                        ++contador;
                        if(contador > maior_sequencia) {
                            maior_sequencia = contador;
                        }
                    } else {
                        contador = 1;
                    }
                    anterior = atual;
                }
                indice++;
            }
            printf("A maior sequencia possui o tamanho igual a [%d]\n", maior_sequencia);
        }
        if(sair) { break; }
    }
    return 0;
}