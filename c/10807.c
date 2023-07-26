#include <stdio.h>

int main() {
  int N, v, count;
  scanf("%d", &N);
  int num_set[N];
  for(int i=0; i<N; i++) {
    scanf("%d", &num_set[i]);
  }
  scanf("%d", &v);
  count = 0;
  for(int i=0; i<N; i++) {
    if(num_set[i]==v) {
      count++;
    }
  }
  printf("%d\n", count);
  return 0;
}