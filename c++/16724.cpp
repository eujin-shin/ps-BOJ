#include <iostream>
#include <string>
using namespace std;

string input[1000];
int map[1000][1000]={0, };

int move(int x, int y) {
  int res;
  if(map[x][y]<0) return 1;
  else if(map[x][y]>0) return 0;
  map[x][y]=-1;
  if(input[x][y]=='U') res=move(x-1, y);
  if(input[x][y]=='D') res=move(x+1, y);
  if(input[x][y]=='L') res=move(x, y-1);
  if(input[x][y]=='R') res=move(x, y+1);
  map[x][y]=1;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, c=0;
  cin>>n>>m;
  for(int i=0; i<n; i++) cin>>input[i];
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(map[i][j]>0) continue;
      c+=move(i, j);
    }
  }
  cout<<c<<'\n';
  return 0;
}