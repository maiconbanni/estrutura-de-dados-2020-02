#include <stdio.h>
#include <stdlib.h>

/*
    Q6) Problema 1533 do URI Online Judge
*/

int compare (const void * a, const void * b) {
   return *(int*)a - *(int*)b;
}

int main(void) {
    while(1) {
        int N;
        int suspeito;

        printf("Digite o número de suspeitos: ");
        scanf("%d", &N);
        
        if(N == 0) { break; }

        int T[N];
        int C[N];

        for(int i = 0; i < N; i++){
            int valor;
            scanf("%d", &valor);
            T[i] = valor;
            C[i] = T[i];
        }

        qsort(T, N, sizeof(int), compare);

        for(int i = 0; i < N; i++){
            // Segundo mais suspeito, eh o penultimo da lista
            if(C[i] == T[N - 2]) {
                suspeito = i + 1;
            }
        }

        printf("%d \n", suspeito);
    }    
    return 0;
}
