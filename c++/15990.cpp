#include <iostream>
#define M 100001
#define Mod 1000000009
using namespace std;

long long map[3][M]={0, }, dp[M]={0, };
int maxnum=3;

long long GetDp(int n) {
  if(maxnum>=n) return dp[n];
  maxnum=n;
  long long tmp=0;
  for(int i=maxnum+1; i<=n; i++) {
    map[0][i]=(map[1][i-1]+map[2][i-1])%Mod;
    tmp=map[0][i];
    map[1][i]=(map[0][i-2]+map[2][i-2])%Mod;
    tmp=(tmp+map[1][i])%Mod;
    map[2][i]=(map[1][i-3]+map[0][i-3])%Mod;
    tmp=(tmp+map[2][i])%Mod;
    dp[i]=tmp;
  }
  return dp[n];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n;
  cin>>t;
  map[0][1]=1; dp[1]=1;
  map[1][2]=1; dp[2]=1;
  map[0][3]=1; map[1][3]=1; map[2][3]=1; dp[3]=1;
  while(t--) {
    cin>>n;
    cout<<GetDp(n)<<'\n';
  }
  return 0;
}