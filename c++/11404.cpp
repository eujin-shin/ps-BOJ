#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int floyd[102][102] = {0, };
  int n, m, x, y, temp;
  cin>>n>>m;
  for(int i=0; i<m; i++) {
    cin>>x>>y>>temp;
    if(floyd[x][y]==0 || floyd[x][y]>temp) floyd[x][y] = temp;
  }
  for(int pass=1; pass<=n; pass++) {
    for(int start=1; start<=n; start++) {
      x = floyd[start][pass];
      if(x==0) continue;
      for(int end=1; end<=n; end++) {
        y = floyd[pass][end];
        if(y==0 || start==end) continue;
        if(floyd[start][end]==0 || floyd[start][end]>x+y) {
          floyd[start][end] = x+y;
        }
      }
    }
  }
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      cout<<floyd[i][j];
      if(j!=n) cout<<' ';
    }
    cout<<'\n';
  }
  return 0;
}