#include <iostream>
#include <string>
#define R 10000
#define C 500
using namespace std;

int map[R][C]={0, };

int dfs(int x, int y, int r, int c) {
  int res=0;
  map[y][x]=1;
  if(x==c-2) return 1;
  if(y!=0 && map[y-1][x+1]==0) res=dfs(x+1, y-1, r, c);
  if(res==0 && map[y][x+1]==0) res=dfs(x+1, y, r, c);
  if(res==0 && y+1<r && map[y+1][x+1]==0) res=dfs(x+1, y+1, r, c);
  return res;
}

int main() {
  string in;
  int r, c, count=0;
  cin>>r>>c;
  for(int y=0; y<r; y++) {
    cin>>in;
    for(int x=0; x<c; x++) {
      if(in[x]=='x') map[y][x]=1;
    }
  }
  for(int y=0; y<r; y++) {
    count+=dfs(0, y, r, c);
  }
  cout<<count<<'\n';
  return 0;
}