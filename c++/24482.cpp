#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector <int> v[100001];
int arr[100001]={0, };

void dfs(int r) {
  int next;
  sort(v[r].begin(), v[r].end());
  for(int i=1; i<=v[r].size(); i++) {
    next=v[r][v[r].size()-i];
    if(arr[next]>=0) continue;
    arr[next]=arr[r]+1;
    dfs(next);
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, r, x, y, cur, tmp;
  cin>>n>>m>>r;
  for(int i=0; i<m; i++) {
    cin>>x>>y;
    v[x].push_back(y); v[y].push_back(x);
  }
  for(int i=1; i<=n; i++) arr[i]=-1;
  arr[r]=0;
  dfs(r);
  for(int i=1; i<=n; i++) cout<<arr[i]<<'\n';
  return 0;
}