#include <iostream>
using namespace std;

int map[2][20][20]={0, };

bool Check(int k) {
  int cnt;
  for(int i=1; i<20; i++) {
    cnt=0;
    for(int j=1; j<20; j++) {
      if(map[k][i][j]==1) cnt++;
      else if(cnt==5) return true;
      else cnt=0;
    }
    if(cnt==5) return true;
    cnt=0;
    for(int j=1; j<20; j++) {
      if(map[k][j][i]==1) cnt++;
      else if(cnt==5) return true;
      else cnt=0;
    }
    if(cnt==5) return true;
  }
  for(int i=5; i<20; i++) {
    cnt=0;
    for(int x=i, y=1; x>0; x--, y++) {
      if(map[k][y][x]==1) cnt++;
      else if(cnt==5) return true;
      else cnt=0;
    }
    if(cnt==5) return true;
    cnt=0;
    for(int y=19, x=i; x>0; y--, x--) {
      if(map[k][y][x]==1) cnt++;
      else if(cnt==5) return true;
      else cnt=0;
    }
  }
  for(int i=1; i<16; i++) {
    cnt=0;
    for(int y=i, x=19; y<20; y++, x--) {
      if(map[k][y][x]==1) cnt++;
      else if(cnt==5) return true;
      else cnt=0;
    }
    if(cnt==5) return true;
    cnt=0;
    for(int y=i, x=1; y<20; y++, x++) {
      if(map[k][y][x]==1) cnt++;
      else if(cnt==5) return true;
      else cnt=0;
    }
    if(cnt==5) return true;
  }
  return false;
}

int main() {
  int n, x, y, ans=-1;
  cin>>n;
  for(int i=1; i<=n; i++) {
    cin>>y>>x;
    map[i%2][y][x]=1;
    if(ans>0) continue;
    else if(Check(i%2)) ans=i;
  }
  cout<<ans<<'\n';
  return 0;
}