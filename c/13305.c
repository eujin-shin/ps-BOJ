#include <stdio.h>

int main() {
  long long sum;
  long long prices[100001] = {0, };
  long long length[100001] = {0, };
  int n, price;
  scanf("%d", &n);
  for(int i=1; i<n; i++) {
    scanf("%lld", &length[i]);
  }
  for(int i=0; i<n; i++) {
    scanf("%lld", &prices[i]);
  }
  sum = length[1]*prices[0];
  price = prices[0];
  for(int i=1; i<n; i++) {
    if(prices[i]<price) {
      price = prices[i];
    }
    sum += length[i+1]*price;
  }
  printf("%lld\n", sum);
  return 0;
}