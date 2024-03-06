#include <iostream>
#include <vector>
#include <algorithm>
#define pnt pair<int, int>
using namespace std;

vector <pnt> v;

int main() {
  int n, p, s, tmp, max=0, ans=0;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>p>>s;
    v.push_back(make_pair(p, s));
  }
  sort(v.begin(), v.end());
  for(int i=0; i<n; i++) {
    tmp=0;
    for(int j=i; j<n; j++) {
      if(v[i].first>v[j].second) tmp+=v[i].first-v[j].second;
    }
    if(tmp>max) {
      max=tmp; ans=v[i].first;
    }
  }
  cout<<ans<<'\n';
  return 0;
}