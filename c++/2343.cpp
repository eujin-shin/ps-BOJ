#include <iostream>
#include <vector>
using namespace std;

vector <int> v;
int m;

int Check(int k) {
  int cur=0, cnt=0;
  for(int i=0; i<v.size(); i++) {
    if(cur+v[i]<=k) {
      cur+=v[i];
    } else {
      if(v[i]>k) return 0;
      cur=v[i]; cnt++;
    }
  }
  if(cur>0) cnt++;
  if(cnt>m) return 0;
  return 1;
}

int Bound(int sum) {
  int l=0, r=sum, mid, ans;
  while(l<=r) {
    mid=(l+r)/2;
    if(Check(mid)) {
      ans=mid;
      r=mid-1;
    } else {
      l=mid+1;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, tmp, sum=0;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    cin>>tmp; sum+=tmp;
    v.push_back(tmp);
  }
  cout<<Bound(sum)<<'\n';
  return 0;
}