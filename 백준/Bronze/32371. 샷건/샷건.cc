#include <iostream>
#include <string>
using namespace std;

int main() {
  string keyboard[4];
  for(int i = 0; i < 4; i++) {
    cin>>keyboard[i];
  }
  string shot;
  cin>>shot;
  int minX = 9, maxX = 0, minY = 3, maxY = 0;
  for(int i = 0; i < 9; i++) {
    for(int y = 0; y < 4; y++) {
      for(int x = 0; x < 10; x++) {
        if(keyboard[y][x] != shot[i]) {
          continue;
        }
        if(x < minX) {
          minX = x;
        }
        if(x > maxX) {
          maxX = x;
        }
        if(y < minY) {
          minY = y;
        }
        if(y > maxY) {
          maxY = y;
        }
      }
    }
  }
  cout<<keyboard[(minY + maxY) / 2][(minX + maxX) / 2]<<'\n';
  return 0;
}