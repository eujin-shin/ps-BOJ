#include <stdio.h>

long long Sum(int A, int B) {
  long long sum = (A+B)*(A-B+1)/2;
  return sum;
}

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  if(a>b) {
    b = (-2)*b+1;
    printf("%d\n", b);
    printf("%lld\n", Sum(a, b));
  } else {
    printf("%lld\n", Sum(b, a));
  }
  return 0;
}