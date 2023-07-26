#include <stdio.h>

int B_result[1000] = {0, };
int history[1001] = {0, };


void DFS(int graph[][1100], int v, int n) {
  int p = v;
  history[p] = 1;
  printf("%d ", p);
  for(int i=1; i<=n; i++) {
    if(graph[p][i] && history[i]==0) {
      DFS(graph, i, n);
    }
  }
  return;
}

int BFS(int graph[][1100], int v, int n) {
  int history[1001] = {0, };
  int x = 0, y = 0, p = v, flag;
  history[p] = 1;
  B_result[y] = p;
  y++;
  while(1) {
    p = B_result[x];
    for(int i=1; i<=n; i++) {
      if(graph[p][i] && history[i]==0) {
        B_result[y] = i;
        y++;
        history[i] = 1;
      }
    }
    x++;
    if(x==y) {
      break;
    }
  }
  return y;
}

int main() {
  int n, m, v, x, y;
  int graph[1100][1100] = {0, };
  scanf("%d %d %d", &n, &m, &v);
  for(int i=0; i<m; i++) {
    scanf("%d %d", &x, &y);
    graph[x][y] = 1;
    graph[y][x] = 1;
  }
  DFS(graph, v, n);
  printf("\n");
  y = BFS(graph, v, n);
  for(int i=0; i<y; i++) {
    printf("%d", B_result[i]);
    if(i==y-1) {
      printf("\n");
    } else {
      printf(" ");
    }
  }
  return 0;
}