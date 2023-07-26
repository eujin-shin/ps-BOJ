#include <iostream>
#define M 1000001
#define Mod 1000000000
#define ll unsigned long long
using namespace std;

ll dp[M]={0, };

ll GetDp(int n) {
  ll tmp;
  for(int i=3; i<=n; i++) {
    dp[i]=(((i-1)*dp[i-1])%Mod)+(((i-1)*dp[i-2])%Mod);
    dp[i]=dp[i]%Mod;
  }
  return dp[n];
}

int main() {
  int n;
  cin>>n;
  dp[1]=0; dp[2]=1;
  cout<<GetDp(n)<<'\n';
  return 0;
}

