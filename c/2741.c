#include <stdio.h>

int RepeatWrite(int n) {
  for(int i=1; i<=n; i++) {
    printf("%d\n", i);
  }
  return 0;
}

int main() {
  int n;
  scanf("%d", &n);
  RepeatWrite(n);
  return 0;
}