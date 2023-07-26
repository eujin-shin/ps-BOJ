#include <iostream>
using namespace std;

int history[5][30] = {0, };

void Check(int x, int y, int z, int n) {
  history[1][y] = z;
  history[2][y+x] = z;
  history[3][y-x+n-1] = z;
} 

void BackTrack(int n, int k) {
  int flag;
  flag = 0;
  for(int i=0; i<n; i++) {
    if(!history[1][i] && !history[2][i+k] && !history[3][i-k+n-1]) {
      Check(k, i, 1, n);
      BackTrack(n, k+1);
      Check(k, i, 0, n);
      flag = 1;
    }
  }
  if(flag && n-1==k) {
    history[0][0] = history[0][0] + 1;
  }
  return;
}

int main() {
  int n;
  cin>>n;
  BackTrack(n, 0);
  cout<<history[0][0]<<endl;
  return 0;
}