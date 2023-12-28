#include <iostream>
#include <vector>
#include <algorithm>
#define pnt pair<int, int>
using namespace std;

vector <pnt> v, sum;

int Bisearch(int k) {
  int l=0, r=sum.size()-1, mid, ans=-1;
  while(l<=r) {
    mid=(l+r)/2;
    if(sum[mid].first<=k) {
      ans=mid; l=mid+1;
    } else r=mid-1;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, s, h, c, idx;
  cin>>n>>s;
  for(int i=0; i<n; i++) {
    cin>>h>>c;
    v.push_back(make_pair(h, c));
  }
  sort(v.begin(), v.end());
  sum.push_back(make_pair(0, 0));
  for(int i=0; i<n; i++) {
    h=v[i].first; c=v[i].second;
    idx=Bisearch(h-s);
    if(idx<0) continue;
    c+=sum[idx].second;
    if(sum[sum.size()-1].second<c) sum.push_back(make_pair(h, c));
  }
  cout<<sum[sum.size()-1].second<<'\n';
  return 0;
}