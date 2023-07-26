#include <stdio.h>

int main() {
  int n, max, x, count;
  int ans_set[3];
  for(int i=0; i<3; i++) {
    scanf("%d", &n);
    count = 0;
    max = 1;
    x = 10;
    for(int j=0; j<8; j++) {
      if(x==n%10) {
        count++;
      } else {
        if(max<count) {
          max = count;
        }
        x = n%10;
        count = 1;
      }
      n /= 10;
    }
    if(count>max) {
      max = count;
    }
    ans_set[i] = max;
  }
  for(int i=0; i<3; i++) {
    printf("%d\n", ans_set[i]);
  }
  return 0;
}