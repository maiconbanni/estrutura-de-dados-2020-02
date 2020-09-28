
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

/*
    Q2) Implemente uma função em C que receba uma string como parâmetro e 
    retorne uma nova string com todos os caracteres minúsculos substituídos
    pelo caracter ‘?’. Por exemplo, se for passada a string “740-Charitas-Leme”
    a função deve retornar a string “740-Ch?r?t?s-L?m?”. A assinatura desta
    função deve ser char * codifica (char *str). A string passada como 
    parâmetro não pode ser alterada. O espaço de memória para a nova string 
    deve ser alocado dinamicamente.
*/

char * codifica (char *str);
char * codifica_todos_caracteres_minusculos (char *str);
void inicializa (char *str, int tamanho);

int main (void)
{
    char *string = (char *) malloc (TAM * sizeof (char));
    inicializa(string, TAM);
    printf("Por favor digite a string: ");
    scanf("%100[^\n]",string);
    char *stringCodifica = codifica(string);
    char *novaCodificao = codifica_todos_caracteres_minusculos(string);
    if (stringCodifica != NULL && novaCodificao != NULL) {
        printf("String Original [%s]\n", string);
        printf("String codificada baseada na saida apresentada [%s]\n", stringCodifica);
        printf("String codificada baseada no entendimento do enunciado [%s]\n", novaCodificao);
    } else {
        printf("Por favor digite uma string\n");
    }
    free(string);
    free(stringCodifica);
    free(novaCodificao);
    return 0;
}

char * codifica_todos_caracteres_minusculos (char *str) {
    int tamanho = strlen(str);
    if(tamanho == 0) { return NULL;}
    char *novaString = (char *) malloc (tamanho * sizeof (char));

    int i = 0;
    while(str[i] != '\0')  {
        if(str[i] >= 97 && str[i] <= 122) {
            novaString[i] = '?';
        } else {
            novaString[i] = str[i];
        }
        i++;
    }
    return novaString;
}

char *  codifica(char *str) {
    int tamanho = strlen(str);
    if(tamanho == 0) { return NULL;}
    char *novaString = (char *) malloc (tamanho * sizeof (char));

    int i = 0;
    while(str[i] != '\0')  {
        if( str[i] == 97 /* letra a */ 
         || str[i] == 101 /* letra e */
         || str[i] == 105 /* letra i */
         || str[i] == 111 /* letra o */
         || str[i] == 117) /* letra u */ { 
            novaString[i] = '?';
        } else {
            novaString[i] = str[i];
        }
        i++;
    }
    return novaString;
}

void inicializa(char *str, int tamanho) {
    for(int i=0; i < tamanho; i++) {
        str[i] = '\0';
    }
}