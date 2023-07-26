#include <stdio.h>

int main() {
  int T;
  scanf("%d", &T);
  for(int i=1;i<=T;i++) {
    for(int n=1;n<=i;n++) {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}