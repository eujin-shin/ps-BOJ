#include <stdio.h>

int main() {
  int N, count;
  scanf("%d", &N);
  count = (N/5)+(N/25)+(N/125);
  printf("%d\n", count);
  return 0;
}