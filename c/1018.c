#include <stdio.h>

int chess[51][51];

int CheckChess(int x, int y) {
  int sum=0;
  for(int i=0; i<8; i++) {
    for(int j=0; j<8; j++) {
      if(i%2+j%2==1) {
        sum += 0 ^ chess[i+x][j+y];
      } else {
        sum += 1 ^ chess[i+x][j+y];
      }
    }
  }
  if(sum<32) {
    return sum;
  }
  return 64-sum;
}

int main() {
  int n, m, chess_num, min;
  char low[51];
  scanf("%d %d", &n, &m);
  for(int i=0; i<n; i++) {
    scanf("%s", low);
    for(int j=0; j<m; j++) {
      if(low[j]=='W') {
        chess[i][j] = 0;
      } else {
        chess[i][j] = 1;
      }
    }
  }
  for(int i=0; i<=n-8; i++) {
    for(int j=0; j<=m-8; j++) {
      chess_num = CheckChess(i, j);
      if(min>chess_num) {
        min = chess_num;
      }
    }
  }
  printf("%d\n", min);
  return 0;
}