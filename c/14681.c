#include <stdio.h>

int Quadrant(int x, int y) {
  if(x>0) {
    if(y>0) {
      return 1;
    } else {
      return 4;
    }
  } else {
    if (y>0) {
      return 2;
    } else {
      return 3;
    }
  }
}

int main() {
  int x, y;
  scanf("%d\n%d", &x, &y);
  printf("%d\n", Quadrant(x, y));
  return 0;
}