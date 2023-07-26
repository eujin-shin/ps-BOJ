#include <iostream>
#include <queue>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  queue <int> xq;
  queue <int> yq;
  int map[1002][1002] = {0, };
  int m, n, all, next, cur, r, tom, x, y;
  cin>>m>>n;
  all = m*n; tom = next = 0;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) {
      cin>>map[j][i];
      if(map[j][i]==1) {
        tom++; next++;
        xq.push(j); yq.push(i);
      } else if(map[j][i]==-1) {
        all--;
      }
    }
  }
  cur = next; next = 0; r = 1;
  if(all==tom) {
    r = 0;
  }
  while(!xq.empty() && tom<all) {
    if(cur==0) {
      cur = next;
      next = 0;
      r++;
    }
    x = xq.front(); xq.pop();
    y = yq.front(); yq.pop();
    if(x>1 && map[x-1][y]==0) {
      map[x-1][y] = 1;
      tom++; next++;
      xq.push(x-1); yq.push(y);
    }
    if(x<m && map[x+1][y]==0) {
      map[x+1][y] = 1;
      tom++; next++;
      xq.push(x+1); yq.push(y);
    }
    if(y>1 && map[x][y-1]==0) {
      map[x][y-1] = 1;
      tom++; next++;
      xq.push(x); yq.push(y-1);
    }
    if(y<n && map[x][y+1]==0) {
      map[x][y+1] = 1;
      tom++; next++;
      xq.push(x); yq.push(y+1);
    }
    cur--;
  }
  if(tom==all) {
    cout<<r<<'\n';
  } else {
    cout<<"-1\n";
  }
  return 0;
}