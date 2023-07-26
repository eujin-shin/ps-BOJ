#include <stdio.h>

int main() {
  long long aptArr[16][16] = {0, };
  int T, k, n, x;
  x=1;
  for(int i=1; i<15; i++) {
    aptArr[0][i]=i;
  }
  for(int i=1; i<15; i++) {
    for(int j=1; j<15; j++) {
      for(int k=1; k<=j; k++) {
        aptArr[i][j]+=aptArr[i-1][k];
      }
    }
  }
  scanf("%d", &T);
  for(int i=0; i<T; i++) {
    scanf("%d\n%d", &k, &n);
    printf("%d\n", aptArr[k][n]);
  }
  return 0;
}