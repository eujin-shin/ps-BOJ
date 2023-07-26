#include <stdio.h>

int main() {
  int n, x, count[10001] = {0, };
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d", &x);
    count[x]++;
  }
  for(int i=1; i<10001; i++) {
    for(int j=0; j<count[i]; j++) {
      printf("%d\n", i);
    }
  }
  return 0;
}