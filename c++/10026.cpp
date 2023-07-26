#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int x_move[4] = {0, 1, 0, -1};
int y_move[4] = {1, 0, -1, 0};

// abcdefghijklmnopqrstuvwxyz
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  char map1[102][102] = {0, }, map2[102][102];
  string inp;
  int n;
  cin>>n;
  for(int y=0; y<n; y++) {
    cin>>inp;
    for(int x=0; x<n; x++) {
      map1[x][y] = map2[x][y] = inp[x];
      if(inp[x]=='R') map2[x][y] = 'G';
    }
  }
  queue <int> xq, yq;
  int count1=0, count2=0, cx, cy, nx, ny;
  char key;
  for(int y=0; y<n; y++) {
    for(int x=0; x<n; x++) {
      if(map1[x][y]=='0') continue;
      else {
        count1++;
        key = map1[x][y];
        xq.push(x); yq.push(y);
        while(!xq.empty()) {
          cx = xq.front(); xq.pop();
          cy = yq.front(); yq.pop();
          for(int i=0; i<4; i++) {
            nx = cx+x_move[i]; ny = cy+y_move[i];
            if(nx>=n || ny>=n || nx<0 || ny<0) continue;
            if(map1[nx][ny]==key) {
              xq.push(nx);
              yq.push(ny);
              map1[nx][ny] = '0';
            }
          }
        }
      }
    }
  }
  for(int y=0; y<n; y++) {
    for(int x=0; x<n; x++) {
      if(map2[x][y]=='0') continue;
      else {
        count2++;
        key = map2[x][y];
        xq.push(x); yq.push(y);
        while(!xq.empty()) {
          cx = xq.front(); xq.pop();
          cy = yq.front(); yq.pop();
          for(int i=0; i<4; i++) {
            nx = cx+x_move[i]; ny = cy+y_move[i];
            if(nx>=n || ny>=n || nx<0 || ny<0) continue;
            if(map2[nx][ny]==key) {
              xq.push(nx);
              yq.push(ny);
              map2[nx][ny] = '0';
            }
          }
        }
      }
    }
  }
  cout<<count1<<' '<<count2<<'\n';
  return 0;
}