#include <iostream>
#include <queue>
#define pnt pair<int, int>
using namespace std;

int walls[50][50] = {0, }, visited[50][50] = {0, }, rooms[2501] = {0, };
int moves[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int n, m;

bool isValidPos(int x, int y);
int findRoom(int num, int x, int y);
int findSum(int x, int y);

int main() {
  cin>>m>>n;
  for(int y = 0; y < n; y++) {
    for(int x = 0; x < m; x++) {
      cin>>walls[y][x];
    }
  }

  int room = 0, maxRoom = 0;
  for(int y = 0; y < n; y++) {
    for(int x = 0; x < m; x++) {
      room = findRoom(room, x, y);
      if(rooms[room] > maxRoom) {
        maxRoom = rooms[room];
      }
    }
  }

  int sum, maxSum = 0;
  for(int y = 0; y < n; y++) {
    for(int x = 0; x < m; x++) {
      sum = findSum(x, y);
      if(sum > maxSum) {
        maxSum = sum;
      }
    }
  }
  
  cout<<room <<'\n'<<maxRoom<<'\n'<<maxSum<<'\n';
  return 0;
}

int findSum(int x, int y) {
  int a = visited[y][x], b, sum = 0, max = 0;

  int nextX, nextY;
  for(int d = 0; d < 4; d++) {
    nextX = x + moves[d][0];
    nextY = y + moves[d][1];
    if(isValidPos(nextX, nextY) && visited[nextY][nextX] != a) {
      b = visited[nextY][nextX];
      sum = rooms[a] + rooms[b];
      if(sum > max) {
        max = sum;
      }
    }
  }

  return max;
}

int findRoom(int num, int x, int y) {
  if(visited[y][x] != 0) {
    return num;
  }

  queue <pnt> q;
  visited[y][x] = ++num;
  q.push(make_pair(x, y));
  int count = 0, nextY, nextX;
  while(!q.empty()) {
    x = q.front().first;
    y = q.front().second;
    q.pop();
    count++;
    for(int d = 0, i = 1; d < 4; d++, i <<= 1) {
      if(i & walls[y][x]) {
        continue;
      }
      nextX = x + moves[d][0];
      nextY = y + moves[d][1];
      if(isValidPos(nextX, nextY) && visited[nextY][nextX] == 0) {
        q.push(make_pair(nextX, nextY));
        visited[nextY][nextX] = num;
      }
    }
  }

  rooms[num] = count;
  return num;
}

bool isValidPos(int x, int y) {
  return x >= 0 && x < m && y >= 0 && y < n;
}