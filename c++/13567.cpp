#include <iostream>
#include <string>
using namespace std;

int mx[4]={1, 0, -1, 0};
int my[4]={0, -1, 0, 1};

int move(int d, int pos) {
  return mx[d] + my[d];
}

int turn(int d, int k) {
  if(k) {
    d++; if(d>3) d=0;
  } else {
    d--; if(d<0) d=3;
  }
  return d;
}

int main() {
  string str;
  bool val=true;
  int x, y, d, m, n, k;
  cin>>m>>n; x=y=d=0;
  for(int i=0; i<n; i++) {
    cin>>str>>k;
    if(str.compare("MOVE")==0) {
      if(d%2==0) x+=mx[d]*k;
      else y+=my[d]*k;
      if(y>m || y<0 || x<0 || x>m) {
        val=false; break;
      }
    } else if(str.compare("TURN")==0) {
      d=turn(d, k);
    }
  }
  if(val) cout<<x<<' '<<y<<'\n';
  else cout<<"-1\n";
  return 0;
}