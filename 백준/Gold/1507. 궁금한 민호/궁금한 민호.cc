#include <iostream>
#include <queue>
#define INF 50000
#define pnt pair<int, int>
#define ppnt pair<int, pnt>
using namespace std;

priority_queue <ppnt, vector<ppnt>, greater<ppnt> > pq;
int map[20][20] = {0, }, dist[20][20] = {0, };

int main() {
  int n;
  cin>>n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin>>map[i][j];
      if(i != j) {
        dist[i][j] = INF;
      }
      if(j > i) {
        pq.push(make_pair(map[i][j], make_pair(i, j)));
      }
    }
  }

  bool isAble = true;
  int sum = 0, distance, update, x, y;
  while(!pq.empty() && isAble) {
    distance = pq.top().first;
    x = pq.top().second.first;
    y = pq.top().second.second;
    pq.pop();

    if(dist[x][y] < distance) {
      isAble = false;
    } else if(dist[x][y] > distance) {
      dist[x][y] = dist[y][x] = distance;
      sum += distance;

      for(int start = 0; start < n; start++) {
        for(int end = start + 1; end < n; end++) {
          update = INF;
          if(dist[x][start] != INF && dist[y][end] != INF) {
            update = dist[x][start] + dist[y][end];
          }
          if(dist[x][end] != INF && dist[y][start] != INF && update > dist[x][end] + dist[y][start]) {
            update = dist[x][end] + dist[y][start];
          }

          if(update != INF && update + distance < dist[start][end]) {
            dist[start][end] = dist[end][start] = update + distance;
          }
        }
      }
    } 
  } 

  if(isAble) {
    cout<<sum<<'\n';
  } else {
    cout<<"-1\n";
  }
  return 0;
}