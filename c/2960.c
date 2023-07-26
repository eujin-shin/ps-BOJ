#include <stdio.h>

int main() {
  int N, K, index, ans;
  int num_arr[1001] = {0, };
  scanf("%d %d", &N, &K);
  num_arr[0] = 1;
  num_arr[1] = 1;
  index = 2;
  while(K) {
    while(num_arr[index]==1) {
      index++;
    }
    num_arr[index] = 1;
    K--;
    if(K==0) {
      ans = index;
      break;
    }
    int i=2;
    while(i*index<=N) {
      if(num_arr[i*index]==0) {
        num_arr[i*index] = 1;
        K--;
      }
      if(K==0) {
        ans = i*index;
        break;
      }
      i++;
    }
  }
  printf("%d\n", ans);
  return 0;
}