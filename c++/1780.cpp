#include <iostream>
using namespace std;

int map[2500][2500] = {0, };

void Go(int x, int y, int l) {
  int k = map[y][x], flag = 1;
  for(int i=y; i<y+l; i++) {
    for(int j=x; j<x+l; j++) {
      if(map[i][j]!=k) {
        flag = 0;
        break;
      }
    }
  }
  if(flag) {
    map[0][k+1] = map[0][k+1] + 1;
  } else {
    l/=3;
    Go(x, y, l);
    Go(x+l, y, l);
    Go(2*l+x, y, l);
    Go(x, y+l, l);
    Go(x+l, y+l, l);
    Go(2*l+x, y+l, l);
    Go(x, 2*l+y, l);
    Go(x+l, 2*l+y, l);
    Go(2*l+x, 2*l+y, l);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      cin>>map[i][j];
    }
  }
  Go(1, 1, n);
  cout<<map[0][0]<<'\n'<<map[0][1]<<'\n'<<map[0][2]<<'\n';
  return 0;
}