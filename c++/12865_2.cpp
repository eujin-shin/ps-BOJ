#include <iostream>
using namespace std;

typedef struct {
  int w, v;
} OBJ;

int map[100001][101]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  OBJ arr[101];
  int n, k, w, v;
  cin>>n>>k;
  for(int i=1; i<=n; i++) {
    cin>>arr[i].w>>arr[i].v;
  }
  for(int y=1; y<=n; y++) {
    for(int x=0; x<=k; x++) {
      w=arr[y].w; v=arr[y].v;
      map[x][y]=map[x][y-1];
      if(x>=w && map[x][y]<map[x-w][y-1]+v) map[x][y]=map[x-w][y-1]+v;
    }
  }
  cout<<map[k][n]<<'\n';
  return 0;
}