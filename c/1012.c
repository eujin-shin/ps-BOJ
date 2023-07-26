#include <stdio.h>

int map[52][52] = {0, };

void DFS(int x, int y, int visited[][52]) {
  visited[x][y] = 1;
  if(visited[x+1][y]==0 && map[x+1][y]) {
    DFS(x+1, y, visited);
  }
  if(visited[x][y+1]==0 && map[x][y+1]) {
    DFS(x, y+1, visited);
  }
  if(x>0) {
    if(visited[x-1][y]==0 && map[x-1][y]) {
      DFS(x-1, y, visited);
    }
    if(visited[x][y-1]==0 && map[x][y-1]) {
      DFS(x, y-1, visited);
    }
  }
  map[x][y] = 0;
}

int main() {
  int t, m, n, k, x, y, count;
  scanf("%d", &t);
  for(int i=0; i<t; i++) {
    count = 0;
    int visited[52][52] = {0, };
    scanf("%d %d %d", &m, &n, &k);
    for(int j=0; j<k; j++) {
      scanf("%d %d", &x, &y);
      map[x][y] = 1;
    }
    for(int x=0; x<m; x++) {
      for(int y=0; y<n; y++) {
        if(map[x][y] && visited[x][y]==0) {
          DFS(x, y, visited);
          count++;
        }
      }
    }
    printf("%d\n", count);
  }
  return 0;
}