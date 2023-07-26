#include <stdio.h>
#include <math.h>

int CheckPrime(int n) {
  int ans = 1;
  for(int i=2; i<=sqrt(n); i++) {
    if(n%i==0) {
      ans = 0;
      break;
    }
  }
  return ans;
}

int main() {
  int m, n;
  scanf("%d %d", &m, &n);
  if(m>2 && m%2==0) {
    m++;
  }
  for(int i=m; i<=n; i+=2) {
    if(i<3) {
      printf("2\n");
      i = 1;
    } else if(CheckPrime(i)) {
      printf("%d\n", i);
    }
  }
  return 0;
}