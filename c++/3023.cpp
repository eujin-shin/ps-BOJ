#include <iostream>
#include <string>
using namespace std;

string s[50];

int main() {
  ios_base::sync_with_stdio(false);
  char tmp;
  int r, c, a, b, x, y;
  cin>>r>>c;
  for(int i=0; i<r; i++) cin>>s[i];
  cin>>a>>b;
  for(int i=0; i<r*2; i++) {
    for(int j=0; j<c*2; j++) {
      y= (i>=r) ? (2*r-i-1) : (i); 
      x= (j>=c) ? (2*c-j-1) : (j);
      if(j==b-1 && i==a-1) {
        if(s[y][x]=='#') cout<<'.';
        else cout<<'#';
      } else cout<<s[y][x];
    }
    cout<<'\n';
  }
  return 0;
}