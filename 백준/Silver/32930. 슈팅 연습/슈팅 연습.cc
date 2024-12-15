#include <iostream>
using namespace std;

int main() {
  int targets[200][2] = {0, };
  int n, m;
  cin>>n>>m;
  for(int i = 0; i < n; i++) {
    cin>>targets[i][0]>>targets[i][1];
  }

  int visited[200] = {0, };
  int sum = 0, x = 0, y = 0, maxDistance, distX, distY, distance, nextIndex;
  for(int i = 0; i < m; i++) {
    maxDistance = 0;
    for(int target = 0; target < n; target++) {
      if(visited[target] != 0) {
        continue;
      }
      distX = targets[target][0] - x;
      distY = targets[target][1] - y;
      distance = distX * distX + distY * distY;
      if(distance > maxDistance) {
        maxDistance = distance;
        nextIndex = target;
      }
    }

    cin>>targets[n][0]>>targets[n][1];
    n++;
    x = targets[nextIndex][0];
    y = targets[nextIndex][1];
    visited[nextIndex] = 1;
    sum += maxDistance;
  }
  cout<<sum<<'\n';
  return 0;
}