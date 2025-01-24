#include <iostream>
#include <string>
using namespace std;

struct Pos {
  int x;
  int y;
};

int min(int a, int b);
int max(int a, int b);

int moves[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int map[101][101] = {0, };

int main() {
  int n;
  string s;
  cin>>n>>s;

  Pos cur = {50, 50}, start = {50, 50}, end = {50, 50};
  int d = 0;
  map[50][50] = 1;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'R') {
      d = ++d % 4;
    } else if(s[i] == 'L') {
      d = --d < 0 ? 3 : d; 
    } else {
      cur.x += moves[d][0];
      cur.y += moves[d][1];
      map[cur.y][cur.x] = 1;

      start.x = min(start.x, cur.x);
      start.y = min(start.y, cur.y);
      end.x = max(end.x, cur.x);
      end.y = max(end.y, cur.y);
    }
  }

  for(int y = start.y; y <= end.y; y++) {
    for(int x = start.x; x <= end.x; x++) {
      cout<<(map[y][x] == 1 ? '.' : '#');
    }
    cout<<'\n';
  }

  return 0;
}

int min(int a, int b) {
  return a < b ? a : b;
}

int max(int a, int b) {
  return a > b ? a : b;
}