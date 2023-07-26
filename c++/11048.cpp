#include <iostream>
using namespace std;

int GetLarge(int a, int b, int c) {
  int large;
  if(a>b) large = a; else large = b;
  if(large<c) large = c;
  return large;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int map[1002][1002] = {0, };
  int n, m, temp;
  cin>>n>>m;
  for(int y=1; y<=n; y++) {
    for(int x=1; x<=m; x++) {
      cin>>temp;
      temp += GetLarge(map[x-1][y], map[x][y-1], map[x-1][y-1]);
      map[x][y] = temp;
    }
  }
  cout<<map[m][n]<<'\n';
  return 0;
}