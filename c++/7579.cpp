#include <iostream>
using namespace std;

typedef struct {
  int m, c;
} APP;

int dp[10002][102]={0, };
APP arr[101]={0, };

int GetDP(int M, int N) {
  int sum=0, c=0, cc, cm;
  while(1) {
    for(int i=1; i<=N; i++) {
      cc=arr[i].c; cm=arr[i].m;
      if(cc>=c && dp[c-cc][i-1]+cm>sum) {
        sum=dp[c-cc][i-1]+cm;
      }
      dp[c][i]=sum;
    }
    if(sum>=M) break;
    c++;
  }
  return c;
}

int main() {
  ios_base::sync_with_stdio(false);
  int N, M;
  cin>>N>>M;
  for(int i=1; i<=N; i++) {
    cin>>arr[i].m;
  }
  for(int i=1; i<=N; i++) {
    cin>>arr[i].c;
  }
  cout<<GetDP(M, N)<<'\n';
  return 0;
}