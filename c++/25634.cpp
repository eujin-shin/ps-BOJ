#include <iostream>
#include <vector>
using namespace std;

vector <int> v;
int dp[2][3]={0, }, c[2]={1, 0};

int main() {
  ios_base::sync_with_stdio(false);
  int n, x;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>x; v.push_back(x);
  }
  cin>>x;
  dp[0][0]=v[0]*x; dp[0][1]=-1; dp[0][2]=v[0]*c[x];

  for(int i=1; i<n; i++) {
    cin>>x;
    dp[1][0]=dp[1][1]=x*v[i];
    dp[1][2]=c[x]*v[i];
    dp[1][0]+=dp[0][0];
    dp[1][1]+=(dp[0][1] > dp[0][2] ? dp[0][1] : dp[0][2]);
    dp[1][2]+=(dp[0][0] > dp[0][2] ? dp[0][0] : dp[0][2]);
    for(int j=0; j<3; j++) dp[0][j]=dp[1][j];
  }
  cout<<(dp[0][1] > dp[0][2] ? dp[0][1] : dp[0][2])<<'\n';
  return 0;
}