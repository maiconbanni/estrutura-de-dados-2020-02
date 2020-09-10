#include <stdio.h>

/*
    Q4) [Problema 1028 do URI Online Judge]  Ricardo e  Vicente são aficionados
        por figurinhas. Nas horas  vagas, eles  arrumam   um jeito de  jogar um 
        “bafo” ou algum outro jogo que  envolva  tais  figurinhas. Ambos também 
        têm o hábito de trocarem as  figuras  repetidas com seus amigos e certo
        dia pensaram em uma brincadeira  diferente. Chamaram  todos os amigos e
        propuseram  o  seguinte: com  as  figurinhas  em  mãos, cada um tentava 
        fazer uma troca com o amigo  que  estava mais perto seguindo a seguinte
        regra: cada  um  contava  quantas figurinhas  tinha. Em  seguida,  eles 
        tinham que dividir as figurinhas de cada um em pilhas do  mesmo tamanho,
        no maior tamanho que fosse possível para ambos. Então, cada um escolhia
        uma das  pilhas de  figurinhas do  amigo para  receber. Por exemplo, se 
        Ricardo   e   Vicente   fossem   trocar   as   figurinhas   e  tivessem
        respectivamente 8 e 12 figuras, ambos dividiam todas as suas figuras em
        pilhas de 4 figuras (Ricardo teria 2 pilhas e Vicente teria 3 pilhas) e
        ambos escolhiam uma pilha do amigo para receber.
        Entrada:  a  primeira  linha  da  entrada  contém  um  único  inteiro N 
        (1 ≤ N ≤ 3000), indicando o número  de  casos  de  teste. Cada  caso de 
        teste contém  2  inteiros F1 ( 1 ≤ F1 ≤ 1000 ) e  F2  ( 1 ≤ F2 ≤ 1000 ) 
        indicando, respectivamente, a  quantidade  de  figurinhas que Ricardo e 
        Vicente têm para trocar.
        --------------------------------------
        Entrada      |      Saída
        --------------------------------------
        3            |
        8 12         |  4
        9 27         |  9
        259 111      |  37
*/

int mdc(int x, int y) {
    int resto = 1;
    int mdc;
    while(resto) {
        resto = x % y;
        x = y;
        y = resto;
    };
    mdc=x;
}

int main(void) {
    int contador = 0;
    int qtd_ct = 0;
    int f1, f2;

    printf("Digite quantos serao os casos de testes: ");
    scanf("%d", &qtd_ct);

    while( qtd_ct  != contador ) {
        scanf("%d %d", &f1, &f2);
        printf("As pilhas serao de [%d] cartas! \n", mdc(f1,f2));
        contador++;
    }

    return 0;
}