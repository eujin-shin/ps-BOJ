#include <iostream>
using namespace std;

int num[9] = {0, };

void BackTrack(int n, int m, int k, int r) {
  if(m==r) {
    for(int i=0; i<r; i++) {
      printf("%d", num[i]);
      if(i==r-1) {
        printf("\n");
      } else {
        printf(" ");
      }
    }
  } else {
    for(int i=k; i<=n; i++) {
      num[r] = i;
      BackTrack(n, m, i, r+1);
    }
  }
  return;
}

int main() {
  int n, m;
  cin>>n>>m;
  BackTrack(n, m, 1, 0);
  return 0;
}