#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solve(int n);

int main() {
  int t, n;
  cin>>t;
  while(t--) {
    cin>>n;
    cout<<solve(n)<<'\n';
  }
  return 0;
}

int solve(int n) {
  vector <int> v[10001];
  int levels[10001] = {0, }, children[10001] = {0, }, parents[10001] = {0, };

  int x, y, a, b;
  for(int i = 1; i < n; i++) {
    cin>>x>>y;
    v[x].push_back(y);
    parents[y] = x;
    children[x]++;
  }
  cin>>a>>b;

  int root = x;
  while(parents[root] != 0) {
    root = parents[root];
  }

  queue <int> q;
  q.push(root);
  int cur, child;
  while(!q.empty()) {
    cur = q.front();
    q.pop();
    for(int i = 0; i < v[cur].size(); i++) {
      child = v[cur][i];
      levels[child] = levels[cur] + 1;
      q.push(child);
    }
  }

  while(a != b) {
    if(levels[a] > levels[b]) {
      a = parents[a];
    } else if(levels[a] < levels[b]) {
      b = parents[b];
    } else {
      a = parents[a];
      b = parents[b];
    }
  }
  return a;
}