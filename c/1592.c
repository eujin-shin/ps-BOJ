#include <stdio.h>

int main() {
  int N, M, L, index, count;
  scanf("%d %d %d", &N, &M, &L);
  int seat[N];
  for(int i=0; i<N; i++) {
    seat[i]=0;
  }
  index = 0;
  count = 0;
  while(1) {
    seat[index] += 1;
    if(seat[index]>=M) {
      break;
    } else if(seat[index]%2==0) {
      index += L;
      while(index>=N) {
        index -= N;
      }
    } else {
      index -= L;
      while(index<0) {
        index += N;
      }
    }
    count++;
  }
  printf("%d\n", count);
  return 0;
}