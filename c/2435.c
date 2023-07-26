#include <stdio.h>

int main() {
  int tem[100] = {0, };
  int n, k, temp, max;
  scanf("%d %d", &n, &k);
  for(int i=0; i<n; i++) {
    scanf("%d", &tem[i]);
  }
  for(int i=0; i<=n-k; i++) {
    temp = 0;
    for(int j=0; j<k; j++) {
      temp += tem[i+j];
    }
    if(i==0) {
      max = temp;
    } else if(max<temp) {
      max = temp;
    }
  }
  printf("%d\n", max);
  return 0;
}