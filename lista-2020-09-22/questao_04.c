#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100
/*
    Q4) Escreva uma função que receba, como entrada, uma cadeia de caracteres s
    e um inteiro n, e, em seguida, retire o "prefixo" da cadeia s de  tamanho n
    (isto é,  retire os n  primeiros  caracteres). Se a  cadeia não  tiver pelo
    menos n caracteres, deve ser impressa a mensagem "erro". Por exemplo, se  s
    = "abcdefghi" e n = 3, então a cadeia  "defghi"  deve  ser  impressa; com a 
    mesma cadeia s e n = 17, deve ser impresso "erro". O protótipo desta função
    é o seguinte: void retira_inicio_n (char *str, int n).
*/

void retira_inicio_n (char *str, int n);
void inicializa (char *str, int tamanho);

int main(void) {
    int n;
    char *string = (char *) malloc (TAM * sizeof (char));
    inicializa(string, TAM);
    
    printf("Por favor digite a string: ");
    scanf("%100[^\n]", string);
    
    printf("Por favor digite o tamanho do prefixo que deseja remover: ");
    scanf("%d", &n);

    if(strlen(string) < n) {
        printf("erro\n");
    } else {
        retira_inicio_n(string, n);
        printf("%s\n", string);
    }
    
    return 0;
}

void retira_inicio_n (char *str, int n) {
    int i;
    for(i = n; i < strlen(str); i++) {
        str[i -n] = str[i];
    }
    str[i -n] = '\0';
}

void inicializa(char *str, int tamanho) {
    for(int i=0; i < tamanho; i++) {
        str[i] = '\0';
    }
}