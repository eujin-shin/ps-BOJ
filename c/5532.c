#include <stdio.h>

int main() {
  int L, A, B, C, D, math, korean;
  scanf("%d\n%d\n%d\n%d\n%d", &L, &A, &B, &C, &D);
  math = B/D;
  if(B%D!=0) {
    math++;
  }
  korean = A/C;
  if(A%C!=0) {
    korean++;
  }
  if(math>korean) {
    printf("%d\n", L-math);
  } else {
    printf("%d\n", L-korean);
  }
  return 0;
}