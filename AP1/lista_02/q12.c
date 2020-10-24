#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
   12. Escrever um programa que lê duas cadeias s1 e s2 , e imprime uma cadeia s3 que
    contém todos os caracteres que aparecem em s1 , mas não aparecem em s2 .
*/

int main()
{
    char *s1 = (char *) malloc(sizeof(char) * 30);
    scanf("%[^\n]", s1);
    
    getchar();
    
    char *s2 = (char *) malloc(sizeof(char) * 30);
    scanf("%[^\n]", s2);
    
    int tam1 = strlen(s1), tam2 = strlen(s2), i, j, k = 0;
    
    s1 = realloc(s1, sizeof(char) * tam1);
    s2 = realloc(s2, sizeof(char) * tam2);
    
    char *s3 = (char *) malloc(sizeof(char) * tam1);
    
    int cont = 0;
    for (i = 0; i < tam1; i++){
        cont = 0;
        for (j = 0; j < tam2; j++) if(s1[i] == s2[j]) cont++;
        if(cont == 0){
            printf("%c", s1[i]);
            s3[k] = s1[i];
            j = tam2;
            k++;
        }
    }
    printf("\n");
    
    free(s1);
    free(s2);
    free(s3);
    
    return 0;
}