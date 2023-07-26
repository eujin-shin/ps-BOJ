#include <iostream>
using namespace std;

int map[130][130] = {0, };

void Go(int x, int y, int l) {
  int std = map[x][y], flag = 1;
  for(int i=x; i<x+l; i++) {
    for(int j=y; j<y+l; j++) {
      if(std!=map[i][j]) {
        flag = 0;
        break;
      }
    }
    if(flag==0) {
      break;
    }
  }
  if(flag) {
    map[0][std] = map[0][std]+1;
  } else {
    Go(x, y, l/2);
    Go(x+l/2, y, l/2);
    Go(x, y+l/2, l/2);
    Go(x+l/2, y+l/2, l/2);
  }
  return;
}

int main() {
  int n;
  cin>>n;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      scanf("%d", &map[i][j]);
    }
  }
  Go(1, 1, n);
  printf("%d\n%d\n", map[0][0], map[0][1]);
  return 0;
}