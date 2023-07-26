#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> v[100001];
int parents[100001] = {0, };
int visit[100001] = {0, };

void DFS(int x) {
  visit[x] = 1;
  for(int i=0; i<v[x].size(); i++) {
    if(visit[v[x][i]]==0) {
      parents[v[x][i]] = x;
      DFS(v[x][i]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, x, y;
  cin>>n;
  for(int i=1; i<n; i++) {
    cin>>x>>y;
    v[x].push_back(y); v[y].push_back(x);
  }
  DFS(1);
  for(int i=2; i<=n; i++) {
    cout<<parents[i]<<'\n';
  }
  return 0;
}