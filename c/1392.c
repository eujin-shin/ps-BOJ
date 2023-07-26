#include <stdio.h>

int main() {
  int N, Q, time, question, sum, index;
  scanf("%d %d", &N, &Q);
  int time_list[N];
  int ans_list[Q];
  sum = 0;
  for(int i=0; i<N; i++) {
    scanf("%d", &time);
    sum += time;
    time_list[i] = sum; 
  }
  for(int i=0; i<Q; i++) {
    scanf("%d", &question);
    index = 0;
    while(time_list[index]<=question) {
      index++;
    }
    ans_list[i] = index+1;
  }
  for(int i=0; i<Q; i++) {
    printf("%d\n", ans_list[i]);
  }
  return 0;
}