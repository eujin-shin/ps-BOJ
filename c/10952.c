#include <stdio.h>

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  do {
    printf("%d\n", a+b);
    scanf("%d %d", &a, &b);
  } while (a+b>0);
  return 0;
}