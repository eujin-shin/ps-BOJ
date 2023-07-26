#include <stdio.h>

int main() {
  int n, count, k;
  scanf("%d", &n);
  count = 1;
  if(n>2 && n%2) {
    count++;
  }
  for(int i=3; i*i/2<n; i+=2) {
    if(!(n%i)) {
      count++;
    } 
  }
  for(int i=4; i<n; i+=2) {
    k = n-(i/2);
    if(k/i<i/2) {
      break;
    }
    if(!(k%i)) {
      count++;
    }
  }
  printf("%d\n", count);
  return 0;
}