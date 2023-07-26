#include <stdio.h>

int main () {
  int D, H, W;
  scanf("%d %d %d", &D, &H, &W);
  int x = H + W;
  int ansH = D*H/x;
  int ansW = D*W/x;
  printf("%d %d", ansH, ansW);
  return 0;
}