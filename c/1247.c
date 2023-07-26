#include <stdio.h>

int main() {
  long long sum;
  char ans_set[4];
  int n, x;
  for(int i=0; i<3; i++) {
    sum = 0;
    scanf("%d", &n);
    for(int j=0; j<n; j++) {
      scanf("%d", &x);
      sum += x;
    }
    if(sum<0) {
      ans_set[i] = '-';
    } else if(sum>0) {
      ans_set[i] = '+';
    } else {
      ans_set[i] = '0';
    }
  }
  for(int i=0; i<3; i++) {
    printf("%c\n", ans_set[i]);
  }
  return 0;
}