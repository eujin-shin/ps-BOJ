#include <stdio.h>

int main() {
  int n, check, ans, num;
  scanf("%d", &n);
  while(1) {
    check = 1;
    num = n;
    while(num) {
      if(num%10!=4 && num%10!=7) {
        check = 0;
        break;
      }
      num /= 10;
    }
    if(check == 1) {
      ans = n;
      break;
    }
    n--;
  }
  printf("%d\n", ans);
  return 0;
}