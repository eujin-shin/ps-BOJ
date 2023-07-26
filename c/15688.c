#include <stdio.h>

int Cmp(const void *a, const void *b) {
  return *(int *)a-*(int *)b;
}

int main() {
  int num[1000000] = {0, };
  int n;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d", &num[i]);
  }
  qsort(num, n, sizeof(int), Cmp);
  for(int i=0; i<n; i++) {
    printf("%d\n", num[i]);
  }
  return 0;
}