#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
#define pnt pair<int, int>
using namespace std;

priority_queue <pnt> pq;
multiset <int> bag;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k, m, v, tmp;
  long long sum=0;
  cin>>n>>k;
  for(int i=0; i<n; i++) {
    cin>>m>>v;
    pq.push(make_pair(v, m));
  }
  for(int i=0; i<k; i++) {
    cin>>tmp;
    bag.insert(tmp);
  }
  multiset<int>::iterator iter;
  while(!bag.empty() && !pq.empty()) {
    v=pq.top().first; m=pq.top().second; pq.pop();
    iter=bag.lower_bound(m);
    if(iter!=bag.end()) {
      sum+=v; bag.erase(iter);
    }
  }
  cout<<sum<<'\n';
  return 0;
}