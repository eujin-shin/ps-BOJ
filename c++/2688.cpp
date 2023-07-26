#include <iostream>
using namespace std;

long long dp[66][12] = {0, };
long long result[65] = {0, };

long long GetDp(int n) {
  long long sum=0;
  if(result[n]>0) {
    return result[n];
  } else {
    if(result[n-1]==0) GetDp(n-1);
    for(int i=1; i<=10; i++) {
      dp[n][i] = dp[n][i-1] + dp[n-1][i];
      sum += dp[n][i];
    }
    result[n] = sum;
  }
  return result[n];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n, sum=0;
  cin>>t;
  for(int i=1; i<=10; i++) {
    dp[1][i]=1; sum++;
  }
  result[1] = sum;
  while(t--) {
    cin>>n;
    cout<<GetDp(n)<<'\n';
  }
  return 0;
}