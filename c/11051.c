#include <stdio.h>

int pascal[1001][1001] = {0, };

int GetPascal(int n, int k) {
  if(pascal[n][k]==0) {
    if(k==0 || k==n) {
      pascal[n][k] = 1;
    } else {
      pascal[n][k] = GetPascal(n-1, k) + GetPascal(n-1, k-1);
      pascal[n][k] %= 10007;
    }
  }
  return pascal[n][k];
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  printf("%d\n", GetPascal(n, k));
  return 0; 
}