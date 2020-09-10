#include <stdio.h>

/*
    Q3) [Problema 1103 do URI Online Judge] Daniela é enfermeira  em  um grande
    hospital, e tem os  horários de trabalho  muito variáveis. Para piorar, ela
    tem s ono  pesado, e uma  grande  dificuldade  para  acordar  com r elógios
    despertadores. Recentemente  ela  ganhou  de presente um  relógio  digital,
    com alarme com vários tons, e tem esperança que isso resolva o seu problema
    No entanto, ela anda muito  cansada  e  quer  aproveitar  cada  momento  de 
    descanso. Por isso, carrega seu relógio digital despertador para  todos  os 
    lugares, e sempre que tem um tempo de descanso procura  dormir, programando 
    o alarme despertador para a hora em  que  tem que  acordar. No entanto, com 
    tanta ansiedade  para  dormir,  acaba  tendo  dificuldades para adormecer e 
    aproveitar o descanso. Um  problema que a tem atormentado na hora de dormir
    é saber quantos minutos ela teria de  sono se  adormecesse  imediatamente e 
    acordasse  somente  quando o  despertador  tocasse. Mas ela realmente não é 
    muito boa  com  números, e  pediu sua ajuda para  escrever  um programa que,
    dada a hora corrente e a hora do alarme, determine o número  de minutos que 
    ela poderia dormir. Entrada: a entrada  contém  vários casos de teste. Cada 
    caso de teste é descrito em uma  linha,  contendo  quatro  números inteiros 
    H1, M1, H2, M2, com H1:M1 representando  a hora e  minuto  atuais, e  H2:M2 
    representando a hora  e  minuto  para  os  quais o  alarme  despertador foi
    programado  (0≤H1≤23, 0≤M1≤59, 0≤H2≤23, 0≤M2 ≤59).  O  final  da  entrada é 
    indicado por uma  linha  que  contém  apenas  quatro  zeros,  separados por 
    espaços em branco.
    Saída: para cada caso de teste da entrada seu programa  deve  imprimir  uma 
    linha, cada uma contendo um número inteiro, indicando o número  de  minutos 
    que Daniela tem para dormir.
    --------------------------------------
        Entrada      |      Saída
    --------------------------------------
    1 5 3 5          |  120
    23 59 0 34       |  35
    21 33 21 10      |  1417
    0 0 0 0          |
*/

int calcula_tempo_sono(int hora_de_dormir, int hora_de_acordar) {
    int tempo_de_sono = hora_de_acordar - hora_de_dormir;
    return (tempo_de_sono < 0) ? 1440 + tempo_de_sono : tempo_de_sono;
}

int converte_para_minuto(int hora) {
    return hora * 60;
}

int main(void) {
    int tempo_total = 0;
    int h1, m1, h2, m2;

    h1 = m1 = h2 = m2 = 0;
    
    while(1) {
        printf("Digite a hora/minutos que voce irá descansar \n");
        printf("e a hora/minuto que deseja acordar no formato \n");
        printf("hora_dormir minuto_dormir hora_acordar minuto_acordar: ");
        scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
        
        if(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0) { break; }

        int hora_de_dormir = converte_para_minuto(h1) + m1;
        int hora_de_acordar = converte_para_minuto(h2) + m2;

        tempo_total = calcula_tempo_sono(hora_de_dormir, hora_de_acordar);
        printf("Tempo total de Sono [%d] \n", tempo_total);
    }

    return 0;
}