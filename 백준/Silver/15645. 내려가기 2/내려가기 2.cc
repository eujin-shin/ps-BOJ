#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int min[2][3] = {0, }, max[2][3] = {0, };
  int n, prevMin, prevMax;
  cin>>n;
  for(int i = 0 ; i < n; i++) {
    for(int j = 0; j < 3; j++) {
      cin>>min[1][j];
      max[1][j] = min[1][j];
      prevMax = 0; prevMin = 900000;
      for(int k = -1; k <= 1; k++) {
        if(j + k < 0 || j + k > 2) {
          continue;
        }
        if(min[0][j + k] < prevMin) {
          prevMin = min[0][j + k];
        }
        if(max[0][j + k] > prevMax) {
          prevMax = max[0][j + k];
        }
      }
      max[1][j] += prevMax;
      min[1][j] += prevMin;
    }
    prevMax = 0; prevMin = 900000;
    for(int j = 0; j < 3; j++) {
      max[0][j] = max[1][j];
      min[0][j] = min[1][j];
      if(min[0][j] < prevMin) {
        prevMin = min[0][j];
      }
      if(max[0][j] > prevMax) {
        prevMax = max[0][j];
      }
    }
  }
  cout<<prevMax<<' '<<prevMin<<'\n';
  return 0;
}