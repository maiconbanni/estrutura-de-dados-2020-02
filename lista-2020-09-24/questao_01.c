#include <stdio.h>
#include <stdlib.h>

/* Q1) [Problema 1514 do URI Online Judge] */

int ninguem_resolveu_todos_os_problemas(int **mat, int n_participantes, int n_problemas);
int todos_os_problemas_foram_resolvidos(int **mat, int n_participantes, int n_problemas);
int nenhum_problema_resolvido_por_todos(int **mat, int n_participantes, int n_problemas);
int todos_resolveram_ao_menos_um_problema(int **mat, int n_participantes, int n_problemas);

int main (void)
{
    while(1) {
        int N, M;

        printf("Por favor digite o Número de Participantes: ");
        scanf("%d", &N);
        printf("Por favor digite o Número de Problemas: ");
        scanf("%d", &M);

        if(N == 0 && M == 0) break;

        int **matriz = (int **) malloc(sizeof(int *) * N);
        for(int i = 0; i < N; i++) matriz[i] = (int *) malloc (sizeof(int) * M);

        for(int linha = 0; linha < N; linha++){
            for(int coluna = 0; coluna < M; coluna++) {
                scanf("%d", &matriz[linha][coluna]);
            }
        }

        // int resultado1 = ninguem_resolveu_todos_os_problemas(matriz, N, M);
        // printf("ninguem_resolveu_todos_os_problemas = %d \n", resultado1);

        // int resultado2 = todos_os_problemas_foram_resolvidos(matriz, N, M);
        // printf("todos_os_problemas_foram_resolvidos = %d \n", resultado2);

        // int resultado3 = nenhum_problema_resolvido_por_todos(matriz, N, M);
        // printf("nenhum_problema_resolvido_por_todos = %d \n", resultado3);

        // int resultado4 = todos_resolveram_ao_menos_um_problema(matriz, N, M);
        // printf("todos_resolveram_ao_menos_um_problema = %d \n", resultado4);

        printf("%d\n", ninguem_resolveu_todos_os_problemas(matriz, N, M)
                    +  todos_os_problemas_foram_resolvidos(matriz, N, M)
                    +  nenhum_problema_resolvido_por_todos(matriz, N, M)
                    +  todos_resolveram_ao_menos_um_problema(matriz, N, M));
    }
    return 0;
}

int ninguem_resolveu_todos_os_problemas(int **mat, int n_participantes, int n_problemas) {
    int qtd_problemas_resolvidos = 0;
    int alguem_resolveu_td_problemas = 0;
    
    for(int linha = 0; linha < n_participantes; linha++){
        for(int coluna = 0; coluna < n_problemas; coluna++) {
            if(mat[linha][coluna] == 1) {
                qtd_problemas_resolvidos++;
            }
        }
        if(qtd_problemas_resolvidos == n_problemas ){
            alguem_resolveu_td_problemas = 1;
            break;
        } 
        qtd_problemas_resolvidos = 0;
    }
    return !alguem_resolveu_td_problemas;
}

int todos_os_problemas_foram_resolvidos(int **mat, int n_participantes, int n_problemas) {
    int n_problemas_resolvidos = 0;
    int vet[n_problemas];
    
    for(int linha = 0; linha < n_participantes; linha++){
        for(int coluna = 0; coluna < n_problemas; coluna++) {
            if(mat[linha][coluna] == 1) {
                vet[coluna] = 1;
            }
        }
    }

    for(int i = 0; i < n_problemas; i ++){
        n_problemas_resolvidos += vet[i] == 1 ? 1 : 0;
    }
    
    return n_problemas_resolvidos == n_problemas ? 1 : 0;
}

int nenhum_problema_resolvido_por_todos(int **mat, int n_participantes, int n_problemas) {
    int qtd_problemas_resolvidos = 0;
    int nenhum_problema_resolvido_por_todos = 1;
    int vet[n_problemas];
    
    for(int linha = 0; linha < n_participantes; linha++){
        for(int coluna = 0; coluna < n_problemas; coluna++) {
            if(mat[coluna][linha] == 1) {
                qtd_problemas_resolvidos++;
            }
        }
        if(qtd_problemas_resolvidos == n_problemas ){
            nenhum_problema_resolvido_por_todos = 0;
            break;
        }
        qtd_problemas_resolvidos = 0;
    }

    return nenhum_problema_resolvido_por_todos;
}

int todos_resolveram_ao_menos_um_problema(int **mat, int n_participantes, int n_problemas) {
    int qtd_problemas_n_resolvidos = 0;
    int todos_resolveram_ao_menos_um_problema = 1;
    
    for(int linha = 0; linha < n_participantes; linha++){
        for(int coluna = 0; coluna < n_problemas; coluna++) {
            if(mat[linha][coluna] == 0) {
                qtd_problemas_n_resolvidos++;
            }
        }
        if(qtd_problemas_n_resolvidos == n_problemas ){
            todos_resolveram_ao_menos_um_problema = 0;
            break;
        } 
        qtd_problemas_n_resolvidos = 0;
    }
    return todos_resolveram_ao_menos_um_problema;
}