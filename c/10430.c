#include <stdio.h>

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  int A = (a+b)%c;
  int B = ((a%c)+(b%c))%c;
  int C = (a*b)%c;
  int D = ((a%c)*(b%c))%c;
  printf("%d\n%d\n%d\n%d\n", A, B, C, D);
  return 0;
}