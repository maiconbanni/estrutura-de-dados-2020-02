#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#define TAM 100

/*
    Q7) Escreva um programa que receba duas strings, como parâmetros de entrada
    e informe qual é a maior substring existente nas duas strings. Por exemplo,
    se as strings de entrada são ACCTGAACTCCCCCC e ACCTAGGACCCCCC, então a maior
    substring existente entre as duas strings será CCCCCC.
*/

char * maior_substring (char *str1, char *str2);
void inicializa (char *str, int tamanho);
void substr(char * destino, char * origem, int posicao, int tamanho);

int main (void)
{
    char *string1 = (char *) malloc (TAM * sizeof (char));
    char *string2 = (char *) malloc (TAM * sizeof (char));

    inicializa(string1, TAM);
    inicializa(string2, TAM);

    printf("Por favor digite a primeira string: ");
    scanf("%100[^\n]", string1);
    __fpurge(stdin);
    printf("Por favor digite a segunda string: ");
    scanf("%100[^\n]", string2);

    printf("resultado = %s\n", maior_substring(string1, string2));
    
    free(string1);
    free(string2);
    
    return 0;
}

char * maior_substring (char *str1, char *str2) {
    // A substring não pode ser maior que a menor string das duas.
    int tamanho = strlen(str1);
    char *substring = (char *) malloc ((tamanho) * sizeof (char));
    char *maior_substring = (char *) malloc ((tamanho) * sizeof (char));
    char *p_existe;
    int posicao_inicial = 0;
    int tamanho_atual_string = 1;
    int indice_auxiliar = 0;

    inicializa(substring, tamanho);
    inicializa(maior_substring, tamanho);
    
    for(int i = 0; i <= strlen(str1); i++) {
        substr(substring, str1, posicao_inicial, tamanho_atual_string);
        p_existe = strstr(str2,substring);
        //printf("str1 [%s] e substring [%s]\n", str1, substring);

        if(p_existe) {
            if(strlen(substring) > strlen(maior_substring)) {
                strcpy(maior_substring, substring);
                tamanho_atual_string++;
                //printf("Maior substring encontrada ate o momento [%s]\n", maior_substring);
            } else {
                tamanho_atual_string++;
            }
        } else {
            indice_auxiliar++;
            i = indice_auxiliar;
            tamanho_atual_string = 1;
            posicao_inicial++;
            inicializa(substring, tamanho);
            //printf("Resetando -> indice_auxiliar [%d], i [%d], tamanho_atual_string [%d], posicao_inicial [%d] \n", indice_auxiliar, i, tamanho_atual_string, posicao_inicial);
        }
    }
    free(substring);
    return maior_substring;
}

void substr(char * destino, char * origem, int posicao, int tamanho) {
  int i;
  for(i = 0; i < tamanho && origem[posicao + i] != '\0'; i++){
    destino[i] = origem[i + posicao];
  }
  destino[i] = '\0';
}

void inicializa(char *str, int tamanho) {
    for(int i=0; i < tamanho; i++) {
        str[i] = '\0';
    }
}