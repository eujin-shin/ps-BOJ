#include <stdio.h>

int main() {
  int N, K, index, cycle;
  scanf("%d %d", &N, &K);
  int circle[N];
  int ans_set[N];
  for(int i=0; i<N; i++) {
    circle[i]=0;
  }
  index = 0;
  for(int i=0; i<N; i++) {
    cycle = K;
    while(1) {
      if(circle[index]==0) {
        cycle--;
      }
      if(cycle==0) {
        break;
      }
      index++;
      if(index==N) {
        index = 0;
      }
    }
    ans_set[i] = index+1;
    circle[index] = 1;
  }
  printf("<");
  for(int i=0; i<N; i++) {
    printf("%d", ans_set[i]);
    if(i<N-1) {
      printf(", ");
    }
  }
  printf(">\n");
  return 0;
}