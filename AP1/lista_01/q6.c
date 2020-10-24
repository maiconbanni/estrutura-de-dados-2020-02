#include <stdio.h>
/*
    Q6) Supondo as seguintes declarações:
    int x, y, z;
    int teste;
    x = 5;
    y = x++;
    z = x--;
    Informe os valores de teste , x , y e z depois da avaliação das seguintes expressões:
    (a) teste = !y == !x;
    (b) teste = ((x++ > y) || (--z <= y));
    (c) teste = ((!x) || (!(!z)));
    (d) teste = (((x + y) > z) && (x++));
    (e) teste = x && y + !3 || 4;
*/

#include <stdio.h>
int main(void){
    int x, y, z;
    int teste;
    x = 5;
    y = x++;
    z = x--;

    printf("teste[%d], x[%d], y[%d], z[%d]\n", teste, x, y, z);
    teste = !y == !x;
    printf("(a) teste = !y == !x, teste[%d], x[%d], y[%d], z[%d]\n", teste, x, y, z);
    teste = ((x++ > y) || (--z <= y));
    printf("(b) teste = ((x++ > y) || (--z <= y)), teste[%d], x[%d], y[%d], z[%d]\n", teste, x, y, z);
    teste = ((!x) || (!(!z)));
    printf("(c) teste = ((!x) || (!(!z))), teste[%d], x[%d], y[%d], z[%d]\n", teste, x, y, z);
    teste = (((x + y) > z) && (x++));
    printf("(d) teste = (((x + y) > z) && (x++)), teste[%d], x[%d], y[%d], z[%d]\n", teste, x, y, z);
    teste = x && y + !3 || 4;
    printf("(e) teste = x && y + !3 || 4, teste[%d], x[%d], y[%d], z[%d]\n", teste, x, y, z);

    return 0;
}