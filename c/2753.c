#include <stdio.h>

int year(int n) {
  if(n%4==0) {
    if(n%100!=0 || n%400==0) {
      return 1;
    } else {
      return 0;
    }
  } else {
    return 0;
  }
}

int main() {
  int a;
  scanf("%d", &a);
  int result = year(a);
  printf("%d\n", result);
  return 0;
}