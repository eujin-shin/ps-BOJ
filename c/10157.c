#include <stdio.h>

int main() {
  int x, y, num, i_x, i_y, count, ver, hor;
  int seats[1010][1010] = {0, };
  scanf("%d %d", &x, &y);
  scanf("%d", &num);
  i_x = 1; i_y = 1;
  ver = y-1; hor = x-1;
  count = 1;
  if(num<=x*y) {
    while(count<num) {
      if(num-count<=ver) {
        i_y += num-count;
        break;
      }
      i_y += ver;
      count += ver;
      if(num-count<=hor) {
        i_x += num-count;
        break;
      }
      i_x += hor;
      count += hor;
      if(num-count<=ver) {
        i_y -= num-count;
        break;
      }
      i_y -= ver;
      count += ver;
      if(num-count<=hor-1) {
        i_x -= num-count;
        break;
      }
      i_x -= hor-1;
      i_y += 1;
      count += hor;
      hor-=2;
      ver-=2;
    }
    printf("%d %d\n", i_x, i_y);
  } else {
    printf("0\n");
  }
  return 0;
}