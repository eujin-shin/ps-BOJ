#include <stdio.h>

int main() {
  int scores[101] = {0, };
  int n, sum;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d", &scores[i]);
  }
  sum = 0;
  for(int i=n-1; i>0; i--) {
    if(scores[i]<=scores[i-1]) {
      sum += scores[i-1]-scores[i]+1;
      scores[i-1] = scores[i]-1;
    }
  }
  printf("%d\n", sum);
  return 0;
}