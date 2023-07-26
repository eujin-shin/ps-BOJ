#include <stdio.h>

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  int n = -1;
  if(b<c) {
    n = a/(b-c);
    n++;
  }
  printf("%d\n", n);
  return 0;
}