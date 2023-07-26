#include <iostream>
#include <queue>
using namespace std;
queue<int>xq;
queue<int>yq;

int history[105][105] = {0, };
int map[105][105] = {0, };

int FindWay(int n, int m) {
  int r=1, x, y, before=1, next=0;
  xq.push(1); yq.push(1);
  while(!xq.empty()) {
    x = xq.front();
    y = yq.front();
    xq.pop();
    yq.pop();
    if(x==n && y==m) {
      break;
    }
    if(map[x-1][y] && history[x-1][y]==0) {
      xq.push(x-1);
      yq.push(y);
      history[x-1][y]=1;
      next++;
    }
    if(map[x][y-1] && history[x][y-1]==0) {
      xq.push(x);
      yq.push(y-1);
      history[x][y-1]=1;
      next++;
    }
    if(map[x+1][y] && history[x+1][y]==0) {
      xq.push(x+1);
      yq.push(y);
      history[x+1][y]=1;
      next++;
    }
    if(map[x][y+1] && history[x][y+1]==0) {
      xq.push(x);
      yq.push(y+1);
      history[x][y+1]=1;
      next++;
    }
    before--;
    if(before==0) {
      before = next;
      next = 0;
      r++;
    }
  }
  return r;
}

int main() {
  int n, m, count;
  cin>>n>>m;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) {
      scanf("%1d", &map[i][j]);
    }
  }
  count = FindWay(n, m);
  cout<<count<<endl;
  return 0;
}