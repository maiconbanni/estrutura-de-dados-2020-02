#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TP.h"

int aval(char *str){
  int indice = 0;
  TP *operacoes = TP_inicializa();
  TP *valores = TP_inicializa();
  int in;
  char numero[strlen(str)];
  int operacao;
  int resultado;

  while (str[indice]){
    switch (str[indice]) {
    case ' ': indice++; break;
    case '(': indice++; break;
    case '+': TP_push(operacoes, 'a'); indice++; break;
    case '-':
        if( str[indice + 1] == ' ') {
            TP_push(operacoes, 's');
            indice++;
            break;
        } else {
            in = 0;
            memset(numero, '\0', strlen(str));
            while(str[indice] != ' ') numero[in++] = str[indice++];
            TP_push(valores, atoi(numero));
        }
    case '*': TP_push(operacoes, 'm'); indice++; break;
    case '/': TP_push(operacoes, 'd'); indice++; break;
    case '%': TP_push(operacoes, 'r'); indice++; break;
    case ')':
        indice++;
        operacao = resultado = 0;
        operacao = TP_pop(operacoes);
        resultado = TP_pop(valores);
                if (operacao == 'a') resultado = TP_pop(valores) + resultado;
        else if (operacao == 's') resultado = TP_pop(valores) - resultado;
        else if (operacao == 'm') resultado = TP_pop(valores) * resultado;
        else if (operacao == 'd') resultado = TP_pop(valores) / resultado;
        else if (operacao == 'r') resultado = TP_pop(valores) % resultado;
        TP_push(valores, resultado);
        break;
    default:
        in = 0;
        memset(numero, '\0', strlen(str));
        while(str[indice] != ' ') numero[in++] = str[indice++];
        TP_push(valores, atoi(numero));
        indice++;
    }
  }
  int resp = TP_pop(valores);
  TP_libera(operacoes);
  TP_libera(valores);
  return resp;
}

int main(void){
  while(1){
    char str[1001];
    scanf(" %1000[^\n]", str);
    if(!strcmp(str, "FIM")) return 0;
    int resp = aval(str);
    printf("%s = %d\n", str, resp);
  }
}