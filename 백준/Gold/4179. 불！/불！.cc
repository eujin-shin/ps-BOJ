#include <iostream>
#include <queue>
#include <string>
#define FIRE 'F'
#define WALL '#'
#define VISITED 'v'
#define EMPTY '.'
#define pnt pair<int, int>
using namespace std;

queue <pnt> fires, q;
string map[1001];
int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}, r, c;

bool exitMap(int x, int y) {
  return (x >= c || x < 0 || y >= r || y < 0);
}

void fireMove() {
  int count = fires.size(), x, y, nextX, nextY;
  while(count--) {
    x = fires.front().first;
    y = fires.front().second;
    fires.pop();

    for(int dir = 0; dir < 4; dir++) {
      nextX = x + moves[dir][0];
      nextY = y + moves[dir][1];
      if(exitMap(nextX, nextY)) {
        continue;
      }
      if(map[nextY][nextX] != FIRE && map[nextY][nextX] != WALL) {
        map[nextY][nextX] = FIRE;
        fires.push(make_pair(nextX, nextY));
      }
    }
  }

  return;
}

int main() {
  cin>>r>>c;
  for(int y = 0; y < r; y++) {
    cin>>map[y];
    for(int x = 0; x < c; x++) {
      if(map[y][x] == 'J') {
        map[y][x] = VISITED;
        q.push(make_pair(x, y));
      } else if(map[y][x] == FIRE) {
        fires.push(make_pair(x, y));
      }
    }
  }

  int escape = -1, current = 1, temp = 0, count = 1;
  int x, y, nextX, nextY;
  while(!q.empty() && escape < 0) {
    x = q.front().first;
    y = q.front().second;
    q.pop();
    if(--count == 0) {
      fireMove();
    }

    for(int dir = 0; dir < 4; dir++) {
      nextX = x + moves[dir][0];
      nextY = y + moves[dir][1];

      if(exitMap(nextX, nextY)) {
        escape = current;
        break;
      } else if(map[nextY][nextX] == EMPTY) {
        q.push(make_pair(nextX, nextY));
        map[nextY][nextX] = VISITED;
        temp++;
      } 
    }

    if(count == 0) {
      count = temp;
      temp = 0;
      current++;
    }
  }

  if(escape < 0) {
    cout<<"IMPOSSIBLE\n";
  } else {
    cout<<escape<<'\n';
  }
  return 0;
}