#include <iostream>
using namespace std;

int main() {
  int map[1026][1026];
  int n, m, x1, x2, y1, y2, temp;
  cin>>n>>m;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      scanf("%d", &temp);
      temp -= map[i-1][j-1];
      temp += map[i-1][j] + map[i][j-1];
      map[i][j] = temp;
    }
  }
  for(int i=0; i<m; i++) {
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    temp = map[x2][y2] - map[x2][y1-1] - map[x1-1][y2] + map[x1-1][y1-1];
    printf("%d\n", temp);
  }
  return 0;
}