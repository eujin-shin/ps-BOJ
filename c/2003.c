#include <stdio.h>

int main() {
  int n, m, sum, count, x;
  int A[10001] = {0, };
  scanf("%d %d", &n, &m);
  sum = 0;
  for(int i=0; i<n; i++) {
    scanf("%d", &A[i]);
    sum += A[i];
  }
  count = 0;
  for(int i=0; i<n; i++) {
    x = 0;
    if(sum<m) {
      break;
    } else if(sum==m) {
      count++;
      break;
    } else {
      for(int j=i; j<n; j++) {
        x += A[j];
        if(x==m) {
          count++;
          break;
        } else if(x>m) {
          break;
        }
      }
    }
    sum -= A[i];
  }
  printf("%d\n", count);
  return 0;
}