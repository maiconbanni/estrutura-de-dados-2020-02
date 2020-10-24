#include <stdio.h>
#include <stdlib.h>

/*
    Escreva um programa que recebe como entrada uma temperatura em o C ou em o F
    e converte a temperatura para a outra escala. A escala em que está a temperatura
    de entrada é indicada pela letra C ou F.

    Celsius into/para Fahrenheit: (oC x 9) / 5) + 32
    Fahrenheit into/para Celsius: (oF – 32) x 5) / 9

*/

float convert(char escala, float temperatura) {
    if(escala == 'C') {
        return (((temperatura * 9) / 5) + 32);
    } else {
        return (((temperatura - 32) * 5) / 9);
    }
}

int main(void) {
    float temperatura;
    char  escala;

    printf("Digite a temperatura: ");
    scanf("%f", &temperatura);
    getchar();
    printf("Digite a escala: ");
    scanf("%c", &escala);
    
    printf("Temperatura: %f \n", convert(escala, temperatura));

    return 0;
}