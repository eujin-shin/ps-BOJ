#include <iostream>
#include <string>
using namespace std;

string map[4];

int main() {
  int n, m, v=0, h=0, tmp;
  cin>>n>>m;
  for(int i=0; i<n; i++) cin>>map[i];
  for(int i=0; i<n; i++) {
    tmp=0;
    for(int j=0; j<m; j++) {
      tmp*=10; tmp+=map[i][j]-'0';
    }
    h+=tmp;
  } 
  for(int i=0; i<m; i++) {
    tmp=0;
    for(int j=0; j<n; j++) {
      tmp*=10; tmp+=map[j][i]-'0';
    }
    v+=tmp;
  }
  cout<<((v>h) ? (v) : (h))<<'\n';
  return 0;
}