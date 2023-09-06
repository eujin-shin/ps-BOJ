#include <iostream>
#include <string>
using namespace std;

int cnt=0, r, c, k;
int xm[4]={0, 0, -1, 1};
int ym[4]={1, -1, 0, 0};
int visit[5][5]={0, };

void DFS(int s, int x, int y) {
  if(s==k) {
    if(x==c-1 && y==0) cnt++;
    return;
  }
  int nx, ny;
  for(int i=0; i<4; i++) {
    nx=x+xm[i]; ny=y+ym[i];
    if(nx<0 || nx>=c || ny<0 || ny>=r) continue;
    if(visit[ny][nx]!=0) continue;
    visit[ny][nx]=1;
    DFS(s+1, nx, ny);
    visit[ny][nx]=0;
  }
  return;
}

int main() {
  string st;
  cin>>r>>c>>k;
  for(int i=0; i<r; i++) {
    cin>>st;
    for(int j=0; j<c; j++) {
      if(st[j]=='T') visit[j][i]=1;
    }
  }
  visit[r-1][0]=1;
  DFS(1, 0, r-1);
  cout<<cnt<<'\n';
  return 0;
}