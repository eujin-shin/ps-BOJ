#include <iostream>
#include <string>
using namespace std;

string map[500];
int r, c;

bool checkWolf(int x, int y);

int main() {
  cin>>r>>c;
  for(int y = 0; y < r; y++) {
    cin>>map[y];
  }
  bool isAble = true;
  for(int y = 0; y < r; y++) {
    for(int x = 0; x < c; x++) {
      isAble = checkWolf(x, y);
      if(!isAble) {
        break;
      }
    }
    if(!isAble) {
      break;
    }
  }
  if(isAble) {
    cout<<"1\n";
    for(int y = 0; y < r; y++) {
      for(int x = 0; x < c; x++) {
        cout<<map[y][x];
      }
      cout<<'\n';
    }
  } else {
    cout<<"0\n";
  }
  return 0;
}

bool checkWolf(int x, int y) {
  if(map[y][x] != 'W') {
    return true;
  }
  int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}, curX, curY;
  for(int i = 0; i < 4; i++) {
    curX = x + moves[i][0];
    curY = y + moves[i][1];
    if(curX < 0 || curY < 0 || curX >= c || curY >= r) {
      continue;
    }
    if(map[curY][curX] == '.') {
      map[curY][curX] = 'D';
    } else if(map[curY][curX] == 'S') {
      return false;
    }
  }
  return true;
}