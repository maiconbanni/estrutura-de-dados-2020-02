#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

/*
    Q1) Implemente uma função em C que receba  uma   string   como  parâmetro e 
    substitua todas as suas  letras  por  predecessoras  do alfabeto,  trocando
    maiúsculas por  minúsculas. Por exemplo, a string     “Amor” seria alterada
    para  “zLNQ”.   Esta    função    deve  obedecer  o   seguinte   protótipo: 
    void shift_troca_string (char *str). A  letra 'a'  deve ser substituída por
    'Z' (e 'A' por 'z'). Caracteres que não forem letras devem ser substituídos
    por '!'. Sabe-se que A = 65, Z = 90, a = 97 e z = 122.
*/

void shift_troca_string (char *str);
void inicializa (char *str, int tamanho);

int main (void)
{
    char *string = (char *) malloc (TAM * sizeof (char));
    inicializa(string, TAM);
    printf("Por favor digite a frase: ");
    scanf("%100[^\n]",string);
    shift_troca_string(string);
    printf("%s\n", string);
}

void shift_troca_string (char *str) {
    int i = 0;
    while(str[i] != '\0')  {
        if(str[i] >= 65 && str[i] <= 90) {
            if(str[i] != 65) {
              str[i] = str[i] + 32 -1;
            } else {
                str[i] = 122;
            }; 
        } else if (str[i] >= 97 && str[i] <= 122){
            if(str[i] != 97) {
              str[i] = str[i] - 32 - 1;
            } else {
                str[i] = 90;
            };             
        } else {
            str[i] = '!';
        }
        i++;
    }
    return 0;
}


void inicializa(char *str, int tamanho) {
    for(int i=0; i < tamanho; i++) {
        str[i] = '\0';
    }
}