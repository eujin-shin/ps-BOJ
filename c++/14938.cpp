#include <iostream>
#define INF 100
using namespace std;

int item[101]={0, }, map[101][101]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, r, a, b, l, tmp, max=0;
  cin>>n>>m>>r;
  for(int i=1; i<=n; i++) cin>>item[i];
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      map[i][j]=INF;
    }
  }
  for(int i=0; i<r; i++) {
    cin>>a>>b>>l;
    if(map[a][b]<=l) continue;
    map[a][b]=l; map[b][a]=l;
  }
  for(int v=1; v<=n; v++) {
    for(int j=1; j<=n; j++) {
      if(v==j) continue;
      for(int i=1; i<=n; i++) {
        if(i==v) continue;
        l=map[i][v]+map[v][i];
        if(map[i][j]<=l) continue;
        map[i][j]=l;
      }
    }
  }
  for(int i=1; i<=n; i++) {
    tmp = item[i];
    for(int j=1; j<=n; j++) {
      if(i==j) continue;
      if(map[i][j]<=m) tmp+=item[j];
    }
    if(max<tmp) max=tmp;
  }
  cout<<max<<'\n';
  return 0;
}