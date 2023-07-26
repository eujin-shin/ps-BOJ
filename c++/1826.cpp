#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pnt pair<int, int>
using namespace std;

vector <pnt> v;
priority_queue <int> pq;

int main() {
  ios_base::sync_with_stdio(false);
  int n, l, p, a, b, i, c=0;
  cin>>n;
  for(i=0; i<n; i++) {
    cin>>a>>b;
    v.push_back(make_pair(a, b));
  }
  cin>>l>>p; i=0;
  sort(v.begin(), v.end());
  while(p<l) {
    while(i<v.size() && v[i].first<=p) {
      pq.push(v[i].second); i++;
    }
    if(pq.empty()) break;
    p+=pq.top(); pq.pop(); c++;
  }
  if(p<l) cout<<"-1\n";
  else cout<<c<<'\n';
  return 0;
}