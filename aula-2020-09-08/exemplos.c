#include <stdio.h>
int main(void){
    while(1){
        int n;
        scanf("%d", &n);
        if(n <= 0) { return 0; }
        int ant, aux, maior = 1, i = 2, cont = 1;
        scanf("%d", &ant);
        while(i <= n){
            scanf("%d", &aux);
            if(aux > ant) cont++;
            else{
            if(cont > maior) maior = cont;
            cont = 1;
            }
            ant = aux;
            i++;
        }
        if(cont > maior) maior = cont;
        printf("O tamanho da maior sequencia: %d\n", maior);
    }
}