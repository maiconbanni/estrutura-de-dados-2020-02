
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    2.  Suponha que criamos uma estrutura para armazenar Datas:
    struct Data{
        int dia;
        int mes;
        int ano;
    };
    Implemente um algoritmo que receba um vetor de Datas como parâmetro
    e que retorne as datas em ordem cronológica 
    (crie uma função com cabeçalho: void ordena(struct Data vet[], int tam).
    Dica:Ordene o vetor separadamente por cada um dos campos
 */
typedef struct Data{
    int dia;
    int mes;
    int ano;
} Data;

int compare(const void *x, const void *y){
    Data *px = (Data *) x, *py = (Data *) y;
    if(px->ano > py->ano) return 1;
    if(px->ano < py->ano) return -1;
    if(px->mes > py->mes) return 1;
    if(px->mes < py->mes) return -1;
    if(px->dia > py->dia) return 1;
    if(px->dia < py->dia) return -1;
    return 0;
}

void adicionar(Data *Data, int index, int dia, int mes, int ano) {
    Data[index].dia = dia;
    Data[index].mes = mes;
    Data[index].ano = ano;
}

void ordena(Data vet[], int n) {
    qsort(vet, n, sizeof(Data), compare);
}

int main(void) {
    Data *Datas = (Data *) malloc(sizeof(Data) * 5);
    adicionar(Datas, 0, 01, 01, 2020);
    adicionar(Datas, 1, 01, 02, 2020);
    adicionar(Datas, 2, 02, 01, 2020);
    adicionar(Datas, 3, 01, 01, 2021);
    adicionar(Datas, 4, 01, 02, 2020);
    ordena(Datas, 5);
    for(int i = 0; i < 5; i++) printf("%d. Data dia[%d], mes[%d], ano[%d]\n", i, Datas[i].dia, Datas[i].mes, Datas[i].ano);
    free(Datas);
    return 0;
}