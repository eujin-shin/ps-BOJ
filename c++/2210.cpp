#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;
int map[5][5]={0, };
int xm[4]={1, 0, -1, 0}, ym[4]={0, 1, 0, -1};

void Jump(int r, int k, int x, int y) {
  if(r==6) {
    v.push_back(k); return;
  }
  int nx, ny;
  for(int i=0; i<4; i++) {
    nx=x+xm[i]; ny=y+ym[i];
    if(ny<0 || ny>4 || nx<0 || nx>4) continue;
    Jump(r+1, k*10+map[nx][ny], nx, ny);
  }
  return;
}

int main() {
  for(int i=0; i<5; i++) {
    for(int j=0; j<5; j++) {
      cin>>map[i][j];
    }
  }
  for(int i=0; i<5; i++) {
    for(int j=0; j<5; j++) {
      Jump(1, map[i][j], i, j);
    }
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  cout<<v.size()<<'\n';
  return 0;
}