#include <stdio.h>

int rev(int n) {
  int ans = 0;
  while(n) {
    ans += n%10;
    n /= 10;
    if(n) {
      ans *= 10;
    }
  }
  return ans;
}

int main() {
  int x, y, xy;
  scanf("%d %d", &x, &y);
  xy = rev(x) + rev(y);
  printf("%d\n", rev(xy));
  return 0;
}