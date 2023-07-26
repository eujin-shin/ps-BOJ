#include <stdio.h>

int Compare(int a, int b) {
  int n = a-b;
  if(n<0) {
    printf("<\n");
  } else if(n>0) {
    printf(">\n");
  } else {
    printf("==\n");
  }
  return 0;
}

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  Compare(a, b);
  return 0;
}