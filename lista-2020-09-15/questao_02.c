#include <stdio.h>

/*
    Q2) Implemente um programa que integre e derive polinômios. Cada  polinômio
    é  definido  por  um  vetor  que  contém seus coeficientes. Por  exemplo, o 
    polinômio  de  grau dois 3x^2 + 2x + 12 terá  um  vetor  de   coeficientes 
    v = {12,2,3}. Sua integral será I = {0, 12, 1, 1}, equivalente ao polinômio
    x 3 + x 2 + 12x, e sua derivada será D = {2, 6}, equivalendo  ao  polinômio 
    6x + 2. O programa deve, infinitamente: (a) receber o valor do maior grau g
    do  polinômio,  seguido de  (g + 1)  coeficientes;  (b)  calcular  qual é a 
    integral e a derivada  do  polinômio  informado; e  (c)  imprimir os  novos
    polinômios na tela. Este programa para somente quando o grau g do polinômio
    for menor ou igual a zero.
*/

#include <stdio.h>

void imprime_polinomio (int *vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++) {
      if(i == 0) { printf("v = {"); } 
      if( i != tamanho -1 ) {
        printf ("%d,", vetor[i]);
      } else {
        printf ("%d}\n", vetor[i]);
      }
    }
}

void gera_integral (int *vetor, int tamanho)
{

}

void gera_derivada (int *vetor, int tamanho)
{

}

int main (void)
{
  int i, grau, coeficiente;
  do
  {
      printf ("Informe o grau: ");
      scanf ("%d", &grau);
      coeficiente = grau + 1;
      
      int polinomio[grau], derivada[grau], integral[coeficiente];

      // Fazendo a leitura dos polinomios
      for (i = 0; i < coeficiente; i++) { scanf ("%d", &polinomio[i]); }
      
      // Imprime o polinomio recebido para validação
      imprime_polinomio(polinomio, coeficiente);
      gera_integral(polinomio, coeficiente);
      gera_derivada(polinomio, coeficiente);
  } while (1);
}
