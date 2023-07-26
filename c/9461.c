#include <stdio.h>

int main() {
  long long t_arr[101] = {0, };
  int N, x;
  for(int i=1; i<6; i++) {
    if(i<4) {
      t_arr[i] = 1;
    } else {
      t_arr[i] = 2;
    }
  }
  for(int i=6; i<101; i++) {
    t_arr[i] = t_arr[i-1] + t_arr[i-5];
  }
  scanf("%d", &N);
  for(int i=0; i<N; i++) {
    scanf("%d", &x);
    printf("%lld\n", t_arr[x]);
  }
}