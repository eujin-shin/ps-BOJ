#include <stdio.h>

int main() {
  int x, count;
  scanf("%d", &x);
  x = 1000-x;
  count = 0;
  while(x>=500) {
    x-=500;
    count++;
  }
  while(x>=100) {
    x-=100;
    count++;
  }
  while(x>=50) {
    x-=50;
    count++;
  }
  while(x>=10) {
    x-=10;
    count++;
  }
  while(x>=5) {
    x-=5;
    count++;
  }
  while (x>=1) {
    x-=1;
    count++;
  }
  printf("%d", count);
  return 0;
}