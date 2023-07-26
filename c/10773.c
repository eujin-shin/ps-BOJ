#include <stdio.h>

int main() {
  int K, x, sum, index;
  scanf("%d", &K);
  int num_set[K];
  index = 0;
  sum = 0;
  for(int i=0; i<K; i++) {
    scanf("%d", &x);
    if(x==0) {
      index--;
      sum -= num_set[index];
    } else {
      sum += x;
      num_set[index] = x;
      index ++;
    }
  }
  printf("%d\n", sum);
  return 0;
}