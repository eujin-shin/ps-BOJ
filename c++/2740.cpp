#include <iostream>
using namespace std;

int a[100][100], b[100][100];

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, k, tmp;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin>>a[i][j];
    }
  }
  cin>>m>>k;
  for(int i=0; i<m; i++) {
    for(int j=0; j<k; j++) {
      cin>>b[i][j];
    }
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<k; j++) {
      tmp=0;
      for(int x=0; x<m; x++) {
        tmp+=a[i][x]*b[x][j];
      }
      cout<<tmp;
      if(j==k-1) cout<<'\n';
      else cout<<' ';
    }
  }
  return 0;
}