#include <iostream>
using namespace std;

int dp[12][1001] = {0, };

int DP(int n) {
  int sum = 10, num = 10007;
  for(int i=1; i<n; i++) {
    sum = 0;
    for(int j=1; j<11; j++) {
      sum += dp[j][i-1];
      sum %= num;
      dp[j][i] = sum;
    }
  }
  return sum;
}

int main() {
  int n;
  for(int i=1; i<11; i++) {
    dp[i][0] = i;
  }
  cin>>n;
  cout<<DP(n)<<'\n';
  return 0;
}