#include <stdio.h>

int money[100000] = {-1, -1, 1, -1, 2, 1, };

int GetCoin(int n) {
  if(!money[n]) {
    int n_2, n_5;
    n_2 = GetCoin(n-2);
    n_5 = GetCoin(n-5);
    if(n_2==-1 && n_5==-1) {
      money[n] = -1;
    } else if(n_2==-1) {
      money[n] = n_5 + 1;
    } else if(n_5==-1) {
      money[n] = n_2 + 1;
    } else if(n_5<n_2) {
      money[n] = n_5 + 1;
    } else {
      money[n] = n_2 + 1;
    }
  }
  return money[n];
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", GetCoin(n));
  return 0;
}