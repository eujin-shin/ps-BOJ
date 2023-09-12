#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack <pair<int, int> > st;
string map[12];
int del[12][6]={0, }, xm[4]={0, 0, -1, 1}, ym[4]={1, -1, 0, 0};

int Connect(int x, int y, char s) {
  int nx, ny, cnt=1;
  st.push(make_pair(x, y));
  for(int i=0; i<4; i++) {
    nx=x+xm[i]; ny=y+ym[i];
    if(nx<0 || nx>5 || ny<0 || ny>11) continue;
    if(map[ny][nx]==s && del[ny][nx]==0) {
      del[ny][nx]=1;
      cnt+=Connect(nx, ny, s);
    }
  }
  return cnt;
}

void Check(bool b) {
  int x, y;
  while(!st.empty()) {
    x=st.top().first; y=st.top().second;
    if(b) del[y][x]=2;
    st.pop();
  }
  return;
}

void Down(int x) {
  int cnt=0;
  for(int y=11; y>=0; y--) {
    if(map[y][x]=='.') cnt++;
    else if(cnt==0) continue;
    else {
      map[y+cnt][x]=map[y][x];
      map[y][x]='.';
    }
  }
}

int main() {
  int cnt=0, tmp, p;
  for(int i=0; i<12; i++) cin>>map[i];
  while(1) {
    p=0;
    for(int y=0; y<12; y++) {
      for(int x=0; x<6; x++) {
        if(map[y][x]=='.' || del[y][x]!=0) continue;
        del[y][x]=1;        
        tmp=Connect(x, y, map[y][x]);
        if(tmp>3) p++;
        Check(tmp>3);
      }
    }
    if(p==0) break;
    for(int y=0; y<12; y++) {
      for(int x=0; x<6; x++) {
        if(del[y][x]==2) map[y][x]='.';
        del[y][x]=0;
      }
    }
    for(int x=0; x<6; x++) {
      Down(x);
    }
    cnt++;
  }
  cout<<cnt<<'\n';
  return 0;
}