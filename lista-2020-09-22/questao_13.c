#include <stdio.h>

void main(void) {

    int N;
    scanf("%d", &N);

	int H[N][N];
	H[0][0] = 1;
	for(int n = 1; n < N; n += n) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                H[i+n][j] = H[i][j];
                H[i][j+n] = H[i][j];
                H[i+n][j+n] = !H[i][j];
            }
        }
    }
    // Imprime
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) printf("%d ", H[i][j]);
        printf("\n");
    }
}