#include <stdio.h>

int main() {
  int n, k, max, min, count, ans;
  int rope[10001] = {0, };
  scanf("%d", &n);
  max = 1; min = 10000;
  for(int i=0; i<n; i++) {
    scanf("%d", &k);
    if(k>max) {
      max = k;
    } 
    if(k<min) {
      min = k;
    }
    rope[k] = rope[k] + 1;
  }
  ans = 0;
  for(int i=max; i>=min; i--) {
    count += rope[i];
    if(count*i>ans) {
      ans = count*i;
    } 
  }
  printf("%d\n", ans);
  return 0;
}