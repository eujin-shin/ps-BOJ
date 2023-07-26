#include <iostream>
using namespace std;

int num[9] = {0, };

void BackTrack(int r, int x, int n, int m) {
  if(r==m) {
    for(int i=0; i<m; i++) {
      printf("%d", num[i]);
      if(i==m-1) {
        printf("\n");
      } else {
        printf(" ");
      }
    }
  } else {
    for(int i=x; i<=n; i++) {
      num[r] = i;
      BackTrack(r+1, i+1, n, m);
    }
  }
}

int main() {
  int n, m;
  cin>>n>>m;
  BackTrack(0, 1, n, m);
  return 0;
}