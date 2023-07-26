#include <iostream>
#include <vector>
#include <queue>
#define MAX 32001
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, small, tall, ind[MAX];
  vector <int> graph[MAX];
  cin>>n>>m;
  for(int i=0; i<m; i++) {
    cin>>small>>tall;
    graph[small].push_back(tall);
    ++ind[tall];
  }
  queue <int> sort;
  for(int i=1; i<=n; i++) {
    if(ind[i]==0) sort.push(i);
  }
  int cur;
  for(int i=1; i<=n; i++) {
    cur=sort.front(); sort.pop();
    for(int j=0; j<graph[cur].size(); j++) {
      if(--ind[graph[cur][j]]==0) {
        sort.push(graph[cur][j]);
      }
    }
    cout<<cur;
    if(i==n) cout<<'\n';
    else cout<<' ';
  }
  return 0;
}