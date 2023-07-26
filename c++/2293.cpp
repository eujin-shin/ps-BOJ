#include <iostream>
using namespace std;

int dp[10001] = {0, };

int Cmp(const void *a, const void *b) {
  return *(int *)a-*(int *)b;
}

int main() {
  int n, k, cur, ans=1;
  int coin[100] = {0, };
  cin>>n>>k;
  for(int i=0; i<n; i++) {
    cin>>coin[i];
  }
  qsort(coin, n, sizeof(int), Cmp);
  for(int i=0; i<n; i++) {
    cur=coin[i];
    for(int j=1; j<=k; j++) {
      if(j==cur) dp[j]+=1;
      if(j>cur) dp[j]+=dp[j-cur];
    }
  }
  cout<<dp[k]<<endl;
  return 0;
}