#include <iostream>
using namespace std;

long long dp[32][32] = {0, };

long long DFS(long long *count, int w, int h) {
  long long temp=0;
  if(dp[w][h]>0) {
    *count = *count+dp[w][h];
    return dp[w][h];
  } 
  if(w>0) temp+=DFS(count, w-1, h+1);
  if(h>0) temp+=DFS(count, w, h-1);
  dp[w][h] = temp;
  return dp[w][h];
}

int main() {
  int n;
  long long count;
  dp[1][0]=1; dp[0][1]=1;
  while(1) {
    cin>>n;
    if(n<=0) break;
    count=0;
    cout<<DFS(&count, n, 0)<<'\n';
  }
}