#include <iostream>
#define MOD 100000
using namespace std;

int map[5][5][110][110]={0, };

int getVal(int c, int d, int y, int x) {
  if(y==1 && x==1) {
    if(c==0) return 1;
    else return 0;
  }
  if(y==0 || x==0) return 0;
  int v=map[0][d][y][x];
  if(c==0) v+=+map[1][d][y][x];
  return v%MOD;
}

int main() {
  int w, h, y;
  cin>>w>>h;
  for(int i=3; i<=w+h; i++) {
    for(int x=1; x<i; x++) {
      y=i-x;
      map[0][0][y][x]=getVal(0, 0, y-1, x);
      map[1][0][y][x]=getVal(1, 1, y-1, x);
      map[0][1][y][x]=getVal(0, 1, y, x-1);
      map[1][1][y][x]=getVal(1, 0, y, x-1);
    }
  }
  cout<<(map[0][0][h][w]+map[0][1][h][w]+map[1][0][h][w]+map[1][1][h][w])%MOD<<'\n';
  return 0;
}