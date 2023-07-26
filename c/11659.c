#include <stdio.h>

int main() {
  int n, m, x, y, temp;
  int num_arr[100001] = {0, };
  scanf("%d %d", &n, &m);
  for(int i=1; i<=n; i++) {
    scanf("%d", &temp);
    num_arr[i] = num_arr[i-1] + temp;
  }
  for(int i=0; i<m; i++) {
    scanf("%d %d", &x, &y);
    printf("%d\n", num_arr[y]-num_arr[x-1]);
  }
  return 0;
}