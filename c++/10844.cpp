#include <iostream>
using namespace std;
#define MAX 1000000000

int dp[102][11] = {0, };
int result[102] = {0, };

int GetDp(int n) {
  int sum;
  for(int i=2; i<=n; i++) {
    sum=0;
    for(int j=0; j<10; j++) {
      if(j==0) dp[i][j]=dp[i-1][1];
      else if(j==9) dp[i][j]=dp[i-1][8];
      else dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
      dp[i][j]=dp[i][j]%MAX;
      sum+=dp[i][j]; sum%=MAX;
    }
    result[i]=sum;
  }
  return result[n];
}

int main() {
  int n;
  cin>>n;
  for(int i=1; i<10; i++) {
    dp[1][i]=1;
  }
  result[1]=9;
  cout<<GetDp(n)<<'\n';
}