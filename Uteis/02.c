#include <stdio.h>
#include <stdlib.h>
#define t 3

struct Produto {
	int cod;
	float preco;
};

void lerVet( struct Produto *p ){
	int i;
	for ( i=0; i < t; i++){
		printf("\tCodigo e Preco? ");
		scanf("%d %f", &p->cod, &p->preco);
		p++;
	}
}

void mostrarVet( struct Produto *p ){
	int i;
	for ( i=0; i < t; i++ ){
		printf("\tCodigo: %d\n", p->cod);
		printf("\tPreco.: %f\n", p->preco);
		p++;
	}
}

void trocar (struct Produto *pv, int x, int y) {
	struct Produto aux = pv[x];
	pv[x] = pv[y];
	pv[y] = aux; 

}

void bubbleSort( struct Produto *p){
    int i, j;
	for ( i = t-1; i > 0; i-- ){
		for ( j = 0; j < i; j++ ){
			if ( p[j].cod > p[j+1].cod ) // A comparação pelo membro cod da struct
				trocar(p, j, j+1);
		}
	}
}

void main(){
	struct Produto *vet = (struct Produto *) malloc (t * sizeof (struct Produto));

	printf("\nDigite o conteudo do vetor:\n");
	lerVet(vet);
	printf("\nConteudo digitado para o vetor:\n");
	mostrarVet(vet);

	printf("\nOrdenando o vetor...\n");
	bubbleSort(vet);

	printf("\nConteudo do vetor ja ordenado:\n");
	mostrarVet(vet);
}
