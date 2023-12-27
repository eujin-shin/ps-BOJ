#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int map[401][401]={0, };
  int n, k, s, a, b;
  cin>>n>>k;
  for(int i=0; i<k; i++) {
    cin>>a>>b;
    map[a][b]=-1; map[b][a]=1;
  }
  for(int v=1; v<=n; v++) {
    for(int y=1; y<=n; y++) {
      for(int x=1; x<=n; x++) {
        if(map[x][v]==0 || map[y][v]==0) continue;
        if(map[x][v]==map[v][y]) map[x][y]=map[x][v];
        if(map[y][v]==map[v][x]) map[y][x]=map[y][v];
      }
    }
  }
  cin>>s;
  for(int i=0; i<s; i++) {
    cin>>a>>b;
    cout<<map[a][b]<<'\n';
  }
  return 0;
}