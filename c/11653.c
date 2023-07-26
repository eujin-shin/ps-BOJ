#include <stdio.h>

int main() {
  int N, a;
  a = 2;
  scanf("%d", &N);
  while(N>1) {
    if(N%a==0) {
      N/=a;
      printf("%d\n", a);
    } else {
      a++;
    }
  }
  return 0;
}