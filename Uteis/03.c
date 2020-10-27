#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Conversão de Número pra String
int main()
{
    int a=54325;
    int resultado;
    char buffer[20];
    snprintf (buffer, sizeof(buffer), "%d",a);
    printf("%s\n", buffer);
    for(int i = 0; i < strlen(buffer); i++) printf("%c ", buffer[i]);
    snprintf (buffer, sizeof(buffer), "%d", a);
    return 0;
}