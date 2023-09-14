#include <iostream>
#include <queue>
using namespace std;

queue <int> q;
int org[300][300]={0, }, rot[300][300]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, r, cnt, tmp;
  cin>>n>>m>>r;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) cin>>org[i][j];
  }
  int minx=0, miny=0, maxx=m-1, maxy=n-1, curx, cury;
  while(minx<maxx && miny<maxy) {
    cnt=(maxx-minx)*2 + (maxy-miny)*2;
    tmp=cnt-(r%cnt);
    curx=minx; cury=miny;
    while(cury<=maxy) {
      q.push(org[cury][curx]); cury++;
    }
    cury--; curx++;
    while(curx<=maxx) {
      q.push(org[cury][curx]); curx++;
    }
    curx--; cury--;
    while(cury>=miny) {
      q.push(org[cury][curx]); cury--;
    }
    cury++; curx--;
    while(curx>minx) {
      q.push(org[cury][curx]); curx--;
    }
    for(int i=0; i<tmp; i++) {
      q.push(q.front()); q.pop();
    }
    curx=minx; cury=miny;
    while(cury<=maxy) {
      rot[cury][curx]=q.front(); q.pop(); cury++;
    }
    cury--; curx++;
    while(curx<=maxx) {
      rot[cury][curx]=q.front(); q.pop(); curx++;
    }
    curx--; cury--;
    while(cury>=miny) {
      rot[cury][curx]=q.front(); q.pop(); cury--;
    }
    cury++; curx--;
    while(curx>minx) {
      rot[cury][curx]=q.front(); q.pop(); curx--;
    }
    minx++; miny++; maxx--; maxy--;
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(j>0) cout<<' ';
      cout<<rot[i][j];
    }
    cout<<'\n';
  }
  return 0;
}