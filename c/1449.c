#include <stdio.h>
#include <stdlib.h>

int Cmp(const void *a, const void *b) {
  int x = *(int *)a, y = *(int *)b;
  return x-y;
}

int main() {
  int n, l, range = 0, count = 0;
  int points[1000] = {0, };
  scanf("%d %d", &n, &l);
  for(int i=0; i<n; i++) {
    scanf("%d", &points[i]);
  }
  qsort(points, n, sizeof(int), Cmp);
  for(int i=0; i<n; i++) {
    if(range<=points[i]) {
      range = points[i]+l;
      count++;
    }
  }
  printf("%d\n", count);
  return 0;
}