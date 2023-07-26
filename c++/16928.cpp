#include <iostream>
#include <queue>
using namespace std;

int arr[101]={0, };
int dp[101]={0, };

int main() {
  int n, m, a, b, cur;
  cin>>n>>m;
  for(int i=0; i<n+m; i++) {
    cin>>a>>b;
    arr[a]=b;
  }
  queue <int> q; q.push(1); dp[1]=1;
  int level=0, now=1, count=0;
  while(!q.empty()) {
    cur=q.front(); q.pop();
    if(cur==100) break;
    for(int i=1; i<=6; i++) {
      if(cur+i>100) break;
      if(arr[cur+i]!=0) {
        if(dp[arr[cur+i]]==0) {
          q.push(arr[cur+i]);
          dp[arr[cur+i]]=1;
          count++;
        }
      } else {
        if(dp[cur+i]==0) {
          q.push(cur+i);
          dp[cur+i]=1;
          count++;
        }
      }
    }
    now--;
    if(now==0) {
      now=count; count=0; level++;
    }
  }
  cout<<level<<'\n';
  return 0;
}