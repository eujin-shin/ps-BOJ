#include <iostream>
#include <string>
using namespace std;

int map[50][50];

int main() {
  ios_base::sync_with_stdio(false);
  string input;
  int n, m, v='|', h='-', f, c=0;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    cin>>input;
    for(int j=0; j<m; j++) map[i][j]=input[j];
  }
  for(int i=0; i<n; i++) {
    f=0;
    for(int j=0; j<m; j++) {
      if(map[i][j]==h) f=1;
      if(map[i][j]==v || j==m-1) {
        c+=f; f=0;
      }
    }
  }
  for(int i=0; i<m; i++) {
    f=0;
    for(int j=0; j<n; j++) {
      if(map[j][i]==v) f=1;
      if(map[j][i]==h || j==n-1) {
        c+=f; f=0;
      }
    }
  }
  cout<<c<<'\n';
  return 0;
}