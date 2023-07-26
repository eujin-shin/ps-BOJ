#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x, y;
} LOCATION;

int Cmp(const void *a, const void *b) {
  LOCATION A = *(LOCATION *)a, B = *(LOCATION *)b;
  if(A.x<B.x || A.x==B.x && A.y<B.y) {
    return -1;
  } else if(A.x==B.x && A.y==B.y) {
    return 0;
  } else {
    return 1;
  }
}

int main() {
  LOCATION array[100000] = {0, };
  int n;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d %d", &array[i].x, &array[i].y);
  }
  qsort(array, n, sizeof(LOCATION), Cmp);
  for(int i=0; i<n; i++) {
    printf("%d %d\n", array[i].x, array[i].y);
  }
  return 0;
}