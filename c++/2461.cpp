#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define pnt pair<int, int>
#define MAX 1000000000
using namespace std;

priority_queue <pnt> pq;
vector <int> v[1000];

int main() {
  int pos[1000]={0, };
  int n, m, x, idx, max, ans=MAX;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin>>x; v[i].push_back(x);
    }
    sort(v[i].begin(), v[i].end());
    pq.push(make_pair(-v[i][0], i));
    if(i==0 || max<v[i][0]) max=v[i][0];
  }
  while(1) {
    x=-pq.top().first; idx=pq.top().second;
    if(ans>max-x) ans=max-x;
    pos[idx]++;
    if(pos[idx]==m) break;
    pq.pop(); x=v[idx][pos[idx]];
    if(max<x) max=x;
    pq.push(make_pair(-x, idx));
  }
  cout<<ans<<'\n';
  return 0;
}