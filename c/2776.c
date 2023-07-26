#include <stdio.h>
#include <stdlib.h>

int Cmp(const void *a, const void *b) {
  int x = *(int *)a, y = *(int *)b;
  if(x>y) {
    return 1;
  } else if(x<y) {
    return -1;
  } else {
    return 0;
  }
}

int BinSearch(int a[], int n, int key) {
  int center, left = 0, right = n-1;
  do {
    center = (left+right)/2;
    if(a[center]==key) {
      return 1;
    } else if(a[center]>key) {
      right = center-1;
    } else {
      left = center+1;
    }
  } while (left<=right);
  return 0;
}

int main() {
  int t, m, n, x;
  int num[1000001] = {0, };
  scanf("%d", &t);
  for(int i=0; i<t; i++) {
    scanf("%d", &n);
    for(int j=0; j<n; j++) {
      scanf("%d", &num[j]);
    }
    qsort(num, n, sizeof(int), Cmp);
    scanf("%d", &m);
    for(int i=0; i<m; i++) {
      scanf("%d", &x);
      printf("%d\n", BinSearch(num, n, x));
    }
  }
  return 0;
}