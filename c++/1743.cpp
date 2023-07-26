#include <iostream>
#include <queue>
using namespace std;

int mx[4]={0, 0, 1, -1};
int my[4]={1, -1, 0, 0};
int map[101][101]={0, };

int GetSize(int r, int c, int m, int n) {
  int size=0, nx, ny;
  queue <pair<int, int> > q;
  q.push(make_pair(r, c));
  map[r][c]=0;
  while(!q.empty()) {
    r=q.front().first; c=q.front().second;
    q.pop();
    size++;
    for(int i=0; i<4; i++) {
      nx=r+mx[i]; ny=c+my[i];
      if(nx>n || ny>m || nx<1 || ny<1) continue;
      if(map[nx][ny]==1) {
        map[nx][ny]=0;
        q.push(make_pair(nx, ny));
      }
    }
  }
  return size;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, k, r, c, max=0, temp;
  cin>>n>>m>>k;
  for(int i=0; i<k; i++) {
    cin>>r>>c;
    map[r][c]=1;
  }
  for(int r=1; r<=n; r++) {
    for(int c=1; c<=m; c++) {
      if(map[r][c]==1) {
        temp = GetSize(r, c, m, n);
        if(max<temp) max=temp;
      }
    }
  }
  cout<<max<<'\n';
  return 0;
}