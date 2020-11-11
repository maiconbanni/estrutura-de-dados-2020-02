#include <stdio.h>
#include <stdlib.h>

int teste (int n){
  int pot = 1;
  while (pot < n) pot *= 10;
  pot /= 100;
  int num1 = n / pot, num2 = n % 100;
  int x = (num1 + num2) * (num1 + num2), y = num1 * 100 + num2;
  if(x == y) return 1;
  return 0;
}
 
int main(void){
  while(1){
    int n;
    scanf("%d", &n);
    if(n < 0) return 0;
    printf("%d\n", teste(n));
  }
}