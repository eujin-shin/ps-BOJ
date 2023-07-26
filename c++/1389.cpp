#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int map[102][102] = {0, };
  int n, m, x, y, k, min, ans = 1;
  cin>>n>>m;
  for(int i=0; i<m; i++) {
    cin>>x>>y;
    if(!map[x][y]) {
      map[x][y] = map[y][x] = 1;
      map[0][x] = map[0][x] + 1;
      map[0][y] = map[0][y] + 1;
    }
  }
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      if(j==i) {
        continue;
      }
      for(int h=1; h<=n; h++) {
        if(h==i || h==j) {
          continue;
        }
        if(map[j][i]!=0 && map[h][i]!=0) {
          k = map[j][i] + map[h][i];
          if(map[j][h]==0 || map[j][h]>k) {
            map[0][j] = map[0][j] - map[j][h] + k;
            map[0][h] = map[0][h] - map[j][h] + k;
            map[j][h] = map[h][j] = k;
          }
        }
      }
    }
  }
  min = map[0][1];
  for(int i=2; i<=n; i++) {
    if(map[0][i]<min) {
      min = map[0][i];
      ans = i;
    }
  }
  cout<<ans<<'\n';
  return 0;
}