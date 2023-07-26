#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  for(int i=n; i>0; i--) {
    for(int l=0; l<i; l++) {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}