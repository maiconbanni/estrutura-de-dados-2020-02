#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100
/*
    Q6) Escreva um programa que receba, como parâmetro de entrada, uma string,
    e verifique se esta string é uma “boa” senha. Entende-se  por “boa”  senha
    uma senha com as  seguintes  características  de formação: (i)  ela   deve 
    possuir, no mínimo,  oito  caracteres; (ii) ela  deve  ter, no mínimo,  um 
    caracter entre '0' a '9'; (iii) ela  deve  possuir, no  mínimo, uma  letra 
    maiúscula; (iv) ela deve ter, no mínimo, uma letra  minúscula; e (v)   ela
    deve ter,  pelo  menos, um  caracter  do  conjunto  formato  pelos  demais
    caracteres do teclado.
*/

int valida_senha (char *str);
void inicializa (char *str, int tamanho);

int main(void) {
    int n;
    char *string = (char *) malloc (TAM * sizeof (char));
    inicializa(string, TAM);
    
    printf("Por favor digite a sua senha: ");
    scanf("%100[^\n]", string);

    if(valida_senha(string)){
        printf("A senha [%s] é válida! \n", string);
    } else {
        printf("A senha [%s] é inválida! \n", string);
    }
    return 0;
}

/*
    (i)   mínimo,  oito  caracteres
    (ii)  ela  deve  ter, no mínimo,  um caracter entre '0' a '9'
    (iii) ela  deve  possuir, no mínimo, uma letra maiúscula
    (iv)  ela deve ter, no mínimo, uma letra  minúscula
    (v)   ela deve ter,  pelo  menos, um  caracter  do  conjunto formato
          pelos  demais caracteres do teclado
*/
int valida_senha (char *str) {
    int caracter_0_a_9, letra_maiuscula, letra_minuscula, demais_caracteres;
    caracter_0_a_9 = letra_maiuscula = letra_minuscula = demais_caracteres = 0;

    if(strlen(str) < 8) return 0;
    
    for(int i = 0; i < strlen(str); i++) {
        if( str[i] >= '0' && str[i] <= '9' && caracter_0_a_9 == 0) caracter_0_a_9 = 1;
        if( str[i] >= 65 && str[i] <= 90 && letra_maiuscula == 0) letra_maiuscula = 1;
        if( str[i] >= 97 && str[i] <= 122 && letra_minuscula == 0) letra_minuscula = 1;
        if( !(str[i] >= 0 && str[i] <= 9) 
         && !(str[i] >= 65 && str[i] <= 90)
         && !(str[i] >= 97 && str[i] <= 122)
         && demais_caracteres == 0) demais_caracteres = 1;
    }
    return caracter_0_a_9 && letra_maiuscula && letra_minuscula && demais_caracteres;
}

void inicializa(char *str, int tamanho) {
    for(int i=0; i < tamanho; i++) {
        str[i] = '\0';
    }
}