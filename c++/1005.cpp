#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

int dp[MAX]={0, };
int tm[MAX]={0, };

int GetDp(int x, vector<int>(&graph)[MAX]) {
  if(dp[x]>-1) return dp[x];
  int res=tm[x], temp;
  for(int i=0; i<graph[x].size(); i++) {
    temp=tm[x]+GetDp(graph[x][i], graph);
    if(temp>res) res=temp;
  }
  dp[x]=res;
  return dp[x];
  /*
  int res;
  if(graph[x].size()==0) {
    dp[x]=-1; res=sum;
  } else {
    int max=0, temp, next;
    for(int i=0; i<graph[x].size(); i++) {
      next=graph[x][i];
      if(dp[next]!=0) {
        temp=sum+tm[next]+dp[next];
        if(dp[next]==-1) temp++;
      } else if(graph[next].size()==0) {
        dp[next]=-1;
        temp=sum+tm[next];
      } else temp=GetDp(graph[x][i], sum+tm[graph[x][i]], graph);
      if(temp>max) max=temp; 
    }
    dp[x]=max-sum; res=max;
  } 
  return res;
  */
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t, n, k, x, y, w;
  cin>>t;
  while(t--) {
    vector <int> graph[MAX];
    cin>>n>>k;
    for(int i=1; i<=n; i++) {
      cin>>tm[i];
      dp[i]=-1;
    }
    for(int i=0; i<k; i++) {
      cin>>x>>y;
      graph[y].push_back(x);
    }
    cin>>w;
    if(graph[w].size()==0) cout<<tm[w]<<'\n';
    else cout<<GetDp(w, graph)<<'\n';
  }
  return 0;
}