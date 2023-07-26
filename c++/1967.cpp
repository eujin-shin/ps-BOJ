#include <iostream>
#include <vector>
using namespace std;

struct node {
  int dest, cost;
};

vector <node> tree[10002];

void DFS(node *max, int cost, int cur, int visit[]) {
  if(max->cost<cost) {
    max->cost=cost; max->dest = cur;
  }
  for(int i=0; i<tree[cur].size(); i++) {
    node *next = &tree[cur][i];
    if(visit[next->dest]==0) {
      visit[next->dest]=1;
      DFS(max, cost+next->cost, next->dest, visit);
      visit[next->dest]=0;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, p, x, y, c, cost;
  cin>>n;
  for(int i=0; i<n-1; i++) {
    cin>>x>>y>>c;
    node a; a.cost = c; a.dest=y;
    tree[x].push_back(a);
    node b; b.cost = c; b.dest = x;
    tree[y].push_back(b);
  }
  node max; max.cost=0;
  int visit[10002] = {0, }; visit[1]=1;
  DFS(&max, 0, 1, visit);
  node max2; max2.cost=0;
  int visit2[10002] = {0, }; visit2[max.dest]=1;
  DFS(&max2, 0, max.dest, visit2);
  cout<<max2.cost<<'\n';
  return 0;
}