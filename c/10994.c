#include <stdio.h>

int main() {
  int n, max, x;
  scanf("%d", &n);
  max = 4*n-3;
  x = max;
  for(int i=1; i<=n; i++) {
    if(i!=n) {
      for(int j=0; j<max+1-i; j++) {
        printf("*");
      }
      printf("\n");
    }
    for(int j=1; j<=i; j++) {
      printf("*");
      if(j!=i) {
        printf(" ");
      }
    }
    for(int j=0; j<max+2-(i*4); j++) {
      printf(" ");
    }
    for(int j=1; j<=i; j++) {
      printf("*");
      if(j!=i) {
        printf(" ");
      }
    }
    printf("\n");
  }
}