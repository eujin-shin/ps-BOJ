#include <iostream>
#include <string>
using namespace std;


string s[10];
int x_move[4]={0, 0, -1, 1}, y_move[4]={1, -1, 0, 0}, r, c;

int Check(int x, int y) {
  int cnt=0, nx, ny;
  for(int i=0; i<4; i++) {
    nx=x+x_move[i]; ny=y+y_move[i];
    if(nx>=c || nx<0 || ny>=r || ny<0 || s[ny][nx]=='.') cnt++;
  }
  return cnt;
}

int main() {
  int map[10][10]={0, };
  pair<int, int> min=make_pair(10, 10), max=make_pair(-1, -1);
  cin>>r>>c;
  for(int i=0; i<r; i++) cin>>s[i];
  for(int i=0; i<r; i++) {
    for(int j=0; j<c; j++) {
      if(s[i][j]=='.') continue;
      if(Check(j, i)>2) continue;
      map[i][j]=1;
      if(j<min.first) min.first=j;
      if(i<min.second) min.second=i;
      if(j>max.first) max.first=j;
      if(i>max.second) max.second=i;
    }
  }
  for(int i=min.second; i<=max.second; i++) {
    for(int j=min.first; j<=max.first; j++) {
      cout<<(map[i][j]==1 ? "X" : ".");
    }
    cout<<'\n';
  }
  return 0;
}