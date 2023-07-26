#include <stdio.h>

int GetGcd(int x, int y) {
  int gcd, large = y, small = x;
  if(x>y) {
    large = x;
    small = y;
  }
  gcd = small;
  if(large%small) {
    gcd = GetGcd(small, large-small);
  }
  return gcd;
} 

int main() {
  int t, n;
  long long gcd;
  int num_arr[100] = {0, };
  long long ans_arr[100] = {0, };
  scanf("%d", &t);
  for(int i=0; i<t; i++) {
    gcd = 0;
    scanf("%d", &n);
    for(int j=0; j<n; j++) {
      scanf("%d", &num_arr[j]);
    }
    for(int j=0; j<n-1; j++) {
      for(int h=j+1; h<n; h++) {
        gcd += GetGcd(num_arr[j], num_arr[h]);
      }
    }
    ans_arr[i] = gcd;
  }
  for(int i=0; i<t; i++) {
    printf("%lld\n", ans_arr[i]);
  }
  return 0;
}