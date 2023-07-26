#include <iostream>
using namespace std;

int map[101][21]={0, }, v[21]={0, }, w[21]={0, };

int main() {
  int n, x, y;
  cin>>n;
  for(int i=1; i<=n; i++) cin>>w[i];
  for(int i=1; i<=n; i++) cin>>v[i];
  for(int i=1; i<=100; i++) {
    for(int j=1; j<=n; j++) {
      x=map[i][j-1];
      if(w[j]>=i) map[i][j]=x;
      else {
        y=map[i-w[j]][j-1]+v[j];
        map[i][j]=(x>y) ? (x) : (y);
      }
    }
  }
  cout<<map[100][n]<<'\n';
  return 0;
}