#include <iostream>
using namespace std;

int map[401][401]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  int v, e, a, b, c, min=-1;
  cin>>v>>e;
  for(int i=0; i<e; i++) {
    cin>>a>>b>>c;
    map[a][b]=c;
  }
  for(int i=1; i<=v; i++) {
    for(int j=1; j<=v; j++) {
      if(j==i || map[j][i]==0) continue;
      for(int h=1; h<=v; h++) {
        if(h==i || map[i][h]==0) continue;
        if(map[j][h]==0 || map[j][h]>map[j][i]+map[i][h]) {
          map[j][h]=map[j][i]+map[i][h];
          if(j==h) {
            if(min<0 || min>map[j][h]) min=map[j][h];
          }
        }
      }
    }
  }
  cout<<min<<'\n';
  return 0;
}