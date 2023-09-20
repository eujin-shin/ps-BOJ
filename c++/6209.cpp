#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> v;
int d, n, m;

bool Check(int k) {
  int cnt=0, cur=0;
  for(int i=0; i<=n; i++) {
    if(v[i]-cur>=k) cur=v[i];
    else {
      cnt++;
    }
  }
  return cnt<=m;
}

int Bisearch(int min) {
  int l=min, r=d, mid, ans;
  while(l<=r) {
    mid=(l+r)/2;
    if(Check(mid)) {
      ans=mid; l=mid+1;
    } else {
      r=mid-1;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  int min, tmp;
  cin>>d>>n>>m;
  for(int i=0; i<n; i++) {
    cin>>tmp;
    v.push_back(tmp);
  }
  v.push_back(d);
  sort(v.begin(), v.end());
  for(int i=1; i<=n; i++) {
    if(i==1 || v[i]-v[i-1]<min) min=v[i]-v[i-1];
  }
  cout<<Bisearch(min)<<'\n';
  return 0;
}