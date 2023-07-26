#include <stdio.h>

int main() {
  int n, l, temp;
  int fruits[10001] = {0, };
  scanf("%d %d", &n, &l);
  for(int i=0; i<n; i++) {
    scanf("%d", &temp);
    fruits[temp] = fruits[temp] + 1;
  }
  for(int i=1; i<=l; i++) {
    l += fruits[i];
  }
  printf("%d\n", l);
  return 0;
}