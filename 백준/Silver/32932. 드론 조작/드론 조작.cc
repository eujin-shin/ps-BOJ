#include <iostream>
#include <string>
#define OFFSET 1000
using namespace std;

int map[2000][2000] = {0, };

int main() {
  string moves;
  int n, k, x, y;
  cin>>n>>k;
  for(int i = 0; i < n; i++) {
    cin>>x>>y;
    map[y + OFFSET][x + OFFSET] = 1;
  }
  x = 0;
  y = 0;
  cin>>moves;
  char move;
  int nextX, nextY;
  for(int i = 0; i < k; i++) {
    move = moves[i];
    nextX = x;
    nextY = y;
    if(move == 'U') {
      nextY = y + 1;
    } else if(move == 'D') {
      nextY = y - 1;
    } else if(move == 'R') {
      nextX = x + 1;
    } else if(move == 'L') {
      nextX = x - 1;
    }
    if(map[nextY + OFFSET][nextX + OFFSET] == 0) {
      x = nextX;
      y = nextY;
    }
  } 
  cout<<x<<' '<<y<<'\n';
  return 0;
}