#include <stdio.h>
int main(void){
    while(1) {
        int x, y;
        scanf("%d", &x);
        if(x <= 1) { break; }
        scanf("%d", &y);
        if(y <= 1) {
            break;
        } else {
            int resto = 1;
            while(resto) {
                resto = x % y;
                x = y;
                y = resto;
            }
            printf("mdc [%d]\n", x);
        }
    }
    return 0;
}