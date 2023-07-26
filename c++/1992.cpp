#include <iostream>
#include <string>
using namespace std;

int map[64][64]={0, };

void Quad(int x, int y, int l) {
  int c=map[x][y];
  bool flag=true;
  for(int i=0; i<l; i++) {
    for(int j=0; j<l; j++) {
      if(map[x+j][y+i]==c) continue;
      flag=false; break;
    }
  }
  if(flag) cout<<c;
  else {
    l/=2;
    cout<<'(';
    Quad(x, y, l);
    Quad(x+l, y, l);
    Quad(x, y+l, l);
    Quad(x+l, y+l, l);
    cout<<')';
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  int n;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>s;
    for(int j=0; j<n; j++) {
      map[j][i]=s[j]-'0';
    }
  }
  Quad(0, 0, n);
  cout<<'\n';
  return 0;
}