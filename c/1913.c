#include <stdio.h>

int main() {
  int snail[1000][1000] = {0, };
  int n, k, x, y, count, count_2, way, x_k, y_k;
  scanf("%d", &n);
  scanf("%d", &k);
  way = 1;
  x = 1;
  y = n;
  for(int i=n*n; i>0; i++) {
    snail[y][x] = i;
    if(i==k) {
      y_k = y;
      x_k = x;
    }
    count++;
    if(count>count_2)
    switch (way%4)
    {
    case 1:
      /* code */
      break;
    
    default:
      break;
    }
  }
}