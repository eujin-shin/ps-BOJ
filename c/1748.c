#include <stdio.h>

int main() {
  int counts[10] = {0, };
  int n, count, ans, sum;
  scanf("%d", &n);
  sum = 1; count = 0; ans = 0;
  while(sum*10<=n) {
    count++;
    counts[count] = 9*sum;
    sum*=10;
    ans+=count*counts[count];
  }
  ans+=(count+1)*(n-sum+1);
  printf("%d\n", ans);
  return 0;
}