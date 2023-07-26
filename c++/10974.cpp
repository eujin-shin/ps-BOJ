#include <iostream>
using namespace std;

int history[9] = {0, };
int num[8] = {0, };

void BackTrack(int n, int r, int x) {
  if(n==r) {
    for(int i=0; i<r; i++) {
      printf("%d", num[i]);
      if(i==r-1) {
        printf("\n");
      } else {
        printf(" ");
      }
    }
  } else {
    for(int i=1; i<=n; i++) {
      if(history[i]) {
        continue;
      }
      history[i] = 1; num[r] = i;
      BackTrack(n, r+1, i+1);
      history[i] = 0;
    }
  }
}

int main() {
  int n;
  cin>>n;
  BackTrack(n, 0, 1);
  return 0;
}