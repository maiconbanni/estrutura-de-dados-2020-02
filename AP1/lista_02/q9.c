#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    9. Escreva um programa que lê uma frase (várias palavras) do teclado, e escreve as
    palavras uma por linha. Por exemplo, se a entrada fosse
    Estruturas de
    Dados
    a saída seria
    Estruturas
    de
    Dados
    Sugestão: O formato %[^\n] (qualquer coisa, exceto \n ) pode ser usado por scanf
    para ler uma cadeia que contém brancos, até o Enter final. Além disso, há outras
    funções de leitura de cadeias, como gets e fgets , em <stdio.h>.
*/

char** s2ss (char *str);

int main() {
    char *entrada = (char *) malloc(sizeof(char)*30);
    scanf(" %29[^\n]", entrada);
    char **resp = s2ss (entrada);
    return 0;
}

char** s2ss (char *str)
{
    int tam = strlen(str);
    char **resp = (char **) malloc(sizeof(char *) * tam);
    int i, j, k = 0, l, pos_barra, barra_anterior = -1;
    
    for(i=0; i < tam; i++)
    {
        if(str[i] < 33 || i == tam-1){
            if (i == tam-1) i++;
            pos_barra = i;
            resp[k] = (char *) malloc(sizeof(char) * (pos_barra - barra_anterior));
            printf("\n");
            l = 0;
            for (j = barra_anterior + 1; j < pos_barra; j++)
            {
                resp[k][l] = str[j];
                printf("%c", resp[k][l]);
                l++;
            }
            k++;
            barra_anterior = i;
        }
    }
}