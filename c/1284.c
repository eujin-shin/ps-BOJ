#include <stdio.h>

int main() {
  while(1) {
    int N, ans, x, index;
    ans = 0;
    scanf("%d", &N);
    if(N==0) {
      break;
    } else {
      x = N;
      index = 0;
      while(x) {
        if(x%10==0) {
          ans += 4;
        } else if(x%10==1) {
          ans += 2;
        } else {
          ans += 3;
        }
        index ++;
        x /= 10;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}