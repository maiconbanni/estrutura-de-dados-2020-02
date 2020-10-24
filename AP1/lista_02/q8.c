#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    8. Um código extremamente simples substitui cada letra pela letra seguinte,
    circularmente (Z é codificado como A). Por exemplo, “Estruturas de Dados” se
    transformaria em “Ftusvuvsbt ef Ebept”. Escreva funções para codificar e para
    decodificar cadeias segundo este código.
*/
char * decodifica(char *s){
    char *string_decodificada = (char *) malloc (strlen(s) * sizeof (char));
    for(int i = 0; i < strlen(s); i++) {
        if(s[i] >= 65 && s[i] <= 90) {
            if(s[i] != 65) {
              string_decodificada[i] = s[i] - 1;
            } else {
                string_decodificada[i] = 90;
            }
        } else if (s[i] >= 97 && s[i] <= 122){
            if(s[i] != 97) {
              string_decodificada[i] = s[i] - 1;
            } else {
                string_decodificada[i] = 97;
            };             
        } else {
            string_decodificada[i] = s[i];
        }
    }
    return string_decodificada;
}

char * codifica(char *s){
    char *string_codificada = (char *) malloc (strlen(s) * sizeof (char));
    for(int i = 0; i < strlen(s); i++) {
        if(s[i] >= 65 && s[i] <= 90) {
            if(s[i] != 90) {
              string_codificada[i] = s[i] + 1;
            } else {
                string_codificada[i] = 65;
            }
        } else if (s[i] >= 97 && s[i] <= 122){
            if(s[i] != 122) {
              string_codificada[i] = s[i] + 1;
            } else {
                string_codificada[i] = 97;
            };             
        } else {
            string_codificada[i] = s[i];
        }
    }
    return string_codificada;
}

int main(void) {
    char *string = (char *) malloc (100 * sizeof (char));
    printf("Digite a string: ");
    scanf("%100[^\n]", string);
    char* string_codificada = codifica(string);
    char* string_decodificada = decodifica(string_codificada);
    printf("String Original: %s \n", string);
    printf("String Codificada: %s \n", string_codificada);
    printf("String Decodificada: %s \n", string_decodificada);
    free(string);
    free(string_codificada);
    free(string_decodificada);
    return 0;
}