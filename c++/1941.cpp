#include <iostream>
#include <string>
#include <queue>
#define pnt pair<int, int>
using namespace std;

int map[5][5]={0, };
int xm[4]={0, 0, 1, -1};
int ym[4]={1, -1, 0, 0};
queue <pnt> q;


int btr(int x, int y, int c, int r) {
  if(r==7) {
    if(c>3) return 1;
    else return 0;
  }
  int nx, ny, ret=0, temp;
  temp=map[x][y]; map[x][y]=-1;
  for(int i=0; i<4; i++) {
    nx=x+xm[i]; ny=y+ym[i];
    if(nx<0 || ny<0 || nx>4 || ny>4) continue;
    if(map[nx][ny]==1) ret+=btr(nx, ny, c+1, r+1);
    else if(map[nx][ny]) ret+=btr(nx, ny, c, r+1);
  }
  map[x][y]=temp;
  return ret;
}

int main() {
  string in;
  int count=0, x, y;
  for(int y=0; y<5; y++) {
    cin>>in;
    for(int x=0; x<5; x++) {
      if(in[x]=='Y') continue;
      map[x][y]=1;
    }
  }
  for(int y=0; y<5; y++) {
    for(int x=0; x<5; x++) {
      count+=btr(x, y, map[x][y], 1);
    }
  }
  cout<<count<<'\n';
  return 0;
}