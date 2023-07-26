#include <stdio.h>

void quick_sort(int num[], int start, int end) {
  int i, j, pivot, temp;
  i = start;
  j = end;
  pivot = num[(start+end)/2];
  while(i<=j) {
    while(num[i]>pivot) {
      i++;
    }
    while(num[j]<pivot) {
      j--;
    }
    if(i<=j) {
      if(i<j) {
        temp = num[i];
        num[i] = num[j];
        num[j] = temp;
      }
      i++; j--;
    }
  }
  if(start < j) {
    quick_sort(num, start, j);
  }
  if(i < end) {
    quick_sort(num, j+1, end);
  }
}

int main() {
  int N, M, max, price, small;
  scanf("%d %d", &N, &M);
  int p_set[M];
  for(int i=0; i<M; i++) {
    scanf("%d", &p_set[i]);
  }
  quick_sort(p_set, 0, M-1);
  if(M>N) {
    small = N;
  } else {
    small = M;
  }
  max = 0;
  for(int i=0; i<small; i++) {
    if(max<=p_set[i]*(i+1)) {
      price = p_set[i];
      max = p_set[i]*(i+1);
    }
  }
  printf("%d %d\n", price, max);
  return 0;
}