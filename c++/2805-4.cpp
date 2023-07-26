#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

ll ans=-1, m;
vector <ll> v;

int Check(ll len) {
  ll sum=0;
  for(int i=0; i<v.size(); i++) {
    if(v[i]>=len) sum+=v[i]-len;
    if(sum>=m) return 1;
  }
  return 0;
}

void Bsearch(ll x, ll y) {
  ll l=x, r=y, mid;
  int rst;
  while(l<=r) {
    mid=(l+r)/2;
    rst=Check(mid);
    if(rst==1) {
      if(ans<=mid) ans=mid;
      l=mid+1;
    } else {
      r=mid-1;
    }
  }
  return;
}

int main() {
  ll tmp;
  int n;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    cin>>tmp; v.push_back(tmp);
  }
  sort(v.begin(), v.end());
  Bsearch(v[n-1]-m, v[n-1]);
  cout<<ans<<'\n';
  return 0;
}