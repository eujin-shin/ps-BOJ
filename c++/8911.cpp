#include <iostream>
#include <string>
using namespace std;

int xm[4]={0, -1, 0, 1}, ym[4]={1, 0, -1, 0};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, max_x, min_x, max_y, min_y, x, y, d;
  string s;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>s;
    max_x=0; max_y=0; min_x=0; min_y=0;
    x=0; y=0; d=0;
    for(int j=0; j<s.length(); j++) {
      if(s[j]=='F') {
        x+=xm[d]; y+=ym[d];
        if(x<min_x) min_x=x;
        if(y<min_y) min_y=y;
        if(x>max_x) max_x=x;
        if(y>max_y) max_y=y;
      } else if(s[j]=='B') {
        x-=xm[d]; y-=ym[d];
        if(x<min_x) min_x=x;
        if(y<min_y) min_y=y;
        if(x>max_x) max_x=x;
        if(y>max_y) max_y=y;
      } else if(s[j]=='L') {
        d+=1;
        if(d>3) d=0;
      } else if(s[j]=='R') {
        d-=1;
        if(d<0) d=3;
      }
    }
    cout<<(max_y-min_y)*(max_x-min_x)<<'\n';
  }
  return 0;
}