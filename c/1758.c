#include <stdio.h>

int main() {
  int tips[100001] = {0, };
  int n, temp;
  long long sum;
  scanf("%d", &n);
  sum = 0;
  for(int i=0; i<n; i++) {
    scanf("%d", &temp);
    tips[temp] = tips[temp] + 1;
    sum += temp;
  }
  for(int i=n-1, index=1; i>=0; i--) {
    while(tips[index]<=0) {
      index++;
    }
    tips[index] = tips[index]-1;
    if(index>i) {
      sum-=i;
    } else {
      sum-=index;
    }
  }
  printf("%lld\n", sum);
  return 0;
}