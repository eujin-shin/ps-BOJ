#include <stdio.h>

int main() {
  int N, K, count;
  int coin_arr[11] = {0, };
  scanf("%d %d", &N, &K);
  for(int i=1; i<=N; i++) {
    scanf("%d", &coin_arr[i]);
  }
  count = 0;
  for(int i=N; i>0; i--) {
    count += K/coin_arr[i];
    K %= coin_arr[i];
    if(K==0) {
      break;
    }
  }
  printf("%d\n", count);
  return 0;
}