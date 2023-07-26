#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> list[501];
  queue<int> q;
  int visit[501] = {0, };
  int n, m, a, b, cur, next, count=0;
  cin>>n>>m;
  visit[1] = 1;
  for(int i=0; i<m; i++) {
    cin>>a>>b;
    list[a].push_back(b);
    list[b].push_back(a);
    if(a==1 && visit[b]==0) {
      count++; visit[b]=1; q.push(b);
    }
  }
  while(!q.empty()) {
    cur = q.front(); q.pop();
    for(int i=0; i<list[cur].size(); i++) {
      next = list[cur][i];
      if(visit[next]==0) {
        visit[next]=1;
        count++;
      }
    }
  }
  cout<<count<<'\n';
  return 0;
}