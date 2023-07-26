#include <stdio.h>

int main() {
  int n, m, min_6, min, temp1, temp2, price;
  scanf("%d %d", &n, &m);
  for(int i=0; i<m; i++) {
    scanf("%d %d", &temp1, &temp2);
    if(i==0) {
      min_6 = temp1;
      min = temp2;
    } else {
      if(min_6>temp1) {
        min_6 = temp1;
      }
      if(min>temp2) {
        min = temp2;
      }
    } 
  }
  if(min*6<=min_6) {
    price = min*n;
  } else {
    price = min_6*(n/6);
    if(n%6) {
      if(min_6<=(n%6)*min) {
        price += min_6;
      } else {
        price += (n%6)*min;
      }
    }
  } 
  printf("%d\n", price);
  return 0;
}