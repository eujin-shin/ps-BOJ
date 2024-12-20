#include <iostream>
#define M 100001
#define MOD 1000000009
using namespace std;

long long dp[4][M] = {0, }, counts[M] = {0, };
int bound = 0;

long long setDp(int k) {
  long long sum = 0;
  for(int cur = 1; cur < 4; cur++) {
    for(int prev = 1; prev < 4; prev++) {
      if(cur != prev) {
        dp[cur][k] = (dp[cur][k] + dp[prev][k - cur]) % MOD;
      }
    }
    sum = (sum + dp[cur][k]) % MOD;
  }
  return sum;
}

long long getCounts(int n) {
  if(bound >= n) return counts[n];

  long long sum = 0;
  for(int i = bound + 1; i <= n; i++) {
    counts[i] = setDp(i);
  } 
  bound = n;
  return counts[n]; 
} 

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  dp[1][1] = 1;
  dp[2][2] = 1;
  dp[3][3] = 1;
  
  int t, n;
  cin>>t;
  while(t--) {
    cin>>n;
    cout<<getCounts(n)<<'\n';
  }
  return 0;
}