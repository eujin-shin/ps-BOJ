#include <stdio.h>

int pascal[31][31] = {0, };

int Pascal(int n, int k) {
  if(pascal[n][k]==0) {
    if(k==1 || k==n) {
      pascal[n][k] = 1;
    } else {
      pascal[n][k] = Pascal(n-1, k) + Pascal(n-1, k-1);
    }
  }
  return pascal[n][k];
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  printf("%d\n", Pascal(n, k));
  return 0;
}