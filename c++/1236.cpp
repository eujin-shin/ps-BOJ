#include <iostream>
#include <string>
using namespace std;

string s[50];

int main() {
  int n, m, a, b, cnt;
  cin>>n>>m;
  a=n; b=m;
  for(int i=0; i<n; i++) cin>>s[i];
  for(int i=0; i<n; i++) {
    cnt=0;
    for(int j=0; j<m; j++) {
      if(s[i][j]=='X') cnt=1;
    }
    a-=cnt;
  }
  for(int i=0; i<m; i++) {
    cnt=0;
    for(int j=0; j<n; j++) {
      if(s[j][i]=='X') cnt=1;
    }
    b-=cnt;
  }
  cout<<((a>b) ? (a) : (b))<<'\n';
  return 0;
}