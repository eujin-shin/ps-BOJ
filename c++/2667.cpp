#include <iostream>
using namespace std;

int map[26][26] = {0, };

void DFS(int x, int y) {
  map[0][0] = map[0][0]+1;
  map[x][y] = 0;
  if(map[x+1][y]) {
    DFS(x+1, y);
  }
  if(map[x][y+1]) {
    DFS(x, y+1);
  }
  if(x>0 && map[x-1][y]) {
    DFS(x-1, y);
  }
  if(y>0 && map[x][y-1]) {
    DFS(x, y-1);
  }
  return;
}

int Cmp(const void *a, const void *b) {
  return *(int *)a-*(int *)b;
}

int main() {
  int n, x=-1;
  int count[400] = {0, };
  cin>>n;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      scanf("%1d", &map[i][j]);
    }
  }
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      if(map[i][j]) {
        map[0][0] = 0;
        DFS(i, j);
        count[++x] = map[0][0];
      }
    }
  }
  cout<<++x<<endl;
  qsort(count, x, sizeof(int), Cmp);
  for(int i=0; i<x; i++) {
    cout<<count[i]<<"\n";
  }
  return 0;
}