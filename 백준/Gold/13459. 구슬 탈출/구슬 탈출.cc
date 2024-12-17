#include <iostream>
#include <string>
#define SUCCESS 1
#define FAILED -1
#define HOLE 'O'
#define WALL '#'
#define EMPTY '.'
using namespace std;

string map[11];
int n, m, ans = 0;

struct Coordinate {
  int x;
  int y;
};

struct Position {
  Coordinate red;
  Coordinate blue;
};

pair<Position, int> move(Position prev, int direction) {
  Position current = prev;
  bool passHole;
  int target, status = 0;
  int start, end, move;

  if(direction < 2) {
    start = 0;
    move = 1;
    end = (direction % 2 == 0) ? m - 1 : n - 1;
  } else {
    start = (direction % 2 == 0) ? m - 1 : n - 1;
    move = -1;
    end = 0;
  }

  if(direction % 2 == 0) {
    for(int y = 1; y < n; y++) {
      target = -1; passHole = false;
      for(int x = start; (start == 0 && x < end) || (end == 0 && x > end); x += move) {
        if(prev.blue.x == x && prev.blue.y == y) {
          if(target > 0 && passHole) {
            status = FAILED;
            break;
          } else if(target > 0) {
            current.blue.x = target;
            target += move;
          } else {
            target = -1;
            passHole = false;
          }
        } else if(prev.red.x == x && prev.red.y == y) {
          if(target > 0 && passHole) {
            status = SUCCESS;
          } else if(target > 0) {
            current.red.x = target;
            target += move;
          } else {
            target = -1;
            passHole = false;
          }
        } else if(map[y][x] == WALL) {
          passHole = false;
          target = -1;
        } else {
          if(target == -1) {
            target = x;
          }
          if(map[y][x] == HOLE) {
            passHole = true;
          }
        } 
      }
      if(status == SUCCESS || status == FAILED) {
        break;
      }
    }
  } else {
    for(int x = 1; x < m; x++) {
      target = -1; passHole = false;
      for(int y = start; (start == 0 && y < end) || (end == 0 && y > end); y += move) {
        if(prev.blue.x == x && prev.blue.y == y) {
          if(target > 0 && passHole) {
            status = FAILED;
            break;
          } else if(target > 0) {
            current.blue.y = target;
            target += move;
          } else {
            target = -1;
            passHole = false;
          }
        } else if(prev.red.x == x && prev.red.y == y) {
          if(target > 0 && passHole) {
            status = SUCCESS;
          } else if(target > 0) {
            current.red.y = target;
            target += move;
          } else {
            target = -1;
            passHole = false;
          }
        } else if(map[y][x] == WALL) {
          passHole = false;
          target = -1;
        } else {
          if(target == -1) {
            target = y;
          }
          if(map[y][x] == HOLE) {
            passHole = true;
          }
        } 
      }
      if(status == SUCCESS || status == FAILED) {
        break;
      }
    }
  }
   return make_pair(current, status);
}

void backtrack(Position prev, int r, int prevDirection) {
  if(r++ == 10) {
    return;
  }
  pair<Position, int> result;
  for(int direction = 0; direction < 4; direction++) {
    if(ans == SUCCESS) {
      break;
    } 
    if(direction == prevDirection) {
      continue;
    }

    result = move(prev, direction);
    
    if(result.second == SUCCESS) {
      ans = SUCCESS;
      break;
    } else if(result.second != FAILED) {
      backtrack(result.first, r, direction);
    }
  } 
  return;
}

int main() {
  Position init;
  cin>>n>>m;
  for(int y = 0; y < n; y++) {
    cin>>map[y];
    for(int x = 0; x < m; x++) {
      if(map[y][x] == 'R') {
        init.red.x = x;
        init.red.y = y;
        map[y][x] = EMPTY;
      } else if(map[y][x] == 'B') {
        init.blue.x = x;
        init.blue.y = y;
        map[y][x] = EMPTY;
      }
    }
  }

  backtrack(init, 0, -1);
  cout<<ans<<'\n';
  return 0;
}