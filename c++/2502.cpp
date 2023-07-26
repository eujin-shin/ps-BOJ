#include <iostream>
using namespace std;

int dp[32][3]={0, };

// 1,0 0,1 1,1 1,2 2,3 3,5 5,8 

void GetDp(int d, int *a, int *b) {
  for(int i=3; i<=d; i++) {
    dp[i][1]=dp[i-1][1]+dp[i-2][1];
    dp[i][2]=dp[i-1][2]+dp[i-2][2];
  }
  *a=dp[d][1]; *b=dp[d][2];
}

int main() {
  int d, k, a, b, ans1, ans2;
  dp[1][1]=1; dp[2][2]=1;
  cin>>d>>k;
  GetDp(d, &a, &b);
  for(int i=1; i<=k; i++) {
    if((k-i*a)%b==0) {
      ans1=i; ans2=(k-i*a)/b; break;
    }
  }
  cout<<ans1<<'\n'<<ans2<<'\n';
  return 0;
}