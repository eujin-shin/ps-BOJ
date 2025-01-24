#include <iostream>
using namespace std;

int map[101][101] = {0, };

void attach(int x, int y);
int count(int x, int y);

int main() {
  int n, x, y;
  cin>>n;
  for(int i = 0; i < n; i++) {
    cin>>x>>y;
    attach(x, y);
  }

  int answer = 0;
  for(int y = 0; y < 100; y++) {
    for(int x = 0; x < 100; x++) {
      answer += count(x, y);
    }
  }
  cout<<answer<<'\n';
}

void attach(int x, int y) {
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      map[y + i][x + j] = 1;
    }
  }
  return;
}

int count(int x, int y) {
  if(map[y][x] == 0) {
    return 0;
  }
  int moves[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  int sum = 0, tempX, tempY;
  for(int d = 0; d < 4; d++) {
    tempX = x + moves[d][0];
    tempY = y + moves[d][1];
    sum += map[tempY][tempX] == 0 ? 1 : 0;
  }
  return sum;
}