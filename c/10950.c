#include <stdio.h>

int main() {
  int n, a, b;
  scanf("%d", &n);
  int sumArr[n];
  for(int i=1; i<=n; i++) {
    scanf("%d %d", &a, &b);
    sumArr[i-1] = a+b;
  }
  for(int i=1; i<=n; i++) {
    printf("%d\n", sumArr[i-1]);
  }
  return 0;
}