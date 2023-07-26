#include <iostream>
#include <vector>
#include <algorithm>
#define M 100001
using namespace std;

vector <int> v[M];
int visit[M]={0, };
int c=1;

void DFS(int r) {
  int next;
  visit[r]=c++;
  sort(v[r].begin(), v[r].end());
  for(int i=0; i<v[r].size(); i++) {
    next=v[r][i];
    if(visit[next]==0) DFS(next);
  }
  return;
}

int main() {
  int n, m, r, x, y;
  cin>>n>>m>>r;
  for(int i=0; i<m; i++) {
    cin>>x>>y;
    v[x].push_back(y); v[y].push_back(x);
  }
  DFS(r);
  for(int i=1; i<=n; i++) {
    cout<<visit[i]<<'\n';
  }
  return 0;
}