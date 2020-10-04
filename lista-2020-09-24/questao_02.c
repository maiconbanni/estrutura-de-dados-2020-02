#include <stdio.h>
#include <stdlib.h>

/* Q1) [[Problema 1171 do URI Online Judge]] */

int compare (const void * a, const void * b) {
   return *(int*)a - *(int*)b;
}

int main ()
{
    int N, contador = 1;
    scanf("%d", &N);

    int entrada[N];
    for(int i = 0; i < N; i++) {
        scanf("%d", &entrada[i]);
    }
    
    qsort(entrada, N, sizeof(int), compare);

    for(int i = 0; i < N; i++) {
        if(entrada[i] == entrada[i+1] && (i + 1) < N) {
            contador++;
        } else {
            printf("%d aparece %d vez(es)\n", entrada[i], contador);
            contador = 1;
        }
    }

    return 0;
}