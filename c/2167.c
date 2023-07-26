#include <stdio.h>

int main() {
  int N, M, k, i, j, x, y;
  scanf("%d %d", &N, &M);
  int num_set[N+2][M+2];
  for(int a=1; a<=N; a++) {
    for(int b=1; b<=M; b++) {
      scanf("%d", &num_set[a][b]);
    }
  }
  scanf("%d", &k);
  int ans_set[k];
  for(int a=0; a<k; a++) {
    int ans = 0;
    scanf("%d %d %d %d", &i, &j, &x, &y);
    int index_x = i;
    int index_y = j;
    while(1) {
      ans += num_set[index_x][index_y];
      if(index_x==x && index_y==y) {
        break;
      }
      index_y += 1;
      if(index_y>y) {
        index_y = j;
        index_x++;
      }
    }
    ans_set[a] = ans;
  }
  for(int a=0; a<k; a++) {
    printf("%d\n", ans_set[a]);
  }
  return 0;
}