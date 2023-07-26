#include <iostream>
#include <string.h>
using namespace std;

int map[22][22] = {0, };
int visit[27] = {0, };
int x_move[4] = {0, 1, -1, 0};
int y_move[4] = {1, 0, 0, -1};

int DFS(int x, int y, int count, int r, int c) {
  int next_x, next_y;
  bool flag = true;
  visit[map[x][y]] = 1;
  for(int i=0; i<4; i++) {
    next_x = x+x_move[i]; next_y = y+y_move[i];
    if(next_x>c || next_x<=0 || next_y>r || next_y<=0) continue;
    if(visit[map[next_x][next_y]]==0) {
      flag = false;
      DFS(next_x, next_y, count+1, r, c);
      visit[map[next_x][next_y]] = 0;
    }
  }
  if(flag) {
    if(count>map[0][0]) map[0][0] = count;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int r, c;
  string temp;
  cin>>r>>c;
  for(int i=1; i<=r; i++) {
    cin>>temp;
    for(int j=0; j<c; j++) {
      map[j+1][i] = temp[j] - 'A' + 1;
    }
  }
  DFS(1, 1, 1, r, c);
  cout<<map[0][0]<<endl;  
  return 0;
}