#include <iostream>
#include <queue>
#define pnt pair<int, int>
using namespace std;

int map[200][200]={0, };
int mr[6]={-2, -2, 0, 0, 2, 2};
int mc[6]={-1, 1, -2, 2, -1, 1};

int main() {
  int n, r, c, nr, nc, er, ec;
  cin>>n>>r>>c>>er>>ec;
  queue <pnt> q;
  q.push(make_pair(r, c)); map[r][c]=1;
  int level=0, now=1, next=0, flag=-1;
  while(!q.empty()) {
    r=q.front().first; c=q.front().second;
    q.pop();
    if(r==er && c==ec) {
      flag=1; break;
    }
    for(int i=0; i<6; i++) {
      nr=r+mr[i]; nc=c+mc[i];
      if(nr>=n || nc>=n || nr<0 || nc<0) continue;
      if(map[nr][nc]==0) {
        map[nr][nc]=1; next++;
        q.push(make_pair(nr, nc));
      }
    }
    now--;
    if(now==0) {
      now=next; next=0; level++;
    }
  }
  if(flag<0) cout<<flag<<'\n';
  else cout<<level<<'\n';
  return 0;
}