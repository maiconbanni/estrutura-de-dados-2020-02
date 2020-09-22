#include <stdio.h>
#include <stdlib.h>

/*
    Q6) Problema 1318 do URI Online Judge
*/

int compare (const void * a, const void * b) {
   return *(int*)a - *(int*)b;
}

int main(void) {
    while(1) {
        int N, M;
        int repetidos = 0, ultimo = -1, numero_repetido = -1;

        printf("Digite o número de bilhetes originais e o número de pessoas presentes na festa: ");
        scanf("%d %d", &N, &M);
        
        if(N == 0 && M == 0) { break; }

        int T[M];

        for(int i = 0; i < M; i++){
            int valor;
            scanf("%d", &valor);
            T[i] = valor;
        }

        qsort(T, M, sizeof(int), compare);

        for(int i = 0; i < M; i++){
            ultimo = T[i];
            if(ultimo == T[i + 1] && numero_repetido != T[i + 1]) {
                numero_repetido = ultimo;
                repetidos += 1;
            }
        }

        printf("%d \n", repetidos);
    }    
    return 0;
}
