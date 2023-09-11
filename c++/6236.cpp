#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector <int> v;

bool Check(int k) {
  int cnt=0, cur=0;
  for(int i=0; i<n; i++) {
    if(cur<v[i]) {
      cnt++; cur=k-v[i];
    } else {
      cur-=v[i];
    }
  }
  return cnt<=m;
}

int Bisearch(int l, int r) {
  int mid, ans;
  while(l<=r) {
    mid=(l+r)/2;
    if(Check(mid)) {
      ans=mid; r=mid-1;
    } else {
      l=mid+1;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  int tmp, sum=0, max=0;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    cin>>tmp;
    sum+=tmp;
    if(max<tmp) max=tmp;
    v.push_back(tmp);
  }
  cout<<Bisearch(max, sum)<<'\n';
}