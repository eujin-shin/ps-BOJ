#include <iostream>
#include <vector>
using namespace std;

vector <int> v;

int Bound(int k) {
  int mid, l=0, r=v.size()-1, idx;
  while(l<=r) {
    mid=(l+r)/2;
    if(v[mid]>=k) {
      idx=mid; r=mid-1;
    } else {
      l=mid+1;
    }
  }
  return idx;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, tmp;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>tmp;
    if(v.size()==0 || v[v.size()-1]<tmp) v.push_back(tmp);
    else {
      v[Bound(tmp)]=tmp;
    }
  }
  cout<<n-v.size()<<'\n';
  return 0;
}