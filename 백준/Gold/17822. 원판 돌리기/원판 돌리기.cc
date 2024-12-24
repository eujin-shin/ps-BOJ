#include <iostream>
using namespace std;

int map[60][60] = {0, }, temp[60][60] = {0, }, n, m;

void right(int y, int k);
void left(int y, int k);
void rotate(int d, int y, int k);
void erase(int x, int y);
pair<int, int> checkErase();
int updateMap(double avg);

int main() {
  int t, sum = 0;
  cin>>n>>m>>t;
  for(int y = 1; y <= n; y++) {
    for(int x = 1; x <= m; x++) {
      cin>>map[y][x];
      sum += map[y][x];
    }
  }

  int x, d, k;
  pair<int, int> result;
  for(int i = 0; i < t; i++) {
    cin>>x>>d>>k;
    for(int y = 1; y <= n; y++) {
      if(y % x == 0) {
        rotate(d, y, k);
      }
    }
    result = checkErase();
    if(sum != 0 && result.first == sum) {
      sum = updateMap((double)sum / (double)result.second);
    } else {
      sum = result.first;
    }
  }
  cout<<sum<<'\n';
  return 0;
}

void right(int y, int k) {
  for(int x = 1; x <= m; x++) {
    temp[y][x] = (x - k < 1 ? map[y][m + x - k] : map[y][x - k]);
  }
  return;
}

void left(int y, int k) {
  for(int x = 1; x <= m; x++) {
    temp[y][x] = (x + k > m ? map[y][x + k - m] : map[y][x + k]);
  }
  return;
}

void rotate(int d, int y, int k) {
  if(d == 0) {
    right(y, k);
  } else {
    left(y, k);
  }
  for(int x = 1; x <= m; x++) {
    map[y][x] = temp[y][x];
  }
  return;
}

void erase(int x, int y) {
  int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  int movedX, movedY;
  bool hasSame = false;
  for(int i = 0; i < 4 && !hasSame; i++) {
    movedX = x + moves[i][0];
    movedY = y + moves[i][1];
    
    if(movedY < 1 || movedY > n) {
      continue;
    }

    if(movedX == 0) {
      movedX = m;
    } else if(movedX == m + 1) {
      movedX = 1;
    }
    
    if(map[movedY][movedX] == map[y][x]) {
      hasSame = true;
    }
  }

  if(hasSame) {
    temp[y][x] = 1;
  } else {
    temp[y][x] = 0;
  }
  return;
}

pair<int, int> checkErase() {
  for(int y = 1; y <= n; y++) {
    for(int x = 1; x <= m; x++) {
      erase(x, y);
    }
  }

  int sum = 0, count = 0;
  for(int y = 1; y <= n; y++) {
    for(int x = 1; x <= m; x++) {
      if(temp[y][x] == 1) {
        map[y][x] = 0;
      } else if(map[y][x] != 0) {
        sum += map[y][x];
        count++;
      }
    }
  }

  return make_pair(sum, count);
}

int updateMap(double avg) {
  int sum = 0;
  for(int y = 1; y <= n; y++) {
    for(int x = 1; x <= m; x++) {
      if(map[y][x] > avg) {
        map[y][x]--;
      } else if(map[y][x] != 0 && map[y][x] < avg) {
        map[y][x]++;
      }
      sum += map[y][x];
    }
  }
  return sum;
}
