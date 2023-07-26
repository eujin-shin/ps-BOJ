#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  for(int i=1; i<=n; i++) {
    int a = 0;
    int b = 0;
    while(a<n-i) {
      printf(" ");
      a++;
    }
    while(b<i) {
      printf("*");
      b++;
    }
    printf("\n");
  }
  return 0;
}