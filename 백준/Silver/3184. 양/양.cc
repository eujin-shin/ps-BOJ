#include <iostream>
#include <string>
#include <queue>
#define EMPTY '.'
#define FENCE '#'
#define SHEEP 'o'
#define WOLF 'v'
#define VISITED 1
using namespace std;

string map[250];
int visited[250][250] = {0, }, r, c;

pair<int, int> check(int x, int y);
bool isMovable(int x, int y);

int main() {
  int s = 0, w = 0;
  cin>>r>>c;
  for(int y = 0; y < r; y++) {
    cin>>map[y];
    for(int x = 0; x < c; x++) {
      if(map[y][x] == SHEEP) {
        s++;
      } else if(map[y][x] == WOLF) {
        w++;
      }
    }
  }

  pair<int, int> result;
  for(int y = 0; y < r; y++) {
    for(int x = 0; x < c; x++) {
      if(!isMovable(x, y)) {
        continue;
      }
      result = check(x, y);
      if(result.first > result.second) {
        w -= result.second;
      } else {
        s -= result.first;
      }
    }
  }
  cout<<s<<' '<<w<<'\n';
  return 0;
}

bool isMovable(int x, int y) {
  if(x >= c || x < 0 || y >= r || y < 0) {
    return false;
  }
  return map[y][x] != FENCE && visited[y][x] != VISITED;
}

pair<int, int> check(int x, int y) {
  int move[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  queue <pair<int, int> > q;
  q.push(make_pair(x, y));
  visited[y][x] = VISITED;

  int nextX, nextY, w = 0, s = 0;
  while(!q.empty()) {
    x = q.front().first;
    y = q.front().second;
    q.pop();

    if(map[y][x] == SHEEP) {
      s++;
    } else if(map[y][x] == WOLF) {
      w++;
    }

    for(int d = 0; d < 4; d++) {
      nextX = x + move[d][0];
      nextY = y + move[d][1];
      if(isMovable(nextX, nextY)) {
        q.push(make_pair(nextX, nextY));
        visited[nextY][nextX] = VISITED;
      }
    }
  }
  return make_pair(s, w);
}