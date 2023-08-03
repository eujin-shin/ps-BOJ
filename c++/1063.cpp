#include <iostream>
#include <string>
using namespace std;

int map[9][9]={0, };
// int xm[8]={1, -1, 0, 0, 1, -1, 1, -1}, ym[8]={0, 0, -1, 1, 1, 1, 1, -1, -1};
string moves[8]={"R", "L", "B", "T", "RT", "LT", "RB", "LB"};

int main() {
  string k, r, m;
  int n, kx, ky, rx, ry, xm, ym;
  cin>>k>>r>>n;

  kx=k[0]-'A'+1; ky=k[1]-'0';
  rx=r[0]-'A'+1; ry=r[1]-'0';
  map[kx][ky]=1; map[rx][ry]=2;

  for(int i=0; i<n; i++) {
    cin>>m; xm=0; ym=0;
    for(int j=0; j<m.size(); j++) {

      if(m[j]=='R') xm=1;
      else if(m[j]=='L') xm=-1;
      else if(m[j]=='T') ym=1;
      else if(m[j]=='B') ym=-1;
    }
    if(kx+xm<1 || kx+xm>8 || ky+ym<1 || ky+ym>8) continue;
    if(kx+xm==rx && ky+ym==ry) {
      if(rx+xm<1 || rx+xm>8 || ry+ym<1 || ry+ym>8) continue;
      rx+=xm; ry+=ym;
    }
    kx+=xm; ky+=ym;
  }
  cout<<char(kx-1+'A')<<char(ky+'0')<<'\n';
  cout<<char(rx-1+'A')<<char(ry+'0')<<'\n';
  return 0;
}