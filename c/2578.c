#include <stdio.h>

int main() {
  int position[27][4] = {0, };
  int bingo[6][6] = {0, };
  int temp, count, str, x, y;
  for(int i=1; i<6; i++) {
    for(int j=1; j<6; j++) {
      scanf("%d", &temp);
      position[temp][1] = i;
      position[temp][2] = j;
    }
  }
  count = 1;
  str = 0;
  for(int i=1; i<6; i++) {
    for(int j=1; j<6; j++, count++) {
      scanf("%d", &temp);
      x = position[temp][1];
      y = position[temp][2];
      bingo[x][y] = 1;
      str += 2;
      for(int h=1; h<6; h++) {
        if(!bingo[x][h]) {
          str--;
          break;
        }
      }
      for(int h=1; h<6; h++) {
        if(!bingo[h][y]) {
          str--;
          break;
        }
      }
      if(x+y==6) {
        str++;
        for(int h=1; h<6; h++) {
          if(!bingo[h][6-h]) {
            str--;
            break;
          }
        }
      }
      if(x==y) {
        str++;
        for(int h=1; h<6; h++) {
          if(!bingo[h][h]) {
            str--;
            break;
          }
        }
      }
      if(str>=3) {
        break;
      }
    }
    if(str>=3) {
      break;
    }
  }
  printf("%d\n", count);
  return 0;
}