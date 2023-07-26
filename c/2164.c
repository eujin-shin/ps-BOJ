#include <stdio.h>

int main() {
  int N, index, cycle;
  scanf("%d", &N);
  int card_set[N];
  for(int i=0; i<N; i++) {
    card_set[i] = 1;
  }
  index = 0;
  for(int i=1; i<N; i++) {
    cycle = 2;
    card_set[index] = 0;
    while(cycle) {
      index++;
      if(card_set[index]==1) {
        cycle--;
      }
      if(index>=N) {
        index = 0;
      }
    }
  }
  printf("%d\n", index+1);
  return 0;
}