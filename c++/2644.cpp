#include <iostream>
#include <queue>
using namespace std;


int map[102][102] = {0, };

int main() {
  queue <int> q;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, x, y, m, a, b;
  cin>>n>>a>>b>>m;
  for(int i=0; i<m; i++) {
    cin>>x>>y;
    map[x][y] = map[y][x] = 1;
  }
  int cur, count = 1, ans = -1;
  x = 1; y = 0;
  q.push(a);
  while(!q.empty()) {
    cur = q.front();
    q.pop();
    x--;
    for(int i=1; i<=n; i++) {
      if(map[cur][i]) {
        q.push(i);
        map[cur][i] = 0;
        y++;
        if(i==b) {
          ans = count;
          break;
        }
      }
    }
    if(x==0) {
      x = y;
      count++;
      y = 0;
    }
    if(ans!=-1) {
      break;
    }
  }
  cout<<ans<<endl;
  return 0;
}