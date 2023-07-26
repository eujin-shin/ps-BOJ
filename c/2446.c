#include <stdio.h>

int main() {
  int N, star, space;
  scanf("%d", &N);
  space = 0;
  star = N*2-1;
  for(int i=0; i<N; i++) {
    for(int j=0; j<space; j++) {
      printf(" ");
    }
    for(int k=0; k<star; k++) {
      printf("*");
    }
    space++;
    star -= 2;
    printf("\n");
  }
  space -= 2;
  star += 4;
  for(int i=0; i<N-1; i++) {
    for(int j=0; j<space; j++) {
      printf(" ");
    }
    for(int k=0; k<star; k++) {
      printf("*");
    }
    space--;
    star += 2;
    printf("\n");   
  }
  return 0;
}