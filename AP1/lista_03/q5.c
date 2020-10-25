#include <stdio.h>
int main(){
    int x = 10, y=20;
    int* p1;
    int* p2;
    p1 = &x;
    p2 = &y;
    (*p1)++;

    printf("(a) x = %d \n", x );
    printf("(b) y = %d \n", y );
    printf("(c) &x  = %p \n", &x );
    printf("(d) &y = %p \n", &y );
    printf("(+) *p1 = %d \n", *p1 );
    printf("(+) *p2 = %d \n", *p2 );
    printf("(e) p1 = %p \n", p1 );
    printf("(f) p2 = %p \n", p2 );
    printf("(g) *p1 + *p2 = %d \n", *p1 + *p2 );
    printf("(h) *(&x) = %d \n", *(&x) );
    printf("(i) &(*p2) = %p \n", &(*p2) );
    printf("(+) (*p1)++ = %d \n", (*p1)++);
}