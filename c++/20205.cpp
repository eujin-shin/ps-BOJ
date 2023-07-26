#include <iostream>
using namespace std;

int map[11][11]={0, };

int main() {
  int n, k;
  cin>>n>>k;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) cin>>map[i][j];
  }
  for(int i=0; i<n*k; i++) {
    for(int j=0; j<n*k; j++) {
      cout<<map[i/k][j/k];
      if(j!=n*k-1) cout<<' ';
    }
    cout<<'\n';
  }
  return 0;
}