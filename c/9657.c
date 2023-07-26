#include <stdio.h>

// 1 2 3 4 5 6 7 8 9 10 11 12
// 2 1 2 1 1 1 1 2 1  2  1  1 

int main() {
  int n;
  scanf("%d", &n);
  if(n%7==1 || n%7==3) {
    printf("CY\n");
  } else {
    printf("SK\n");
  }
  return 0;
}