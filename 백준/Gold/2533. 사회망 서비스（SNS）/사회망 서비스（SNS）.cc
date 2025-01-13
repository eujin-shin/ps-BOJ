#include <iostream>
#include <vector>
#include <queue>
#define pnt pair<int, int> 
#define MAX 1000001
using namespace std;

vector <int> v[MAX];
int parents[MAX] = {0, }, children[MAX] = {0, };
int dp[MAX][2] = {0, };

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin>>n;

  int x, y;
  for(int i = 1; i < n; i++) {
    cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
  }

  queue <int> q, leaf;
  int cur;
  q.push(1);
  while(!q.empty()) {
    cur = q.front();
    q.pop();
    children[cur] = v[cur].size() - (cur == 1 ? 0 : 1);
    if(children[cur] == 0) {
      leaf.push(cur);
    }
    for(int i = 0; i < v[cur].size(); i++) {
      if(v[cur][i] != parents[cur]) {
        q.push(v[cur][i]);
        parents[v[cur][i]] = cur;
      }
    }
  }

  int parent;
  while(!leaf.empty()) {
    cur = leaf.front();
    parent = parents[cur];
    leaf.pop();

    dp[cur][1]++;
    if(cur == 1) {
      break;
    }

    dp[parent][0] += dp[cur][1];
    dp[parent][1] += (dp[cur][1] < dp[cur][0] ? dp[cur][1] : dp[cur][0]);

    if(--children[parent] == 0) {
      leaf.push(parent);
    }
  }
  cout<<(dp[1][0] < dp[1][1] ? dp[1][0] : dp[1][1])<<'\n';
  return 0;
}