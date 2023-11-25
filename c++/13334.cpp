#include <iostream>
#include <queue>
#include <vector>
#define pnt pair<int, int>
using namespace std;

vector <pnt> v;
priority_queue <pnt> pq;

int main() {
  ios_base::sync_with_stdio(false);
  int n, h, o, d;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>h>>o;
    if(h>o) v.push_back(make_pair(h, o));
    else v.push_back(make_pair(o, h));
  }
  cin>>d;
  priority_queue <int> cur;
  int max=0, s, e;
  for(int i=0; i<n; i++) {
    s=v[i].first; e=v[i].second;
    if(s-e>d) continue;
    pq.push(make_pair(e+d, s));
  }
  while(!pq.empty()) {
    s=pq.top().first; e=pq.top().second;
    pq.pop();
    while(!cur.empty() && cur.top()>s) cur.pop();
    cur.push(e);
    max=(max<cur.size()) ? (cur.size()) : (max);
  }
  cout<<max<<"\n";
  return 0;
}