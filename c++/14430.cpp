#include <iostream>
using namespace std;

#define max(x, y) (((x)>(y)) ? (x):(y))

int map[301][301]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin>>map[i][j];
    }
  }
  for(int i=n-1; i>=0; i--) {
    for(int j=m-1; j>=0; j--) {
      map[i][j]+=max(map[i+1][j], map[i][j+1]);
    }
  }
  cout<<map[0][0]<<'\n';
  return 0;
}