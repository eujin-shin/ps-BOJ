#include <iostream>
using namespace std;

int map[1001][1001]={0, };

int main() {
  int r, c, q, x1, x2, y1, y2, tmp;
  cin>>r>>c>>q;
  for(int i=1; i<=r; i++) {
    for(int j=1; j<=c; j++) {
      cin>>map[i][j];
      map[i][j]+=map[i][j-1];
    }
  }
  for(int i=0; i<q; i++) {
    cin>>y1>>x1>>y2>>x2;
    tmp=0;
    for(int j=y1; j<=y2; j++) {
      tmp+=map[j][x2]-map[j][x1-1];
    }
    cout<<tmp/((y2-y1+1)*(x2-x1+1))<<'\n';
  }
  return 0;
}