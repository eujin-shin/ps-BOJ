#include <iostream>
#include <vector>
#include <algorithm>
#define pnt pair<int, pair<int, int> >
using namespace std;

vector <pnt> v;

int compare(pnt x, pnt y) {
  return y.first < x.first;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, k, x, s, tmp;
  bool flag=false;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>k>>x>>s;
    v.push_back(make_pair(s, make_pair(k, x)));
  }
  sort(v.begin(), v.end(), compare);
  int i=-1, cnt=0;
  while(cnt<3) {
    i++;
    tmp=v[i].second.first;
    if(i>0 && tmp==k) {
      if(!flag) flag=true;
      else continue;
    }
    cout<<tmp<<' '<<v[i].second.second<<'\n';
    k=tmp; cnt++;
  }
  return 0;
}