#include <stdio.h>
#include <math.h>

int main() {
  int nums[400] = {0, };
  int DP[100001] = {0, };
  int n, i, count;
  scanf("%d", &n);
  i = 0;
  while(nums[i]<n) {
    i++;
    nums[i] = i*i;
  }
  i=1;
  while(i<=n) {
    DP[i] = i;
    for(int j=1; j<=sqrt(i); j++) {
      if(DP[i]>DP[i-j*j]+1) {
        DP[i] = DP[i-j*j]+1;
      }
    }
    i++;
  }

  printf("%d\n", DP[n]);
  return 0;
}