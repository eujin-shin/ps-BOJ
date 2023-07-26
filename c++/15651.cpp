#include <iostream>
using namespace std;

int num[8] = {0, };

void BackTrack(int r, int m, int n) {
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
    for(int i=1; i<=n; i++) {
      num[r] = i;
      BackTrack(r+1, m, n);
    }
  }
}

int main() {
  int n, m;
  cin>>n>>m;
  BackTrack(0, m, n);
  return 0;
}