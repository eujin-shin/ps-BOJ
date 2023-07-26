#include <stdio.h>
#include <stdlib.h>

int BinSearch(int base[], int start, int n, int key) {
  int x = start+1, y = n-1, center;
  do {
    center = (x+y)/2;
    if(base[center]==key) {
      return 1;
    } else if(base[center]<key) {
      x = center+1;
    } else {
      y = center-1;
    }
  } while (x<=y);
  return 0;
}

int Cmp(const void *a, const void *b) {
  int x = *(int *)a, y = *(int *)b;
  return x-y;
}


int main() {
  int num[15000] = {0, };
  int n, i, m, count = 0;
  scanf("%d", &n);
  scanf("%d", &m);
  for(int i=0; i<n; i++) {
    scanf("%d", &num[i]);
  }
  qsort(num, n, sizeof(int), Cmp);
  for(i=0; num[i]<m/2; i++) {
    count+=BinSearch(num, i, n, m-num[i]);
  }
  if(m%2) {
    count+=BinSearch(num, i-1, n, m/2+1);
  }
  printf("%d\n", count);
  return 0;
}