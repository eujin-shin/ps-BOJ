#include <iostream>
#include <vector>
#include <queue>
#define pnt pair<int, int>
using namespace std;

vector <pnt> rules;
queue <pnt> q;
int map[1000][1000]={0, }, visit[1000][1000]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  int r, c, ans=-1;
  cin>>r>>c;
  for(int i=0; i<r; i++) {
    for(int j=0; j<c; j++) {
      cin>>map[i][j];
      if(i!=0) visit[i][j]=-1;
      else if(map[i][j]==1) q.push(make_pair(j, i));
    }
  }
  int n, x, y, nx, ny, d;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>y>>x;
    rules.push_back(make_pair(x, y));
  }
  while(!q.empty()) {
    x=q.front().first; y=q.front().second;
    if(y==r-1) {
      ans=visit[y][x]; break;
    }
    q.pop();
    d=visit[y][x]+1;
    for(int i=0; i<n; i++) {
      nx=x+rules[i].first;
      ny=y+rules[i].second;
      if(nx<0 || nx>=c || ny<0 || ny>=r) continue;
      if(map[ny][nx]==0 || (visit[ny][nx]>=0 && visit[ny][nx]<=d)) continue;
      q.push(make_pair(nx, ny));
      visit[ny][nx]=d;
    }
  }
  cout<<ans<<'\n';
  return 0;
}
