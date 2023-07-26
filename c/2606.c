#include <stdio.h>

int main() {
  int graph[101][101] = {0, };
  int visit[101] = {0, 1, };
  int stack[100] = {1, };
  int n, cur, e, x, y, count;
  scanf("%d", &n);
  scanf("%d", &e);
  for(int i=0; i<e; i++) {
    scanf("%d %d", &x, &y);
    graph[x][y] = graph[y][x] = 1;
  }
  count = 0;
  x = 0; y = 1;
  while(x!=y) {
    cur = stack[x++];
    for(int i=1; i<=n; i++) {
      if(visit[i]==0 && graph[cur][i]) {
        count++;
        visit[i] = 1;
        stack[y] = i;
        y++;
      }
    }
  }
  printf("%d\n", count);
  return 0;
}