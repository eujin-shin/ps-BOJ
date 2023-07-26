#include <iostream>
using namespace std;

int Min(int x, int y) {
  int min;
  if(x>y) min = y; else min = x;
  return min;
}

int Max(int x, int y) {
  int max;
  if(x>y) max = x; else max = y;
  return max;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int min_dp[3][4] = {0, }, max_dp[3][4] = {0, }, num[3] = {0, };
  int n, min, max;
  cin>>n;
  cin>>min_dp[0][0]>>min_dp[0][1]>>min_dp[0][2];
  max_dp[0][0]=min_dp[0][0]; max_dp[0][1]=min_dp[0][1]; max_dp[0][2]=min_dp[0][2];
  for(int i=1; i<n; i++) {
    cin>>num[0]>>num[1]>>num[2];
    min = Min(min_dp[0][0], min_dp[0][1]);
    min_dp[1][0] = num[0] + min;
    min = Min(min, min_dp[0][2]);
    min_dp[1][1] = num[1] + min;
    min = Min(min_dp[0][2], min_dp[0][1]);
    min_dp[1][2] = num[2] + min;

    for(int i=0; i<3; i++) {
      min_dp[0][i] = min_dp[1][i];
      min_dp[1][i] = 0;
    }

    max = Max(max_dp[0][0], max_dp[0][1]);
    max_dp[1][0] = num[0] + max;
    max = Max(max, max_dp[0][2]);
    max_dp[1][1] = num[1] + max;
    max = Max(max_dp[0][2], max_dp[0][1]);
    max_dp[1][2] = num[2] + max;

    for(int i=0; i<3; i++) {
      max_dp[0][i] = max_dp[1][i];
      max_dp[1][i] = 0;
    }
  }
  min = Min(Min(min_dp[0][0], min_dp[0][1]), min_dp[0][2]);
  max = Max(Max(max_dp[0][0], max_dp[0][1]), max_dp[0][2]);
  cout<<max<<' '<<min<<'\n';
  return 0;
}