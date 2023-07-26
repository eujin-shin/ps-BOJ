#include <iostream>
#include <vector>
#include <string>
#define M 201
using namespace std;

int visit[M]={0, };
vector <int> v[M];

void DFS(int r) {
  int next;
  for(int i=0; i<v[r].size(); i++) {
    next=v[r][i];
    if(visit[next]!=1) {
      visit[next]=1; DFS(next);
    }
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  string ans = "YES";
  int n, m, x;
  cin>>n>>m;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      cin>>x;
      if(x==0) continue;
      v[i].push_back(j); v[j].push_back(i);
    }
  }
  for(int i=0; i<m; i++) {
    cin>>x;
    visit[x]=-1;
  }
  visit[x]=1; DFS(x);
  for(int i=1; i<=n; i++) {
    if(visit[i]==-1) ans="NO";
  }
  cout<<ans<<'\n';
  return 0;
}