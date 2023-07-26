#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int, int> > v;

int main() {
  ios_base::sync_with_stdio(false);
  int n, sum=0, i, x, y;
  cin>>n;
  for(i=0; i<n; i++) {
    cin>>x>>y; 
    v.push_back(make_pair(x, y));
  }
  sort(v.begin(), v.end());
  x=-1; y=-1; i=0;
  while(i<=n) {
    if(i==n || v[i].first>y) {
      sum+=y-x;
      x=v[i].first; y=v[i].second;
      i++; continue;
    }
    if(v[i].second>y) y=v[i].second;
    i++;
  }
  cout<<sum<<'\n';
  return 0;
}