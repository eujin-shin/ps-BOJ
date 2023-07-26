#include <stdio.h>

int main() {
  int Coord[102][102] = {0, };
  int x1, x2, y1, y2, ans;
  ans=0;
  for(int i=0; i<4; i++) {
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    for(int k=x1; k<x2; k++) {
      for(int j=y1; j<y2; j++) {
        if(Coord[k][j]==0) {
          Coord[k][j]=1;
          ans+=1;
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}