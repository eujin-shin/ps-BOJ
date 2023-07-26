#include <stdio.h>

int main() {
  int a, b, sum, num, cycle;
  scanf("%d %d", &a, &b);
  num = 0;
  sum = 0;
  while(sum<a) {
    num++;
    sum+=num;
  }
  cycle = sum-a+1;
  sum=0;
  while(a<=b) {
    sum+=num;
    cycle--;
    a++;
    if(cycle==0) {
      num++;
      cycle=num;
    }
  }
  printf("%d\n", sum);
  return 0;
}