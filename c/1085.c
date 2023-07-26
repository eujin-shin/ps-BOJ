#include <stdio.h>

int main() {
  int x, y, w, h;
  int distanceArr[4];
  scanf("%d %d %d %d", &x, &y, &w, &h);
  distanceArr[0]=x; distanceArr[1]=y;
  distanceArr[2]=w-x; distanceArr[3]=h-y;
  int n = distanceArr[0];
  for(int i=0; i<3; i++) {
    if(n>distanceArr[i+1]) {
      n=distanceArr[i+1];
    }
  }
  printf("%d\n", n);
  return 0;
}