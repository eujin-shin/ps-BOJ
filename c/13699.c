#include <stdio.h>

long long num_arr[36] = {1, };

long long GetNum(int n) {
  long long num;
  if(!num_arr[n]) {
    num = 0;
    if(n%2) {
      for(int i=0; i<n/2; i++) {
        num += (GetNum(i) * GetNum(n-1-i))*2;
      }
      num += GetNum(n/2) * GetNum(n/2);
    } else {
      for(int i=0; i<n/2; i++) {
        num += (GetNum(i) * GetNum(n-1-i))*2;
      }
    }
    num_arr[n] = num;
  }
  return num_arr[n];
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%lld\n", GetNum(n));
  return 0;
}