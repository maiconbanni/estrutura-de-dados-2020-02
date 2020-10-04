#include <stdio.h>

int main ()
{
    int N, contador = 1;
    scanf("%d", &N);

    int entrada[N];
    for(int i = 0; i < N; i++) {
        scanf("%d", &entrada[i]);
    }
    
    // ordeno na mao, por algum motivo nao aceita o qsort
    for(int i = 0; i < N; i++){
        int j, menor = i;
        for(j = i + 1; j < N; j++) {
            if(entrada[j] < entrada[menor]) {
                menor = j;
            } if(menor != i){
                int temp = entrada[i];
                entrada[i] = entrada[menor];
                entrada[menor] = temp;
            }
        }
    }

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