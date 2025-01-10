#include <iostream>
#include <queue>
#define pnt pair<int, int>
#define ppnt pair<int, pnt>
using namespace std;

vector <pnt> bridges[7];
int map[10][10] = {0, }, moves[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
int n, m;

bool isValidPos(int x, int y);
int findIsland(int x, int y, int num);
void findBridge();

int main() {
  cin>>n>>m;
  for(int y = 0; y < n; y++) {
    for(int x = 0; x < m; x++) {
      cin>>map[y][x];
      if(map[y][x] == 1) {
        map[y][x] = -1;
      }
    }
  }

  int island = 0;
  for(int y = 0; y < n; y++) {
    for(int x = 0; x < m; x++) {
      island = findIsland(x, y, island);
    }
  }

  findBridge();

  priority_queue <pnt, vector<pnt>, greater<pnt> > pq;
  pq.push(make_pair(0, 1));
  int visited[7] = {0, }, count = 0, sum = 0, len, a;
  while(!pq.empty() && count < island) {
    len = pq.top().first;
    a = pq.top().second;
    pq.pop();

    if(visited[a] != 0) {
      continue;  
    }
    visited[a] = 1;
    sum += len;
    count++;
    for(int i = 0; i < bridges[a].size(); i++) {
      pq.push(bridges[a][i]);
    } 
  }

  if(count == island) {
    cout<<sum<<'\n';
  } else {
    cout<<"-1\n";
  }

  return 0;
}

void findBridge() {
  int start, a, b, len;
  for(int y = 0; y < n; y++) {
    start = -1;
    for(int x = 0; x < m; x++) {
      if(map[y][x] == 0) {
        continue;
      } else if(start != -1 && map[y][x] != map[y][start] && x - start > 2) {
        a = map[y][start];
        b = map[y][x];
        len = x - start - 1;
        bridges[a].push_back(make_pair(len, b));
        bridges[b].push_back(make_pair(len, a));
      }
      start = x;
    }
  }

  for(int x = 0; x < m; x++) {
    start = -1;
    for(int y = 0; y < n; y++) {
      if(map[y][x] == 0) {
        continue;
      } else if(start != -1 && map[y][x] != map[start][x] && y - start > 2) {
        a = map[start][x];
        b = map[y][x];
        len = y - start - 1;
        bridges[a].push_back(make_pair(len, b));
        bridges[b].push_back(make_pair(len, a));
      }
      start = y;
    }
  }
  return;
}

int findIsland(int x, int y, int num) {
  if(map[y][x] != -1) {
    return num;
  }
  queue <pnt> q;
  q.push(make_pair(x, y));
  map[y][x] = ++num;
  int nextY, nextX;
  while(!q.empty()) {
    x = q.front().first;
    y = q.front().second;
    q.pop();
    for(int d = 0; d < 4; d++) {
      nextX = x + moves[d][0];
      nextY = y + moves[d][1];
      if(isValidPos(nextX, nextY) && map[nextY][nextX] == -1) {
        q.push(make_pair(nextX, nextY));
        map[nextY][nextX] = num;
      }
    }
  }
  return num;
}

bool isValidPos(int x, int y) {
  return x >= 0 && x < m && y >= 0 && y < n;
}