#include <stdio.h>

int main() {
  int m, n;
  scanf("%d %d", &m, &n);
  if(m<=n) {
    printf("%d\n", (m-1)*2);
  } else {
    printf("%d\n", (n-1)*2+1);
  }
  return 0;
}