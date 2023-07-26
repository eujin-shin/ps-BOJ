#include <iostream>
#include <string>
using namespace std;

int map[100][100]={0, }, m[8]={1, -1, 0, 0, 1, -1, 0, 0};
int h, w;

void GetC(int x, int y) {
  int nx, ny;
  map[y][x]=0;
  for(int i=0; i<4; i++) {
    nx=x+m[i]; ny=y+m[7-i];
    if(nx>=w || nx<0 || ny>=h || ny<0) continue;
    if(map[ny][nx]==1) GetC(nx, ny);
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  int t, s;
  string line;
  cin>>t;
  while(t--) {
    cin>>h>>w; s=0;
    for(int i=0; i<h; i++) {
      cin>>line;
      for(int j=0; j<w; j++) {
        if(line[j]=='#') map[i][j]=1;
      }
    }
    for(int i=0; i<h; i++) {
      for(int j=0; j<w; j++) {
        if(map[i][j]==0) continue;
        s++; GetC(j, i);
      }
    }
    cout<<s<<'\n';
  }
  return 0;
}