#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int num[1002][1002] = {0, };
  int n, x, max, ans = 1;
  cin>>n;
  for(int i=1; i<=n; i++) {
    cin>>x;
    num[i][0] = num[0][i] = x;
  }
  for(int i=1; i<=n; i++) {
    max = 1;
    for(int j=1; j<i; j++) {
      if(num[j][i]>max) max = num[j][i];
    }
    max++;
    for(int j=i+1; j<=n; j++) {
      if(num[i][0]>num[0][j]) {
        num[i][j] = max;
        if(max>ans) ans = max;
      }
    }
  }
  cout<<ans<<'\n';
  return 0;
}

//   10  30  10  20  20  10
// 10 0   0   0   0   0   0
// 30 0   0   1   1   1   1
// 10 0   0   0   1   1   1
// 20                 1   2
// 20 
// 10