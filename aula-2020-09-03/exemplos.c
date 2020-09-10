#include <stdio.h>
int main(void){
    
    printf("--------------------------------------\n");
    printf("-------------Exemplo 01---------------\n");
    printf("--------------------------------------\n");
    printf("%d\n", 5/2);
    printf("%f\n", 5/2.0);
    printf("%f\n", 5.0/2);

    printf("--------------------------------------\n");
    printf("-------------Exemplo 02---------------\n");
    printf("--------------------------------------\n");
    int x = 5, y;
    y = x++; // primeiro atribui, depois incrementa
    printf("x[%d] - y[%d]\n", x, y);
    y = ++x; // primeiro incrementa, depois atribui
    printf("x[%d] - y[%d]\n", x, y);
    y = x--; // primeiro atribui, depois decrementa
    printf("x[%d] - y[%d]\n", x, y);
    y = --x; // primeiro decrementa, depois atribui
    printf("x[%d] - y[%d]\n", x, y);
    /* y = (x + 1)++; Essa linha gera erro de compilação */

    printf("--------------------------------------\n");
    printf("-------------Exemplo 03---------------\n");
    printf("--------------------------------------\n");
    int a = 10, b = 2, r;
    r = ~b;
    printf("~b    = [%d]\n", r);
    r = a & b;
    printf("a & b = [%d]\n", r);
    a >>= 1;
    printf("a >>= 1 [%d]\n", a);

    printf("--------------------------------------\n");
    printf("-------------Exemplo 04---------------\n");
    printf("--------------------------------------\n");
    int x1, y1, z1;
    int teste;
    x1 = 5;
    y1 = x1++;
    z1 = x1--;
    
    // Informe os valores de teste, x, y e z depois da avaliação das seguintes expressões
    printf("x[%d] - y[%d] - z[%d]\n", x1, y1, z1);
    printf("!y == !x - [%d]\n", !y1 == !x1);
    printf("x[%d] - y[%d] - z[%d]\n", x1, y1, z1);
    printf("--------------------------------------\n");
    printf("((x++ > y) || (--z <= y)) - [%d]\n", ((x1++ > y1) || (--z1 <= y1)));
    printf("x[%d] - y[%d] - z[%d]\n", x1, y1, z1);
    printf("--------------------------------------\n");
    printf("((!x) || (!(!z))) - [%d]\n", ((!x1) || (!(!z1))));
    printf("x[%d] - y[%d] - z[%d]\n", x1, y1, z1);
    printf("--------------------------------------\n");
    printf("(((x + y) > z) && (x++)) - [%d]\n", (((x1 + y1) > z1) && (x1++)));
    printf("x[%d] - y[%d] - z[%d]\n", x1, y1, z1);
    printf("--------------------------------------\n");
    printf("x && y + !3 || 4 - [%d]\n", x1 && y1 + !3 || 4);
    printf("x[%d] - y[%d] - z[%d]\n", x1, y1, z1);

    return 0;
}
