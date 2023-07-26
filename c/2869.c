#include <stdio.h>

int main() {
  int A, B, V, ans;
  scanf("%d %d %d", &A, &B, &V);
  if(A==V) {
    ans = 1;
  } else if((V-A)%(A-B)==0) {
    ans = (V-A)/(A-B)+1;
  } else {
    ans = (V-A)/(A-B)+2;
  }
  printf("%d\n", ans);
  return 0;
}