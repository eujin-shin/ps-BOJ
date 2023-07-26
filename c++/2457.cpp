#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int, int> > v;

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, d, x, y, c=0, i, start, end;
  cin>>n;
  for(i=0; i<n; i++) {
    cin>>m>>d; x=m*100+d;
    cin>>m>>d; y=m*100+d;
    v.push_back(make_pair(x, y));
  }
  sort(v.begin(), v.end());
  i=0; start=301; end=301;
  while(1) {
    if(i>=v.size() || v[i].first>end) break;
    while(v[i].first<=start) {
      if(end<v[i].second) end=v[i].second;
      i++;
      if(i>=v.size()) break;
    }
    start=end; c++;
    if(end>1130) break;
  }
  if(end<=1130) cout<<"0\n";
  else cout<<c<<'\n';
  return 0;
}