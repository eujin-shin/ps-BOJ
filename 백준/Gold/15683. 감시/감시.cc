#include <iostream>
#include <vector>
using namespace std;

vector <pair<int, int> > cctv;
int directions[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
int rotates[6][4][4] = {{{0, }}, {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}, {{1, 0, 1, 0}, {0, 1, 0, 1}, }, {{1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 1}, {1, 0, 0, 1}}, {{0, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {1, 1, 1, 0}}, {{1, 1, 1, 1}}};
int rotateCases[6] = {0, 4, 2, 4, 4, 1};
int map[8][8] = {0, }, visited[8][8] = {0, }, maxCount = 0;


void rotateCCTV(int n, int m, int r, int sum) {
  if(r == cctv.size()) {
    if(sum > maxCount) {
      maxCount = sum;
    }
    return;
  }
  int x = cctv[r].first, y = cctv[r].second, type = map[y][x], k = rotateCases[type];
  int curX, curY, count;
  r++;
  for(int i = 0; i < k; i++) {
    count = 0;
    for(int d = 0; d < 4; d++) {
      if(rotates[type][i][d] == 0) {
        continue;
      }
      curX = x + directions[d][0];
      curY = y + directions[d][1];
      while(curX >= 0 && curX < m && curY >= 0 && curY < n) {
        if(map[curY][curX] == 0 && visited[curY][curX] == 0) {
          visited[curY][curX] = r;
          count++;
        } else if(map[curY][curX] == 6) {
          break;
        }
        curX += directions[d][0];
        curY += directions[d][1];
      }
    }
    rotateCCTV(n, m, r, sum + count);
    for(int y = 0; y < n; y++) {
      for(int x = 0; x < m; x++) {
        if(visited[y][x] == r) {
          visited[y][x] = 0;
        }
      }
    }
  }
  return;
}


int main() {
  int n, m;
  cin>>n>>m;
  int x, y, place = 0;
  for(y = 0; y < n; y++) {
    for(x = 0; x < m; x++) {
      cin>>map[y][x];
      if(map[y][x] >= 1 && map[y][x] <= 5) {
        cctv.push_back(make_pair(x, y));
      } else if(map[y][x] == 0) {
        place++;
      }
    }
  }
  rotateCCTV(n, m, 0, 0);
  cout<<place - maxCount<<'\n';
  return 0;
}