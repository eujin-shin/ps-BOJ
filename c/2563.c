#include <stdio.h>

int main() {
  int N;
  int space[101][101] = {0, };
  int ans = 0;
  scanf("%d", &N);
  for(int i=0; i<N; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    for(int i=0; i<10; i++) {
      for(int j=0; j<10; j++) {
        if(space[x+i][y+j]==0) {
          space[x+i][y+j]=1;
          ans += 1;
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}