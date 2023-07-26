#include <stdio.h>
#include <stdlib.h>

int Cmp(const void *a, const void *b) {
  int x = *(int *)a, y = *(int *)b;
  if(x<y) {
    return 1;
  } else if(x>y) {
    return -1;
  } else {
    return 0;
  }
}

int main() {
  int n;
  int num[1000000] = {0, };
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