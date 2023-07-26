#include <stdio.h>

int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  int Arr[n];
  for(int i=0; i<n; i++) {
    scanf("%d", &Arr[i]);
  }
  for(int i=0; i<n; i++) {
    if(Arr[i]<x) {
      printf("%d ", Arr[i]);
    }
  }
  printf("\n");
  return 0;
}