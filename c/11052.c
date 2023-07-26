#include <stdio.h>

int DP[1001] = {0, };
int cardset[1001] = {0, };

int main() {
  int n, max;
  scanf("%d", &n);
  for(int i=1; i<=n; i++) {
    scanf("%d", &cardset[i]);
    max = cardset[i];
    for(int j=i-1; j>=i/2; j--) {
      if(DP[j]+DP[i-j]>max) {
        max = DP[j] +DP[i-j];
      }
    }
    DP[i] = max;
  }
  printf("%d\n", DP[n]);
  return 0;
}