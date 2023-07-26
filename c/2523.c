#include <stdio.h>

int main() {
  int N, count;
  scanf("%d", &N);
  count=0;
  for(int i=1; i<(2*N); i++) {
    if(i>N) {
      count--;
    } else {
      count++;
    }
    for(int k=0; k<count; k++) {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}