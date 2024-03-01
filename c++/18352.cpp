#include <iostream>
#include <vector>
#include <queue>
#define MAX 300001
using namespace std;

vector <int> v[MAX];
queue <int> q;
int dist[MAX]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, k, x, a, b;
  cin>>n>>m>>k>>x;
  for(int i=0; i<m; i++) {
    cin>>a>>b;
    v[a].push_back(b);
  }
  int cur, tmp, next=0, cnt=1, l=0;
  q.push(x);
  while(!q.empty() && l<k) {
    cur=q.front(); q.pop();
    for(int i=0; i<v[cur].size(); i++) {
      tmp=v[cur][i];
      if(dist[tmp]!=0 || tmp==x) continue;
      dist[tmp]=dist[cur]+1; q.push(tmp);
      next++;
    }
    cur--;
    if(cur==0) {
      cur=next; next=0; l++;
    }
  }
  cnt=0;
  for(int i=1; i<=n; i++) {
    if(dist[i]==k) {
      cout<<i<<'\n'; cnt++;
    }
  }
  if(cnt==0) cout<<"-1\n";
  return 0;
}